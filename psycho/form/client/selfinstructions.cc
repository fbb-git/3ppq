#include "client.ih"

void Client::selfInstructions(WIPdata const &wipData)
{
    pidCid(wipData);
    d_display.append("ratingType", to_string(SELF));

    d_display.out("instructions.h", 
        {
            "Bent u"
        }
    );
}
