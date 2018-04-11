//#include "psych.ih"
//
//string Psych::publicData() const
//{
//    ostringstream out;
//
//    uint32_t v32 = time(0);               // registration time
//    Tools::write(out, &v32);
//    
//    uint16_t v16 = Tools::random(8999) + 1000;    // 1000 .. 9999
//    Tools::write(out, &v16);            // ack. nr
//
//    v16 = 0;                            // flags
//    Tools::write(out, &v16);
//
//    v16 = identNr();                    // identnr
//    Tools::write(out, &v16);
//
////FBB
////    string pwdHash = Tools::md5hash(d_cgi.param1("pwd"));
////    ostringstream out2;
////    out2 << hex;
////    for (char ch: pwdHash)
////        out2 << (int)(unsigned char)ch << ' ';
////    g_log << "publicData hash: " << out2.str() << endl;
//
//    Tools::write(out, Tools::md5hash(d_cgi.param1("pwd")));
//
//    return out.str();
//}
//
//
