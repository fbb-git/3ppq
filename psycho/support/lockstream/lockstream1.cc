#include "lockstream.ih"

LockStream::LockStream(string const &path)
:
    d_path(path),
    d_lockFd(creat((d_path + ".lck").c_str(), 0660))
{
    if (d_lockFd == -1)
        throw Exception{} << "can't use " << d_path << ".lck";
    
}
