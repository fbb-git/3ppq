#include "psych.ih"

void Psych::tryAdd()
{
    LockGuard lg{ d_lockPath, d_lockFd };

    if (not acceptRegistration())
        alreadyRegistered();
}



//    fstream str(g_options.psychs(), ios::in);
//    
//    if (not str)
//    {
//        str.clear();
//        str.open(g_options.psychs(), ios::out);
//        str.close();
//    }
//    else
//    {
//        while (readRecord(str))                         // read a psych. record
//        {
//            if (d_record.nip == d_cgi.param1("nip"))    // already registered?
//            {
//                alreadyRegistered();
//                return;
//            }
//        }
//    }

