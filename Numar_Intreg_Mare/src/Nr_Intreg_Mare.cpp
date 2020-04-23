#include "Nr_Intreg_Mare.h"
#include<iostream>

numar_intreg_mare::numar_intreg_mare()
{
    this->semn='+';
    nrc=0;
    this->prim=NULL;
    this->ultim=NULL;
    std::cout<<"crearea numarului intreg vid\n";
}
numar_intreg_mare::~numar_intreg_mare()
{
    v *temp;
    this->semn='+';
    this->nrc=0;
    while(prim!=NULL)
    {
        temp=prim->next;
        delete prim;
        prim=temp;
        if(prim==NULL)
            ultim=NULL;
        else
            prim->prev=NULL;
    }
    std::cout<<"distruge numarului\n";
}
numar_intreg_mare::numar_intreg_mare(const numar_intreg_mare &other)
{
    this->semn=other.semn;
    this->nrc=other.nrc;
    this->prim=other.prim;
    this->ultim=other.ultim;
    std::cout<<"copierea numarului\n";
}

std::ostream& operator <<(std::ostream& outs,numar_intreg_mare& x)
{
    if(x.nrc==0)
    {
    outs<<0<<" "<<x.semn<<" Numar Vid\n";
    }
    else{
        if(x.nrc<0)
            {
                outs<<x.nrc<<" "<<x.semn<<" Numarul de cifre negativ\n";
                v *temp=x.getPrim();
            while(temp!=NULL)
            {
                outs<<temp->c;
                temp=temp->next;
            }
            outs<<'\n';
            }
        else
        {
            outs<<x.nrc<<" "<<x.semn;
            v *temp=x.getPrim();
            while(temp!=NULL)
            {
                outs<<temp->c;
                temp=temp->next;
            }
            outs<<'\n';
        }
    }
	return outs;
}

std::istream& operator>>(std::istream& in, numar_intreg_mare& x){
    int nrc;
    bool ok;
    int k=0;
    in>>nrc;
    if(nrc>0)
    {
        ok=1;
        char c;
        int i;
        std::cin>>c;
        if(c=='+')
            x.semn='+';
        else if(c=='-')
            x.semn='-';
        std::cin>>c;
        ++k;
        if(c>='1' && c<='9')
            x.push_right((c-'0'));
        else
        {
        ok=0;
        while(!(c>='1' && c<='9'))
        {
            std::cin>>c;
            ++k;
        }
        x.push_right((c-'0'));
        }
        for(i=k+1;i<=nrc;++i)
        {
            std::cin>>c;
            if(c>='0' && c<='9')
                x.push_right((c-'0'));
        }
    }
    else std::cout<<"Eroare! Numarul de cifre introdus este negativ!\n";
    return in;
}

