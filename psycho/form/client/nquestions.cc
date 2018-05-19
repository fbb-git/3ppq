#include "client.ih"

// static
std::string Client::nQuestions()
{
    ifstream nqStream{ g_options.dataDir() + "nq" };

    size_t nq = Tools::N_QUESTIONS;

    nqStream >> nq;

    g_log << "nQuestions: " << nq << endl;

    return to_string(
                nq > Tools::N_QUESTIONS ? Tools::N_QUESTIONS : nq
            );
}
