#include <bits/stdc++.h>
using namespace std;

struct nodo
{
    int nro;
    int grado;
    nodo *sig;
};
void entre(nodo *&, nodo *&);
nodo *inserta_pol(nodo *);
void leer(nodo *);
nodo *sumar_nodo(nodo *, nodo *);
nodo *restar_nodo(nodo *, nodo *);
nodo *derivar(nodo *);
nodo *repetido(nodo *);
nodo *multiplicacion(nodo *, nodo *);

nodo *crear_nodo(int coeficiente, int exponente)
{
    nodo *nuevo = new (nodo);
    nuevo->nro = coeficiente;
    nuevo->grado = exponente;
    nuevo->sig = NULL;
    return nuevo;
}

int main()
{
    nodo *p = NULL;
    nodo *q = NULL;
    nodo *suma = NULL;
    nodo *resta = NULL;
    int opc;
    nodo *x = NULL;

    do
    {
        system("cls");
        cout << " 1. insertar nodo en p: " << endl;
        cout << " 2. Insertar nodo en q:" << endl;
        cout << " 3. Leer p" << endl;
        cout << " 4. Leer q" << endl;
        cout << " 5. SUMAR" << endl;
        cout << " 6. RESTAR" << endl;
        cout << "7. DERIVAR" << endl;
        cout << " 8. limpiar P: ";
        cout << " 9. limpiar Q: ";
        cout << "10. MUltiplicar" << endl;
        cout << "11. entrelazar" << endl;
        cout << "12 ELIMINAR DATOS REPETIDOS" << endl;
        cout << "LEER OPC: " << endl;
        cin >> opc;

        switch (opc)
        {
        case 1:
            p = inserta_pol(p);
            break;
        case 2:
            q = inserta_pol(q);
            break;
        case 3:
            system("cls");
            leer(p);
            system("pause");
            break;
        case 4:
            system("cls");
            leer(q);
            system("pause");
            break;
        case 5:
            system("cls");
            suma = sumar_nodo(p, q);
            leer(suma);
            system("pause");
            break;
        case 6:
            system("cls");
            resta = restar_nodo(p, q);
            leer(resta);
            system("pause");
            break;
        case 7:
            system("cls");
            nodo *der;
            der = derivar(p);
            leer(der);
            system("pause");
            break;
        case 8:
            p = NULL;
            break;
        case 9:
            q = NULL;
            break;
        case 10:
            system("cls");
            x = multiplicacion(p, q);
            leer(x);
            system("pause");
            break;
        case 11:
            system("cls");
            entre(p, q);
            leer(p);
            leer(q);
            system("pause");
            break;
        case 12:
            system("cls");
            x=repetido(p);
            leer(x);
            system("pause");
            break;
        default:
            cout << "Opc no valida";
            break;
        }
    } while (opc != 0);

    return 0;
}
nodo* repetido(nodo* p) {
    nodo* r = p; // Nodo de referencia para recorrer la lista
    nodo* s;     // Nodo auxiliar para recorrer y comparar con r
    nodo* x;     // Nodo auxiliar para mantener la referencia del nodo anterior

    while (r != NULL && r->sig != NULL) {
        s = r; // s comienza desde r en cada iteración de r

        while (s->sig != NULL) {
            if (r->nro == s->sig->nro) {
                // Si encontramos un nodo duplicado después de s
                nodo* nodoDuplicado = s->sig;
                s->sig = s->sig->sig; // Saltamos el nodo duplicado
                delete nodoDuplicado; // Liberamos memoria del nodo duplicado
            } else {
                s = s->sig; // Avanzamos s al siguiente nodo
            }
        }
        r = r->sig; // Avanzamos r al siguiente nodo
    }

    return p; // Devolvemos el puntero al inicio de la lista actualizada
}


