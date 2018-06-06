#ifndef INCLUDED_PSYCH_
#define INCLUDED_PSYCH_

#include <iosfwd>
#include <unordered_map>
#include <vector>
#include <string>

#include <bobcat/align>

#include "../psychclient/psychclient.h"
#include "../../support/datastore/datastore.h"
#include "../../support/display/display.h"
#include "../../support/tools/tools.h"

#include "../clientpage/clientpage.h"


namespace FBB
{
    class CGI;
};

class LockGuard;
class WIPdata;

class Psych
{
    friend std::ostream &operator<<(std::ostream &out, Psych const &psych);

    typedef std::unordered_map<std::string, void (Psych::*)()>  Map;
    typedef std::unordered_map<std::string, 
                               ClientPage::Info (Psych::*)()>   Map2display;

    DataStore d_data;          // psychologists' data
    FBB::CGI *d_cgi = 0;

    Display d_display;

    static Map          s_state;    // maps state names to handling functions
    static Map2display  s_clientPageRequest;    // maps "request" values to 
                                                // functions returning strings

    static std::string s_activate;
    static std::string s_add;
    static std::string s_addActive;
    static std::string s_deactivate;
//    static std::string s_erase;
    static std::string s_remove;
    static std::string s_update;
    

    // data below are saved to file

    uint32_t    d_time;             // registration time 
    uint16_t    d_ack;              // if != 0 then e-mail acknowledgement
                                    // pending

    uint16_t    d_nClients;         // # clients this psychologist
                                    // (unique order number)

    uint16_t    d_ID;               // identification number
                                    
    std::string d_pwdHash;          // MD5 hash of the password (16 bytes)
        
        // encrypted section:
    uint64_t    d_nip;
    uint8_t     d_field;            // occupation field(s)
    std::string d_name; 
    std::string d_lastName;
    std::string d_eMail;

    std::vector<PsychClient> d_client;  // client info. # actual clients is
                                        // determined as d_client.size()
    public:
        Psych(std::string const &data); 
        Psych(FBB::CGI &cgi);
        void process();

        std::string const &eMail() const;
        bool get(std::string const &key);
        void put(DataStore &dataStore, std::string const &key) const;

        uint16_t ID() const;
        bool ack() const;           // true: acknowledgement received
        uint32_t registrationTime() const;
        std::string fullName() const;

        void deactivateClient(WIPdata const &wipData);  // 2.cc

        bool erase();               // used by psychrecords

    private:
        void read(std::string const &data);
        bool get();                     // get psych record
        std::string emailKey() const;   // get key from cgi.param1("email")

        void verify();
        void notRegistered();
        void confirmNewPwd();
        void newPwd();

        void login();
        bool pwdMatch() const;
        void requestAck();

        void getData();                 // called from www/data.shtml
        void nQuest();                  // change the # questions to use

        void addPsych();
        bool validRegistrationData(uint64_t *nip, uint8_t *field);
        uint8_t parseField();
        static bool pwdRequirements(std::string const &pwd);

        void verifyAck();

        std::string messages();         // messages for this psychologist

        void profilePage();             // show profile page
        void profile();                 // update current profile
        bool validPwd();
        bool checkProfileData(uint8_t *field);
        bool validProfileData(uint8_t *field);
        bool changedPwd();

        void noPwd();

        void clientPage();                  // show the client page
        void report();                      // download a report

//  -------------------------------------------------------------------------
//                  client      
//  nr  reqActive   active    wipExists              action
//  -------------------------------------------------------------------------
//   1      .          1           1                    -
//   2      .          1           0      deactivate client (data completed)
//   3      1          0           1      should not happen: activate client
//   4      1          0           0      activate client
//   5      0          0           1      rm wipfile
//   6      0          0           0                    -
//  -------------------------------------------------------------------------

        ClientPage::Info activateClient();   // handles 3 by removing existing 
                                             //           file
        ClientPage::Info addClient();        // logs 5
        ClientPage::Info addActivateClient();// logs 5
        ClientPage::Info deactivateClient(); // logs 6 if no wip file
        ClientPage::Info removeClient();
        ClientPage::Info showClient();
        ClientPage::Info updateClient();

        PsychClient *validClientData();
        size_t validClientIdx();

        bool pushClient();

        void rmExistingWIPdata(PsychClient const &client, 
                              char const *txt) const;

                                    // all require members throw false on
                                    // failure
        void requireOneOf(char const *name, char const *charSet);
        void requireEqual(char const *name, std::string const &target);
        void requireContents(char const *name);
        long long requireNumber(char const *name);

        void inviteClient(PsychClient &client);

        std::string toString() const;
        static std::string newPassword();

        std::vector<LockGuard> updateWIPemail() const;

        std::ostream &insertInto(std::ostream &out) const;
};

inline std::ostream &operator<<(std::ostream &out, Psych const &psych)
{
    return psych.insertInto(out);
}

inline uint32_t Psych::registrationTime() const
{
    return d_time;
}

inline bool Psych::ack() const
{
    return d_ack == 0;
}

inline std::string Psych::fullName() const
{
    return d_name + ' ' + d_lastName;
}

inline std::string const &Psych::eMail() const
{
    return d_eMail;
}

inline uint16_t Psych::ID() const
{
    return d_ID;
}

#endif


