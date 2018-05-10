#ifndef INCLUDED_OPTIONS_
#define INCLUDED_OPTIONS_

#include <string>

class Options
{
    std::string d_base;
    std::string d_psychEmail;

    public:
        Options(std::string const &base);

        std::string baseDir() const;          // all Dir-entries end in '/'
        std::string binDir() const;     
        std::string dataDir() const;    
        std::string tmpDir() const;     
        std::string imagesDir() const;  
        std::string reportsDir() const; 
        std::string moldsDir() const;   
        std::string mailDir() const;    
        std::string htmlDir() const;    

        std::string config() const;
        std::string data() const;
        std::string log() const;
        std::string nrs() const;
        std::string psych() const;
        std::string questions() const;
};

inline std::string Options::baseDir() const
{
    return d_base;
}

inline std::string Options::binDir() const
{
    return d_base + "bin/";
}

inline std::string Options::reportsDir() const
{
    return d_base + "reports/";
}

inline std::string Options::tmpDir() const
{
    return d_base + "tmp/";
}

inline std::string Options::dataDir() const
{
    return d_base + "data/";
}

inline std::string Options::moldsDir() const
{
    return d_base + "molds/";
}

inline std::string Options::imagesDir() const
{
    return d_base + "images/";
}

inline std::string Options::htmlDir() const
{
    return d_base + "html/";
}

inline std::string Options::mailDir() const
{
    return d_base + "mail/";
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

extern Options g_options;           // defined in main.cc

#endif
