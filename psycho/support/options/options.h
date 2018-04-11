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
        std::string mail() const;
        std::string questions() const;
        std::string nrs() const;
        std::string config() const;
};

inline std::string Options::config() const
{
    return d_base + "etc/3ppq_config";
}

inline std::string Options::nrs() const
{
    return d_base + "data/nrs.bin";
}

inline std::string Options::questions() const
{
    return d_base + "questions/questions.txt";
}

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

inline std::string Options::mail() const
{
    return d_base + "mail/";
}

extern Options g_options;           // defined in main.cc

#endif
