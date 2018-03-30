#include "handler.ih"

void Handler::showHtmlPage()
{
    if (d_reply.find("autologout") == 0)
    {
        autoLogout();
        return;
    }
    
    if (d_reply.find("killed") == 0)
    {
        killed();
        return;
    }
    
    cout << 
    "<h1>The C++ Red Thread Maze...</h1>\n" <<
    d_reply << 
R"(
<p>
<div style="background-color:#dddddd">
<hr>
<p>

Next: <input type="text" name="next" size="40" autofocus><p>

To leave the game click here: 
                        <input type="checkbox" name="logout" value="1"><p>
)";

}
