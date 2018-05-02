#include "client.ih"

Client::Map Client::s_state =
{
    { "storeEmail", &Client::storeEmail  },     // store e-mail adresses and
                                                // invide others.
    { "answered",   &Client::answered  },       // handle received answers

    { "testing",    &Client::testing },
};

Client::CompletedHandler Client::s_completed[] =
{
    &Client::selfCompleted,             // RatingType: SELF
    &Client::metaCompleted,             // RatingType: META
    &Client::otherCompleted,            // RatingType: OTHER
};

size_t const Client::s_completedSize = size(s_completed);


