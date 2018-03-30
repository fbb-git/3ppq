#include "handler.ih"

void Handler::setState(void (Handler::**handler)())
{
    string stateValue = d_cgi.param1("state");

    if (
        handler == &s_empty || 
        stateValue.empty() || not isdigit(stateValue[0])
    )
    {
        d_state = START;
        return;
    }
    
    size_t stateNr = stoul(stateValue);         // current state nr
    if (stateNr == 0)
    {
        d_state = START;
        return;
    }

    d_state = REQUEST;
}
