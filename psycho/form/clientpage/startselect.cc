#include "clientpage.ih"

void ClientPage::startSelect(ostream &out, size_t idLength) const
{
    size_t nRows = std::max(Tools::min(d_clients.size(), 
                                       Tools::MAX_CLIENT_SELECT_ROWS),
                            2UL);
    
    out << R"(
    <table>         
    <tr>            
    <td class=topAlign>
            <span class=monospace style=' margin-left: 4px' > 
                  <b>ID&nbsp;&nbsp;&nbsp;Naam</b> </span>
            <br>
            <select class=monospace id=selectID onclick='process("show")'
                     size=)" << nRows << ">\n";
}
