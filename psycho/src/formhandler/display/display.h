#ifndef INCLUDED_DISPLAY_
#define INCLUDED_DISPLAY_

#include <iostream>
#include <fstream>
#include <string>

class Display
{
    template <typename Type>
    friend Display &&operator<<(Display &&dest, Type &&arg);

    std::ifstream d_file;
    std::string d_line;

    static std::string s_base;      // set by FormHandler, calling setBase()

    public:
        Display(std::string const &name);
        ~Display();

        static void setBase(std::string const &base);

    private:
        void copy();                // copy the skeleton to cout
};

inline void Display::setBase(std::string const &base)
{
    s_base = base;
}

template <typename Type>
Display &&operator<<(Display &&dest, Type &&arg)
{
    std::cout << arg;
    dest.copy();
    return std::move(dest);
}
        
#endif
