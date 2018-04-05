#include "lfstream.ih"

Lfstream::~Lfstream()
{
    unlock();
}
