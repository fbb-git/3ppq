#include "clientpage.ih"

// static
void ClientPage::endSelect(ostream &out, bool foundReport)
{
    out << R"_(
            </select>
    </td>
    </tr>
    </table>
)_";

}
