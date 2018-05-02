#ifndef INCLUDED_DOLLARTEXT_
#define INCLUDED_DOLLARTEXT_

#include "../types/types.h"

    // replace \$\d+ patterns by element \d+ of the StringVector d_str

struct DollarText
{
    static std::string replaceStream(                   // contents in return-
                            std::string const &path,    //              value
                            StrVector const &elements
                        );


    static void replace(                                // contents to 'out'
                            std::ostream &out, std::string const &inPath,
                            StrVector const &elements
                        );


    static std::string const &replaceLine(              // one single line.
                                    std::string &line,
                                    StrVector const &elements
                            );
};

#endif
