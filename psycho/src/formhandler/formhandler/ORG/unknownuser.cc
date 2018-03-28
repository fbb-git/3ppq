#include "formhandler.ih"

void FormHandler::unknownUser()
{
    cout <<
R"(
    <h1>You don't exist. Go away...</h1>
    <p>
    <img src="/images/0/dontexist.jpg">

    <hr>
)";
    d_state = LOGIN;
}
