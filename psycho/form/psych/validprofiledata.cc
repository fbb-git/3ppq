#include "psych.ih"

//    var name =        form["name"].value;
//    var lastName =    form["lastName"].value;
//    var nip =         form["nip"].value;
//    var email =       form["email"].value;
//    var newemail =    form["newemail"].value;
//    var pwd =         form["pwd"].value;
//    var newpwd =      form["newpwd"].value;
//    var newpwd2 =     form["newpwd2"].value;
//    var field =       form["field"].value;

bool Psych::validProfileData(uint8_t *field)
{
    if (checkProfileData(field))
        return true;

    d_display.append("email");
    d_display.out(
        "actions.h",
        {
            R"_(
<h1>Profiel wijzigingen zijn niet verwerkt</h1>

De nieuwe gegevens van uw profiel konden niet worden verwerkt.<br>
Controleer met name uw NIP-nummer en e-mail adres.<br>
Ook dient een eventueel nieuw wachtwoord twee keer te zijn vermeld en
moet een nieuw wachtwoord minstens uit )_" + 
          to_string(Tools::MIN_PWD_LENGTH) + R"_( tekens bestaan, waaronder
letters, cijfers en tekens uit de serie: 
        <pre>-.,\/#!$%\^&\*;:{}=`~()</pre>
<p>
)_"
        }
    );

    return false;
}



