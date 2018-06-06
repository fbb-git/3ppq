#include "records.ih"

void Records::removeExistingNew() const
{
    remove(d_arg[1]);
    remove(d_arg[1] + ".idx"s);
}
