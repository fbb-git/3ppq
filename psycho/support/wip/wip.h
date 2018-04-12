#ifndef INCLUDED_WIP_
#define INCLUDED_WIP_

#include <string>
#include <string>

#include "../lockstream/lockstream.h"
#include "../tools/tools.h"

class WIP
{
    LockStream d_wipStream;

    uint16_t d_psychID;
    uint16_t d_clientID;
                                // 0: login0, 1: self, 2: meta, 3-5: other
    uint8_t d_login[Tools::N_OTHER + 2];
    std::string d_email[Tools::N_OTHER];

    public:
        WIP();
        void add(uint16_t psychID, uint16_t clientID, uint8_t login0);

        string toString() const;

    private:
};
        
#endif
