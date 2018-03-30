#include "psychologist.ih"

Psychologist::Map Psychologist::s_state =
{
    {"register",    &Psychologist::newPsych} ,
    {"add",         &Psychologist::newPsych} ,
};

