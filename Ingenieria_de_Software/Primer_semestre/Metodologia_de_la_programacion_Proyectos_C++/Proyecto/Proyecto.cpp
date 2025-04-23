// Este programa permite que una tienda en línea de galletas pueda gestionar su inventario
// Nombre de la tienda en línea: Galletas "El Surtidor"
// Autor: Gabriel Hernández Martínez

/* Para decorar, se utilizaron códigos ANSI de colores:
Rojo claro: "\033[91m"
Verde claro: "\033[92m"
Amarillo brillante: "\033[93m"
Azul claro: "\033[94m"
Blanco brillante: "\033[97m"
*/
#include <iostream>
using namespace std;

int n_productos = 0;

// Función para obtener las dos primeras letras del proovedor paa la clave
string extraer_letras_proveedor(string proveedor) {
    string letras = "";
    for (int i = 0; i < 2; i++) {
        if (proveedor[i] != ' ' && proveedor[i] != '\0') {
            letras += toupper(proveedor[i]);
        } else {
            letras += 'X';
        }
    }
    return letras;
}

// Procedimiento para generar la clave
string generar_clave(int i, string proveedor) {
    string clave = extraer_letras_proveedor(proveedor);
    if (i + 1 < 10) {
        clave += "00" + to_string(i + 1);
    } else if (i + 1 < 100) {
        clave += "0" + to_string(i + 1);
    } else if (i + 1 < 1000) {
        clave += to_string(i + 1);
    }
    return clave;
}


// Estructura con los datos de cada producto
struct Galleta {
    string clave;
    string proveedor;
    string nombre;
    int cantidad;
    float precio;
};

// Procedimiento para ingresar los datos
void ingresar_datos(int i, Galleta galleta[100]) {
    cin.ignore();
    
    do {
        cout << "\n\033[97mIngrese el proveedor del producto: \033[0m";
        getline(cin, galleta[i].proveedor);
        if (galleta[i].proveedor == "") {
            cout << "\n\033[91mEl proveedor no puede estar vacio. Ingrese un proveedor valido.\033[0m\n";
        }
    } while (galleta[i].proveedor == "");

    do {
        cout << "\033[97mIngrese el nombre del producto: \033[0m";
        getline(cin, galleta[i].nombre);
        if (galleta[i].nombre == "") {
            cout << "\n\033[91mEl nombre del producto no puede estar vacio. Ingrese un nombre valido.\033[0m\n";
        }
    } while (galleta[i].nombre == "");

    do {
        cout << "\033[97mIngrese la cantidad: \033[0m";
        cin >> galleta[i].cantidad;
        if (galleta[i].cantidad < 0) {
            cout << "\n\033[91mIngrese una cantidad valida.\033[0m\n";
        }
    } while (galleta[i].cantidad < 0);

    do {
        cout << "\033[97mIngrese el precio:\033[0m $";
        cin >> galleta[i].precio;
        if (galleta[i].precio < 0) {
            cout << "\n\033[91mIngrese un precio valido.\033[0m\n";
        }
    } while (galleta[i].precio < 0);

    cout << endl << endl;
}

// Procedimiento para mostrar un determinado producto
void mostrar_producto(int i, Galleta galleta[100]) {
        cout << "\n\033[97mProveedor:\033[0m " << galleta[i].proveedor;
        if (galleta[i].clave != "") {
            cout << "\n\033[97mClave: \033[0m" << galleta[i].clave;
        }
        cout << "\n\033[97mNombre del producto:\033[0m " << galleta[i].nombre;
        cout << "\n\033[97mCantidad:\033[0m " << galleta[i].cantidad;
        cout << "\n\033[97mPrecio:\033[0m $" << galleta[i].precio;
        cout << endl << endl;
}

