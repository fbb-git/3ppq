#include "mail.ih"

void Mail::clientFields(string const &line)
try
{
    auto vect = String::split(line, ",");

    d_client.reserve(Fields::size);

    if (d_client.size() !=  Fields::size)
        throw Exception{} << "number of fields must be " << Fields::size;

    d_client[CLIENT] = move(vect[CLIENT].first);
    
    d_client[GENDER] = String::lc(vect[GENDER].first).substr(0, 1);

    if ("mv"s.find(d_client[GENDER]) == string::npos)
        throw Exception{} << "gender specification must be M or F";

    if (
        (d_client[E_MAIL] = vect[E_MAIL].first).find('@') == string::npos
        ||
        (d_client[ASS1_MAIL] = vect[ASS1_MAIL].first).find('@') 
                                                            == string::npos
        ||
        (d_client[ASS2_MAIL] = vect[ASS2_MAIL].first).find('@') 
                                                            == string::npos
        ||
        (d_client[ASS3_MAIL] = vect[ASS3_MAIL].first).find('@') 
                                                            == string::npos
    )
        throw Exception{} << "e-mail addresses must contain @ characters";

    d_client[ASS1] = vect[ASS1].first;
    d_client[ASS2] = vect[ASS2].first;
    d_client[ASS3] = vect[ASS3].first;

    uniquePreID(vect[PRE_ID].first);
}
catch (exception const &exc)
{
    mailError("In client specification `"s + line + "': "s + exc.what());
}
