#include "psych.ih"

void Psych::verifyAck()
{
    LockGuard lg{ d_lockPath, d_lockFd };

    string data;
    d_psychData.get(&data, nipKey());

    getUnencrypted(data);

    try
    {
        if (d_record.ack == stoul(d_cgi.param1("ack")))
        {
            d_record.ack = 0;
            data.replace(8, d_record.size, d_record.toString());
            d_psychData.update(nipKey(), data);
            Display{ g_options.html() + "actions" };
            return;
        }
    }
    catch (...)
    {}

    Display{
        {
            Tools::passParam(d_cgi, "nip"),
            Tools::passParam(d_cgi, "pwd")
        },
        g_options.html() + "ackerr" 
    };
}



