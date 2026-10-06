#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

class Pila {
private:
    Nodo* top;

public:
    Pila() {
        top = NULL;
    }

    bool estaVacia() {
        return top == NULL;
    }

    void push(int valor) {
        Nodo* nuevo = new Nodo();

        nuevo->dato = valor;
        nuevo->siguiente = top;

        top = nuevo;

        cout << "Se agrego: " << valor << "\n";
    }

    int pop() {
        if (estaVacia()) {
            cout << "Error: la pila esta vacia." << "\n";
            return -1;
        }

        Nodo* auxiliar = top;
        int valor = auxiliar->dato;

        top = top->siguiente;

        delete auxiliar;

        return valor;
    }

    int peek() {
        if (estaVacia()) {
            cout << "La pila esta vacia." << "\n";
            return -1;
        }

        return top->dato;
    }

    ~Pila() {
        while (!estaVacia()) {
            pop();
        }
    }
};

int main() {

    // Crear un objeto de la clase Pila
    Pila miPila;

    miPila.push(100);
    miPila.push(200);
    miPila.push(300);

    cout << "Elemento superior: " << miPila.peek() << "\n";

    cout << "Elemento eliminado: " << miPila.pop() << "\n";

    cout << "Elemento superior: " << miPila.peek() << "\n";

    return 0;
}