#ifndef INCLUDED_PSYCH_
#define INCLUDED_PSYCH_

#include <iosfwd>
#include <unordered_map>
#include <vector>
#include <string>

#include "../psychclient/psychclient.h"
#include "../../support/datastore/datastore.h"
#include "../../support/display/display.h"
#include "../../support/tools/tools.h"

#include <bobcat/align>

namespace FBB
{
    class CGI;
};

class LockGuard;

class Psych
{
    struct DisplayInfo
    {
        std::string submitActions;
        size_t      clientIdx;          // show this client idx unless >=
    };                                  // d_client.size()

    typedef std::unordered_map<std::string, void (Psych::*)()>  Map;
    typedef std::unordered_map<std::string, 
                               DisplayInfo (Psych::*)()>      Map2display;

    DataStore d_data;          // psychologists' data
    FBB::CGI &d_cgi;

    Display d_display;

    static Map          s_state;    // maps state names to handling functions
    static Map2display  s_clientPageRequest;    // maps "request" values to 
                                                // functions returning strings

    static std::string s_activate;
    static std::string s_add;
    static std::string s_addActive;
    static std::string s_deactivate;
    static std::string s_erase;
    static std::string s_remove;
    static std::string s_update;
    

    // data below are saved to file

    uint32_t    d_time;             // registration time 
    uint16_t    d_ack;              // if != 0 then e-mail acknowledge
    uint16_t    d_nClients;         // # clients this psychologist
    uint16_t    d_ID;               // identification number
                                    
    std::string d_pwdHash;          // MD5 hash of the password (16 bytes)
        
        // encrypted section:
    uint64_t    d_nip;
    uint8_t     d_field;            // occupation field(s)
    std::string d_name; 
    std::string d_lastName;
    std::string d_email;

    std::vector<PsychClient> d_client;  // client info

    public:
        Psych(FBB::CGI &cgi);
        void process();

        void read(std::string const &data);
        std::string const &eMail() const;

    private:
        bool get();                     // get psych record
        std::string emailKey() const;   // get key from cgi.param1("email")

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
        void resultsDir(std::string const &pwd) const;
        void htpasswd(std::string const &pwd) const; // new htpasswd file

        void verifyAck();

        std::string messages();         // messages for this psychologist

        void profilePage();             // show profile page
        void profile();                 // update current profile
        bool validProfileData(uint8_t *field);


        void noPwd();

        void clientPage();                  // show the client page
        void displayClientPage(DisplayInfo const &displayInfo);

        void infoClient(std::string *clientArray, std::string *clientSelect);

        void selectTag(std::string *clientArray, std::string *clientSelect);
        size_t buildClientArray(string *array) const;
        void buildSelectTag(std::string *select, size_t idLength) const;
        void startSelect(std::ostream &out, size_t idLength) const;
        void endSelect(std::ostream &out) const;

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

        DisplayInfo activateClient();   // handles 3 by removing existing file
        DisplayInfo addClient();        // logs 5
        DisplayInfo addActivateClient();// logs 5
        DisplayInfo deactivateClient(); // logs 6 if no wip file
        DisplayInfo removeClient();
        DisplayInfo showClient();
        DisplayInfo updateClient();

        uint16_t validClientIdx();
        void pushClient();

        void rmExistingWIPdata(PsychClient const &client, 
                              char const *txt) const;

        uint32_t validClientData();         // throws false on failure
        void inviteClient(PsychClient &client);

//        std::vector<PsychClient>::iterator existingClient();

        std::string toString() const;
        static std::string fixedWidth(std::string const &txt, size_t length,
                                      Tools::Align align = Tools::LEFT);
        static std::string newPassword();

        std::vector<LockGuard> updateWIPemail() const;
};

inline std::string const &Psych::eMail() const
{
    return d_email;
}

#endif


