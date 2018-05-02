#include "datafiles.ih"

void DataFiles::gnuplot(char const *path) const
{
    ofstream out;
    Exception::open(out, path);

    for (
        size_t perspective = 0; 
            perspective != Values::N_PERSPECTIVES;
                ++perspective
    )
    {
        for (
            size_t factor = 0, end = Values::N_FACTORS - 1; 
                factor != end; 
                    ++factor
        )
            out << (factor + 1) << ' ' << 
                    d_fscores[factor][perspective] << '\n';

        out << "\n\n";
    }
    out.flush();
}
