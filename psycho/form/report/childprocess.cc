#include "report.ih"

void Report::childProcess()
{
    prepareDaemon();

    fsplot();
    latex();
    dvipdf();

    for (
        char const *name: Glob{ g_options.tmpDir() + d_pidCid + ".*" } 
    )
        unlink(name);

    throw Tools::ForkChild::DONE;    
}
