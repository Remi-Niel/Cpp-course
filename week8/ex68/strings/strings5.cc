#include "strings.ih"

Strings::Strings(size_t nIterate, bool copy)
	: Strings()
{
	d_nIter = nIterate;
	if (copy)
		this->enlargeFunc = &Strings::enlargeByCopy;
	else
		this->enlargeFunc = &Strings::enlargeByMove;
}
