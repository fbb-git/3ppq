#include "handler.ih"

void Handler::process()
{
    string const &type = d_cgi.param1("type");
 
    g_log << "Starting Handler::process: type = `" << type << '\'' << endl;
    g_log << "Starting Handler::process: state = `" << 
                                            d_cgi.param1("state") << '\'' << 
                                            endl;

    if (type == "psychologist")
        d_psychologist.process();

    else if (type == "client")
        ; // d_client.process();

    else 
        empty();
}


//     void (Handler::**handler)() = s_psychoStates;
// 
// //        src.find("/psychologist.shtml") != string::npos ?   s_psychoStates :
// //        src.find("/client.shtml") != string::npos ?         s_psychoStates :
// //                                                            &s_empty;
// 
// 
//         // when more URIs are used, use a map to select the appropriate
//         // handler. 
// 
//     setState(handler);                                  // find the FSA state
// 
//     (this->*handler[d_state]) ();    // Initial state is START






