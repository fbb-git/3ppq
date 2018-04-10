#ifndef INCLUDED_PSYCHENCRYPTED_
#define INCLUDED_PSYCHENCRYPTED_

#include <string>

class PsychEncrypted
{
    uint64_t    d_nip;
    std::string d_name; 
    std::string d_lastName;
    std::string d_email;
    bool        d_gender;       // 0: female, 1: male

    public:
        PsychEncrypted();

        void get(std::string const &iv, std::string const &data);

        char const *genderText() const;
        std::string const &lastName() const;
        std::string const &name() const;
        std::string const &email() const;

    private:
};
        
inline char const *PsychEncrypted::genderText() const
{
    return d_gender == 0 ? "mevrouw" : "heer";
}

inline std::string const &PsychEncrypted::lastName() const
{
    return d_lastName;
}

inline std::string const &PsychEncrypted::name() const
{
    return d_name;
}

inline std::string const &PsychEncrypted::email() const
{
    return d_email;
}

#endif
