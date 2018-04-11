#include "datastore.ih"

LockGuard DataStore::lg() const
{
    return d_stream.lg();    
}

