#include "lockstream.ih"

#include <string>
#include <iostream>

void LockStream::open()
{
    if (is_open())
        return;

    fstream::open(d_path, ios::in | ios::out);

    if (not Tools::exists(d_path))
        Exception::open(
            static_cast<fstream &>(*this), 
            d_path, ios::in | ios::trunc | ios::out);
}
