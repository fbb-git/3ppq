#ifndef INCLUDED_RATINGS_
#define INCLUDED_RATINGS_

#include <string>
#include <vector>

class Ratings
{
    std::string d_psychID;
    std::string d_clientIdent;
    uint32_t d_from;
    uint32_t d_until;

    std::vector< std::vector<double> > d_data;

    public:
        Ratings(char const *filename);
        std::vector< std::vector<double> > const &data() const;

        std::string const &clientIdent() const;
        std::string const &psychID() const;
        uint32_t from() const;
        uint32_t until() const;

    private:
        void cleanup(std::vector< std::vector<std::string> > const &data);
};

inline uint32_t Ratings::from() const
{
    return d_from;
}
        
inline uint32_t Ratings::until() const
{
    return d_until;
}
        
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
