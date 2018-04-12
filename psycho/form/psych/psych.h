#ifndef INCLUDED_PSYCH_
#define INCLUDED_PSYCH_

#include <iosfwd>
#include <unordered_map>
#include <vector>
#include <string>

#include "../psychclient/psychclient.h"
#include "../../support/datastore/datastore.h"
#include "../../support/dollartext/dollartext.h"
#include "../../support/display/display.h"

namespace FBB
{
    class CGI;
};

class Psych
{
    typedef std::unordered_map<std::string, void (Psych::*)()> Map;

    DataStore d_data;          // psychologists' data
    FBB::CGI &d_cgi;

    DollarText d_dollarText;
    Display d_display;

    static Map      s_state;        // maps state names to handling functions

    // data below are saved to file

    uint32_t    d_time;             // registration time 
    uint16_t    d_ack;              // if != 0 then e-mail acknowledge
    uint16_t    d_flags;            // room for 16 bit-flags
    uint16_t    d_ID;               // identification number
    uint64_t    d_nip;
    std::string d_pwdHash;          // MD5 hash of the password (16 bytes)
        
        // encrypted section:
    bool        d_gender;           // 0: female, 1: male
    std::string d_name; 
    std::string d_lastName;
    std::string d_email;

    std::vector<PsychClient> d_client;  // client info

    public:
        Psych(FBB::CGI &cgi);
        void process();

    private:
        void tryAdd();
        bool acceptSignup();

        void verify();
        void noPwd();

        void verifyAck();

        void client();                  // WIP

        std::string nipKey() const; // get key from cgi.param1("nip")

        bool pwdMatch() const;

        std::string toString() const;
        bool get();

        void unknown();
        char const *genderText() const;

        static std::string newPassword();
};

inline char const *Psych::genderText() const
{
    return d_gender == 0 ? "mevrouw" : "heer";
}

#endif


