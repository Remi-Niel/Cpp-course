#include "charcount.h"

// declare static list
void (CharCount::*CharCount::s_updater[])(char newchar) =
{   
    &CharCount::append,
    &CharCount::insert,
    &CharCount::update
};