#include "psych.ih"

size_t Psych::buildClientArray(string *array) const
{
    size_t idLength = 0;
//    for (auto const &client: d_client)
//        idLength = ::max(idLength, client.id().length());
    idLength += 2;

    ostringstream out;
    for (auto const &client: d_client)      // construct the client array
    {
//    g_log << client.id() << ": active = " << client.active() << 
//                            ", login0 = " << client.login0() << endl;

        out << setw(11) << '[' <<   
                client.id()         << ",\""  <<    
                client.name() << ' ' << client.lastName() << "\"],\n";

//        out << setw(11) << '[' <<   
//                client.id()         << ','      <<      //  0
//                client.gender()     << ','      <<      //  1
//                client.active()     << ",\""    <<      //  2
//                client.name()       << "\",\""  <<      //  3
//                client.lastName()   << "\",\""  <<      //  4
//                client.email()      << "\"],\n";        //  5
    }

    *array = out.str();

    return idLength;
}
