#include "datafiles.ih"

void DataFiles::scoresTable(char const *path) const
{
    ofstream out;
    Exception::open(out, path);
                                                // show decimal point + 
                                                // trailing zeroes
    out.setf(ios::fixed, ios::floatfield | ios::showpoint);

    out.precision(2);                           // 2 digits behind the .

    StrVector label {
                        "Extraversie",
                        "Mildheid",
                        "Ordelijkheid",
                        "Emotionele Stabiliteit",
                        "Automomie",
                        "Algemene Factor",
                    };

    for (size_t factor = 0; factor != Tools::N_FACTORS; ++factor)
    {
        out <<
            "    \\makecell[l]{" << label[factor] << '}';

        size_t col = 0;
        for (; col != Tools::N_PERSPECTIVES; ++col)
            out <<  " &\n"
                    "    \\makecell[r]{" << d_fscores[factor][col] << '}';

        out << " &\n"
               "    \\makecell[l]{}";

        out << showpos;

        for (; col != Tools::REPORT_COLUMNS; ++col)
            out <<  " &\n"
                    "    \\makecell[r]{" << d_fscores[factor][col] << '}';

        out << noshowpos << "\n\\\\\n";
    }
}


