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
    };

        // to retrieve: d_psychData.get() returns a char buffer:
        // bytes 0..7 contain the iv, 
        //  getRecord reads the Record's fields
        // remaining bytes are the encrypted string
        // the encrypted string can be converted to a Private record
        // using getPrivate. 
    Display{ 
        d_psychData.add(nipKey(), iv + toString(record) + encrypted) ?
                    "newregistration"
                :
                    "cantregister"
    };
}
