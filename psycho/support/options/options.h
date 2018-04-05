#ifndef INCLUDED_OPTIONS_
#define INCLUDED_OPTIONS_

#include <string>

class Options
{
    std::string d_base;

    public:
        Options(std::string const &base);

        std::string log() const;
        std::string psych() const;
        std::string html() const;
};

inline std::string Options::log() const
{
    return d_base + "log";
}

inline std::string Options::psych() const
{
    return d_base + "data/psych";
}

inline std::string Options::html() const
{
    return d_base + "html/";
}

extern Options g_options;           // defined in main.cc

#endif
