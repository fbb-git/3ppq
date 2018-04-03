#include "psychologist.ih"

Psychologist::Map Psychologist::s_state =
{
                                                    // show registration page
    { "registration",   &Psychologist::registration },  
    { "tryAdd",         &Psychologist::tryAdd },    // add new psychologist
};




