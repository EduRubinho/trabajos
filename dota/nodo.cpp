#include <bits/stdc++.h>
using namespace std;

struct nodo
{
    int dato;
    nodo *sig;
};

nodo *insertar(nodo *);
void leer(nodo *);
nodo *invertir(nodo *);

int main()
{
    nodo *p = NULL;
    bool op=1;
    while(op==1)
    {
        cout<<"Inserta el dato: ";
        p=insertar(p);
        leer(p);
        cout<<"Otra ves? 1 o 0";
        cin>>op;
    }
    p = invertir(p);
    leer(p);
    

    return 0;
}

nodo *insertar(nodo *p)
{
    nodo *q;
    q = new (nodo);
    cin >> q->dato;
    q->sig = p;
    p = q;
    return p;
}

void leer(nodo *p)
{
    nodo *q;
    q = p;
    if (p != NULL)
    {
        while (q != NULL)
        {
            cout << q->dato << endl;
            q = q->sig;
        }
    }
    else
    {
        cout << "NO HAY NADA DE DATOS";
    }
}

nodo *invertir(nodo *p)
{
    nodo *a = NULL;//previo
    nodo *b = p;//actu
    nodo *c = NULL;//sig

    while (b != NULL)
    {
        c = b->sig; // Guarda el siguiente nodo
        b->sig = a; // Invierte el puntero
        a = b;      // Mueve a a b
        b = c;      // Mueve b al siguiente nodo
    }

    p=a;

    return p; // a será el nuevo cabeza de la lista invertida
}

/*
nodo *invertir(nodo *p)
{
    nodo *a[2];
    int cen=0;
    int i=0;
    while (p!=NULL and cen==0)
    {
        a[i]=p;
        i++;
        p=p->sig;
        if(i==2)
        {
            cen==1;
        }

    }
    while (p->sig!=NULL)
    {
        p=p->sig;
    }
    int pan=0;
    a[0]->sig=NULL;
    int j=0;
    while(pan==0)
    {
        a[j+1]->sig=a[j];
        a[j]=a[j+2]->sig;
        a[j+2]->sig=a[j+1];
        a[j+1]=a[j]->sig;
        a[j]->sig=a[j+2];
        a[j+2]=a[j+1]->sig;
        
        if((a[0]==NULL)or(a[1]==NULL)or (a[2]==NULL))
        {
            pan=1;
        }
    }
    
}
*/
