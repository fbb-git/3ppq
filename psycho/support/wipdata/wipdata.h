#ifndef INCLUDED_WIPDATA_
#define INCLUDED_WIPDATA_

#include <iosfwd>
#include <cstdint>
#include <string>

#include "../options/options.h"
#include "../tools/tools.h"
#include "../lockstream/lockstream.h"

class WIPdata
{
    friend std::ostream &operator<<(std::ostream &out, WIPdata const &data);

    uint16_t    d_psychID = 0;
    std::string d_clientIdent;
    bool        d_gender;               // false: female, true: male;
    std::string d_clientName;           // client's first name
    std::string d_clientLastName;       // client's last name

    uint32_t d_start = 0;               // starting time

    uint16_t d_clientLogin = 0;
    uint16_t d_otherLogin[Tools::N_OTHER];

    std::string d_selfRatings;
    std::string d_metaRatings;
    std::string d_otherRatings[Tools::N_OTHER];

    std::string d_psychEmail;
    std::string d_otherEmail[Tools::N_OTHER];

    mutable LockStream d_io;

    public:
        WIPdata(std::string const &psychEmail,          // new WIPdata
                uint16_t psychID, std::string const &clientIdent, 
                std::string const &clientName, 
                std::string const &clientLastName, bool gender);
        WIPdata(std::string const &query);              // update WIPdata
        WIPdata(std::string const &pid, std::string const &cid); // same

        WIPdata(char const *csvFile, char const *psychEmail,    // mainly for
                bool gender, char const *clientName);           // testing
        WIPdata() = default;

        uint16_t psychID() const;
        std::string const &clientIdent() const;
        bool gender() const;                            // false: F, true: M
        std::string const &clientName() const;
        std::string const &clientLastName() const;

        uint16_t clientLogin() const;
        uint16_t otherLogin(size_t idx) const;

        std::string const &psychEmail() const;
        void setPsychEmail(std::string const &email);

        std::string const &otherEmail(size_t idx) const;
        void setOtherEmail(size_t idx, std::string const &mail);

        std::string const &selfRatings() const;
        std::string const &metaRatings() const;
        std::string const &otherRatings(size_t idx) const;

        void rmClientLogin();
        void rmOtherLogin(size_t idx);

        void setSelfRatings(std::string const &ratings);
        void setMetaRatings(std::string const &ratings);
        void setOtherRatings(size_t idx, std::string const &ratings);

        bool hasEmail() const;          // email addresses available

        LockGuard read();
        void read(char const *path);        // for testing purposes only

        void write() const;

        void remove();                      

        std::string path() const;
        std::string pidCid() const;

        uint32_t startTime() const;

        static bool exists(uint16_t pid, std::string const &cid);
        static void remove(uint16_t pid, std::string const &cid);     // 2.cc

        void read(std::istream &in);            // for testing purposes only
        void write(std::ostream &out) const;

    private:
        void assign(std::string &dest, std::vector<double> const &src);
        std::ostream &insert(std::ostream &out) const;
        void insertRatings(std::ostream &out, int type, size_t endTime,
                           std::string const &ratings) const;

        static void cleanup(std::string &dest, std::string const &ratings);
        static std::string pidCid(uint16_t pid, std::string const &cid);
        static std::string path(uint16_t pid, std::string const &cid);
};

inline std::string WIPdata::path() const
{
    return path(d_psychID, d_clientIdent);
}

inline std::string WIPdata::pidCid() const
{
    return pidCid(d_psychID, d_clientIdent);
}

inline uint16_t WIPdata::psychID() const
{
    return d_psychID;
}

inline std::string const &WIPdata::clientIdent() const
{
    return d_clientIdent;
}

inline bool WIPdata::gender() const
{
    return d_gender;
}

inline uint16_t WIPdata::clientLogin() const
{
    return d_clientLogin;
}

inline uint16_t WIPdata::otherLogin(size_t idx) const
{
    return d_otherLogin[idx];
}

inline uint32_t WIPdata::startTime() const
{
    return d_start;
}

inline std::string const &WIPdata::psychEmail() const
{
    return d_psychEmail;
}

inline void WIPdata::setPsychEmail(std::string const &email)
{
    d_psychEmail = email;
}

inline std::string const &WIPdata::clientName() const
{
    return d_clientName;
}

inline std::string const &WIPdata::clientLastName() const
{
    return d_clientLastName;
}

inline std::string const &WIPdata::otherEmail(size_t idx) const
{
    return d_otherEmail[idx];
}

inline void WIPdata::setOtherEmail(size_t idx, std::string const &mail)
{
    d_otherEmail[idx] = mail;
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

inline void WIPdata::rmClientLogin()
{
    d_clientLogin = 0;
}

inline void WIPdata::setSelfRatings(std::string const &ratings)
{
    cleanup(d_selfRatings, ratings);
}

inline void WIPdata::setMetaRatings(std::string const &ratings)
{
    cleanup(d_metaRatings, ratings);
}

inline void WIPdata::setOtherRatings(size_t idx, std::string const &ratings)
{
    cleanup(d_otherRatings[idx], ratings);
}

//static
inline bool WIPdata::exists(uint16_t pid, std::string const &cid)
{
    return Tools::rwExists(path(pid, cid));
}

//static
inline std::string WIPdata::path(uint16_t pid, std::string const &cid)
{
    return g_options.dataDir() + pidCid(pid, cid);
}

//static
inline std::string WIPdata::pidCid(uint16_t pid, std::string const &cid)
{
    return to_string(pid) + '.' + cid;
}

inline std::ostream &operator<<(std::ostream &out, WIPdata const &data)
{
    return data.insert(out);
}
    
#endif



