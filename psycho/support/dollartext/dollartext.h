#ifndef INCLUDED_DOLLARTEXT_
#define INCLUDED_DOLLARTEXT_

#include "../types/types.h"

    // replace \$\d+ patterns by element \d+ of the StringVector d_str

class DollarText
{
    StrVector d_dollarText;

    public:
        void operator+=(std::string const &text);   // inline:
                                                    //  add replacement text

        std::string replace(std::string const &path);   // convert, and clear.

                                                        // convert, and 
                                                        // move d_dollarText
                                                        // to dest
        std::string replace(StrVector &dest, std::string const &path);   
        void useReplacements(StrVector &src);           // inline src is moved

        std::string const &replaceDollars(std::string &line) const;

        void clear();                               // inline

        bool empty() const;                         // inline

    private:
        std::string replacePath(std::string const &path);
};

inline void DollarText::useReplacements(StrVector &src) // src is moved
{
    d_dollarText = move(src);
}

inline bool DollarText::empty() const
{
    return d_dollarText.empty();
}

inline void DollarText::clear()
{
    d_dollarText.clear();
}

inline void DollarText::operator+=(std::string const &text)
{
    d_dollarText.push_back(text);
}


        
#endif
