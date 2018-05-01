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
    uint16_t d_ID = 0;              // internal client nr
    uint32_t d_active = 0;          // active since, or 0 if not active

    bool        d_gender = false;   // false: female, true: male

    std::string d_ident;            // id used by the psychologist for this
                                    // client
    std::string d_name;
    std::string d_lastName;
    std::string d_email;

    public:
        PsychClient() = default;        // for vectors etc.
        PsychClient(uint16_t ID, bool gender,
                    std::string const &ident,
                    std::string const &name, std::string const &lastName,
                    std::string const &email);

        std::string toString() const;  // includes encrypted person-data
        void get(std::string const &data);

        void activate();
        void deactivate();
        void update(std::string const &ident,
                    std::string const &name, std::string const &lastName,
                    std::string const &email);

        uint16_t ID() const;
        uint32_t active() const; 
        bool     gender() const;        
        char const *genderText() const;

        std::string const &ident() const;
        std::string const &name() const;
        std::string const &lastName() const;
        std::string const &email() const;
};

inline void PsychClient::activate()
{
    d_active = time(0);
}

inline void PsychClient::deactivate()
{
    d_active = 0;
}

inline uint16_t PsychClient:: ID() const
{
    return d_ID;
}
        
inline uint32_t PsychClient::active() const
{
    return d_active;
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
        
inline std::string const &PsychClient::ident() const
{
    return d_ident;
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
