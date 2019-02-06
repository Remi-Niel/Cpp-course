#include "producer.ih"

void Producer::list_producer()
{
    ifstream in{d_source};

    while (!in.eof() && in.good())
    {
        string buffer;
        getline(in, buffer);

        // skip empty lines and lines starting with # (comments).
        if (!buffer.empty() && buffer[0] != '#')
            d_sourcefiles.push(buffer);
    }
}