#ifndef INCLUDED_REPORT_
#define INCLUDED_REPORT_

#include <string>

class WIPdata;

class Report
{
    std::string d_psychEmail;
    std::string d_path;             // wip-data csv path

        
    public:
        Report(WIPdata const &wipData);
        void generate();

    private:
};
        
#endif
