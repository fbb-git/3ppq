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
        throw Tools::DATA_AVAILABLE;

    wipData.setOtherRatings(otherIdx, ratings);
    wipData.rmOtherLogin(otherIdx);

    wipData.write();

    d_display.out("alldone.h");

    checkCompleted(wipData);   

}
