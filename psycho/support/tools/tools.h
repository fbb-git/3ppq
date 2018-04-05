#ifndef INCLUDED_TOOLS_
#define INCLUDED_TOOLS_

#include <unistd.h>

#include <iosfwd>
#include <fstream>

#include "../types/types.h"

class Tools
{
    enum { BUFSIZE = 5000 };
    
    public:
        template <typename Type>
        static Type *as(size_t *skip, std::string const &str);

                                // open to RW, create if not existing
        static std::fstream fstream(std::string const &path);

        static std::string encrypt(std::string const &iv, 
                                   std::string const &data);

        static std::string decrypt(std::string const &iv, 
                                   std::string const &data);

        static std::string iv();        // return an initialization vector

                                        // return the 16-byte MD5 hash
        static std::string md5hash(std::string const &text);
                                        // lowest 8 bytes of md5hash
        static uint64_t md5hash8(std::string const &text);

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

                                                        // 3.f
        static bool write(std::ostream &out, std::string const &str);
                          
        static Uint32 tellg(std::istream &stream);  

        static bool exists(std::string const &fname);   // true: exists

            // files must exist. If not -1 (~0UL) is returned
        static uint64_t size(std::istream &stream);     // 1.f
        static uint64_t size(std::ostream &stream);     // 2.f
        static uint64_t size(std::fstream &stream);     // 3.f

    private:
        static std::string key();
};

#include "as.f"
#include "md5hash8.f"
#include "exists.f"

#include "read1.f"
#include "read2.f"

#include "write1.f"
#include "write2.f"
#include "write3.f"

#include "tellg.f"

#include "size1.f"
#include "size2.f"
#include "size3.f"

#endif
