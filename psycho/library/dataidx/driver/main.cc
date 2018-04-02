#include "main.ih"

int main(int argc, char **argv)
try
{
    DataIdx dataIdx{ "data.idx" };

    cout << "add key " << 100 << ": " << dataIdx.add(100, 0x11) << '\n';
    cout << "add key " << 100 << ": " << dataIdx.add(100, 0x11) << '\n';
    cout << "add key " << 200 << ": " << dataIdx.add(200, 0x22) << '\n';

    cout << "remove 100\n";
    dataIdx.remove(100);
    cout << '\n';
    cout << "add key " << 100 << ": " << dataIdx.add(100, 0x11) << '\n';

    // for this test, temporarily define extend as a public member
    dataIdx.extend();

    cout << "Data offset of key 100: " << dataIdx.dataOffset(100) << '\n';
    cout << "Data offset of key 200: " << dataIdx.dataOffset(200) << '\n';
    cout << "Data offset of key 20: "  << dataIdx.dataOffset(20) << '\n';
}
catch (exception const &exc)
{
    cout << "Exception: " << exc.what() << '\n';
}
