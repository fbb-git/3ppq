#include "psych.ih"

void Psych::infoClient(string *clientArray, string *clientSelect)
{
    size_t nameLength = 0;
    for (auto const &client: d_client)
        nameLength = ::max(nameLength, client.d_name.length());
    nameLength += 2;

    *clientSelect = 
        "<div style='margin-right: 10px; float:left'>\n"
        "<span style='font-family: courier;'><b>\n" +
        " ID  " + 
            setWidth("Naam", nameLength) + "Achternaam</b>"
        "</span><br>\n"
        "<select size=" +
        (
            d_client.size() > 5 ? 
                "5"s 
            : 
                to_string(d_client.size())
        ) +
        "style='font-family: courier; border:solid,3px; "
                            "overflow-y: scroll;'>\n

    *clientArray = "var clients = [\n";

    for (auto const &client: d_client)
    {
        string id = to_string(d_ID);

        *clientSelect +=
            "    <option value=" + id + ">" + setWidth(id, 3, right) + "  " +
            setWidth(d_name, nameLength) + d_lastName + "</option>\n";

        *clientArray += 
              "    [" + to_string(d_ID)             + ',' +
                        to_string(d_activeTime)     + ',' +
                        to_string(d_login0)         + ",\"" +
                        d_name                      + "\",\"" +
                        d_lastName                  + "\",\"" +
                        d_email                     + "\""
                    "],\n";
    }

    *clientSelect += "</select><br>\n";
                    "

    *clientArray += "];\n";
}


