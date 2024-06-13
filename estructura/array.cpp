#include <iostream>
#include "funciones.h"
#define MAX 10
using namespace std;



int main()
{
    int x[MAX];

    int op;
    int opc;
    int n = -1;
    int dato;
    int dato1;
    int dato2;
    
    do
    {
        system("cls");
        cout << "--MENU--" << endl;
        cout << "--------" << endl;
        cout << "1.- Array Desordenado..." << endl;
        cout << "2.- Array Ordenado..." << endl;
        cout << "3.- Salir..." << endl;
        cout << "Opcion: ";
        cin >> op;
        switch (op)
        {
        case 1:
            do
            {
                system("cls");
                cout << "Arreglo Desordenado" << endl;
                cout << "--------" << endl;
                cout << "1.- Insertar..." << endl;
                cout << "2.- Eliminar..." << endl;
                cout << "3.- Modificar..." << endl;
                cout << "4.- Mostrar..." << endl;
                cout << "5.- Salir..." << endl;
                cout << "Opcion: ";
                cin >> opc;
                switch (opc)
                {
                case 1:
                    cout << "Dato a insertar: ";
                    cin >> dato;
                    inserta_d(x, n, dato, MAX);
                    mostrar_d(x, n);
                    break;

                case 2:
                    cout << "Dato a eliminar: ";
                    cin >> dato;
                    elimina_d(x, n, dato);
                    mostrar_d(x, n);
                    break;

                case 3:
                    cout << "Dato a modificar: ";
                    cin >> dato;
                    modifica_d(x, n, dato);
                    mostrar_d(x, n);
                    break;

                case 4:
                    mostrar_d(x, n);
                    system("pause");
                    break;

                case 5:
                    cout << "Saliendo..." << endl;
                    break;
                default:
                    cout << "Opcion no valida" << endl;
                    system("pause");
                    break;
                }

            } while (opc > 0 and opc < 5);
            break;

        case 2:
        do
        {
            system("cls");
            cout << "Arreglo Ordenado" << endl;
            cout << "--------" << endl;
            cout << "1.- Insertar..." << endl;
            cout << "2.- Eliminar..." << endl;
            cout << "3.- Modificar..." << endl;
            cout << "4.- Mostrar..." << endl;
            cout << "5.- Salir..." << endl;
            cout << "Opcion: ";
            cin >> opc;
            switch (opc)
            {
            case 1:
                cout << "Dato a insertar: ";
                cin >> dato;
                inserta_o(x, n, dato, MAX);
                mostrar_o(x, n);
                break;

            case 2:
                cout << "Dato a eliminar: ";
                cin >> dato;
                elimina_o(x, n, dato);
                mostrar_o(x, n);
                break;

            case 3:
                cout << "Dato a modificar: ";
                cout << "Dame el dato a modificar: ";
                cin >> dato1;
                cout<<"Dame el nuevo dato: ";
                cin>>dato2;
                modifica_o(x,n,dato1,dato2);
                mostrar_o(x, n);
                break;

            case 4:
                mostrar_o(x, n);
                    system("pause");
                    break;

            case 5:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
                system("pause");
                break;
            }
    
        } while (opc>0 and opc<4);
            break;
        case 3:
            cout << "Saliendo..." << endl;
            break;
        


        }

    } while (op > 0 and op < 3);

    return 0;
}
