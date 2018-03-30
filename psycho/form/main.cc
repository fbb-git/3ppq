#include "main.ih"

// see README

namespace {
                // contains the abs. path to the directory 
                // containing stubs and skeletons
#include "basedir.f"

} //namespace

Log g_log;                              // generic log facility

int main(int argc, char **argv)
{
    Handler handler{ g_base };          // Form handling object

    handler.process();                  // process incoming forms
}

