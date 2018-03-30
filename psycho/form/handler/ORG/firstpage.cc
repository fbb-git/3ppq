#include "handler.ih"

void Handler::firstPage()
{
    cout << 
R"(
    <h1>Welcome to the C++ Red Thread Maze</h1>
)";

    monitorSubmit() << d_uid << " stateinfo";

    cout << d_reply << 
R"(
<p>
<div style="background-color:#dddddd">
<hr>
<p>
Next: <input type="text" name="next" size="40" autofocus><p>
)";

    if (d_help)
        helpInfo();

    cout << 
R"(
    <p>
    To leave the game click here: <input type="checkbox" name="logout"
                                         value="1"><p>
)";

    d_state = CMD;
}





