#include "client.ih"

Client::Map Client::s_state =
{
    { "storeEmail", &Client::storeEmail  },     // store e-mail adresses and
                                                // invide others.

    { "answered",   &Client::answered  },       // handle received answers
};




