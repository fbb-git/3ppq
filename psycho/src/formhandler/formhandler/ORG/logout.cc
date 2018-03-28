#include "formhandler.ih"

void FormHandler::logout()
{
    monitorSubmit() << d_uid << " logout";

    cout <<
R"(
<img src="/images/0/thanks.jpg" style="float:right">
<h1>Thank you for visiting the C++ Red Thread Maze</h1>
You may press the `submit' button to login again...<p>
)";

    d_uid = maxUint16;
    d_state = LOGIN;
}
