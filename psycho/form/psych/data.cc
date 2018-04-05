#include "psych.ih"

Psych::Map Psych::s_state =
{
                                                    // show signup page
    { "signup",   &Psych::signup },  
    { "tryAdd",         &Psych::tryAdd },    // add new psychologist
    { "login",          &Psych::login  },    // login with UN/PW    
    { "noPwd",          &Psych::noPwd  },    // lost password       
};




