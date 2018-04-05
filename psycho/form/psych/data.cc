#include "psych.ih"

Psych::Map Psych::s_state =
{
                                                    // show signup page
    { "signup",   &Psych::signUp },  
    { "tryAdd",   &Psych::tryAdd },    // add new psychologist
    { "verify",   &Psych::verify  },   // verify UN/PW    
    { "noPwd",    &Psych::noPwd  },    // lost password       
};




