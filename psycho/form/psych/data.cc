#include "psych.ih"

Psych::Map Psych::s_state =
{
    { "actions",          &Psych::actions },        // actions page 
    { "profile",          &Psych::profile },        // profile page 
    { "verify",           &Psych::verify  },        // verify UN/PW    
    { "newPwd",           &Psych::newPwd  },        // verify UN/PW    
    { "verifyAck",        &Psych::verifyAck },      // verify the Ack nr
    { "addPsych",         &Psych::addPsych },       // add a new psych.
};

char const *Psych::s_actions[] = 
{
    "client.h",
    "data.h",
    "profile.h",
    "contact.h"
};

size_t Psych::s_actionsSize = size(Psych::s_actions);
