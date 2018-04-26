#include "client.ih"

void Client::otherCompleted(WIPdata &wipData, string const &ratings)
{
    size_t otherIdx = stoul(d_cgi.param1("other"));

    if 
    (
        otherIdx >= Tools::N_OTHER 
        || 
        wipData.otherRatings(otherIdx).front() != 0
    )
        throw false;

    wipData.setOtherRatings(otherIdx, ratings);
    wipData.rmOtherLogin(otherIdx);

    d_display.out("alldone.h");

    checkCompleted(wipData);   

}
