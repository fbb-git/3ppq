#ifndef INCLUDED_PSYCHCLIENT_
#define INCLUDED_PSYCHCLIENT_

#include <cstdint>
#include <string>

class PsychClient
{
    uint16_t d_nr = 0;
    uint16_t d_nCompleted = 0;  // #completed data sets for this client

    bool        d_gender = 0;   // 0: female, 1: male
    std::string d_name;
    std::string d_lastName;
    std::string d_email;
    
    static uint16_t s_nr;

    public:
        PsychClient();

        std::string toString() const;  // includes encrypted person-data
        void get(std::string const &data);

    private:
};
        
#endif
