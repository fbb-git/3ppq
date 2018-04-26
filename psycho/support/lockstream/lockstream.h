#ifndef INCLUDED_LOCKSTREAM_
#define INCLUDED_LOCKSTREAM_

#include <fstream>

class LockGuard;
                                    // creates the .lck file, but does not
                                    // lock. To lock, call lg()
class LockStream: public std::fstream       
{
    std::string d_path;             // lockpath is d_path + ".lck"
    int d_lockFd = -1;

    public:
        LockStream() = default;

        LockStream(std::string const &path);

        void open();
        std::string const &path() const;

        LockGuard lg() const;
    private:
};

inline std::string const &LockStream::path() const
{
    return d_path;
}
        
#endif
