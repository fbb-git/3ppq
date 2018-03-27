#include "formhandler.ih"

void FormHandler::monitorCommand()
{
    monitorSubmit() << d_uid << " next " << d_next;

    g_log << __FILE__ << " receives: `" << 
                            d_reply.substr(0, 20) << '\'' << endl;
    showHtmlPage();
}
