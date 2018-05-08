#include "psych.ih"

void Psych::endSelect(ostream &out, vector<bool> const &reportExists) const
{
    out << R"(
            </select>
    </td>
    <td class=topAlign>    
        <div class=float> 
            &nbsp;
            <br>
             Klik op een client in het linker overzicht<br>
             om de clientgegevens te zien of te wijzigen<br>
            )" << 
            (
                reportExists.empty() ? 
                    "" 
                : 
                    "R: beoordelingsrapport is beschikbaar."
            ) << R"(
        </div>
    </td>
    </tr>
    </table>
)";

}
