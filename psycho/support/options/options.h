#ifndef INCLUDED_OPTIONS_
#define INCLUDED_OPTIONS_

#include <string>

class Options
{
    std::string d_base;

    public:
        Options(std::string const &base);

        std::string log() const;
        std::string psychologists() const;
        std::string stubs() const;
};

inline std::string Options::log() const
{
    return d_base + "log";
}

inline std::string Options::psychologists() const
{
    return d_base + "data/psychologists";
}

inline std::string Options::stubs() const
{
    return d_base + "stubs/";
}

extern Options g_options;           // defined in main.cc

#endif
