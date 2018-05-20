#ifndef INCLUDED_CLIENTPAGE_
#define INCLUDED_CLIENTPAGE_

#include <vector>
#include <string>

#include "../../support/tools/tools.h"

class Display;
class PsychClient;

class ClientPage
{
    Display &d_display;
    std::vector<PsychClient> const &d_clients;
    uint16_t d_ID;
    std::vector<size_t> d_deactivated;
    std::vector<bool> d_reportExists;

    static std::string s_erase;

    public:
        struct Info
        {
            std::string submitActions;
            size_t      clientIdx;          // show this client idx unless >=
        };                                  // d_clients.size()

        ClientPage(Display &display, std::vector<PsychClient> const &clients,
                   uint16_t ID);

        bool display(Info const &info, std::string const &eMail);

        std::vector<size_t> const &deactivated() const;

    private:
        size_t buildClientArray(std::string *array);
        void infoClient(std::string *array, std::string *select);
        std::string reportHyperlink(size_t idx) const;
        void buildSelectTag(std::string *select, size_t idLength) const;
        void startSelect(std::ostream &out, size_t idLength) const;

        static void endSelect(std::ostream &out, bool foundReport);
        static std::string fixedWidth(std::string const &txt, size_t length,
                                      Tools::Align align = Tools::LEFT);
};

inline std::vector<size_t> const &ClientPage::deactivated() const
{
    return d_deactivated;
}
        
#endif


