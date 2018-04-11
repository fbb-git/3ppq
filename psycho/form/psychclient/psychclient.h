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
    uint16_t d_nr = 0;      // client nr
    bool     d_wip = false; // currently no WIP record

    bool        d_gender = 0;   // 0: female, 1: male
    std::string d_name;
    std::string d_lastName;
    std::string d_email;

    char d_data[Tools::N_OTHER + 2][Tools::N_ITEMS];

    static uint16_t s_nr;

    public:
        bool set(FBB::CGI &cgi);

        std::string toString() const;  // includes encrypted person-data
        void get(std::string const &data);

    private:
};
        
#endif