// Opcion 1. Función para insertar productos
void registrar_producto(Galleta galleta[100]) {
    cout << "\n\033[94m********* \033[93mRegistrar productos\033[0m \033[94m********\033[0m\n";

    // Se pregunta al usuario el número de productos a dar de alta
    cout << "\033[97mIngrese el numero de productos a registrar: ";
    int n_productos_a_ingresar;
    cin >> n_productos_a_ingresar;

    // Se pide al usuario que ingrese los datos
    cout << "\n\033[97mIngrese los datos: \n\n";
    for(int i = 0; i < n_productos_a_ingresar; i++) {
        cout << "\033[97mProducto #" << n_productos+1 << "\033[0m";
        ingresar_datos(n_productos, galleta);

        // Se muestran los datos ingresados
        cout << "\033[97mDatos ingresados en el producto #" << n_productos+1 << " :\033[0m";
        mostrar_producto(n_productos, galleta);

        // Se confirma si los datos son correctos
        char confirmacion;
        cout << "\a\n\033[97mConfirma si los datos son correctos (S/N): \033[0m";
        cin >> confirmacion;

        // Si los datos son correctos, se genera la clave del producto
        if (confirmacion == 'S' || confirmacion == 's') {
            galleta[n_productos].clave = generar_clave(n_productos, galleta[n_productos].proveedor);
            n_productos ++;
            cout << "\n\033[92mProducto registrado exitosamente!\033[0m\n";
        } else {
            cout << "\n\033[91mNo se registro el producto\033[0m\n";
        }

    }
}

// Opcion 2. Procedimiento para modificar datos de un producto a partir de su clave
void modificar_datos(Galleta galleta[100]) {
    if (n_productos == 0) {
        cout << "\n\033[91mEl inventario esta vacio.\033[0m\n";
    } else {
        cout << "\n\n\033[94m*********** \033[93mModificar datos\033[0m \033[94m***********\n\033[0m";

        string clave_producto_a_modificar;
        bool clave_encontrada = false;
        // Se pide al usuario la clave del producto a modificar
        cout << "\033[97mIngrese la clave del producto que quieres modificar: \033[0m";
        cin >> clave_producto_a_modificar;

        int i = 0;
        while (i < n_productos && clave_encontrada == false) {
            // Si se encuentra un producto con la clave ingresada, se muestra el producto a modificar y luego se piden sus nuevos datos
            if (clave_producto_a_modificar == galleta[i].clave) {
                clave_encontrada = true;
                cout << "\n\033[97mEl producto a modificar es:\033[0m";
                mostrar_producto(i, galleta);
                cout << "\n\033[97mIngrese los datos:\033[0m";
                ingresar_datos(i, galleta);
                galleta[i].clave = generar_clave(i, galleta[i].proveedor);
                cout << "\n\033[92mDatos del producto actualizados exitosamente!\033[0m\n";
            }
            i++;
        }
        if (clave_encontrada == false) {
            cout << "\n\033[91mNo se encontro la clave.\033[0m\n";
        }
    }
}

// Opcion 3. Procedimiento para mostrar el inventario completo
void mostrar_inventario(Galleta galleta[100]) {
    if (n_productos == 0) {
        cout << "\033[91mEl inventario esta vacio.\033[0m";
    } else {
        cout << "\n\n\033[94m************* \033[93mInventario\033[0m \033[94m*************\033[0m";
        for(int i = 0; i < n_productos; i++) {
            mostrar_producto(i, galleta);
        }
    }

    cout << "\n\n";
}

// Opcion 4. Procedimiento para mostrar los productos que tengan un precio menor al ingresado
void mostrar_productos_por_existencia_menor(Galleta galleta[100]) {
    if (n_productos == 0) {
        cout << "\n\033[91mEl inventario esta vacio.\033[0m\n";
    } else {
        cout << "\n\033[94m********* \033[93mMostrar productos por existencia menor a la ingresada\033[0m \033[94m********\033[0m\n";
        bool existen_productos_existencia_menor = false;
        int cantidad;

        // Se pregutna al usuario el nombre del proveedor
        cout << "Ingrese el numero de existencias: ";
        cin >> cantidad;

        // Se recorren los productos registrados y si se encuentran productos que tengan la cantidad menor a la ingresada, se muestran
        for (int i = 0; i < n_productos; i++) {
            if (galleta[i].cantidad < cantidad) {
                existen_productos_existencia_menor = true;
                mostrar_producto(i, galleta);
            }
        }

        // Si no se encuentran productos con la cantidad menor a la ingresada, se muestra un mensaje
        if (existen_productos_existencia_menor == false) {
            cout << "\n\033[91mNo se encontraron productos con existencia menor a la ingresada\033[0m\n";
        }
    }
}

