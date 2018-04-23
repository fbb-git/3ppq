//#include "tools.ih"
//
//    // static
//bool Tools::copy(ostream &out, istream &in, Uint32 begin, Uint32 end)
//{
//    out.clear();
//
//    unique_ptr<char> buffer(new char[BUFSIZE]);
//
//    in.seekg(begin);
//
//    Uint32 todo = end - begin;
//
//    while (todo != 0)
//    {
//        Uint32 read = todo >= BUFSIZE ? BUFSIZE : todo;
//        todo -= read;
//        
//        if (in.read(buffer.get(), read) and out.write(buffer.get(), read))
//            continue;
//
//        return false;
//    }
//
//    return true;
//}
//
//
