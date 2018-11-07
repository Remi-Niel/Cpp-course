#include "charcount.h"

// Static variables can't be initialized in the header so 
// we do it here.
void (CharCount::*CharCount::s_updater[])(char newchar) =
{   
    &CharCount::append,
    &CharCount::insert,
    &CharCount::update
};