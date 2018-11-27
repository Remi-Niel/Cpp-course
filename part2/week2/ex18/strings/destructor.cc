#include "strings.ih"

// basic guarentee: now new memory is allocated and all allocated memory in the object
// is destroyed.
// Strong guarentee: it is the destructor hence rollback is not really possible, when a destructor has destroyed
// partially and something goes wrong you can't magically regain data.
// Nothrow guarentee: delete and destroy have nothrow guarentee hence no exceptions are thrown.
Strings::~Strings()
{
    for (; d_size--; )
        delete d_str[d_size];

    destroy();
}
