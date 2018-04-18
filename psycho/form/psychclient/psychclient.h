#ifndef INCLUDED_PSYCHCLIENT_
#define INCLUDED_PSYCHCLIENT_

#include <cstdint>
#include <string>
#include <vector>

namespace FBB
{
    class CGI;
};

class PsychClient
{
    uint16_t d_ID = 0;      // client nr
    uint32_t d_activeTime;  // active since, or 0 if not active
    uint8_t  d_login0;      // login nr passed by Psych to Client

    bool        d_gender = 0;   // 0: female, 1: male
    std::string d_name;
    std::string d_lastName;
    std::string d_email;

    public:
        // PASSIVE!
        bool set(uint16_t psychID, uiint16_t ID, uint8_t login0, 
                 FBB::CGI &cgi);

        std::string toString() const;  // includes encrypted person-data
        void get(std::string const &data);

        uint16_t id() const
        uint32_t activeTime() const; 
        uint8_t  login0 const;
        
        char const *genterText() const;

        std::string name() const;
        std::string lastName() const;
        std::string email() const;

    private:
};

inline uint16_t PsychClient:: id() const
{
    return d_ID;
}
        
inline uint32_t PsychClient::activeTime() const
{
    return d_activeTime;
}
        
inline uint8_t PsychClient::login0() const
{
    return d_login0;
}
        
inline char const *PsychClient::genderText() const
{
    return d_gender == 0 ? "mevrouw" : "heer";
}
        
inline std::string const &PsychClient::name() const
{
    return d_name;
}
        
inline std::string const &PsychClient::lastName() const
{
    return d_lastName;
}
        
inline std::string const &PsychClient::email() const
{
    return d_email;
}
        
#endif
