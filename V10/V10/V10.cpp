#include "stdio.h"
#include "conio.h"

int main()
{
    double x = 0.45, b, a;

    __asm {
        fld1
        fadd st(0), st(0)
        fld x
        fld st(0)
        fadd st(0), st(2)
        fcos
        fmul st(0), st(0)
        fmul st(0), st(2)
        fadd st(0), st(2)

        fld st(1)
        fsin
        fmul st(0), st(0)
        fadd st(0), st(3)
        fxch st(2)
        fmul st(0), st(0)
        fld st(0)
        fmul st(0), st(0)
        fptan
        fxch st(4)
        fdivp st(1), st(0)
        fdivp st(2), st(0)

        fxch st(2)
        faddp st(2), st(0)
        fxch st(1)
        fsin
        fsqrt
        fmulp st(2), st(0)
        faddp st(1), st(0)

        fstp b
        ffree st(0)

        // вычисление а
        fld1
        fld x
        fld st(0)
        fmul st(0), st(0)
        fadd st(0), st(2)
        fsqrt
        fld st(0)
        fsin
        fmul st(0), st(2)
        f2xm1
        
        fxch st(2)
        fsincos
        fmul st(0), st(1)
        fxch st(1)
        fxch st(2)
        fyl2x
        fdivp st(2), st(0)
        fstp st(0)
        
        fld x
        f2xm1
        fxch st(2)
        faddp st(2), st(0)
        fxch st(1)
        fsqrt
        fld1
        fpatan
        faddp st(1), st(0)

        fstp a
    }

    printf("\t b = %g\n", b);
    printf("\n\t a = %g\n", a);
    printf("\n\t Press key...");
    _getch();
    return 0;
}

