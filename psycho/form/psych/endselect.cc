#include "psych.ih"

void Psych::endSelect(ostream &out) const
{
    out << R"(
            </select>
        </div>
    </td>
    <td class=topAlign>    
        <div class=float> 
            &nbsp;
            <p>
            <input type=submit value=Verwijder onclick='remove()'><br>
            (verwijdert de gemarkeerde cli&euml;nt)<br>
        </div>
    </td>
    </tr>
    </table>
)";

}
