#include "handler.ih"

// function ordering must match Action symbol ordering                         

void (Handler::*Handler::s_psychoStates[])() =
{
//    &Handler:: psychoStart,         // START,
    &Handler:: psychoRequest,       // START,
};

void (Handler::*Handler::s_clientStates[])() =
{
};

void (Handler::*Handler::s_empty)() =
{
    &Handler:: empty,                 // should not occur
};

