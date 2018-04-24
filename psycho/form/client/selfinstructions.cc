#include "client.ih"

void Client::selfInstructions(WIPdata const &wipData)
{
    pidCid(wipData);
    d_display.out("instructions.h", 
        {
            "Bent u"
        }
    );
}
