#include "lockstream.ih"

LockGuard LockStream::lg() const
{
    return {d_path, d_lockFd};      // .lck exists, d_path: maybe exists
}
