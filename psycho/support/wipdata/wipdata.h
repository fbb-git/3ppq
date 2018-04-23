#ifndef INCLUDED_WIPDATA_
#define INCLUDED_WIPDATA_

#include <iosfwd>
#include <cstdint>
#include <string>

#include "../tools/tools.h"
#include "../lockstream/lockstream.h"

class WIPdata
{
    uint16_t d_psychID = 0;
    uint16_t d_clientID = 0;

    uint32_t d_start = 0;               // starting time

    uint16_t d_clientLogin = 0;
    uint16_t d_otherLogin[Tools::N_OTHER];

    std::string d_selfRatings;
    std::string d_metaRatings;
    std::string d_otherRatings[Tools::N_OTHER];

    std::string d_otherMail[Tools::N_OTHER];

    mutable LockStream d_io;

    public:
        WIPdata(uint16_t psychID, uint16_t clientID);   // new WIPdata
        WIPdata(std::string const &query);              // update WIPdata
        WIPdata(std::string const &pid, std::string const &cid); // same

        uint16_t psychID() const;
        uint16_t clientID() const;

        uint16_t clientLogin() const;
        uint16_t otherLogin(size_t idx) const;
        
        std::string const &otherMail(size_t idx) const;
        void setOtherMail(size_t idx, std::string const &mail);

        std::string const &selfRatings() const;
        std::string const &metaRatings() const;
        std::string const &otherRatings(size_t idx) const;

        LockGuard read();
        void write() const;

    private:
        void read(std::istream &in);
        std::string path() const;
};

inline uint16_t WIPdata::psychID() const
{
    return d_psychID;
}

inline uint16_t WIPdata::clientID() const
{
    return d_clientID;
}

inline uint16_t WIPdata::clientLogin() const
{
    return d_clientLogin;
}

inline uint16_t WIPdata::otherLogin(size_t idx) const
{
    return d_otherLogin[idx];
}
inline std::string const &WIPdata::otherMail(size_t idx) const
{
    return d_otherMail[idx];
}

inline void WIPdata::setOtherMail(size_t idx, std::string const &mail)
{
    d_otherMail[idx] = mail;
}

inline std::string const &WIPdata::selfRatings() const
{
    return d_selfRatings;
}
    
inline std::string const &WIPdata::metaRatings() const
{
    return d_metaRatings;
}
    
inline std::string const &WIPdata::otherRatings(size_t idx) const
{
    return d_otherRatings[idx];
}
    
#endif
