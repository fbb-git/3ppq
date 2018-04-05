#include "options.ih"

Options::Options(std::string const &baseDir)
{
    char *cp = realpath(baseDir.c_str(), 0);
    d_base = cp;

    if (cp == 0)
        throw Exception{} << baseDir << ": does not exist";

    free(cp);

    if (d_base.back() != '/')
        d_base += '/';
    
    Stat info{d_base};

    if 
    (   
        not info.isType(Stat::DIRECTORY) 
        or 
            (info.mode() & (Stat::UR | Stat::UW | Stat::UX)) 
            !=
            (Stat::UR | Stat::UW | Stat::UX)
    )
        throw Exception{} << d_base << 
                ": not a directory or insufficient permissions";
}

