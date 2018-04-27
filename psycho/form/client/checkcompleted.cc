#include "client.ih"

void Client::checkCompleted(WIPdata &wipData) const
{
    if (
        wipData.selfRatings().front() == 0    or
        wipData.metaRatings().front() == 0    or
        not otherRatingsCompleted(wipData)
    )
        return;

g_log << "data collection completed: writing " << g_options.data() << endl;

    LockStream data{ g_options.data() };

    data.open();
    LockGuard lg = data.lg();

    data.seekp(0, ios::end);
    
    data << wipData << endl;

    wipData.remove();

g_log << "data stored" << endl;

}
