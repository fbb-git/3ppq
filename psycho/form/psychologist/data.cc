#include "psychologist.ih"

Psychologist::Map Psychologist::s_state =
{
                                                    // show registration page
    { "registration",   &Psychologist::registration },  
    { "tryAdd",         &Psychologist::tryAdd },    // add new psychologist
    { "login",          &Psychologist::login  },    // login with UN/PW    
    { "noPwd",          &Psychologist::noPwd  },    // lost password       
};




