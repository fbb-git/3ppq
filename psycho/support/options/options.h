#ifndef INCLUDED_OPTIONS_
#define INCLUDED_OPTIONS_

#include <string>

class Options
{
    std::string d_base;
    std::string d_psychEmail;

    public:
        Options(std::string const &base);

        std::string binDir() const;                 // ends in '/'
        std::string config() const;
        std::string data() const;
        std::string dataDir() const;                // ends in '/'
        std::string tmpDir() const;                 // ends in '/'
        std::string html() const;
        std::string log() const;
        std::string mail() const;
        std::string nrs() const;
        std::string psych() const;
        std::string latexMold() const;
        std::string gnuplotMold() const;
        std::string questions() const;
};

inline std::string Options::binDir() const
{
    return dataDir() + "bin/";
}

inline std::string Options::tmpDir() const
{
    return dataDir() + "tmp/";
}

inline std::string Options::data() const
{
    return dataDir() + "data.csv";
}

inline std::string Options::config() const
{
    return d_base + "etc/3ppq_config";
}

inline std::string Options::nrs() const
{
    return d_base + "data/nrs.bin";
}

inline std::string Options::dataDir() const
{
    return d_base + "data/";
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

inline std::string Options::gnuplotMold() const
{
    return d_base + "mold/gnuplot";
}

inline std::string Options::latexMold() const
{
    return d_base + "mold/latex";
}

extern Options g_options;           // defined in main.cc

#endif
