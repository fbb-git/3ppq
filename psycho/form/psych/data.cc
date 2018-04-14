#include "psych.ih"

Psych::Map Psych::s_state =
{
    { "verify",       &Psych::verify  },    // verify UN/PW    
    { "newPwd",       &Psych::newPwd  },    // verify UN/PW    
    { "verifyAck",    &Psych::verifyAck },  // verify the Ack nr
    { "addPsych",     &Psych::addPsych },   // add (register) a new psych.
};