numar_intreg_mare numar_intreg_mare::operator+(const numar_intreg_mare &A){
v *temp1,*temp2;
numar_intreg_mare AUX;
int c,rest;
temp1=this->ultim;
temp2=A.ultim;
rest=0;
if(this->semn==A.semn)
{
    AUX.semn=A.semn;
    while(temp1!=NULL && temp2!=NULL)
    {
        c=temp1->c+temp2->c+rest;
        std::cout<<c<<" ";
        rest=0;
        if(c<10)
            AUX.push_left(c);
        else
        {
            AUX.push_left((c%10));
            rest=1;
        }
        temp1=temp1->prev;
        temp2=temp2->prev;
    }
    while(temp1!=NULL)
    {
        c=temp1->c+rest;
        rest=0;
        if(c<10)
            AUX.push_left(c);
        else
        {
            AUX.push_left((c%10));
            rest=c/10;
        }
        temp1=temp1->prev;
    }
    while(temp2!=NULL)
    {
        c=temp2->c+rest;
        rest=0;
        if(c<10)
            AUX.push_left(c);
        else
        {
            AUX.push_left((c%10));
            rest=c/10;
        }
        temp2=temp2->prev;
    }
    if(rest>0)
        AUX.push_left(rest);
    return AUX;
}
else if(A.semn=='-')
{
v *temp1,*temp2;
numar_intreg_mare AUX;
int c,rest;
temp1=this->ultim;
temp2=A.ultim;
if(this->nrc<A.nrc)
    return AUX;
rest=0;
while(temp1!=NULL && temp2!=NULL)
{
    c=temp1->c-temp2->c-rest;
    std::cout<<c<<" ";
    rest=0;
    if(c>-1  && c<10)
        AUX.push_left(c);
    else
    {
        AUX.push_left(10+c);
        rest=1;
    }
    temp1=temp1->prev;
    temp2=temp2->prev;
}
while(temp1!=NULL)
{
    c=temp1->c-rest;
    rest=0;
    if(c>-1 && c<10)
        AUX.push_left(c);
    else
    {
        AUX.push_left(10+c);
        rest=1;
    }
    temp1=temp1->prev;
}
while(temp2!=NULL)
{
    c=temp2->c-rest;
    rest=0;
    if(c>-1 && c<10)
        AUX.push_left(c);
    else
    {
        AUX.push_left(10+c);
        rest=1;
    }
    temp2=temp2->prev;
}
if(rest>0)
    AUX.nrc=0;
return AUX;
}
else if(this->semn=='-')
{
v *temp1,*temp2;
numar_intreg_mare AUX;
AUX.semn='-';
int c,rest;
temp1=this->ultim;
temp2=A.ultim;
if(this->nrc<A.nrc)
    return AUX;
rest=0;
while(temp1!=NULL && temp2!=NULL)
{
    c=temp1->c-temp2->c-rest;
    std::cout<<c<<" ";
    rest=0;
    if(c>-1  && c<10)
        AUX.push_left(c);
    else
    {
        AUX.push_left(10+c);
        rest=1;
    }
    temp1=temp1->prev;
    temp2=temp2->prev;
}
while(temp1!=NULL)
{
    c=temp1->c-rest;
    rest=0;
    if(c>-1 && c<10)
        AUX.push_left(c);
    else
    {
        AUX.push_left(10+c);
        rest=1;
    }
    temp1=temp1->prev;
}
while(temp2!=NULL)

{
    c=temp2->c-rest;
    rest=0;
    if(c>-1 && c<10)
        AUX.push_left(c);
    else
    {
        AUX.push_left(10+c);
        rest=1;
    }
    temp2=temp2->prev;
}
if(rest>0)
    AUX.nrc=0;
return AUX;
}
}
/*
numar_natural_mare numar_natural_mare::operator-(const numar_natural_mare &A){
v *temp1,*temp2;
numar_natural_mare AUX;
int c,rest;
temp1=this->ultim;
temp2=A.ultim;
if(this->nrc<A.nrc)
    return AUX;
rest=0;
while(temp1!=NULL && temp2!=NULL)
{
    c=temp1->c-temp2->c-rest;
    std::cout<<c<<" ";
    rest=0;
    if(c>-1  && c<10)
        AUX.push_left(c);
    else
    {
        AUX.push_left(10+c);
        rest=1;
    }
    temp1=temp1->prev;
    temp2=temp2->prev;
}
while(temp1!=NULL)
{
    c=temp1->c-rest;
    rest=0;
    if(c>-1 && c<10)
        AUX.push_left(c);
    else
    {
        AUX.push_left(10+c);
        rest=1;
    }
    temp1=temp1->prev;
}
while(temp2!=NULL)
{
    c=temp2->c-rest;
    rest=0;
    if(c>-1 && c<10)
        AUX.push_left(c);
    else
    {
        AUX.push_left(10+c);
        rest=1;
    }
    temp2=temp2->prev;
}
if(rest>0)
    AUX.nrc=0;
return AUX;
}
*/
