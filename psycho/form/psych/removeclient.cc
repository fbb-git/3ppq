#include "psych.ih"

void Psych::removeClient()
{
    g_log << "Remove client" << endl;
    auto clientIter = existingClient();

    g_log << "Remove client ID " << clientIter->id() << endl;

    d_client.erase(clientIter);
}
