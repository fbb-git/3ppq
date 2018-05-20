#include "psych.ih"

Psych::Map Psych::s_state = // states must retrieve the psych's data
{
    { "profilePage",      &Psych::profilePage },    // profile page 
    { "clientPage",       &Psych::clientPage },     // client page 
    { "profile",          &Psych::profile },        // process new profile 
    { "verify",           &Psych::verify  },        // verify UN/PW    
    { "newPwd",           &Psych::newPwd  },        // verify UN/PW    
    { "verifyAck",        &Psych::verifyAck },      // verify the Ack nr
    { "addPsych",         &Psych::addPsych },       // add a new psych.
    { "report",           &Psych::report },         // download a report
    { "getData",          &Psych::getData },        // download a report
    { "nQuest",           &Psych::nQuest },         // set # questions
};

Psych::Map2display Psych::s_clientPageRequest =
{
    { "activate",       &Psych::activateClient },
    { "add",            &Psych::addClient }, 
    { "addActivate",    &Psych::addActivateClient }, 
    { "deactivate",     &Psych::deactivateClient }, 
    { "remove",         &Psych::removeClient }, 
    { "show",           &Psych::showClient }, 
    { "update",         &Psych::updateClient }, 
};

    // submitrequest: call psych/clientpage with the argument as request.
    // process: returns client idx and calls submitRequest passing
    //          the argument to submitRequest
string Psych::s_activate = R"(
                <input type=submit name='action' value="Afname activeren"
                    title="verstuur een uitnodiging aan deze cli&euml;nt"
                    onclick='process("activate")'>)";

string Psych::s_add = R"(
                <input type=submit name='action' value='Aan lijst toevoegen'
                    title="cli&euml;nt toevoegen"
                    onclick='submitRequest("add")' >)";

string Psych::s_addActive = R"(
                <input type=submit name='action' value="Toevoegen + activeren"
                    title="cli&euml;nt toevoegen + uitnodiging versturen"
                    onclick='submitRequest("addActivate")' >)";

string Psych::s_erase = R"(
                <input type=submit value="Velden wissen"
                    title="wis de inhoud van de invulvelden"
                    onclick='resetFields()' >)";

string Psych::s_deactivate = R"(
                <input type=submit name='action' value="Deactiveren"
                    title=
                    "be&euml;indig de vragenlijstafname voor deze cli&euml;nt"
                    onclick='process("deactivate")' >)";

string Psych::s_remove = R"(
                <input type=submit name='action' value="Verwijderen"
                    title = "verwijder deze cli&euml;nt"
                    onclick='process("remove")' >)";

string Psych::s_update = R"(
                <input type=submit name='action' value=Wijzigen
                    title="cli&euml;nt gegevens wijzigen"
                    onclick='process("update")' >)";


