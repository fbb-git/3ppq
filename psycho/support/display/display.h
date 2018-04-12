#ifndef INCLUDED_DISPLAY_
#define INCLUDED_DISPLAY_

#include <string>

#include <bobcat/cgi>

#include "../types/types.h"
#include "../dollartext/dollartext.h"

class Display
{
    std::string d_path;

    DollarText d_dollarText;
    StrVector d_append;

    FBB::CGI *d_cgi = 0;
    
    public:
        Display() = default;
        Display(FBB::CGI &cgi);


        void append(char const *param);         // inl., d_cgi required.
        void append(char const *param, std::string const &value);

        void operator+=(std::string const &text);   // inline: 
                                                    // add replacement text

        void useReplacements(StrVector &src);       // inline, src is moved

        void out(std::string const &name);      // copy the skeleton to cout
                                                // (clears StrVector contents)
};

inline void Display::useReplacements(StrVector &src)
{
    d_dollarText.useReplacements(src);
}

inline void Display::append(char const *param)
{
    append(param, d_cgi->param1(param));
}

inline void Display::operator+=(std::string const &text)
{
    d_dollarText += text;
}

#endif
