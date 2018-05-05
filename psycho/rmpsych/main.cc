#include "main.ih"

namespace {

#include "../basedir.f"

}   // anonymous

Options g_options{ g_base };

int main(int argc, char **argv)
try
{
    if (argc == 1)
        usage(basename(argv[0]));

    DataStore dataStore{ g_options.psych() };

    string hash = Tools::md5hash(argv[1]);

    LockGuard lg{ dataStore.lg() };

    string data;
    if (not dataStore.get(&data, hash))
        cout << argv[1] << " not found\n";
    else
    {
        istringstream in{ data };
        in.seekg(Tools::IV_SIZE + 2 * sizeof(uint16_t) + sizeof(uint32_t));
        uint16_t ID;
        Tools::readN(in, &ID);

        if (dataStore.erase(hash))
            cout << argv[1] << "(ID = " << ID << ") was removed\n";
    }
        
}
catch (int)
{
    return 0;
}
catch (exception const &exc)
{
    cout << exc.what() << '\n';
}
catch (...)
{
    cout << "unexpected exception\n";
    return 1;
}

