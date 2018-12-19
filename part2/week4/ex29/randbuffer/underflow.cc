#include "randbuffer.ih"

int RandBuffer::underflow()
{
    int tmp = d_range * random() / (RAND_MAX + 0.1);
    tmp = tmp % d_end;

    string value = to_string(tmp);
    if (d_buffer)
        delete[] d_buffer ;
    
    d_buffer = new char[value.size()];
    value.copy(d_buffer, value.size(), 0);

    setg(d_buffer, d_buffer + 1, d_buffer + value.size());
    return *d_buffer;
}

