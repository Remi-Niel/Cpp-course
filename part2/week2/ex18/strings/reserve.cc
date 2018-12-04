#include "strings.ih"

// Basic guarantee: memory allocated to d_str is destroyed by the destructor 
// when needed.
// Strong guarentee: d_capacity is corrected incase of exceptions.
// Exception neutral: exceptions are propagated to the caller.

void Strings::reserve(size_t nextCapacity)
{
    size_t capacity = d_capacity; //Keep track of previous capacity
    try
    {
        if (d_capacity < nextCapacity)
        {
            capacity = d_capacity; //Get the most recent capacity
            while (d_capacity < nextCapacity)
                d_capacity <<= 1;
            
            d_str = enlarged();
        }   
    }
    catch(...)
    {
        //Set d_capacity to the amount actually reserved.
        d_capacity = capacity; 
        throw;
    }
}
