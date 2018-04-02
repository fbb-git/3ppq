#include "psychologist.ih"

bool Psychologist::readFields(istream &in)
{
    string field;

    while (getline(in, field) && field != "=")
        d_fields.push_back(field);

    return fields == '=' && d_fields.size() 
    return true;
}


