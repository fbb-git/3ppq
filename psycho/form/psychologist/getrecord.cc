//#include "psychologist.ih"
//
//size_t Psychologist::getRecord(Record *record, 
//                             string const &data, size_t offset)
//{
//    char const *cp = &data.front() + offset;
//
//    record->nr = *reinterpret_cast<uint16_t const *>(cp);
//    cp += sizeof(uint16_t);
//
//    record->pwdHash.assign(cp, cp + 16);
//
//    return (cp + 16) - &data.front();       // returns offset of encrypted
//                                            // section.
//}
