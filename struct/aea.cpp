#include <bits/stdc++.h>
#define MAX 20
using namespace std;

struct alumno
{
    char codi[20], nombre[20];
    float nota1, nota2, prom;
};
void inserta_d(alumno *, int &);
void elimina_d(alumno *, int &);
void modifica_d(alumno *, int &);

int busca_o(alumno *, int &, char[]);
void inserta_o(alumno *x, int &n, int max);
void elimina_o(alumno *, int &, char[]);
void modifica_o(alumno *, int &);
void mostrar(alumno *, int &);

int main()
{
    alumno x[MAX];
    int op, opc, n = -1, i;
    do
    {
        system("cls");
        cout << "\nM  E  N  U ";
        cout << "\n============";
        cout << "\n\n1.- ARRAY DESORDENADO";
        cout << "\n\n2.- ARRAY ORDENADO";
        cout << "\n\n3.- SALIR";
        cout << "\n\nOPCION: ";
        cin >> op;
        switch (op)
        {
        case 1:
            do
            {
                system("cls");
                cout << "\nARREGLO DESORDENADO ";
                cout << "\n==========";
                cout << "\n\n1.- INSERTAR";
                cout << "\n\n2.- ELIMINAR";
                cout << "\n\n3.- MODIFICAR";
                cout << "\n\n4.- MOSTRAR";
                cout << "\n\n5.- SALIR";
                cout << "\n\nOPCION: ";
                cin >> opc;
                switch (opc)
                {
                case 1:
                    inserta_d(x, n);
                    mostrar(x, n);
                    break;
                case 2:
                    elimina_d(x, n);
                    mostrar(x, n);
                    break;
                case 3:
                    modifica_d(x, n);
                    mostrar(x, n);
                    break;
                case 4:
                    mostrar(x, n);
                    break;
                case 5:
                    break;
                }
            } while (opc > 0 and opc < 5);

            break;
        case 2:
            do
            {
                system("cls");
                cout << "\nARREGLO ORDENADO ";
                cout << "\n==========";
                cout << "\n\n1.- INSERTAR";
                cout << "\n\n2.- ELIMINAR";
                cout << "\n\n3.- MODIFICAR";
                cout << "\n\n4.- MOSTRAR";
                cout << "\n\n5.- SALIR";
                cout << "\n\nOPCION: ";
                cin >> opc;
                switch (opc)
                {
                case 1:
                    inserta_o(x, n, MAX);
                    mostrar(x, n);
                    break;
                case 2:
                    char dato[10];
                    cout << "Dato a eliminar: ";
                    cin >> dato;
                    elimina_o(x, n, dato);
                    mostrar(x, n);
                    break;
                case 3:
                    modifica_o(x, n);
                    mostrar(x, n);
                    break;
                case 4:
                    mostrar(x, n);
                    break;
                case 5:
                    break;
                }
            } while (opc > 0 and opc < 5);
            break;

        default:
            break;
        }
    } while (op > 0 and op < 3);

    return 0;
}

void inserta_d(alumno *x, int &n)
{
    int i, j, cen;
    char codigo[20];
    if (n < MAX - 1)
    {
        cen = 0;
        i = 0;
        cout << "\n\n\nDATO DEL REGISTRO A INSERTAR:  ";
        cout << "\n\nCODIGO: ";
        cin >> codigo;
        if (n > -1)
        {
            while ((i <= n) and (cen == 0))
            {
                if (strcmp(x[i].codi, codigo) == 0)
                {
                    cen = 1;
                }
                else
                {
                    i++;
                }
            }
        }
        if (cen == 0)
        {
            n++;
            strcpy(x[i].codi, codigo);
            cout << "\n\nNOMBRE: ";
            cin >> x[i].nombre;
            cout << "\n\nNOTA 1: ";
            cin >> x[i].nota1;
            cout << "\n\nNOTA 2: ";
            cin >> x[i].nota2;
            x[i].prom = (x[i].nota1 + x[i].nota2) / 2;
            cout << "\n\n\t\tPromedio: " << x[i].prom;
        }
        else
        {
            cout << "\n\n\nCODIGO YA EXISTE NO SE REALIZO LA INSERCCION";
        }
    }
    else
    {
        cout << "\n\n\nNO HAY ESPACIO PARA MAS REGISTROS";
    }
}

