#ifndef INCLUDED_TYPES_H_
#define INCLUDED_TYPES_H_

#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <unordered_map>

typedef uint8_t     Uint8;
typedef uint16_t    Uint16;
typedef uint32_t    Uint32;
typedef uint64_t    Uint64;

typedef int32_t     Int32;
typedef int64_t     Int64;

Uint16 const maxUint16 = ~0;
Uint8  const maxUint8  = ~0;
                                                    // compiler/writer, 
                                                    // library/fileheader:
typedef std::pair<std::string, Uint16>  IDPair;
typedef std::unordered_map<std::string, Uint16> IDMap;

typedef std::unordered_map<std::string, Int32> VariableMap;

typedef std::pair<int, int>             IntPair;

typedef std::vector<Uint8>          Uint8Vector;
typedef std::vector<Uint16>         Uint16Vector;
typedef std::vector<Int32>          Int32Vector;
typedef std::vector<Uint32>         Uint32Vector;
typedef std::vector<std::string>    StrVector;

constexpr Uint8 uint8_(auto value)
{
    return static_cast<Uint8>(value);   // st. cast is needed when value is
}                                       // a strongly typed enum.

constexpr Uint16 uint16_(auto value)
{
    return value;
}

constexpr Uint32 uint32_(auto value)
{
    return value;
}

constexpr size_t size_t_(auto value)
{
    return value;
}


template <typename Type>
inline constexpr int int_(Type tp)
{
    return static_cast<int>(tp);
}

#endif




