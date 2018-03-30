#include "psychologist.ih"

bool Psychologist::readRecord(istream &in)
{
    g_log << "readRecord" << endl;

    getline(in, d_record.name);
    g_log << "readRecord 2" << endl;

    getline(in, d_record.email);
    g_log << "readRecord 3" << endl;

    getline(in, d_record.nip);
    g_log << "readRecord 4" << endl;

    getline(in, d_record.passwd);
    g_log << "readRecord 5" << endl;

    string gender;
    if (not getline(in, gender))
    {
        g_log << "readRecord false" << endl;
        return false;
    }

    d_record.gender = gender == "M";

        g_log << "readRecord true" << endl;
    return true;
}