void elimina_d(alumno *x, int &n)
{
    int i, j, cen;
    char codigo[10];
    if (n > -1)
    {
        cen = 0;
        i = 0;
        cout << "\n\n\nDATO DEL REGISTRO A ELIMINAR:  ";
        cout << "\n\nCODIGO: ";
        cin >> codigo;
        while ((i <= n) and (cen == 0))
        {
            if (strcmp(x[i].codi, codigo) == 0)
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
            cout << "\n\n\nCODIGO: " << codigo << " NO EXISTE NO SE REALIZO LA ELIMINACION";
        }
    }
    else
    {
        cout << "\n\n\n EL ARREGLO ESTA VACIO";
    }
}

void modifica_d(alumno *x, int &n)
{
    int i, cen, op;
    char codigo1[10];
    cout << "\n\n\nCODIGO DEL REGISTRO A MODIFICAR:  ";
    cout << "\n\nCODIGO: ";
    cin >> codigo1;
    if (n > -1)
    {
        cen = 0;
        i = 0;

        while ((i <= n) and (cen == 0))
        {
            if (strcmp(x[i].codi, codigo1) == 0)
            {
                cen = 1;
                cout << "\n\n\nQUE CAMPO DESEA MODIFICAR?";
                cout << "\n\n1.- CODIGO";
                cout << "\n\n2.- NOMBRE";
                cout << "\n\n3.- NOTA 1";
                cout << "\n\n4.- NOTA 2";
                cout << "\n\nOpccion: ";
                cin >> op;
                switch (op)
                {
                case 1:
                    cout << "\n\nCODIGO: ";
                    cin >> x[i].codi;
                    break;
                case 2:
                    cout << "\n\nNOMBRE: ";
                    cin >> x[i].nombre;
                    break;
                case 3:
                    cout << "\n\nNOTA 1: ";
                    cin >> x[i].nota1;
                    x[i].prom = (x[i].nota1 + x[i].nota2) / 2;
                    break;
                case 4:
                    cout << "\n\nNOTA 2: ";
                    cin >> x[i].nota2;
                    x[i].prom = (x[i].nota1 + x[i].nota2) / 2;
                    break;
                }
            }
            else
            {
                i++;
            }
        }
        if (cen == 0)
        {
            cout << "\n\n\nCODIGO: " << codigo1 << " NO EXISTE NO SE REALIZO LA MODIFICACION";
        }
    }
    else
    {
        cout << "\n\n\n EL ARREGLO ESTA VACIO";
    }
}

void mostrar(alumno *x, int &n)
{
    int i;
    if (n > -1)
    {
        cout << "\n\n\nCODIGO\t\tNOMBRE\t\tNOTA 1\t\tNOTA 2\t\tPROMEDIO";
        for (i = 0; i <= n; i++)
        {
            cout << "\n\n"
                 << x[i].codi << "\t\t" << x[i].nombre << "\t\t" << x[i].nota1 << "\t\t" << x[i].nota2 << "\t\t" << x[i].prom;
        }
        cout << "\n\n\n";
        system("pause");
    }
    else
    {
        cout << "\n\n\n EL ARREGLO ESTA VACIO";
    }
}

int busca_o(alumno *x, int &n, char codigo[])
{
    int i, pos;
    i = 0;

    while ((i <= n) and (strcmp(x[i].codi, codigo) < 0))
    {
        i++;
    }
    if ((i > n) or (strcmp(x[i].codi, codigo) > 0))
    {
        pos = -i;
    }
    else
    {
        pos = i;
    }
    return pos;
}

