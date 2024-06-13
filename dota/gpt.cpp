#include <iostream>
#define MAX 10
using namespace std;

void insertar(int *, int &, int, int);
void insertar_ad(int *, int &, int, int, int);
void leer(int *, int &);

int main() {
    int x[MAX] = {0}; // Inicializar el array con ceros
    int op;
    int n = -1; // El índice inicial del array vacío
    int dato;
    do {
        system("cls");
        cout << "---M E N U---" << endl;
        cout << "1. Insertar dato nomas: " << endl;
        cout << "2. Insertar dato antes de REF: " << endl;
        cout << "9. LEER" << endl;
        cout << "10. SALIR" << endl;
        cout << "Ingrese la opcion: ";
        cin >> op;
        switch (op) {
            case 1:
                system("cls");
                cout << "Ingrese el dato: ";
                cin >> dato;
                insertar(x, n, dato, MAX);
                system("pause");
                break;
            case 2:
                system("cls");
                int ref;
                cout << "Ingrese el dato: ";
                cin >> dato;
                cout << "Ingrese el dato referencial: ";
                cin >> ref;
                insertar_ad(x, n, dato, ref, MAX);
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

void insertar(int *x, int &n, int dato, int max) {
    if (n < max - 1) {
        n++;
        x[n] = dato;
        cout << "Dato insertado: " << dato << endl;
    } else {
        cout << "Arreglo lleno, no se inserto el dato." << endl;
    }
}

void insertar_ad(int *x, int &n, int dato, int ref, int max) {
    if (n < max - 1) {
        int i = 0;
        int cen = 0;
        while (i <= n && cen == 0) {
            if (x[i] == ref) {
                cen = 1;
            } else {
                i++;
            }
        }
        if (cen == 1) {
            for (int j = n; j >= i; j--) {
                x[j + 1] = x[j];
            }
            x[i] = dato;
            n++;
        } else {
            cout << "No se encontro el dato referencial." << endl;
        }
    } else {
        cout << "Arreglo lleno, no se inserto el dato." << endl;
    }
}

void leer(int *x, int &n) {
    if (n >= 0) {
        for (int i = 0; i <= n; i++) {
            cout << x[i] << endl;
        }
    } else {
        cout << "El arreglo esta vacio." << endl;
    }
}
