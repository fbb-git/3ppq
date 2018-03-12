#include "main.ih"

// Room for Args initialization

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
try
{
    Mail mail;

    mail.process();
}
catch (...)
{
    return 0;
}
