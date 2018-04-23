#include "client.ih"

Client::Map Client::s_state =
{
    { "storeEmail",   &Client::storeEmail  },   // store e-mail adresses and
                                                // invide others.
//    { "verify",     &Client::verify  }, // verify activation data
//    { "quest",      &Client::quest },   // present the questionnaire
};




