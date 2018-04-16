#include "psych.ih"

Psych::Map Psych::s_state =
{
//    { "actions",          &Psych::actions },        // actions page 
    { "profilePage",      &Psych::profilePage },    // profile page 
    { "profile",          &Psych::profile },        // process new profile 
    { "verify",           &Psych::verify  },        // verify UN/PW    
    { "newPwd",           &Psych::newPwd  },        // verify UN/PW    
    { "verifyAck",        &Psych::verifyAck },      // verify the Ack nr
    { "addPsych",         &Psych::addPsych },       // add a new psych.
};
