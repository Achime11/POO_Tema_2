#include "Nr_Natural_Mare.h"
#include<iostream>
numar_natural_mare::numar_natural_mare()
{
    this->nrc=0;
    this->prim=NULL;
    this->ultim=NULL;
    std::cout<<"crearea numarului natural vid\n";
}
numar_natural_mare::~numar_natural_mare()
{
    v *temp;
    this->nrc=0;
    while(prim!=NULL)
    {
        temp=prim->next;
        prim=temp;
        if(prim==NULL)
            ultim=NULL;
        else
            prim->prev=NULL;
    }
    std::cout<<"distruge numarului natural\n";
}
numar_natural_mare::numar_natural_mare(const numar_natural_mare &other)
{
    this->prim=other.prim;
    this->ultim=other.ultim;
    std::cout<<"copierea numarului\n";
}
v *numar_natural_mare::getPrim()
{
return prim;
}
void numar_natural_mare::setPrim(v *prim)
{
    this->prim=prim;
}

void numar_natural_mare::setUltim(v *ultim)
{
this->ultim=ultim;
}
void numar_natural_mare::afisare()
{
    if(nrc==0)
    {
    std::cout<<0<<" Numar Vid\n";
    }
    else{
        if(nrc<0)
            std::cout<<"Numarul de cifre negativ\n";
        else
        {
            v *temp=prim;
            while(temp!=NULL)
            {
                std::cout<<temp->c;
                temp=temp->next;
            }
            std::cout<<'\n';
        }
    }
}
void numar_natural_mare::push_right(int x)
{
    v *temp=new v;
    temp->c=x;
    ++nrc;
    if(ultim==NULL)
    {
        temp->prev=NULL;
        temp->next=NULL;
        prim=ultim=temp;
    }
    else
    {
        temp->prev=ultim;
        temp->next=NULL;
        ultim->next=temp;
        ultim=temp;
    }

}
void numar_natural_mare::push_left(int x)
{
    v *temp=new v;
    temp->c=x;
    ++nrc;
    if(prim==NULL){
        temp->prev=NULL;
        temp->next=NULL;
        prim=ultim=temp;}
    else{
        temp->prev=NULL;
        temp->next=prim;
        prim->prev=temp;
        prim=temp;}
}
std::ostream& operator <<(std::ostream& outs,numar_natural_mare& x)
{
    if(x.nrc==0)
    {
    outs<<0<<" Numar Vid\n";
    }
    else{
        if(x.nrc<0)
            {
                outs<<x.nrc<<" Numarul de cifre negativ\n";
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
            outs<<x.nrc<<" ";
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
std::istream& operator>>(std::istream& in, numar_natural_mare& x){
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
        if(ok==0)
            throw(InvalidFirstDigit());
    }
    return in;
}
numar_natural_mare numar_natural_mare::operator+(const numar_natural_mare &A){
v *temp1,*temp2;
numar_natural_mare AUX;
int c,rest;
temp1=this->ultim;
temp2=A.ultim;
rest=0;
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
        rest=1;
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
        rest=1;
    }
    temp2=temp2->prev;
}
if(rest>0)
    AUX.push_left(rest);
return AUX;
}

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
