//#include "tools.ih"
//
//void Tools::reduce(LockStream &io, int64_t high, int64_t low)
//{
//    if (high == low)
//        return;
//
//    if (high < low)
//        throw Exception{} << "cannot reduce from " << from << " to " << low;
//
//    char *buffer = new char[BUFSIZE];
//
//    io.open();
//
//    while (true)
//    {
//        io.seekg(high);
//        size_t size = io.read(buffer, BUFSIZE).gcount(); // read a block
//        if (size == 0)
//            break;
//
//        io.clear();
//        io.seekp(low);
//
//        io.write(buffer, size);                       // write the block
//
//        low += size;                                         // next block
//        high += size;
//    }
//
//    io.close();
//    truncate(d_path.c_str(), low);
//}
//
