#include "psych.ih"

void Psych::put(DataStore &dataStore, string const &key) const
{
    dataStore.add(key, toString());
}
