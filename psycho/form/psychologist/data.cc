#include "psychologist.ih"

Psychologist::Map Psychologist::s_state =
{
    { "register",   &Psychologist::registration },  // show registration page
    { "tryAdd",     &Psychologist::tryAdd },        // add new psychologist
};




