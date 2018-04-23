#ifndef INCLUDED_WIPDATA_
#define INCLUDED_WIPDATA_

#include <iosfwd>
#include <cstdint>
#include <string>

#include "../tools/tools.h"

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

    public:
        enum Type
        {
            INIT,
            UPDATE
        };

        WIPdata(uint16_t psychID, uint16_t clientID, Type type);

        uint16_t clientLogin() const;
        uint16_t otherLogin(size_t idx) const;
        
        std::string const &otherMail(size_t idx) const;

    private:
        void read(std::istream &in);
        void write(std::ostream &out) const;
        std::string path() const;
};

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

#endif
