#include "clientpage.ih"

void ClientPage::startSelect(ostream &out, size_t idLength) const
{
    size_t nRows = std::max(Tools::min(d_clients.size(), 
                                       Tools::MAX_CLIENT_SELECT_ROWS),
                            2UL);
    
    out << R"(
    <h3>Cli&euml;ntlijst</h3>

    Klik op een cli&euml;nt om de cli&euml;ntgegevens te tonen, te kunnen
wijzigen of om een rapport (R) te kunnen ophalen.
<p>

    <table>         
    <tr>            
    <td class=topAlign>
            <span class=monospace style=' margin-left: 4px' > 
                  <b>Cli&euml;nt&nbsp;ID&nbsp;&nbsp;&nbsp;Naam</b> </span>
            <br>
            <select class=monospace id=selectID onclick='process("show")'
                     size=)" << nRows << ">\n";
}
