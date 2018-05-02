#ifndef INCLUDED_DATAFILES_
#define INCLUDED_DATAFILES_

#include "../../support/types/types.h"

#include "../values/values.h"

class DataFiles: public Values
{
    Dvector2 d_fscores;

    public:
        DataFiles(Dvector2 &&fscores);

        void scoresTable(char const *path) const;
        void gnuplot(char const *path) const;
};
        
#endif