// Opcion 5. Procedimiento para mostrar mostrar productos por proveedor
void mostrar_productos_por_proveedor(Galleta galleta[100]) {
    if (n_productos == 0) {
        cout << "\n\033[91mEl inventario esta vacio.\033[0m\n";
    } else {
        cout << "\n\n*** Mostrar productos por proveedor ***";
        bool proveedor_encontrado = false;
        string proveedor;

        // Se pregunta al usuario el nombre del proveedor
        cout << "\nIngrese el nombre del proveedor: ";
        cin.ignore();
        getline(cin, proveedor);

        // Si se encuentran productos con el mismo proveedor al ingresado, se muestran esos productos
        for (int i = 0; i < n_productos; i++) {
            if (proveedor == galleta[i].proveedor) {
                proveedor_encontrado = true;
                mostrar_producto(i, galleta);
            }
        }

        // Si no hay productos con el mismo proveedor que se ingresó, se muestra un mensaje
        if (proveedor_encontrado == false) {
            cout << "\n\033[91mProveedor no encontrado. Asegurese de que haya escrito correctamente el proveedor\033[0m\n";
        }
    }
}

// Opcion 6. Procedimiento para mostrar los productos que tengan un precio mayor al ingresado
void mostrar_productos_por_precio_mayor(Galleta galleta[100]) {
    if (n_productos == 0) {
        cout << "\n\033[91mEl inventario esta vacio.\033[0m\n";
    } else {
        cout << "\n\n*** \033[93mMostrar productos con precio mayor ***";

        bool existen_productos_precio_mayor = false;
        float precio;
        cout << "\nIngrese el precio: ";
        cin >> precio;

        for (int i = 0; i < n_productos; i++) {
            if (galleta[i].precio > precio) {
                existen_productos_precio_mayor = true;
                mostrar_producto(i, galleta);
            }
        }
        if (existen_productos_precio_mayor == false) {
            cout << "\n\033[91mNo se encontraron productos con precio mayor al ingresado\033[0m\n";
        }
    }
}


// Procedimiento para mostrar las opciones del menú
void mostrar_opciones_menu() {
        cout << "\n\033[92m======================================";
        cout << "\n=======\033[0m \033[1;93mGalletas \"El surtidor\"\033[0m \033[92m=======";
        cout << "\n======================================";
        cout << "\n\033[94m***********\033[0m \033[1;93mMENU PRINCIPAL\033[0m \033[94m***********\033[0m";
        cout << "\n\033[97m1. Registrar un producto" << endl;
        cout << "2. Modificar datos de un producto" << endl;
        cout << "3. Mostrar inventario" << endl;
        cout << "4. Mostrar productos por existencia menor a la ingresada" << endl;
        cout << "5. Mostrar productos por proveedor" << endl;
        cout << "6. Mostrar productos por precio mayor al ingresado" << endl;
        cout << "7. Salir\033[0m" << endl;
        cout << "\033[94m**************************************\033[0m" << endl;
}

void menu() {
    Galleta galleta[100];

    int opcion;

    do {
        // Mostrar las opciones del menú
        mostrar_opciones_menu();

        // Se pide al usuario que seleccione una opción
        cout << "\nSeleccione una opcion: ";
        cin >> opcion;
        cout << endl;

        switch (opcion) {
            case 1:
                registrar_producto(galleta);
                break;
            case 2:
                modificar_datos(galleta);
                break;
            case 3:
                mostrar_inventario(galleta);
                break;
            case 4:
                mostrar_productos_por_existencia_menor(galleta);
                break;
            case 5:
                mostrar_productos_por_proveedor(galleta);
                break;
            case 6:
                mostrar_productos_por_precio_mayor(galleta);
                break;
            case 7:
                break;
            default:
                cout << "\033[91mOpcion invalida. Intentelo de nuevo.\033[0m" << endl;
                break;
        }

    } while (opcion != 7);
}

int main(){
    menu();

    return 0;
}
