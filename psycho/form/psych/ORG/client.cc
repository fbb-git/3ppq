//#include "psych.ih"
//
//void Psych::client()
//{
//    LockGuard lg{ d_data.lg() };
//
//    if (not get())              // retrieve psych data
//        return;
//   
//    // show client data, modify / delete 
//
//
//        // add client:
//        
//    d_client.resize(d_client.size() + 1);
//
//    PsychClient &client = d_client.back();
//
//    uint8_t login0 = Tools::random(10, 99);
//
//    if (not client.set(d_ID, login0, d_cgi))
//        return;
//
//    // send instructions to the client, return the initial login code
//    // to the client
//
//    // once a client has completed the questionnaire the data are stored in
//    // the datamatrix as a block of 5 lines: 4 beingempty. The
//    // client and the 3 others receive an invitation mail. 
//    // Once all data have been received the wip record is removed, and the
//    // psychologist is informed that the data are available.
//}
//
