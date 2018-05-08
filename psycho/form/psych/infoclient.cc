#include "psych.ih"

    // at least some clients are available.
    // see also buildclientarray.cc and buildselecttag.cc

void Psych::infoClient(string *array, string *select)
{
    vector<bool> reportExists;

    size_t idLength = buildClientArray(array, reportExists);

    buildSelectTag(select, reportExists, idLength);
}



