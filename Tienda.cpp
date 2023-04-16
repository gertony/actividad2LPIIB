#include <iostream>
#include <string>

using namespace std;

//Se crea la clase producto
class Producto{
    private://encapsulamiento de los atributos
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
        //Constructor
        Producto(string nombre, string descripcion, float precio, int cantidad){
            this->nombre = nombre;
            this->descripcion = descripcion;
            this->precio = precio;
            this->cantidad = cantidad;
        }
    
        //creaccion de getters y setters(encapsulamiento)
        string getNombre(){
            return nombre;
        }
        string getDescripcion(){
            return descripcion;
        }
        float getPrecio(){
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
        void setPrecio(float p){ 
            precio = p;
        }
        void setCantidad(int c){
            cantidad = c;
        }
};

//Se crea la clase Tienda
class Tienda {
    
    private://encapsulamiento de los atributos
        Producto productos[100];
        int numProductos;

    public: 
    //constructor
        Tienda() {
            numProductos = 0;
        }
    //creación de métodos a usar
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
    //Inicialización de las variables
    int opc;
    Tienda tienda;
    Producto p1("Leche","Lacteo",2,3);
    Producto p2("Arroz", "Cereal", 5, 10);
    tienda.agregarProducto(p1);
    tienda.agregarProducto(p2);
    
    //Creación de menú
    do{
        
        cout<<"Menu"<<endl;
        cout<<"1. Agregar producto"<<endl;
        cout<<"2. Ver lista de productos"<<endl;
        cout<<"3. Salir"<<endl;
        cin>>opc;
        //Switch para poder usar y validar las opciones del menú
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
