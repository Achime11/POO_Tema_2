#pragma once
#include <iostream>
#include "Nr_Natural_Mare.h"

class numar_intreg_mare : public virtual numar_natural_mare
{
    protected:
        char semn;
    public:
        numar_intreg_mare();
        virtual ~numar_intreg_mare();
        numar_intreg_mare(const numar_intreg_mare&);
        friend std::ostream& operator<<(std::ostream& outs,numar_intreg_mare& x);
        friend std::istream& operator>>(std::istream& in, numar_intreg_mare& x);
        numar_intreg_mare operator+(const numar_intreg_mare&);
        numar_intreg_mare operator-(const numar_intreg_mare&);
};
