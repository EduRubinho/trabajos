#include <bits/stdc++.h>
using namespace std;

struct nodo
{
    char codigo[20];
    nodo *sig;
    nodo *ant;
};

void insertar_i(nodo *&, nodo *&);
void insertar_f(nodo *&, nodo *&);
void leer(nodo *p);

int main()
{
    nodo *p = NULL;
    nodo *f = NULL;
    int op;

    do
    {
        cout << "Menu" << endl;
        cout << "Insertar por inicio" << endl;
        cout << "Insertar por final" << endl;

        cout << "Leer lista" << endl;
        cout << "Opcion: " << endl;
        cin >> op;
        switch (op)
        {
        case 1:
            system("cls");
            insertar_i(p, f);
            break;
        case 2:
            system("cls");
            insertar_f(p, f);
            break;
        case 9:
            leer(p);
            system("pause");
            break;
        default:
            break;
        }
    } while (op != 10);

    return 0;
}
void insertar_i(nodo *&p, nodo *&f)
{
    nodo *q = new (nodo);
    cout << "Introduza el codigo: " << endl;
    cin >> q->codigo;

    q->ant = NULL;
    q->sig = p;
    if (p == NULL)
    {
        f = q;
    }
    else
    {
        p->ant = q;
    }
    p = q;
}
void insertar_f(nodo *&p, nodo *&)
{
    
}
void leer(nodo *p)
{
    nodo *q = p;
    while (q != NULL)
    {
        cout << q->codigo << endl;
        q = q->sig;
    }
}