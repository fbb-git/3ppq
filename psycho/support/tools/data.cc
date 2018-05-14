#include "tools.ih"

char const *Tools::s_messages[] =
{
    "Vereiste parameters ontbreken of zijn foutief gespecificeerd", // REQUIRE,            
    "Onbekende gebruiker",                                          // NO_PSYCH,           
    "Onbekende cli&euml;t",                                         // NO_CLIENT,          
    "Rapport niet beschikbaar",                                     // NO_REPORT,          
    "Niet gedefinieerde opdracht",                                  // NO_STATE,           
    "De vragenlijst is al ingevuld",                                // DATA_AVAILABLE,     
    "De gespecificieerde URI is niet (meer) actief",                // NO_QUERY,           
    "Email adressen zijn al gespecificeerd",                        // EMAIL_AVAILABLE,    
    "Falende deelopdracht",                                         // CHILD,
    "Data niet toegankelijk",                                       // NO_DATA,            
    "URI niet herkend",                                             // QUERY,              
    "Geneste vragenlijstafname niet beschikbaar",                   // BUSY,               
};
