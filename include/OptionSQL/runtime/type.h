#ifndef OPTIONSQL_TYPE_H
#define OPTIONSQL_TYPE_H


#include <complex>
#include <cstdint>

namespace option
{
    using bool_ = bool; // compatible: Python bool	'?'
    using bool8 = bool; // 8 bits	 
    // Integers
    using byte = char; // compatible: C char	'b'
    using short_ = short; // compatible: C short	'h'
    using intc = int; // compatible: C int	'i'
    using int_ = int; // compatible: Python int	'l'
    using longlong = long long; // compatible: C long long	'q'
    using intp = int *; // large enough to fit a pointer	'p'
    using int8 = std::int8_t; // 8 bits	 
    using int16 = std::int16_t; // 16 bits	 
    using int32 = std::int32_t; // 32 bits	 
    using int64 = std::int64_t; // 64 bits

    //Unsigned integers:
    using ubyte = unsigned char; // compatible: C unsigned char	'B'
    using ushort = unsigned short; // compatible: C unsigned short	'H'
    using uintc = unsigned int; // compatible: C unsigned int	'I'
    using uint = unsigned int; // compatible: Python int	'L'
    using ulonglong = unsigned long long; // compatible: C long long	'Q'
    using uintp = unsigned int *; // large enough to fit a pointer	'P'
    using uint8 = std::uint8_t; // 8 bits	 
    using uint16 = std::uint16_t; // 16 bits	 
    using uint32 = std::uint32_t; // 32 bits	 
    using uint64 = std::uint64_t; // 64 bits

    //Floating-point numbers:
    //using half = ; //  	'e'
    using single = float; // compatible: C float	'f'
    using double_ = double; // compatible: C double	 
    using float_ = float; // compatible: Python float	'd'
    using longfloat = long float; // compatible: C long float	'g'
    //using float16 = ; // 16 bits	 
    using float32 = float; // 32 bits	 
    using float64 = double; // 64 bits	 
    using float96 = long double; // 96 bits, platform?	 
    using float128 = long double; // 128 bits, platform?

    //Complex floating-point numbers:
    typedef struct { float real, imag; } numcpp_complex_float;
    typedef struct { double real, imag; } numcpp_complex_double;
    typedef struct { long double real, imag; } numcpp_complex_long_double;
    //using csingle = ; //  	'F'
    using complex_ = numcpp_complex_float; // compatible: Python complex 'D'
    using clongfloat = numcpp_complex_float; // 'G'
    using complex64 = numcpp_complex_float; // two 32-bit floats	 
    using complex128 = numcpp_complex_double; // two 64-bit floats	 
    //using complex192 = ; // two 96-bit floats, platform?	 
    //using complex256 = ; // two 128-bit floats, platform?	 
}

#endif