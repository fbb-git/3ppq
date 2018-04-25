#include "client.ih"

void Client::checkCompleted(WIPdata const &wipData)
{
    if (
        wipData.selfRatings.front() == 0    or
        wipData.metaRatings.front() == 0    or
        not otherRatingsCompleted(wipData)
    )
        return;

    LockStream data{ d_options.data() };

    data.open();
    LockGuard lg = data.lg();

    data.seekp(0, ios::end);
    
    data << wipData << endl;

    unlink(data.path().c_str());
}
