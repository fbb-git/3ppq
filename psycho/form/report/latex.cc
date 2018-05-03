#include "report.ih"

    // fsplot has generated d_scores
void Report::latex() const
{
    string const &mold = g_options.latexMold();

    string base { g_options.tmpDir() + d_pidCid };

    string latexIn{ base + ".latex" };
    {
        ofstream latex;
        Exception::open(latex, latexIn);
    
        DollarText::replace(
                        latex, mold, 
                        { 
                            g_options.imagesDir() + "3ppqUL.eps",
                            headerInfo(),
                            d_eps,
                            latexScoresTable()
                        }
                    );
    }
    
    g_log << "calling `/usr/bin/latex " << latexIn << '\'' << endl;

    Process latex { Process::IGNORE_COUT_CERR, 
                    "/usr/bin/latex "     // call LaTeX
                    "--output-directory=" + g_options.tmpDir() + " "
                    "--aux-directory=" + g_options.tmpDir() +    " " +
                    latexIn
            };

    g_log << "starting\n";
    latex.start();

    g_log << "waiting\n";
    latex.waitForChild();

    g_log << "done\n";
}


