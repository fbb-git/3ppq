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

char const *Client::s_heShe[2] =    { "hij",    "zij" };
char const *Client::s_hisHer[2] =   { "zijn",   "haar" };
char const *Client::s_himHer[2] =   { "hem",    "haar" };
        
char const Client::s_closeSelf[] = 
    "U hebt alle vragen van deel 1 beantwoord. Klik op "
    "`Verstuur' om uw vragen op te slaan, waarna u direct verder kunt "
    "gaan met deel 2.";

char const Client::s_closeMeta[] = 
    "U hebt alle vragen van deel 2 beantwoord. Klik op "
    "`Verstuur' om uw vragen op te slaan, waarna u direct verder kunt "
    "gaan met deel 3.";

char const Client::s_closeOther[] = 
    "Dit was de laatste vraag. Als u wilt kunt u nog antwoorden wijzigen. "
    "Door op onderstaande knop `Verstuur' te klikken worden uw antwoorden "
    "definitief.";

char const Client::s_selfThanks[] = 
    "Het onderzoek is afgerond. Uw psycholoog krijgt de resultaten "
    "en zal deze met u bespreken.";

char const Client::s_otherThanks[] = 
    "Hartelijk dank voor het invullen van de vragenlijst.";


