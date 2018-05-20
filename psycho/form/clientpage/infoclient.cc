#include "clientpage.ih"

    // at least some clients are available.
    // see also buildclientarray.cc and buildselecttag.cc

void ClientPage::infoClient(string *array, string *select)
{
    buildSelectTag( select, buildClientArray(array) );
}



