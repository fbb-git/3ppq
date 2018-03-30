#ifndef INCLUDED_LFSTREAM_
#define INCLUDED_LFSTREAM_

#include <fstream>
#include <string>

#include "../tools/tools.h"

class Lfstream: public std::fstream
{
    int d_fd;
    std::string d_path;

    public:
        Lfstream() = default;
        Lfstream(std::string const &path);

        ~Lfstream();

        void open(std::string const &path);

        void lock() const;
        void unlock();
        
    private:
};
        
inline void Lfstream::lock() const
{
    Tools::lock(d_fd, d_path);
}

inline void Lfstream::unlock()
{
    Tools::unlock(d_fd);
}
#endif
