#include "main.ih"

// see README

namespace {
                // abs. path to the directory containing stubs and skeletons
    char const g_base[] = "/home/frank/src/psycho/data";
}

Log g_log;                              // generic log facility

int main()
{
    FormHandler formHandler{ g_base };  // Form handling object

    formHandler.process();              // process incoming forms
}

