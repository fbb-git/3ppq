#ifndef INCLUDED_PSYCHCLIENT_
#define INCLUDED_PSYCHCLIENT_

#include <ctime>
#include <cstdint>
#include <string>
#include <vector>

namespace FBB
{
    class CGI;
};

class PsychClient
{
    uint16_t d_ID = 0;              // client nr
    uint32_t d_active = 0;      // active since, or 0 if not active
    uint8_t  d_login0 = 0;          // login nr passed by Psych to Client

    bool        d_gender = false;   // false: female, true: male
    std::string d_name;
    std::string d_lastName;
    std::string d_email;

    public:
        PsychClient() = default;        // for vectors etc.
        PsychClient(uint16_t ID, uint32_t active, uint8_t login0, bool gender,
                    std::string const &name, std::string const &lastName,
                    std::string const &email);

//        // PASSIVE!
//        bool set(uint16_t psychID, uiint16_t ID, uint8_t login0, 
//                 FBB::CGI &cgi);

        std::string toString() const;  // includes encrypted person-data
        void get(std::string const &data);

        void activate();
        void update(std::string const &name, std::string const &lastName,
                    std::string const &email);

        uint16_t id() const;
        uint32_t active() const; 
        uint16_t login0() const;        // uint8_t is a character!!
        bool     gender() const;        
        char const *genderText() const;

        std::string const &name() const;
        std::string const &lastName() const;
        std::string const &email() const;

    private:
};

inline void PsychClient::activate()
{
    d_active = time(0);
}

inline uint16_t PsychClient:: id() const
{
    return d_ID;
}
        
inline uint32_t PsychClient::active() const
{
    return d_active;
}
        
inline uint16_t PsychClient::login0() const
{
    return d_login0;
}
        
inline bool PsychClient::gender() const
{
    return d_gender;
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