void inserta_o(alumno *x, int &n, int max)
{
    int pos;
    if (n < max - 1)
    {
        char codigo[20];
        cout << "Codigo: ";
        cin >> codigo;

        pos = busca_o(x, n, codigo);
        if (pos <= 0)
        {
            pos = abs(pos);
            if ((strcmp(codigo, x[pos].codi)) != 0) // Verifica si el dato ya existe
            {
                n++;
                for (int i = n; i > pos; i--)
                {
                    strcpy(x[i].codi, x[i - 1].codi);
                    strcpy(x[i].nombre, x[i - 1].nombre);
                    x[i].nota1 = x[i - 1].nota1;
                    x[i].nota2 = x[i - 1].nota2;
                    x[i].prom = x[i - 1].prom;
                }
                strcpy(x[pos].codi, codigo);
                cout << "\n\nNOMBRE: ";
                cin >> x[pos].nombre;
                cout << "\n\nNOTA 1: ";
                cin >> x[pos].nota1;
                cout << "\n\nNOTA 2: ";
                cin >> x[pos].nota2;
                x[pos].prom = (x[pos].nota1 + x[pos].nota2) / 2;
                cout << "\n\n\t\tPromedio: " << x[pos].prom;
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
void elimina_o(alumno *x, int &n, char codigo[])
{
    if (n > -1)
    {
        int pos;
        pos = busca_o(x, n, codigo);
        if (pos >= 0)
        {
            n--;
            for (int i = pos; i <= n; i++)
            {
                strcpy(x[i].codi, x[i + 1].codi);
                strcpy(x[i].nombre, x[i + 1].nombre);
                x[i].nota1 = x[i + 1].nota1;
                x[i].nota2 = x[i + 1].nota2;
                x[i].prom = x[i + 1].prom;
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
void modifica_o(alumno *x, int &n)
{
    if (n > -1)
    {
        char dato1[10];
        cout << "codigo del Alumno a modificar: ";
        cin >> dato1;
        int pos;
        pos = busca_o(x, n, dato1);
        int ops;
        cout << "Que parametro desea modificar: " << endl;
        cout << "1.- Codigo" << endl;
        cout << "2.- Nombre" << endl;
        cout << "3.- Nota 1" << endl;
        cout << "4.- Nota 2" << endl;
        cout << "Opcion: ";
        cin >> ops;
        switch (ops)
        {
        case 1:
            int auxnota1, auxnota2;
            char auxnombre[20];
            auxnota1 = x[pos].nota1;
            auxnota2 = x[pos].nota2;
            strcpy(auxnombre, x[pos].nombre);
            elimina_o(x, n, dato1);
            char dato2[20];
            cout << "Nuevo codigo: ";
            cin >> dato2;
            int newpos;
            newpos = busca_o(x, n, dato2);
            if (newpos <= 0)
            {
                newpos = abs(newpos);
                n++;
                for (int i = n; i >= newpos; i--)
                {
                    strcpy(x[i].codi, x[i - 1].codi);
                    strcpy(x[i].nombre, x[i - 1].nombre);
                    x[i].nota1 = x[i - 1].nota1;
                    x[i].nota2 = x[i - 1].nota2;
                    x[i].prom = x[i - 1].prom;
                }

                strcpy(x[newpos].codi, dato2);
                x[newpos].nota1 = auxnota1;
                x[newpos].nota2 = auxnota2;
                strcpy(x[newpos].nombre, auxnombre);
                x[newpos].prom = (x[newpos].nota1 + x[newpos].nota2) / 2;

                
            }
            else
            {
                cout << "El dato ya existe" << endl;
                cout<< newpos;
            }
            break;
        case 2:
            cout << "Nuevo nombre: ";
            cin >> x[pos].nombre;
            break;
        case 3:
            cout << "Nueva nota 1: ";
            cin >> x[pos].nota1;
            x[pos].prom = (x[pos].nota1 + x[pos].nota2) / 2;
            break;
        case 4:
            cout << "Nueva nota 2: ";
            cin >> x[pos].nota2;
            x[pos].prom = (x[pos].nota1 + x[pos].nota2) / 2;
            break;
            break;

        default:
            break;
        }
        /*
        elimina_o(x, n, dato1);
        int pos;
        pos = busca_o(x, n, dato2);
        if (pos < 0)
        {
            pos = abs(pos);
            n++;
            for (int i = n; i >= pos; i--)
            {
                strcpy(x[i].codi, x[i - 1].codi);
                strcpy(x[i].nombre, x[i - 1].nombre);
                x[i].nota1 = x[i - 1].nota1;
                x[i].nota2 = x[i - 1].nota2;
                x[i].prom = x[i - 1].prom;
            }

            strcpy(x[pos].codi, dato2);
            cout << "\n\nNOMBRE: ";
            cin >> x[pos].nombre;
            cout << "\n\nNOTA 1: ";
            cin >> x[pos].nota1;
            cout << "\n\nNOTA 2: ";
            cin >> x[pos].nota2;
            x[pos].prom = (x[pos].nota1 + x[pos].nota2) / 2;
            cout << "\n\n\t\tPromedio: " << x[pos].prom;
            cout << "Dato insertado en la posicion " << pos << endl;
        }
    }
    else
    {
        cout << "No hay elementos" << endl;
        system("pause");
    }
    */
    }
}