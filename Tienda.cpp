#include <iostream>
#include <string>

using namespace std;

class Producto{
    private:
        string nombre;
        string descripcion;
        float precio;
        int cantidad;
    public:
        Producto() {
            nombre = "";
            descripcion = "";
            precio = 0;
            cantidad = 0;
        }
        Producto(string nombre, string descripcion, float precio, int cantidad){
            this->nombre = nombre;
            this->descripcion = descripcion;
            this->precio = precio;
            this->cantidad = cantidad;
        }
        string getNombre(){
            return nombre;
        }
        string getDescripcion(){
            return descripcion;
        }
        float getPrecio(){ // Corregido: Debe ser float en vez de int
            return precio;
        }
        int getCantidad(){
            return cantidad;
        }
        void setNombre(string n){
            nombre = n;
        }
        void setDescripcion(string d){
            descripcion = d;
        }
        void setPrecio(float p){ // Corregido: Debe ser float en vez de int
            precio = p;
        }
        void setCantidad(int c){
            cantidad = c;
        }
};

class Tienda {
    private:
        Producto productos[100];
        int numProductos;

    public:
        Tienda() {
            numProductos = 0;
        }

        void agregarProducto(Producto p){
            productos[numProductos] = p;
            numProductos++;
        }

        void imprimirProductos(){
            for(int i=0; i<numProductos; i++){
                cout << "Nombre: " << productos[i].getNombre() << endl;
                cout << "Descripción: " << productos[i].getDescripcion() << endl;
                cout << "Precio: S/" << productos[i].getPrecio() << endl;
                cout << "Cantidad: " << productos[i].getCantidad() << endl << endl;
            }
        }

        void anadirProductos(){
            string nP, dP;
            float pP;
            int cP;
            cin.ignore(); //ignora los caracteres del flujo de entrada del teclado
            cout << "Ingrese el nombre del producto: ";
            getline(cin, nP); // Usar getline para inputs con espacio como "Producto perecible"
            cout << "Ingrese la descripción del producto: ";
            getline(cin, dP);
            cout << "Ingrese el precio del producto: ";
            cin >> pP;
            cout << "Ingrese la cantidad del producto: ";
            cin >> cP;
            Producto nuevoProducto(nP, dP, pP, cP);
            agregarProducto(nuevoProducto);
        }

};
int main(){
    int opc;
    Tienda tienda;
    Producto p1("Leche","Lacteo",2,3);
    Producto p2("Arroz", "Cereal", 5, 10);
    tienda.agregarProducto(p1);
    tienda.agregarProducto(p2);
    do{
        
        cout<<"Menu"<<endl;
        cout<<"1. Agregar producto"<<endl;
        cout<<"2. Ver lista de productos"<<endl;
        cout<<"3. Salir"<<endl;
        cin>>opc;
        switch (opc)
        {
        case 1:
            tienda.anadirProductos();
            break;
        case 2:
            tienda.imprimirProductos();
            break;
        case 3:
            cout<<"Saliendo...";
        default:
            cout<<"Opción inválida, ingrese otra opción";
            break;
        }
    }while(opc != 3);
    return 0;
}
