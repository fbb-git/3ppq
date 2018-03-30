#ifndef INCLUDED_TOOLS_
#define INCLUDED_TOOLS_

#include <iostream>         // TMP
#include <fstream>

#include "../types/types.h"

class Tools
{
    enum { BUFSIZE = 5000 };
    
    public:
        static size_t random(int max);  // next random nr from uniform 
                                        // int distribution [0 .. max)

        static void lock(int fd, std::string const &path);
        static int unlock(int fd);      // returns -1

        static Uint16 htmlTextSize(StrVector const &htmlTexts);

        static bool copy(std::ostream &out, std::istream &in, 
                                            Uint32 begin, Uint32 end);

        template <typename Type>                       // 1.f
        static bool read(std::istream &in, Uint32 offset,
                         Type *dest, size_t size = sizeof(Type));

        template <typename Type>                       // 2.f
        static bool read(std::istream &in, 
                         Type *dest, size_t size = sizeof(Type));

        template<typename Type>                        // 1.f
        static bool write(std::ostream &out, Uint32 offset, 
                        Type const *src, size_t size = sizeof(Type));

        template<typename Type>                        // 2.f
        static bool write(std::ostream &out, 
                        Type const *src, size_t size = sizeof(Type));

        static Uint32 tellg(std::istream &stream);  

        static Uint32 size(std::istream &stream);     // 1.f
        static Uint32 size(std::ostream &stream);     // 2.f
        static Uint32 size(std::fstream &stream);     // 3.f

};

#include "read1.f"
#include "read2.f"

#include "write1.f"
#include "write2.f"

#include "tellg.f"

#include "size1.f"
#include "size2.f"
#include "size3.f"

#endif
