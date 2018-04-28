#include "psych.ih"

void Psych::startSelect(ostream &out, size_t idLength) const
{
    size_t nRows = std::max(Tools::min(d_client.size(), 
                                       Tools::MAX_CLIENT_SELECT_ROWS),
                            2UL);
    
    out << R"(
    <table>
    <tr>
    <td>
        <div class=leftFloat>
            <span class=courier18><b>
            &nbsp;ID )" << fixedWidth("ID", idLength) << R"(Naam</b>
            </span><br>
            <select class=clientSelect id=selectID onclick='update()' size=)" 
                                                                            <<
                nRows << ">\n";
}
