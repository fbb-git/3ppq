#include "psych.ih"

size_t Psych::buildClientArray(string *array) const
{
    size_t idLength = 0;
    for (auto const &client: d_client)
        idLength = ::max(idLength, client.ident().length());
    idLength += 2;

    ostringstream out;
    for (auto const &client: d_client)      // construct the client array
    {
//    g_log << client.id() << ": active = " << client.active() << 
//                            ", login0 = " << client.login0() << endl;

        out << setw(11) << "[\"" <<   
                client.ident() << "\",\""  <<    
                client.name() << ' ' << client.lastName() << "\"],\n";
    }

    *array = out.str();

    return idLength;
}
