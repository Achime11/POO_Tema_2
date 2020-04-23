#pragma once
#include "InvalidFirstDigit.h"
#include <iostream>
struct v{
    int c;
    v *prev,*next;};
class numar_natural_mare
{
    protected:
        int nrc;
        v *prim,*ultim;
    public:
        numar_natural_mare();
        virtual ~numar_natural_mare();
        numar_natural_mare(const numar_natural_mare&);
        virtual void afisare();
        void push_right(int x);
        void push_left(int x);
        v *getPrim();
        void setPrim(v *prim);
        void setUltim(v *ultim);
        friend std::ostream& operator <<(std::ostream& outs,numar_natural_mare& x);
        friend std::istream& operator>>(std::istream& in, numar_natural_mare& x);
        numar_natural_mare operator+(const numar_natural_mare&);
        numar_natural_mare operator-(const numar_natural_mare&);

};
