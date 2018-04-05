#include "psych.ih"

Psych::Map Psych::s_state =
{
                                                    // show registration page
    { "registration",   &Psych::registration },  
    { "tryAdd",         &Psych::tryAdd },    // add new psychologist
    { "login",          &Psych::login  },    // login with UN/PW    
    { "noPwd",          &Psych::noPwd  },    // lost password       
};




