#include "tools.ih"

// static
void Tools::childProcess(string const &command)
{
    Process process(Process::IGNORE_COUT_CERR, command);
    process.start();

    if (process.waitForChild() != 0)
    {
        g_log << "Child process `" << command << "' failed" << endl;
        throw false;
    }
}
