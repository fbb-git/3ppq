#ifndef INCLUDED_PSYCH_
#define INCLUDED_PSYCH_

#include <iosfwd>
#include <unordered_map>
#include <vector>
#include <string>

#include "../psychclient/psychclient.h"
#include "../../support/datastore/datastore.h"
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

    Display d_display;

    static Map      s_state;        // maps state names to handling functions

    static char const *s_actions[]; // client.h, data.h, profile.h, contact.h
    static size_t s_actionsSize;

    // data below are saved to file

    uint32_t    d_time;             // registration time 
    uint16_t    d_ack;              // if != 0 then e-mail acknowledge
    uint16_t    d_flags;            // room for 16 bit-flags
    uint16_t    d_ID;               // identification number
    std::string d_pwdHash;          // MD5 hash of the password (16 bytes)
        
        // encrypted section:
    bool        d_gender;           // 0: female, 1: male
    uint64_t    d_nip;
    uint8_t     d_field;            // occupation field(s)
    std::string d_name; 
    std::string d_lastName;
    std::string d_email;

    std::vector<PsychClient> d_client;  // client info

    public:
        Psych(FBB::CGI &cgi);
        void process();

    private:
        bool get();
        std::string emailKey() const;   // get key from cgi.param1("email")
        void homePage();

        void verify();
        void notRegistered();
        void confirmNewPwd();
        void newPwd();

        void login();
        bool pwdMatch() const;
        void requestAck();

        void addPsych();
        uint8_t parseField();
        bool validRegistrationData(uint64_t *nip, uint8_t *field);

        void verifyAck();
        std::string messages();         // messages for this psychologist
        void actions();                 // from actions.h
        void profile();                 // update profile


        void noPwd();


        void client();                  // WIP

        std::string toString() const;

        char const *genderText() const;

        static std::string newPassword();
};

inline char const *Psych::genderText() const
{
    return d_gender == 0 ? "mevrouw" : "heer";
}

#endif


