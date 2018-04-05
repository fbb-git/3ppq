#include "datastore.ih"

DataStore::DataStore(string const &path)
:
    d_path(path),
    d_dataIdx(path + ".idx")
{}
