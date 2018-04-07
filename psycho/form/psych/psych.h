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

        char const *genderText() const;
    };

    struct Record
    {
        uint32_t    time;           // registration time 
        uint16_t    ack;            // if != 0 then e-mail acknowledge
        uint16_t    flags;          // room for 16 bit-flags
        uint16_t    nr;             // identification number
        std::string pwdHash;        // MD5 hash of the password (16 bytes)
        uint16_t    size;           // deduced: #bytes occupied by the 
                                    //  unencrypted data

        std::string toString() const;   // update when Record is modified
    };
        
    static Map s_state;             // maps state names to handling functions

    std::string d_path;
    std::string d_lockPath;
    int d_lockFd;

    DataStore d_psychData;          // psychologists' data

    FBB::CGI &d_cgi;

    Record d_record;
    Private d_private;

    public:
        Psych(FBB::CGI &cgi);
        void process();

    private:
        void tryAdd();
        bool acceptSignup();

        void verify();
        void noPwd();

        void verifyAck();

        uint16_t identNr() const;
        std::string nipKey() const; // get key from cgi.param1("nip")

        std::string getData();

        std::string publicData() const;
        std::string privateData() const;

        std::string encrypt(std::string const &iv) const;

        void getUnencrypted(std::string const &data);
        void getPrivate(std::string const &data, size_t offset);


        bool pwdMatch() const;

        static bool acceptNr(std::istream &nrs, uint16_t idNr);
        static std::string newPassword();
};
        

#endif


