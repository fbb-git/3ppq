#ifndef INCLUDED_PSYCH_
#define INCLUDED_PSYCH_

#include <iosfwd>
#include <unordered_map>

#include "../../support/datastore/datastore.h"

namespace FBB
{
    class CGI;
};

class Psych
{
    // data retrieved from d_psychData.get:
    //  iv (8 bytes)
    //  Record data (written by publicData): 2 uint16_t, 16 pytes pwd hash
    //  encrypted data (written by privateData)

    typedef std::unordered_map<std::string, void (Psych::*)()> Map;

    // when these records change after the system's been used then
    // a convertor is required, converting the old data structure to the new
    // then add the required new fields, and recompile
    struct Private
    {
        uint64_t    nip;
        bool        gender;         // 0: female, 1: male
        std::string name;           // w/o \n: add #string fields to the
                                    //         record's length
        std::string lastName;
        std::string email;
    };

    struct Record
    {
        uint16_t    ack;            // if != 0 then e-mail acknowledge
        uint16_t    nr;             // identification number
        std::string pwdHash;        // MD5 hash of the password (16 bytes)
    };
        
    static Map s_state;             // maps state names to handling functions

    std::string d_path;
    std::string d_lockPath;
    int d_lockFd;

    DataStore d_psychData;          // psychologists' data

    FBB::CGI &d_cgi;

    public:
        Psych(FBB::CGI &cgi);
        void process();

    private:
        void tryAdd();
        void alreadyRegistered();
        bool acceptRegistration();

        void registration();
        void login();
        void noPwd();


        uint16_t identNr() const;
        std::string nipKey() const; // get key from cgi.param1("nip")

//        void getPrivate(Private *priv, std::string const &data, 
//                                        size_t offset);

        std::string publicData() const;
        std::string privateData() const;

        std::string encrypt(std::string const &iv) const;
        void decrypt(std::string const &data);

        static Record getUnencrypted(std::string const &data);
        bool pwdMatch(Record const &) const;

        static bool acceptNr(std::istream &nrs, uint16_t idNr);
};
        

#endif


