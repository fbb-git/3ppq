#ifndef INCLUDED_RATINGS_
#define INCLUDED_RATINGS_

#include <string>
#include <vector>

#include "../values/values.h"

class Ratings: public Values
{
    std::string d_psychID;
    std::string d_clientIdent;
    std::vector< std::vector<double> > d_data;

    public:
        Ratings(char const *filename);
        std::vector< std::vector<double> > const &data() const;

        std::string const &clientIdent() const;
        std::string const &psychID() const;

    private:
        void cleanup(std::vector< std::vector<std::string> > const &data);
};

inline std::string const &Ratings::psychID() const
{
    return d_psychID;
}

inline std::string const &Ratings::clientIdent() const
{
    return d_clientIdent;
}

inline std::vector< std::vector<double> > const &Ratings::data() const
{
    return d_data;
}
        
#endif
