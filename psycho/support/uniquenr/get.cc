#include "uniquenr.ih"

// static
uint16_t UniqueNr::get(uint16_t first, uint16_t last)
{
    last -= first;

    LockStream nrs{ g_options.nrs() };
    nrs.open();

    LockGuard lg{ nrs.lg() };

    uint16_t nr;
    do                                      // generate new random id
    {
        nr = Tools::random(last) + first;   // range first .. last
    }
    while (not acceptNr(nrs, nr));

    nrs.seekp(0, ios::end);                 // go to the file's end
    Tools::write(nrs, &nr);               // write the next value

    return nr;                            // return next ID nr
}
