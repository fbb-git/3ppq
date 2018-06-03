#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <iomanip>

using namespace std;

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        cout << "First argument: factor weights file,\n"
                "Second argument: question answers\n";
        return 0;
    }

    ifstream weights{ argv[1] };
    ifstream scores{ argv[2] };

    vector<double> fweights;
    copy(istream_iterator<double>(weights), istream_iterator<double>(),
         back_inserter(fweights));

    vector<double> ratings;
    copy(istream_iterator<double>(scores), istream_iterator<double>(),
         back_inserter(ratings));

    for (double value: fweights)
        cout << setw(8) << value;
    cout << '\n';

    for (double value: ratings)
        cout << setw(8) << value;
    cout << '\n';

    double value, sum = 0;
    for (size_t idx = 0; idx != 42; ++idx)
    {
        value = ratings[idx] * fweights[idx];
        sum += value;
        cout << idx << ' ' << 
            ratings[idx] << " * " << fweights[idx] << 
            " = " << value << ", sum = " << sum << '\n';
    }

    cout << "N weights: " << fweights.size() << "\n"
            "N scores:  " << ratings.size() << "\n"
            "inner product: " <<
            inner_product(fweights.begin(), fweights.end(), 
                          ratings.begin(), 0.0) << '\n';

}




