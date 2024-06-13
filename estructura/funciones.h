#include <iostream>
using namespace std;

void mostrar_d(int *x, int n)
{
    int i;

    for (i = 0; i <= n; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}

void inserta_d(int *x, int &n, int dato, int max)
{
    if (n < max - 1)
    {
        n++;
        x[n] = dato;
    }
    else
    {
        cout << "No hay espacio, no se pudo ingresar el dato" << endl;
        system("pause");
    }
}
void elimina_d(int *x, int &n, int dato)
{
    int i, j, cen;

    if (n > -1)
    {
        i = 0;
        cen = 0;
        while ((i <= n) and (cen == 0))
        {
            if (x[i] == dato)
            {
                cen = 1;
                n--;
                for (j = i; j <= n; j++)
                {
                    x[j] = x[j + 1];
                }
            }
            else
            {
                i++;
            }
        }
        if (cen == 0)
        {
            cout << "No se encontro el dato" << endl;
        }
    }
    else
    {
        cout << "No hay elementos" << endl;
        system("pause");
    }
}

void modifica_d(int *x, int &n, int dato)
{
    int i, cen;
    if (n > -1)
    {
        i = 0;
        cen = 0;
        while ((i <= n) and (cen == 0))
        {
            if (x[i] == dato)
            {
                cen = 1;
                cout << "Dame el nuevo dato: ";
                cin >> x[i];
            }
            else
            {
                i++;
            }
        }
        if (cen == 0)
        {
            cout << "No se encontro el dato" << endl;
            system("pause");
        }
    }
    else
    {
        cout << "No hay elementos" << endl;
        system("pause");
    }
}

void mostrar_o(int *x, int &n)
{
    int i;
    for (i = 0; i <= n; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}

int busca_o(int *x, int &n, int dato)
{
    int i, pos;
    i = 0;

    while ((i <= n) and (x[i] < dato))
    {
        i++;
    }
    if ((i>n) or (x[i] > dato))
    {
        pos = -i;
    }
    else
    {
        pos = i;
    }
return pos;
}

void inserta_o(int *x, int &n, int dato, int max)
{
    int pos;
    if (n < max - 1)
    {
        pos = busca_o(x, n, dato);
        if (pos <= 0)
        {
            pos = abs(pos);
            if (x[pos] != dato) // Verifica si el dato ya existe
            {
                n++;
                for (int i = n; i > pos; i--)
                {
                    x[i] = x[i - 1];
                }
                x[pos] = dato;
                cout << "Dato insertado en la posicion " << pos << endl;
            }
            else
            {
                cout << "El dato ya existe" << endl;
            }
        }
        else
        {
            cout << "El dato ya existe" << endl;
        }
    }
    else
    {
        cout << "No hay espacio, no se pudo ingresar el dato" << endl;
    }
    system("pause");
}



void elimina_o(int *x, int &n, int dato)
{
    if (n > -1)
    {
        int pos;
        pos = busca_o(x, n, dato);
        if (pos >= 0)
        {
            n--;
            for (int i = pos; i <= n; i++)
            {
                x[i] = x[i + 1];
            }
        }
        else
        {
            cout << "No se encontro el dato" << endl;
            system("pause");
        }
    }
    else
    {
        cout << "No hay elementos" << endl;
        system("pause");
    }
}
void modifica_o(int *x, int &n, int dato1, int dato2)
{
    if (n > -1)
    {
        elimina_o(x, n, dato1);
        int pos;
        pos = busca_o(x, n, dato2);
        if (pos < 0)
        {
            pos = -pos;
            n++;
            for (int i = n; i >= pos; i--)
            {
                x[i] = x[i - 1];
            }
            x[pos] = dato2;
        }
    }
    else
    {   
        cout << "No hay elementos" << endl;
        system("pause");
    }
}
