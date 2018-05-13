#ifndef INCLUDED_DATAFILTERSTREAMBUF_
#define INCLUDED_DATAFILTERSTREAMBUF_

#include <string>
#include <iosfwd>

#include <bobcat/ifilterstreambuf>

class DataFilterStreambuf: public FBB::IFilterStreambuf
{
    std::string d_ID;
    std::istream &d_in;


    std::string d_buffer;
    bool d_csvData = false;
//    bool filter(char const **srcBegin, char const **srcEnd) override;

    public:
        DataFilterStreambuf(std::istream &in, uint16_t ID);
        bool csvData() const;

    private:
        bool filter(char const **srcBegin, char const **srcEnd) override;

};

inline bool DataFilterStreambuf::csvData() const
{
    return d_csvData;
}
        
#endif
