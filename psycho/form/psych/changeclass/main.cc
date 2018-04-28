#include "main.ih"

Options g_options{ "./" };

Log  g_log{ g_options.log() };           // generic log facility

int main(int argc, char **argv)
{
//    if (argc == 1)
//    {
//        usage(argv[0]);
//        return;
//    }

    ifstream dataIdx{ "data/psych.idx" };
    DataStore dataStore{ "data/psych" };

    CGI cgi(false);
    Psych psych{ cgi };

    string data;

    for (size_t idx = 0, end = DataIdx::nEntries(dataIdx); idx != end; ++idx)
    {
        uint64_t offset = DataIdx::nextOffset(dataIdx);
        cerr << "Entry offset at " << offset << ", ";

        dataStore.get(&data, offset);
        cerr << "size = " << data.size() << '\n';

        psych.read(data);

        cerr << "e-mail: " << psych.eMail() << '\n';
    }
//    in.open();


//    size_t nr = 0;
//    string dest;
//    while (in.get(&dest))
//        ++nr;
//
//    cout << "read " << nr << " records\n";
}


