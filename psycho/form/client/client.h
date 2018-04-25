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

    FBB::CGI &d_cgi;
    Display d_display;

    static Map s_state;             // maps state names to handling functions

    public:
        Client(FBB::CGI &cgi);
        void process();

        bool accept(std::string const &query);

    private:
        bool clientPage(WIPdata &wipData);
        bool otherPage(WIPdata &wipData, size_t idx);

        bool selfRatings(WIPdata &wipData);
        void metaRatings(WIPdata &wipData);
        void trySaveData();

        void selfInstructions(WIPdata const &wipData);

        void pidCid(WIPdata const &wipData);
        void inviteOther(std::string const &otherMail);
        void storeEmail();

        std::string loginHash(uint16_t login) const;
        void checkCompleted(WIPdata const &wipData) const;
        bool otherRatingsCompleted(WIPdata const &wipData) const;

//////////////////////////////////////////////////////////////////////////
//        void verify();
//        void quest();           // question 0: 1st question, no back
                                // last q.: no next, but finish
};
        
#endif
