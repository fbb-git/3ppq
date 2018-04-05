#include "main.ih"

DataStore dataStore{ "data/data" };

int main(int argc, char **argv)
try
{
    while (true)
    {
        add();
        retrieve();
        update();
        remove();
    }
}
catch (exception const &exc)
{
    cout << "Exception: " << exc.what() << '\n';
}
catch (...)
{}

