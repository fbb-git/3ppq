#include "psych.ih"

Psych::Map Psych::s_state =
{
    { "client",       &Psych::client },     // handle client-requests
    { "tryAdd",       &Psych::tryAdd },     // add new psychologist
    { "verify",       &Psych::verify  },    // verify UN/PW    
    { "verifyAck",    &Psych::verifyAck },  // verify the Ack nr
    { "noPwd",        &Psych::noPwd  },     // lost password       
};




