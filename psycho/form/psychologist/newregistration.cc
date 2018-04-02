#include "psychologist.ih"

void Psychologist::newRegistration()
{
    Private priv
    {
        stoull(d_cgi.param1("nip")),
        d_cgi.param1("gender") == "M",
        
        d_cgi.param1("name"),
        d_cgi.param1("name"),         // UPDATE! TODO
        d_cgi.param1("email")
    };
    
    string iv = Tools::iv();

    string encrypted = Tools::encrypt(iv, toString(priv));

    Record record
    {
        identNr(),
        Tools::md5hash(d_cgi.param1("passwd")),
        static_cast<uint16_t>(
            2 * sizeof(uint64_t) +                  // key and iv's sizes
            sizeof(Record) + encrypted.size()
        )
    };

    Display{ 
        d_psychData.add(nipKey(), iv, toString(record) + encrypted) ?
                    "newregistration"
                :
                    "cantregister"
    };
}
