#include "lfstream.ih"

void Lfstream::open(std::string const &path)
{
    d_path = path;

    close();
    fstream::open(path, ios::in | ios::out);
    if (not good())
        Exception::open(static_cast<fstream &>(*this), path, 
                        ios::in | ios::out | ios::trunc);

    d_fd = ::open(path.c_str(), O_RDWR, 0600);

    if (d_fd == -1)
        throw Exception{} << "Can't lock " << path;
}
