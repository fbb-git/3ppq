#include "datastore.ih"

uint16_t DataStore::nextNr()
{
    LockGuard lck { lg() };
    
    uint16_t next;

    d_stream.open();

    Tools::readN(d_stream, 0, &next);
    ++next;
    Tools::writeN(d_stream, 0, &next);

    return next;
}
