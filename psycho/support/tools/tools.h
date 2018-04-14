#ifndef INCLUDED_TOOLS_
#define INCLUDED_TOOLS_

#include <unistd.h>

#include <iosfwd>
#include <fstream>

#include "../types/types.h"
#include "../global/global.h"

namespace FBB
{
    class CGI;
}

class Tools
{
    enum { BUFSIZE = 5000 };

    public:
        enum 
        {
            LOG_DEBUG = 0,
            LOG_STD = 10,
            LOG_OFF,
            N_OTHER = 3,            // assuming 1 x self, 1 x meta rating
            IV_SIZE = 8,
            KEY_SIZE = 16,
            HASH_SIZE = 16,
            N_QUESTIONS = 42,
            MAX_PSYCH_FIELD = 16,
        };
    
        template <typename Type>
        static Type *as(size_t *skip, std::string const &str);

        static void setLogLevel();  
        static std::ostream &debug();       // debug emessage 
        static std::ostream &stdLog();      // std log message

        static void delay();

        static bool checkParam(FBB::CGI &cgi, char const *param);

        static long long valueOr(std::string const &value, int fallback);

        static std::string passParam(FBB::CGI &cgi, char const *name);
        static std::string passParam(char const *name, 
                                     std::string const &value);

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

                                        // next random nr from uniform 
                                        // int distribution [first .. last]
        static size_t random(int first, int last);  

        static void lock(int fd, std::string const &path);
        static int unlock(int fd);      // returns -1

        static Uint16 htmlTextSize(StrVector const &htmlTexts);

        static bool copy(std::ostream &out, std::istream &in, 
                                            Uint32 begin, Uint32 end);

                    // read members return number of `Type' elements read.
        template <typename Type>                       // 1.f
        static size_t read(std::istream &in, Uint32 offset,
                         Type *dest, size_t size = sizeof(Type));

        template <typename Type>                       // 2.f
        static size_t read(std::istream &in, 
                         Type *dest, size_t size = sizeof(Type));

        template <typename Type>                       // 1.f
        static size_t readN(std::istream &in, Uint32 offset,
                         Type *dest, size_t nToRead = 1);

        template <typename Type>                       // 2.f
        static size_t readN(std::istream &in, 
                         Type *dest, size_t nToRead = 1);


        template<typename Type>                        // 1.f
        static bool write(std::ostream &out, Uint32 offset, 
                        Type const *src, size_t size = sizeof(Type));

        template<typename Type>                        // 2.f
        static bool write(std::ostream &out, 
                        Type const *src, size_t size = sizeof(Type));

                                                        // 3.f
        static bool write(std::ostream &out, std::string const &str);

        template<typename Type>                        // 1.f
        static bool writeN(std::ostream &out, Uint32 offset, 
                        Type const *src, size_t nToWrite = 1);

        template<typename Type>                        // 2.f
        static bool writeN(std::ostream &out, 
                        Type const *src, size_t nToWrite = 1);

                          
        static Uint32 tellg(std::istream &stream);  

        static bool exists(std::string const &fname);   // true: exists

            // files must exist. If not -1 (~0UL) is returned
        static uint64_t size(std::istream &stream);     // 1.f
        static uint64_t size(std::ostream &stream);     // 2.f
        static uint64_t size(std::fstream &stream);     // 3.f

        static void rename(std::string const &oldName, 
                           std::string const &newName);
    private:
        static std::string key();
};

#include "as.f"
#include "md5hash8.f"
#include "exists.f"

#include "read1.f"
#include "read2.f"

#include "readn1.f"
#include "readn2.f"

#include "write1.f"
#include "write2.f"
#include "write3.f"

#include "writen1.f"
#include "writen2.f"

#include "tellg.f"

#include "size1.f"
#include "size2.f"
#include "size3.f"

#include "debug.f"
#include "stdlog.f"

#endif
