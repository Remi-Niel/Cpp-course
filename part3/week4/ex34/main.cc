// Prime number computation by Erwin Unruh
// Rewritten to run on C++11 by Frank Brokken

// To let the program generate all prime numbers up to the value 25, run it as
//      g++ --std=c++0x -DLAST=25 primefrank.cc |& grep 'instantiation of'
// of course, to get another value specify that value instead of 25.
// Alternatively, use this script to beautify the output:


#ifndef LAST
#define LAST 18
#endif

enum 
{ 
};

// This struct is needed to determine whether you can stop sieving.
//Determines 3 cases, if testvalue > sqrt(candidate) the candidate
// IS_PRIME since it is not divisble by other numbers besides 1 and itself.
// NO_PRIME if candidate is divisible by the testvalue. 
// CONTINUE if it is not divisible by the current testvalue but might still be divisible,
// by another value.
template <int candidate, int testValue>
struct Eval
{
    enum
    { 
        IS_PRIME,
        NO_PRIME,
        CONTINUE ,
        mode = 
            testValue * testValue > candidate ? IS_PRIME  :    
            candidate % testValue == 0 ?        NO_PRIME  :
                                                CONTINUE
    };
};

//Recursive definition, where candidate is the possible prime, and
// is tested against the testvalue prime + 1. Sieve is then used again,
// however mode is provided by Eval, in case of CONTINUE this default 
// implementation of sieve is used again. However for mode = IS_PRIME and
// mode = NO_PRIME specializations of sieve exist which exit the recursion.
template <int candidate, int prime, int mode >
struct sieve
{
    enum 
    { 
        next = prime + 1,
        isPrime = sieve<candidate, next, Eval<candidate, next>::mode>::isPrime
    };
};

//This sets isprime to IS_PRIME effectively exiting the recursion.
template <int candidate, int prime> 
struct sieve<candidate, prime, Eval<1, 1>::IS_PRIME>
{
    enum { isPrime = IS_PRIME };
};

//This sets isprime to NO_PRIME effectively exiting the recursion.
template <int candidate, int prime>
struct sieve<candidate, prime, Eval<1, 1>::NO_PRIME >
{
    enum { isPrime = NO_PRIME };
}; 

//Initializes the sieve to start testing with testvalue = 2
template <int prime>
struct test
{
    enum {isPrime = sieve<prime, 2, Eval<prime, 2>::mode>::isPrime };
};

//In the default case of the struct show, f() does not actually show
// the prime. Instead it just continues to the next prime candidate.
template <int prime, int isPrime>
struct show
{                           
    static void f()
    {
        show<prime - 1, test<prime - 1>::isPrime >::f();
    }
};

//If prime is a prime, the return statement causes compiler to print this
// specific instantiation of static int* show<prime,0>::f()
template <int prime>
struct show<prime,  Eval<1, 1>::IS_PRIME>
{
    static int *f()
    {
        show<prime - 1, test<prime - 1>::isPrime >::f();

        int x;
        return &x;
    }
};

//1 returns prime in test<> ::IsPrime and is the final case,
// so here the program stops.
template <>
struct show<1,  Eval<1, 1>::IS_PRIME>
{
    static void f()
    {}
};

//Starts the seach for primes at prime.
template <int prime>
void primes()
{
    show<prime, test<prime>::isPrime>::f();
}

int main() 
{
        // weird messages make sense because of the suggested grep command
    static_assert(LAST >= 2, 
        "instantiation of LAST must be >= 2");
    
    primes<LAST>();

    static_assert(0, 
        "instantiation of compilation terminated");
}
