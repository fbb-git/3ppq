#ifndef INCLUDED_RECORDS_
#define INCLUDED_RECORDS_

#include <string>

#include "../../support/tools/tools.h"
#include "../../support/dataidx/dataidx.h"

namespace FBB
{
    class Arg;
}

class Records
{
    FBB::Arg &d_arg;
    std::string d_data;
    DataIdx d_dataIdx;

    enum { SHIFT = Tools::KEY_SIZE + sizeof(uint64_t) } ;

    public:
        Records();
        void process();

    private:
        void expired() const;
        void list() const;
        void modify() const;
        void remove() const;

        void removeExistingNew() const;
        static void remove(std::string const &path);
};
        
#endif
