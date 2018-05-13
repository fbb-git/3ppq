#ifndef INCLUDED_FILTERSTREAMBUF_
#define INCLUDED_FILTERSTREAMBUF_

#include <string>
#include <iosfwd>

#include <bobcat/ifilterstreambuf>

class FilterStreambuf: public FBB::IFilterStreambuf
{
    std::string d_ID;
    std::istream &d_in;


    std::string d_buffer;
    bool (FilterStreambuf::*d_filter)
                (char const **srcBegin, char const **srcEnd) override;

    public:
        FilterStreambuf(std::istream &in, uint16_t ID);

    private:
        bool filter(char const **srcBegin, char const **srcEnd) override;
        bool contentType(char const **srcBegin, char const **srcEnd);
        bool trailer(char const **srcBegin, char const **srcEnd);

};

#endif


