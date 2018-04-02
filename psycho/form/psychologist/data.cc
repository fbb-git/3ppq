#include "psychologist.ih"

Psychologist::Map Psychologist::s_state =
{
    {"register",    &Psychologist::newPsych} ,
    {"add",         &Psychologist::add} ,
};


/*
    psychologist.html
        submit (psycholgoist.js)    state:
        ------------------------    -------
        Password kwijt:             noPwd
        Inloggen:                   login
        Aanmelden:                  register

state:      call:               stub (->.js)    submit          state
------      -----               ------------    ------          -----
register    newPsych            newpsych        Aanmelden       add
                                           
login

noPwd

add         add                                     
            alreadyRegistered   alreadyregistered   Aanmelding  register
                                                    Homepage->index.html

            newRegistration     newregistration     
*/




