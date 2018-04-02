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

    struct Record
    {
        uint16_t    nr;             // identification number
        std::string pwdHash;        // MD5 hash of the password (16 bytes)
    };
        
    static Map s_state;         // maps state names to handling functions

    std::string d_path;
    FBB::CGI &d_cgi;
    DataStore d_psychData;      // psychologists' data

    public:
        Psychologist(FBB::CGI &cgi);
        void process();

    private:
        void add();
        void alreadyRegistered();
        void newRegistration();

        void newPsych();

        uint16_t identNr() const;
        uint64_t nipKey() const;    // get key from cgi.param1("nip")

        static bool acceptNr(std::istream &nrs, uint16_t idNr);
        static std::stringstream toString(Private const &priv);
        static std::string toString(Record const &rec);

        size_t getRecord(Record *record, std::string const &data, 
                                        size_t offset);
        void getPrivate(Private *priv, std::string const &data, 
                                        size_t offset);
};
        

#endif


