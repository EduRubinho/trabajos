#include <bits/stdc++.h>
using namespace std;

#define MAX 10

struct libro
{
    char codigo[20];
    float precio;
    libro *sig;
};
int buscar_o(libro *, int &, char);

void registrar(libro *, int &, int);
void leer(libro *, int &);
void pasar_lista(libro *, int &, libro *);

libro *crear_nodo(char[], float);


int main()
{
    libro *p=NULL;
    int n = 0;
    libro x[MAX];
    int op;
    do
    {
        cout << "menu"<<endl;
        cout<<"1. Registrar: "<<endl;
        cout<<"2. Leer: "<<endl;
        cout<<"3 Pasar a lista:"<<endl;
        cout<<" Opcion:"<<endl;
        cin >> op;
        switch (op)
        {
        case 1:
            registrar(x, n, MAX);
            break;
        case 2:
            leer(x, n);
            break;
        case 3:
            pasar_lista(x, n, p);
            break;

        default:
            break;
        }

    } while (op != 9);

    return 0;
}

libro *crear_nodo(char codigo[], float precio)
{
    libro *aux;
    aux = new libro;
    strcpy(aux->codigo, codigo);
    aux->precio = precio;
    return aux;
}
void pasar_lista(libro *x, int &n, libro *p)
{
    for (int i = 0; i < n; i++)
    {
        libro *aux;
        aux=crear_nodo(x[i].codigo, x[i].precio);
        if(p==NULL)
        {
            p=aux;
            aux->sig=NULL;
        }
        else
        {
            libro *r, *t;
            r=p;
            t=r;
            while(r!=NULL and r->precio<=aux->precio)
            {
                t=r;
                r=r->sig;
            }
            if(t==r)
            {
                aux->sig=p;
                p=aux;
            }
            else
            {
                aux->sig=r;
                t->sig=aux;
            }
            
        }
    }
    libro *q;
    q=p;
    while(q!=NULL)
    {
        cout<<q->codigo<<endl;
        cout<<q->precio<<endl;
        q=q->sig;
        cout<<endl;
    }
    

}


int buscar_o(libro *x, int &n, char dato[])
{
    int i = 0;
    int pos;
    while ((i < n) && (strcmp(x[i].codigo, dato) <= 0))
    {
        i++;
    }
    if (i >= n or (strcmp(x[i].codigo, dato) > 0))
    {
        pos = -i;
    }
    else
    {
        pos = i;
    }
    return pos;
}

void registrar(libro *x, int &n, int max)
{

    if (n < max)
    {
        char codi[20];
        float precio;
        cout << "Introduzca el codigo del libro: " << endl;
        cin >> codi;
        int pos = buscar_o(x, n, codi);
        cout<<pos;
        
            pos = abs(pos);
            for (int i = n; i > pos; i--)
            {
                x[i] = x[i - 1];
            }
            strcpy(x[pos].codigo, codi);
            cout << "Introduzca el precio del libro: ";
            cin >> x[pos].precio;
            n++;
            cout<<"Se inserto correctamente en la posicion: "<<pos<<endl;
        
    }
    else
    {
        cout << "El arreglo de estruc esta lleno" << endl;
    }
}

void leer(libro *x, int &n)
{
    cout << "Lista de libro agregados:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Codigo\t" << x[i].codigo<<endl;
        cout << "Precio\t" << x[i].precio;
        cout << endl;
    }
}

