#ifndef INCLUDED_VALUES_
#define INCLUDED_VALUES_

class Values
{
    protected:
        enum EnumValues
        {
            N_FACTORS = 6,
            N_LINES = 5,        // # lines to process
            N_PRE = 5,          // psychID, ident, type, begintime, endtime
            N_QUESTIONS = 42,
            TYPE = 2,           // field holding the data-type (1: self, etc)
            N_PERSPECTIVES = 3, // self, meta, other(average)
        };
};
        
#endif
