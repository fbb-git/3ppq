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

char const *Client::s_heShe[2] =    { "zij",  "hij" };
char const *Client::s_hisHer[2] =   { "haar", "zijn"};
char const *Client::s_himHer[2] =   { "haar", "hem" };
        
char const Client::s_closeSelf[] = 
    "U hebt alle vragen van deel 1 beantwoord.<p>\n"
    "Klik op &#x2018;Verstuur&#x2019; om uw vragen op te slaan, "
    "waarna u verder kunt gaan met deel 2.\n";

char const Client::s_closeMeta[] = 
    "U hebt alle vragen van deel 2 beantwoord.<p>\n"
    "Klik op &#x2018;Verstuur&#x2019; om uw vragen op te slaan, "
    "waarna u verder kunt gaan met deel 3.\n";

char const Client::s_closeOther[] = 
    "U hebt alle vragen beantwoord. Klik op &#x2018;Verstuur&#x2019; "
    "om uw vragen op te slaan\n";

char const Client::s_selfThanks[] = 
    "Het onderzoek is afgerond. Uw psycholoog krijgt de resultaten "
    "en zal deze met u bespreken.";

char const Client::s_otherThanks[] = 
    "Hartelijk dank voor het invullen van de vragenlijst.";


