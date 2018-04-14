#ifndef INCLUDED_DISPLAY_
#define INCLUDED_DISPLAY_

#include <string>
#include <initializer_list>

#include <bobcat/cgi>

#include "../types/types.h"
#include "../dollartext/dollartext.h"

class Display
{
    FBB::CGI *d_cgi = 0;

    StrVector d_append;   

    public:
        Display() = default;
        Display(FBB::CGI &cgi);

        void append(char const *param);         // inl.  d_cgi required.
        void append(std::initializer_list<char const *> params);    // 1

        void append(char const *param, std::string const &value);   // 2

        void out(std::string const &name);      // copy the skeleton to cout

        void out(std::string const &name,       // copy the skeleton to cout
                 StrVector const &elements);    // $-replacement elements

    private:
        void end();
        static void state(std::string const &path);
};

inline void Display::append(char const *param)
{
    append(param, d_cgi->param1(param));
}

#endif
