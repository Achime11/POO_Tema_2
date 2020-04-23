#include <iostream>
#include "Nr_Natural_Mare.h"
#include "Nr_Intreg_Mare.h"
using namespace std;
int main()
{
    int n,i,m;
    numar_natural_mare A;
    cin>>A;
    numar_natural_mare B;
    cin>>B;
    cout<<B;
    B=B+A;
    cout<<B;
    cout<<A;
    numar_natural_mare C;
    cin>>C;
    C=C-A;
    cout<<C;
    A.push_right(1);
    A.push_right(2);
    A.push_right(3);
    A.push_right(4);
    cout<<A;

    cin>>n;
    numar_natural_mare V[n];
    for(i=0;i<n;++i)
        cin>>V[i];
    for(i=0;i<n;++i)
        cout<<V[i];

    cin>>m;
    numar_intreg_mare M[m];
    for(i=0;i<m;++i)
        cin>>M[i];
    for(i=0;i<m;++i)
        cout<<M[i];
    return 0;
}
