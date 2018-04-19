#include "tools.ih"

template <typename T1, typename T2>
inline T1 Tools::min(T1 t1, T2 t2)
{
    return std::min(t1, static_cast<T1>(t2));
}
