#ifndef INCLUDED_WIPDATA_
#define INCLUDED_WIPDATA_

#include <iosfwd>
#include <cstdint>
#include <string>

class WIPdata
{
    uint16_t d_psychID;
    uint16_t d_clientID;

    uint32_t d_start;                   // starting time

    struct CompletedFlags
    {
        int self:   1;
        int meta:   1;
        int other1: 1;
        int other2: 1;
        int other3: 1;
    };

    CompletedFlags d_flags = {0};     

    uint16_t d_login0;
    uint16_t d_loginClient;
    uint16_t d_loginOther1;
    uint16_t d_loginOther2;
    uint16_t d_loginOther3;

    std::string d_other1;
    std::string d_other2;
    std::string d_other3;

    public:
        WIPdata(uint16_t psychID, uint16_t clientID, uint16_t login0);

        uint16_t login0() const;
        uint16_t loginClient() const;
        uint16_t loginOther1() const;
        uint16_t loginOther2() const;
        uint16_t loginOther3() const;
        
        std::string const &mailOther1() const;
        std::string const &mailOther2() const;
        std::string const &mailOther3() const;

        void write(std::ostream &out) const;
        void read(std::istream &in);
    private:
};

inline uint16_t WIPdata::login0() const
{
    return d_login0;
}

inline uint16_t WIPdata::loginClient() const
{
    return d_loginClient;
}

inline uint16_t WIPdata::loginOther1() const
{
    return d_loginOther1;
}

inline uint16_t WIPdata::loginOther2() const
{
    return d_loginOther2;
}

inline uint16_t WIPdata::loginOther3() const
{
    return d_loginOther3;
}

inline std::string const &WIPdata::mailOther1() const
{
    return d_other1;
}

inline std::string const &WIPdata::mailOther2() const
{
    return d_other2;
}

inline std::string const &WIPdata::mailOther3() const
{
    return d_other3;
}


#endif
