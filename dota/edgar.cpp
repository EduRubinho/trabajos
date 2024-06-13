#include<iostream>
#include<string.h>
#include<cstring>
#define max 5
using namespace std;

struct libro{
    char codi[10];
    float precio;
};

void Primera_Parte(libro x[], int m)
{
    int n=0;
    char op;
    int i=1;
    do
    {
        float auxP;
        char auxC[10];
        n++;
        cout<<"Ingrese el precio: ";
        cin>>auxP;
        cout<<"Ingrese el codigo";
        cin>>auxC;
        if(n==1)
        {
            strcpy(x[n].codi,auxC);
            x[n].precio=auxP;
        }
        else{
            while(i<=n-1 && (strcmp(x[i].codi, auxC)<1))
            {
                i++;
            }
            for(int j=n;j>i+1;j--)
            {
                x[j]=x[j-1];
            }
            strcpy(x[i].codi, auxC);
            x[i].precio=auxP;
        }
        cout<<"Desea agregar mas datos?";
        cin>>op;

    } while (op=='s' && n<max);

    if(op=='s')
    {
        cout<<"Arreglo lleno"<<endl;
    }
}

int main()
{
    libro array[max];
        int m=max;
    Primera_Parte(array, max);
    return 0;
}