void entre(nodo *&p, nodo *&q)
{
    nodo *a, *b, *x, *y;
    a = p;
    b = q;
    x = a->sig;
    y = b->sig;

    p = q;
    q = a;
    while (x != NULL and y != NULL)
    {
        a->sig = y;
        b->sig = x;
        a = x;
        b = y;
        x = x->sig;
        y = y->sig;
    }
}
nodo *derivar(nodo *p)
{
    nodo *res = NULL;    // el que mandamos a retornar gaa
    nodo *t = NULL;      // para recorrer la lista
    nodo *x = NULL;      // para almacenar nodo
    t = p;               // copia de nodo
    nodo *ultimo = NULL; // almacena ultimno nodo

    while (t != NULL)
    {
        int coe;
        int gra;
        coe = t->grado * t->nro;
        gra = t->grado - 1;
        nodo *x = crear_nodo(coe, gra);
        if (res == NULL)
        {
            res = x;
            ultimo = x;
        }
        else
        {
            ultimo->sig = x;
            ultimo = ultimo->sig;
        }

        t = t->sig;
    }

    return res;
}

nodo *inserta_pol(nodo *p)
{
    nodo *s;
    nodo *r;
    r = p;
    s = new (nodo);
    cout << "Numero: ";
    cin >> s->nro;
    cout << "Grado: ";
    cin >> s->grado;
    s->sig = NULL;
    if (p == NULL)
    {
        p = s;
    }
    else
    {

        while (r->sig != NULL)
        {
            r = r->sig;
        }
        r->sig = s;
    }

    return p;
}

void leer(nodo *p)
{
    nodo *s;
    s = p;
    cout << "nodo: " << endl;
    while (s != NULL)
    {
        cout << s->nro << "x^" << s->grado << " ";
        s = s->sig;
    }

    cout << endl;
}

nodo *sumar_nodo(nodo *p, nodo *q)
{
    nodo *a, *b;
    a = p;
    b = q;
    nodo *h = NULL;      // lista retornada
    nodo *x = NULL;      // almacenar struct
    nodo *ultimo = NULL; // para la inserccion al ultimo

    while (a != NULL || b != NULL)
    {
        if (a != NULL && b != NULL && a->grado == b->grado)
        {
            int aux = a->nro + b->nro;
            if (aux != 0)
            {
                x = crear_nodo(aux, a->grado);
            }
            a = a->sig;
            b = b->sig;
        }
        else if (b == NULL || (a != NULL && a->grado > b->grado))
        {
            x = crear_nodo(a->nro, a->grado);
            a = a->sig;
        }
        else
        {
            x = crear_nodo(b->nro, b->grado);
            b = b->sig;
        }

        if (x != NULL)
        {
            if (h == NULL)
            {
                h = x;
                ultimo = h;
            }
            else
            {
                ultimo->sig = x;
                ultimo = ultimo->sig;
            }
        }
    }

    return h;
}

nodo *restar_nodo(nodo *p, nodo *q)
{
    nodo *a, *b;
    nodo *h = NULL;
    nodo *ultimo = NULL;
    nodo *x = NULL;
    a = p;
    b = q;
    while (a != NULL or b != NULL)
    {
        if (a != NULL and b != NULL and a->grado == b->grado)
        {
            int aux = a->nro - b->nro;
            if (aux != 0)
            {
                x = crear_nodo(aux, a->grado);
            }
            a = a->sig;
            b = b->sig;
        }
        else if (b == NULL || (a != NULL and a->grado > b->grado))
        {
            x = crear_nodo(a->nro, a->grado);
            a = a->sig;
        }
        else if (a == NULL || (b != NULL and a->grado < b->grado))
        {
            x = crear_nodo(b->nro, b->grado);
            b = b->sig;
        }
        if (x != NULL)
        {
            if (h == NULL)
            {
                h = x;
                ultimo = h;
            }
            else
            {
                ultimo->sig = x;
                ultimo = ultimo->sig;
            }
        }
    }

    return h;
}

nodo *multiplicacion(nodo *p, nodo *q)
{
    nodo *r, *s;
    r = p;
    s = q;
    nodo *x = NULL; // retortanr
    while (r != NULL)
    {
        s = q;
        while (s != NULL)
        {
            if (r->nro * s->nro != 0)
            {
                int aux_nro = r->nro * s->nro;
                int aux_gra = r->grado + s->grado;
                nodo *h = crear_nodo(aux_nro, aux_gra);
                nodo *aux = x;
                if (x == NULL)
                {
                    x = h;
                }
                else
                {

                    while (aux->sig != NULL)
                    {
                        aux = aux->sig;
                    }
                    aux->sig = h;
                }
            }
            s = s->sig;
        }
        r = r->sig;
    }
    return x;
}
