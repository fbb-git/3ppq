#ifndef INCLUDED_DOLLARTEXT_
#define INCLUDED_DOLLARTEXT_

#include "../types/types.h"

    // replace \$\d+ patterns by element \d+ of the StringVector d_str

struct DollarText
{
    static std::string replaceStream( 
                            std::string const &path,
                            StrVector const &elements
                        );


    static std::string const &replaceLine(
                                    std::string &line,
                                    StrVector const &elements
                            );
};

#endif
