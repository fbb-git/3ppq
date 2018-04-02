#include "psychologist.ih"

void Psychologist::getPrivate(Private *priv, 
                              string const &data, size_t offset)
{
    istringstream in{ 
            Tools::decrypt(
                data.substr(0, 8), 
                stringstream{ 
                    string{ data.begin() + offset, data.end() }
                }
            )
    };

    Tools::read(in, &priv->nip);
    Tools::read(in, &priv->gender, 1);

    getline(in, priv->name);
    getline(in, priv->lastName);
    getline(in, priv->email);
}

