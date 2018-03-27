#include "formhandler.ih"

void FormHandler::alreadyLoggedIn()
{
    cout <<
R"(
    <h1>You're already logged in...</h1>

    You cannot login twice. But you can continue at the computer where you're
currently logged in.
)";

    d_state = LOGIN;
}
