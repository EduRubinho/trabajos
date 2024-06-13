#include <bits/stdc++.h>
using namespace std;

struct nodo
{
    int dato;
    nodo *sig;
};

nodo *inserta_pol(nodo *);
void leer(nodo *);
void partir(nodo *, nodo *&, nodo *&);

int main()
{
    nodo *p = NULL;
    nodo *impar = NULL;
    nodo *par = NULL;
    int opc;

    do
    {
        system("cls");
        cout << " 1. insertar nodo en p: " << endl;
        cout << "2. Dividir lista" << endl;
        cout << " 3. Leer p" << endl;
        cout << " 4. Leer impar" << endl;
        cout << " 5. Leer par" << endl;
        cout << " 8. limpiar P: ";
        cout << "LEER OPC: " << endl;
        cin >> opc;

        switch (opc)
        {
        case 1:
            p = inserta_pol(p);
            break;
        case 2:
            system("cls");
            partir(p, impar, par);
            system("pause");
        case 3:
            system("cls");
            leer(p);
            system("pause");
            break;
        case 4:
            system("cls");
            leer(impar);
            system("pause");
            break;
        case 5:
            system("cls");
            leer(par);
            system("pause");
            break;
        case 8:
            p = NULL;
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

void partir(nodo *p, nodo *&impar, nodo *&par)
{
    int cont = 1;
    nodo *q = p;
    while (q != NULL)
    {
        if (cont % 2 == 0)
        {
            nodo *r; // ultimo dato
            r = impar;
            nodo *x = new (nodo);
            x->dato = q->dato;

            x->sig = NULL;
            if (impar == NULL)
            {
                impar = x;
            }
            else
            {
                while (r->sig != NULL)
                {
                    r = r->sig;
                }
                r->sig = x;
            }
        }
        else
        {
            nodo *r; // ultimo dato
            r = par;
            nodo *x = new (nodo);
            x->dato = q->dato;

            x->sig = NULL;
            if (par == NULL)
            {
                par = x;
            }
            else
            {
                while (r->sig != NULL)
                {
                    r = r->sig;
                }
                r->sig = x;
            }
        }

        cont++;
        q = q->sig;
    }
}

nodo *inserta_pol(nodo *p) {
    nodo *q = new nodo; // Crear un nuevo nodo
    std::cout << "Numero: ";
    std::cin >> q->dato; // Leer el dato para el nuevo nodo

    // Caso 1: Insertar al principio o cuando la lista está vacía
    if (p == NULL || q->dato < p->dato) {
        q->sig = p;
        return q; // q se convierte en la nueva cabeza
    }

    // Caso 2: Insertar en el medio o al final de la lista
    nodo *r = p;
    while (r->sig != NULL && r->sig->dato < q->dato) {
        r = r->sig;
    }
    q->sig = r->sig;
    r->sig = q;

    return p; // La cabeza no cambia
}

void leer(nodo *p)
{
    nodo *s;
    s = p;
    cout << "nodo: " << endl;
    while (s != NULL)
    {
        cout << s->dato;
        s = s->sig;
    }

    cout << endl;
}
