#ifndef INCLUDED_CLIENT_
#define INCLUDED_CLIENT_

#include <iosfwd>
#include <unordered_map>

#include "../../support/display/display.h"

namespace FBB
{
    class CGI;
};

class WIPdata;

class Client
{
    enum RatingType
    {
        SELF,
        META,
        OTHER           // + idx
    };

    typedef std::unordered_map<std::string, void (Client::*)()> Map;
    typedef void (Client::*CompletedHandler)(WIPdata &, std::string const &);

    FBB::CGI &d_cgi;
    Display d_display;

    static Map s_state;             // maps state names to handling functions

    static CompletedHandler s_completed[];
    static size_t const s_completedSize;
    static char const *s_hisHer[2];
    static char const *s_himHer[2];
    static char const *s_heShe[2];

    static char const s_closeSelf[];
    static char const s_closeMeta[];
    static char const s_closeOther[];
    static char const s_selfThanks[];
    static char const s_otherThanks[];


    public:
    Client(FBB::CGI &cgi);

        void process();
        void accept(std::string const &query);

    private:
        void testing();          // for testing purposes only

        void answered();

        void clientPage(WIPdata &wipData);  // show self, meta ratings, email
                                            // request. 

                                            // self/meta-ratings instructions
        void selfRatings(WIPdata &wipData, RatingType type, 
                         char const *file, 
                         char const *opening, char const *closing); 

        void emailRequest(WIPdata const &wipData);

                                            // show other page
        void otherPage(WIPdata &wipData, size_t idx);

        void pidCid(WIPdata const &wipData);
        void inviteOther(WIPdata const &wipData, size_t idx);
        void storeEmail();

        std::string loginHash(uint16_t login) const;

        void selfCompleted(WIPdata &wipData, std::string const &ratings);
        void metaCompleted(WIPdata &wipData, std::string const &ratings);

        void otherCompleted(WIPdata &wipData, std::string const &ratings);
        bool otherRatingsCompleted(WIPdata &wipData) const;
        void checkCompleted(WIPdata &wipData) const;

        static std::string nQuestions();
};
        
#endif
