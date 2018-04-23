#include "lockguard.ih"

//static 
void LockGuard::remove(string const &path)
{
    unlink(path.c_str());
    unlink( string{ path + ".lck" }.c_str() );
}
