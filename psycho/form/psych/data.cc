#include "psych.ih"

Psych::Map Psych::s_state =
{
    { "profilePage",      &Psych::profilePage },    // profile page 
    { "clientPage",       &Psych::clientPage },     // client page 
    { "profile",          &Psych::profile },        // process new profile 
    { "verify",           &Psych::verify  },        // verify UN/PW    
    { "newPwd",           &Psych::newPwd  },        // verify UN/PW    
    { "verifyAck",        &Psych::verifyAck },      // verify the Ack nr
    { "addPsych",         &Psych::addPsych },       // add a new psych.
};

Psych::Map2display Psych::s_clientPageRequest =
{
    { "activate",       &Psych::activateClient },       // 2.cc
    { "add",            &Psych::addClient }, 
    { "addActivate",    &Psych::addActivateClient }, 
    { "deactivate",     &Psych::deactivateClient }, 
    { "remove",         &Psych::removeClient }, 
    { "show",           &Psych::showClient }, 
    { "update",         &Psych::updateClient }, 
};

string Psych::s_activate = R"(
                <input type=submit name='action' value="Versturen"
                    title="verstuur een uitnodiging aan deze client"
                    onclick='process("activate")'>)";

string Psych::s_add = R"(
                <input type=submit name='action' value=Toevoegen
                    title="client toevoegen"
                    onclick='process("add")' >)";

string Psych::s_addActive = R"(
                <input type=submit name='action' value="Toevoegen + versturen"
                    title="client toevoegen + uitnodiging versturen"
                    onclick='process("addActivate")' >)";

string Psych::s_erase = R"(
                <input type=submit value="Velden wissen"
                    title="wis de inhoud van de invulvelden"
                    onclick='resetFields()' >)";

string Psych::s_deactivate = R"(
                <input type=submit name='action' value="Deactiveren"
                    title=
                        "be&euml;indig de vragenlijstafname voor deze client"
                    onclick='process("deactivate")' >)";

string Psych::s_remove = R"(
                <input type=submit name='action' value="Verwijderen"
                    title = "verwijder deze client"
                    onclick='process("remove")' >)";

string Psych::s_update = R"(
                <input type=submit name='action' value=Wijzigen
                    title="client gegevens wijzigen"
                    onclick='process("update")' >)";


