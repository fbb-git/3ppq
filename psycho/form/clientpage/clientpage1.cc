#include "clientpage.ih"

ClientPage::ClientPage(Display &display, vector<PsychClient> const &clients,
                   uint16_t ID)
:
    d_display(display),
    d_clients(clients),
    d_ID(ID)
{}
