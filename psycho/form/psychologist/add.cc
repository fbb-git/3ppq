#include "psychologist.ih"

void Psychologist::add()
{
    LockGuard lg;
    d_psychData.guard(lg);

    if (d_psychData.find(nipKey()))         // key already exists
        alreadyRegistered();
    else
        newRegistration();                  // new registration
}

//    fstream str(g_options.psychologists(), ios::in);
//    
//    if (not str)
//    {
//        str.clear();
//        str.open(g_options.psychologists(), ios::out);
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

