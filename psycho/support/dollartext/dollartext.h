#ifndef INCLUDED_DOLLARTEXT_
#define INCLUDED_DOLLARTEXT_

#include "../types/types.h"

    // replace \$\d+ patterns by element \d+ of the StringVector d_str

class DollarText
{
    std::string const &d_path;
    StrVector const &d_strVector;
    public:
        DollarText(std::string const &path,
                   StrVector const &strVector);

        std::string text() const;

    private:
        std::string const &replaceDollars(std::string &line) const;
};
        
#endif
