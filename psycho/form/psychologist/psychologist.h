#ifndef INCLUDED_PSYCHOLOGIST_
#define INCLUDED_PSYCHOLOGIST_

#include <iosfwd>
#include <unordered_map>

#include "../../library/datastore/datastore.h"

namespace FBB
{
    class CGI;
};

class Psychologist
{
    typedef std::unordered_map<std::string, void (Psychologist::*)()> Map;

    // when these records change after the system's been used then
    // a convertor is required, converting the old data structure to the new
    // then add the required new fields, and recompile
    struct Private
    {
        uint64_t    nip;
        bool        gender;         // 0: female, 1: male
        std::string name;           // w/o \n: add #string fields to the
                                    //         record's length
        std::string lastName;
        std::string email;
    };

    enum Record
    {
        uint16_t    nr;             // identification number
        std::string pwdHash;        // MD5 hash of the password
        uint16_t    size;           // size of the record
    };
        
    static Map s_state;         // maps state names to handling functions

    std::string d_path;
    FBB::CGI &d_cgi;
    DataStore d_psychData;      // psychologists' data

    StrVector d_fields;         // TMP (?)

    public:
        Psychologist(FBB::CGI &cgi);
        void process();

    private:
        bool readFields(std::istream &in);

        void add();
        void alreadyRegistered();
        void newRegistration();

        void newPsych();

        uint16_t identNr() const;
        static bool acceptNr(istream &nrs, uint16_t idNr);
        static std::stringstream toString(Private const &private);
};
        

#endif
