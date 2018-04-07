#include "client.ih"

Client::Map Client::s_state =
{
    { "verify",     &Client::verify  }, // verify activation data
    { "quest",      &Client::quest },   // present the questionnaire
};




