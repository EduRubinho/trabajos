#include <bits/stdc++.h>
#define MAX 2
using namespace std;

void insertar(int *, int &, int, int);
void insertar_ad(int *, int &, int, int, int);
void insertar_dd(int *, int &, int, int, int);
void elimina_ad(int *, int &, int);
void elimina_dd(int *, int &, int);

void leer(int *, int &);

int main()
{
    int x[MAX];
    int op;
    int n = -1;
    int dato;
    int ref;
    do
    {
        system("cls");
        cout << "---M E N U---" << endl;
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
            insertar(x, n, dato, MAX);
            system("pause");
            break;
        case 2:
            system("cls");
            cout << "Ingrese el dato referencial";
            cin >> ref;
            cout << "Ingrese el dato a ingresar: ";
            cin >> dato;
            insertar_ad(x, n, dato, ref, MAX);
            system("pause");
            break;
        case 3:
            system("cls");

            cout << "Ingrese el dato referencial";
            cin >> ref;
            cout << "Ingrese el dato a ingresar: ";
            cin >> dato;
            insertar_dd(x, n, dato, ref, MAX);
            system("pause");
            break;
        case 4:
            system("cls");
            cout << "Ingrese el dato de referencia para eliminar el anterio: ";
            cin >> ref;
            elimina_ad(x, n, ref);
            system("pause");
            break;
        case 5:
            system("cls");
            cout << "Ingrese el dato de referencia para eliminar el posterior: ";
            cin >> ref;
            elimina_dd(x, n, ref);
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
void elimina_dd(int *x, int &n, int ref)
{
    int i = 0;
    int cen = 0;
    if (n > -1)
    {
        if (n == 0)
        {
            cout << "No hay despues de este numero";
        }
        else
        {
            if (x[n] == ref)
            {
                cout<<"No hay despues de este numero";
            }
            else
            {
                while (i <= n)
                {
                    if (x[i] == ref)
                    {
                        for (int j = i + 1; j <= n; j++)
                        {
                            x[j] = x[j + 1];
                        }
                        n--;
                    }
                    i++;
                }
            }
            
        }
    }
    else
    {
        cout << "No hay elementos en la lista. ";
    }
}

void elimina_ad(int *x, int &n, int ref)
{
    int i = 0;
    int cen = 0;
    if (n > -1)
    {
        if (n == 0)
        {
            cout << "No hay antes de este numero";
        }
        else
        {
            while (i <= n)
            {
                if (x[i] == ref)
                {

                    for (int j = i; j <= n; j++)
                    {
                        x[j - 1] = x[j];
                    }
                    n--;
                }
                i++;
            }
        }
    }
    else
    {
        cout << "No hay elementos en la lista. ";
    }
}

void insertar(int *x, int &n, int dato, int max)
{

    if (n < max-1)
    {
        n++;
        x[n] = dato;
        cout << "Dato insertado correctamente ";
    }
    else
    {
        cout << "Arreglo lleno no se inserto: ";
    }
}
void insertar_dd(int *x, int &n, int dato, int ref, int max)
{
    if (n < max-1)
    {
        int i = 0;
        int cen = 0;
        while ((i <= n) and (cen == 0))
        {
            if (x[i] == ref)
            {
                cen = 1;
            }
            else
            {
                i++;
            }
        }
        if (cen)
        {
            for (int j = n; j > i; j--)
            {
                x[j + 1] = x[j];
            }
            x[i + 1] = dato;
            n++;
        }
        else
        {
            cout << "No se encontro el dato ref: ";
        }
    }
    else
    {
        cout << "Arreglo lleno";
    }
}

void insertar_ad(int *x, int &n, int dato, int ref, int max)
{
    if (n < max - 1)
    {
        int i = 0;
        int cen = 0;
        while (i <= n and cen == 0)
        {
            if (x[i] == ref)
            {
                cout << "Se encontro el dato";
                cen = 1;
            }
            else
            {
                i++;
            }
        }
        if (cen)
        {
            for (int j = n; j >= i; j--)
            {
                x[j + 1] = x[j];
            }
            x[i] = dato;
            n++;
            cout << "Dato insertado antes de " << ref << ": " << dato << endl;
        }
        else
        {
            cout << "ni se encontro el ref";
        }
    }
    else
    {
        cout << "arreglo esta lleno";
    }
}

void leer(int *x, int &n)
{

    for (int i = 0; i <= n; i++)
    {
        cout << x[i] << endl;
    }
}