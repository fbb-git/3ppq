// #include "psych.ih"
// 
// vector<PsychClient>::iterator Psych::existingClient()
// {
// //g_log << "existingClient RECEIVES ID " << d_cgi.param1("ID") << endl;
// 
//     uint16_t ID = Tools::valueOr(d_cgi.param1("ID"), 0);
// 
//     if (ID == 0)
//         throw false;
// 
// //g_log << "Looking for ID " << ID << endl;
// 
//     auto clientIter = find_if(d_client.begin(), d_client.end(), 
//                         [&](PsychClient const &client)
//                         {
// //g_log << "Saw ID " << client.id() << endl;                            
//                             return client.id() == ID;            
//                         }
//                     );
// 
//     if (clientIter == d_client.end())     // no such client? Cannot happen:
//         throw false;
// 
//     return clientIter;
// }
// 
