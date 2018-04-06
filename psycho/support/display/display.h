#ifndef INCLUDED_DISPLAY_
#define INCLUDED_DISPLAY_

#include <iostream>
//#include <fstream>
#include <string>

#include "../types/types.h"

class Display
{
    std::string d_path;
    StrVector const *d_dollarVars = 0;
    StrVector const *d_append = 0;

    public:
        Display(std::string const &name, StrVector const *dollarVars = 0);

                                                // usually hidden fields
        Display(StrVector const &append,        // passing hidden params
                std::string const &name, StrVector const *sv = 0);

        ~Display();

    private:
        void copy();                    // copy the skeleton to cout
};

#endif
