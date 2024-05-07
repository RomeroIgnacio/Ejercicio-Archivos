#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Producto
{
    private:
        string nombre;
        float precio;
        int existencia;

    public:
        Producto(const string& nombre = "", float precio = 0.0, int existencia = 0);
        ~Producto();

        string getNombre() const;
        void setNombre(const string& valor);

        float getPrecio() const;
        void setPrecio(float valor);

        int getExistencia() const;
        void setExistencia(int valor);

        friend ostream& operator << (ostream& os, const Producto& producto)
        {
            os << producto.nombre << " " << producto.precio << " " << producto.existencia << endl;
            return os;
        }

        friend istream& operator >> (istream& is, Producto& producto)
        {
            is >> producto.nombre >> producto.precio >> producto.existencia;
            return is;
        }
};

class Tienda {
    public:
        void agregarProducto(const Producto& producto)
        {
            if (numProductos < MAX_PRODUCTOS)
            {
                productos[numProductos++] = producto;
            }
            else
            {
                cerr << "No se pueden agregar más productos, límite alcanzado." << endl;
            }
        }

        void mostrarProductos()
        {
            for (int i = 0; i < numProductos; ++i)
            {
                cout << productos[i];
            }
        }

        void guardarProductos(const string& nombreArchivo)
        {
            ofstream archivo(nombreArchivo);
            if (archivo.is_open())
            {
                for (int i = 0; i < numProductos; ++i)
                {
                    archivo << productos[i];
                }
                
                archivo.close();
                cout << "Productos guardados correctamente en " << nombreArchivo << endl;
            }
            else
            {
                cerr << "No se pudo abrir el archivo " << nombreArchivo << endl;
            }
        }

        void cargarProductos(const string& nombreArchivo)
        {
            ifstream archivo(nombreArchivo);
            if (archivo.is_open())
            {
                Producto producto;
                while (archivo >> producto && numProductos < MAX_PRODUCTOS)
                {
                    productos[numProductos++] = producto;
                }

                archivo.close();
                cout << "Productos cargados correctamente desde " << nombreArchivo << endl;
            }
            else
            {
                cerr << "No se pudo abrir el archivo " << nombreArchivo << endl;
            }
        }

    private:
        static const int MAX_PRODUCTOS = 100;
        Producto productos[MAX_PRODUCTOS];
        int numProductos = 0;
};

#endif
