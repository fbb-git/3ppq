#ifndef INCLUDED_UNIQUENR_
#define INCLUDED_UNIQUENR_

#include <iosfwd>
#include <cstdint>

class UniqueNr
{
    static int s_lockFd;

    public:
        static uint16_t get(uint16_t first = 100, uint16_t last = 9999);
        static void rm(uint16_t nr);

    private:
        static bool acceptNr(std::istream &nrs, uint16_t nr);
};
        
#endif
