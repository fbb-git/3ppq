#ifndef INCLUDED_REPORT_
#define INCLUDED_REPORT_

#include <string>

#include <bobcat/fork>

class WIPdata;

class Report: private FBB::Fork
{
    std::string d_pidCid;
    std::string d_pathPrefix;       // prefix (including the final .) of 
                                    // generated files

    std::string d_csvPath;          // csv 
    std::string d_fScores;          // factor scores table generated by fsplot

    std::string d_gnuplotInput;     // gnuplot input file
    std::string d_gnuplotData;      // gnuplot data

    std::string d_gnuplotEps;       // eps generated by gnuplot 

    std::string d_latexInput;       // input file for LaTeX
    std::string d_dviFile;          // output file from LaTeX
    std::string d_pdfFile;          // output file from pdfdvi

    std::string d_clientName;       // currently not used
    std::string d_clientIdent;

    uint32_t d_from;
    std::string d_psychEmail;

    public:
        Report(WIPdata const &wipData);
        Report(char const *pidCid, char const *psychemail);

        virtual ~Report();          // Currently no actions

        void generate();

    private:
        void childProcess() override;
        void parentProcess() override;

        void fsplot() const;
        void latex() const;
        void dvipdf() const;

        void writeLatexInputFile() const;
        std::string headerInfo() const;
        std::string latexScoresTable() const;
};
        
#endif






