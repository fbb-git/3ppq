//#include "wipdata.ih"
//
//int64_t WIPdata::find(istream &in, uint16_t psychID, uint16_t clientID)
//{
//    int64_t offset;
//
//    in.seekg(0);
//    
//    while (true)
//    {
//        offset = in.tellg();
//
//        if (not read(in))
//            return -1;
//
//        if (d_psychID == psychID and d_clientID == clientID)
//            return offset;
//    }
//}
//
