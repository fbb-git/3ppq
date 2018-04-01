#include "psychologist.ih"

uint16_t Psychologist::identNr() const
{
    Lftream nrs{ d_filename + ".nrs");      // binary uint16_t file

    nrs.lock();
    uint16_t idNr;
    do                                      // generate new random id
    {
        idNr = Tools::random(9899) + 100;  // range 100 .. 9999
    }
    while (not acceptNr(nrs, idNr));

    nrs.seekp(0, ios::end);                 // go to the file's end
    Tools::write(nrs, idNr);                // write the next value

    nrs.unlock();

    return idNr;                            // return next ID nr
}


