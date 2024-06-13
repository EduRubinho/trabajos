#include <bits/stdc++.h>
#define MAX 10
using namespace std;

void insertar_o(int *, int &, int, int);
int busca_o(int *, int, int);

void insertar_ad_o(int *, int &, int, int, int);
void insertar_dd_o(int *, int &, int, int, int);
void elimina_ad_o(int *, int &, int);
void elimina_dd(int *, int &, int);

void leer(int *, int &);

int main()
{
    int x[MAX];
    int op;
    int n = 0;
    int dato;
    int ref;
    do
    {
        system("cls");
        cout << "---M E N U---" << endl;
        cout << " ARREGLO ORDENADOS" << endl;
        cout << "1. Insertar dato nomas: " << endl;
        cout << "2. Insertar dato antes de REF: " << endl;
        cout << "3. Insertar dato despues de REF: " << endl;
        cout << "4. Eliminar dato antes de REF: " << endl;
        cout << "5. Eliminar dato despues de REF: " << endl;

        cout << "9. LEER" << endl;
        cout << "10. SALIR" << endl;
        cout << "Ingrese la opcion;" << endl;
        cin >> op;
        switch (op)
        {
        case 1:
            system("cls");
            cout << "Ingrese el dato: ";
            cin >> dato;
            insertar_o(x, n, dato, MAX);
            system("pause");
            break;
        case 2:
            system("cls");
            cout << "Ingrese el dato referencial";
            cin >> ref;
            cout << "Ingrese el dato a ingresar: ";
            cin >> dato;
            insertar_ad_o(x, n, dato, ref, MAX);
            system("pause");
            break;
        case 3:
            system("cls");

            cout << "Ingrese el dato referencial";
            cin >> ref;
            cout << "Ingrese el dato a ingresar: ";
            cin >> dato;
            insertar_dd_o(x, n, dato, ref, MAX);
            system("pause");
            break;
        case 4:
            system("cls");
            cout << "Ingrese el dato de referencia para eliminar el anterio: ";
            cin >> ref;
            elimina_ad_o(x, n, ref);
            system("pause");
            break;
        case 5:
            system("cls");
            cout << "Ingrese el dato de referencia para eliminar el posterior: ";
            cin >> ref;
            // elimina_dd(x, n, ref);
            system("pause");
            break;
        case 9:
            system("cls");
            leer(x, n);
            system("pause");
            break;
        default:
            break;
        }

    } while (op != 10);

    return 0;
}

void elimina_ad_o(int *x, int &n, int ref)
{
    if (n < 0)
    {
        cout << "El arreglo esta vacio";
    }
    else
    {

        int pos = busca_o(x, n, ref);
        for (int i = pos; i < n; i++)
        {
            x[i-1]=x[i];
        }
        cout<<"Se elimino correctamente el dato";
        n--;
    }
}

void insertar_ad_o(int *x, int &n, int dato, int ref, int max)
{
    if (n < max)
    {
        if (dato > ref)
        {
            cout << "No se puede ingresar por que desordenaria el arreglo";
        }
        else
        {
            insertar_o(x, n, dato, max);
            cout << "Se inserto antes sin embargo no desordeno el array";
        }
    }
    else
    {
        cout << "El arreglo esta lleno no se ingreso por desborde";
    }
}

void insertar_dd_o(int *x, int &n, int dato, int ref, int max)
{
    if (n < max)
    {
        if (dato < ref)
        {
            cout << "No se puede ingresar por que desordenaria el arreglo";
        }
        else
        {
            insertar_o(x, n, dato, max);
            cout << "Se inserto despues sin embargo no desordeno el array";
        }
    }
    else
    {
        cout << "El arreglo esta lleno no se ingreso por desborde";
    }
}

void insertar_o(int *x, int &n, int dato, int max)
{

    if (n < max)
    {
        int pos = busca_o(x, n, dato);

        pos = abs(pos);
        for (int i = n; i > pos; i--)
        {
            x[i] = x[i - 1];
        }

        x[pos] = dato;
        n++;
    }
    else
    {
        cout << "arreglo lleno";
    }
}

void leer(int *x, int &n)
{

    for (int i = 0; i < n; i++)
    {
        cout << x[i] << endl;
    }
}
int busca_o(int *x, int n, int dato)
{
    int i = 0;
    int pos;
    while (i < n and x[i] < dato)
    {
        i++;
    }
    if (i >= n or x[i] > dato)
    {
        pos = -i;
    }
    else
    {
        pos = i;
    }
    return pos;
}