#include <bits/stdc++.h>

using namespace std;

struct nodo
{
    char nombre[20];
    nodo *sig;
};

nodo *creai(nodo *);
nodo *creaf(nodo *);
void leer(nodo *);
nodo *inserta_i(nodo *);
nodo *inserta_f(nodo *);
nodo *inserta_ad(nodo *, char *);

int main()
{
    char ref[20];
    nodo *p;
    p = NULL;

    int opc;

    do
    {
        cout << "LEER OPC: ";
        cin >> opc;

        switch (opc)
        {
        case 1:
            p = NULL;
            p = creai(p);
            break;
        case 2:
            p = NULL;
            p = creaf(p);
            break;
        case 3:
            system("cls");
            leer(p);
            break;
        case 4:
            system("cls");
            p = inserta_i(p);
            break;
        case 5:
            system("cls");
            p = inserta_f(p);
            break;
        case 6:
            system("cls");
            cout << "Ingrese la referencia: ";
            cin >> ref;
            p = inserta_ad(p, ref);
            break;
        case 10:
            cout << "Saliendo...";
            break;

        default:
            cout << "Opc no valida";
            break;
        }
    } while (opc != 10);

    return 0;
}

nodo *inserta_ad(nodo *p, char *codigo)
{
    if (p != NULL)
    {
        nodo *q, *r, *s;
        int cen;
        cen = 0;

        r = p;

        while ((strcmp(r->nombre, codigo) != 0) && (cen == 0))
        {
            if (r->sig == NULL)
            {
                cen = 1;
            }
            else
            {
                s = r;
                r = r->sig;
            }
        }

        if (cen == 1)
        {
            cout << "El dato ref no existe";
        }
        else
        {
            q = new (nodo);
            cout << "Nombre: ";
            cin >> q->nombre;
            q->sig = r;
            if (p == r)
            {
                p = q;
            }
            else
            {
                s->sig = q;
            } 
        }
    }
    else
    {
        cout << "NO hay datos";
    }

    return p;
}

 

nodo *inserta_i(nodo *p)
{
    nodo *q;
    q = new (nodo);
    cout << "Nombre: ";
    cin >> q->nombre;
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
            cout << q->nombre << endl;
            q = q->sig;
        }
    }
    else
    {
        cout << "NO HAY NADA DE DATOS";
    }
}

nodo *creai(nodo *p)
{
    char op;
    nodo *q;
    do
    {
        q = new (nodo);
        cout << "Nombre: ";
        cin >> q->nombre;
        q->sig = p;
        p = q;
        cout << "Desea agregar otro S/N: ";
        cin >> op;
    } while ((op == 's') || (op == 'S'));

    return p;
}
nodo *creaf(nodo *p)
{
    char op;
    nodo *q, *r;
    do
    {
        q = new (nodo);
        cout << "Nombre: ";
        cin >> q->nombre;
        q->sig = NULL;
        r = p;
        if (p == NULL)
        {
            p = q;
        }
        else
        {
            while (r->sig != NULL)
            {
                r = r->sig;
            }
            r->sig = q;
        }
        cout << "Desea agregar otro S/N: ";
        cin >> op;

    } while (op == 's' || op == 'S');
    return p;
}