#include <iostream>
#include <fstream>

#include "tienda.h"

using namespace std;

int menu()
{
    int op;

    cout << 
    "1. Agregar producto" << endl <<
    "2. Mostrar productos" << endl <<
    "3. Guardar productos" << endl <<
    "4. Cargar productos" << endl <<
    "0. Salir" << endl <<
    "Ingrese una opcion: ";
    cin >> op;

    return op;
}

int main()
{
    Tienda tienda;
    tienda.cargarProductos("productos.txt");

    cout << "Bienvenido a la tienda de abarrotes" << endl;
    do
    {
        switch (menu())
        {
            case 1: {
                string nombre;
                float precio;
                int existencia;
                cout << "Ingrese el nombre del producto: ";
                cin >> nombre;
                cout << "Ingrese el precio del producto: ";
                cin >> precio;
                cout << "Ingrese la existencia del producto: ";
                cin >> existencia;
                tienda.agregarProducto(Producto(nombre, precio, existencia));
                break;
            }

            case 2:
            {
                tienda.mostrarProductos();
                break;
            }

            case 3:
            {
                tienda.guardarProductos("productos.txt");
                break;
            }

            case 4:
            {
                tienda.cargarProductos("productos.txt");
                break;
            }

            case 0:
            {
                cout << "Saliendo del programa..." << endl;
                return 0;
                break;
            }

            default:
            {
                cout << "Opción inválida. Intente de nuevo." << endl;
            }
        }
    }
    while (true);

    return 0;
}