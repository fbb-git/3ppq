#include "formhandler.ih"

// function ordering must match Action symbol ordering                         

void (FormHandler::*FormHandler::s_handler[])() =
{
    &FormHandler:: login,                 // LOGIN,              
    &FormHandler:: verifyUnPw,            // VERIFY_UNPW,        
    &FormHandler:: monitorCommand,        // CMD           
    &FormHandler:: logout,                // LOGOUT
};
