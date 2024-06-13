#include <bits/stdc++.h>
using namespace std;

#define MAX 10

void insertar(int *, int &, int);
void eliminar(int *, int &);
void mostrar(int *, int);

int main()
{
    int tope = -1;
    int pila[MAX];
    int op;

    do
    {
        cout << "Menu de opciones\n";
        cout << "1. Insertar\n";
        cout << "2. Eliminar\n";
        cout << "3. Mostrar\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> op;

        switch (op)
        {
        case 1:
            insertar(pila, tope, MAX);
            break;
        case 2:
            eliminar(pila, tope);
            break;
        case 3:
            mostrar(pila, tope);
            break;
        case 0:
            cout << "Saliendo...\n";
            break;
        default:
            cout << "Opcion no valida\n";
        }

    } while (op != 0);

    return 0;
}

void insertar(int *pila, int &tope, int max)
{
    int dato;
    cout << "Dato: ";
    cin >> dato;
    if (tope < max - 1)
    {
        tope++;
        pila[tope] = dato;
        cout << "Elemento insertado\n";
    }
    else
    {
        cout << "Pila llena\n";
    }
}

void eliminar(int *pila, int &tope)
{
    if (tope >= 0)
    {
        cout << "Elemento eliminado: " << pila[tope] << "\n";
        tope--;
    }
    else
    {
        cout << "Pila vacia\n";
    }
}

void mostrar(int *pila, int tope)
{
    if (tope >= 0)
    {
        cout << "Elementos en la pila:\n";
        for (int i = tope; i >= 0; i--)
        {
            cout << pila[i] << "\n";
        }
    }
    else
    {
        cout << "Pila vacia\n";
    }
}
