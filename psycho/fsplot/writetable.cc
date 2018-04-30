#include "main.ih"

void writeTable(char const *path, Fscores::Dvector2 const &scores)
{
    ofstream out;
    Exception::open(out, path);

cout << "writing " << path << endl;

                                                // show decimal point + 
                                                // trailing zeroes
    out.setf(ios::fixed, ios::floatfield | ios::showpoint);

    out.precision(2);                           // 2 digits behind the .

    for (size_t factor = 0; factor != Values::N_FACTORS; ++factor)
    {
        size_t col = 0;
        for (; col != Values::N_PERSPECTIVES; ++col)
            out << setw(7) << scores[factor][col]; 

        out << showpos;

        for (; col != Values::REPORT_COLUMNS; ++col)
            out << setw(7) << scores[factor][col]; 

        out << noshowpos << '\n';
    }
}
