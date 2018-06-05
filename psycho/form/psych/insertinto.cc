#include "psych.ih"

ostream &Psych::insertInto(ostream &out) const
{
    DateTime registrationTime(d_time, DateTime::UTC);

    out <<
        "   Initials and name: " << d_name << ' ' << d_lastName << "\n"
        "        Registration: " << registrationTime << "\n"
        "                 NIP: " << d_nip << "\n"
        "                  ID: " << d_ID << "\n"
        "      clients so far: " << d_nClients << '\n';

    for (size_t idx = 0; idx != d_client.size(); ++idx)
        out << "        client " << (idx + 1) << ":\n" <<
               d_client[idx] << '\n';

    return out;
}
