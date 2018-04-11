#include "datastore.ih"

DataStore::DataStore(string const &path)
:
    d_stream(path),
    d_dataIdx(path + ".idx")
{}
