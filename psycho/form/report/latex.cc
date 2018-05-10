#include "report.ih"

    // LaTeX produces d_pathPrefix.dvi from d_pathPrefix.latex, produced by
    // fsplot
void Report::latex() const
{
    writeLatexInputFile();    

    string command = g_config.findKeyTail("latex:") +  " "
                    "--output-directory=" + g_options.tmpDir() + " "
                    "--aux-directory=" + g_options.tmpDir() +    " " +
                    d_latexInput;

    for (size_t idx = 0; idx != 2; ++idx)
    {
        Tools::childProcess(command);
        g_log << "DONE" << endl;
    }
   
}


