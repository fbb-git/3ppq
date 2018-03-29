#include "formhandler.ih"

// function ordering must match Action symbol ordering                         

void (FormHandler::*FormHandler::s_psychoStates[])() =
{
//    &FormHandler:: psychoStart,         // START,
    &FormHandler:: psychoRequest,       // START,
};

void (FormHandler::*FormHandler::s_clientStates[])() =
{
};

void (FormHandler::*FormHandler::s_empty)() =
{
    &FormHandler:: empty,                 // should not occur
};

