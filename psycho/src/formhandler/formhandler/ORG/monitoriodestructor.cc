#include "formhandler.ih"

FormHandler::MonitorIO::~MonitorIO()
{
    Tools::lock(d_rtForm.d_toMonitorFd, d_rtForm.d_lockPath);

    d_rtForm.d_out << d_rtForm.d_reply << endl;

    d_rtForm.d_reply.clear();

    while (true)
    {
        string line;
        char sentinel;

        d_rtForm.d_in >> sentinel;
        getline(d_rtForm.d_in, line);

        if (sentinel == '0')
        {
            g_log << __FILE__ << ": closing 0" << endl;
            break;
        }

        d_rtForm.d_reply += line + '\n';
    }

    Tools::unlock(d_rtForm.d_toMonitorFd);
}


