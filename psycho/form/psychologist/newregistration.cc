#include "psychologist.ih"

void Psychologist::newRegistration()
{
    Private private
    {
        stoull(d_cgi.param1("nip")),
        d_cgi.param1("gender") == 'M',
        
        d_cgi.param1("name"),
        d_cgi.param1("name"),         // UPDATE! TODO
        d_cgi.param1("email")
    };
    
    uint64_t iv = Tools::iv();

    string encrypted = Tools::encrypt(record.iv, toString(private));

    Record record
    {
        identNr(),
        Tools::md5hash(d_cgi.param1("passwd")),
        2 * sizeof(uint64_t) +                  // key and iv's sizes
            sizeof(Record) + encrypted.size()
    };

    Display{ 
        d_psychData.add(
                    Tools::Tools::md5hash8(d_cgi.param1("nip")),    // key
                    iv, 
                    toString(record) + encrypted                    // data
                ) ?
                    "newregistration" 
                :
                    "cantregister"
    };
}
