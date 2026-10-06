#include <iostream>
using namespace std;

const int MAX = 5;

class Pila {
private:
    int  datos[MAX];
    int top;
    
public:
    Pila() {
        top = -1;
    }

    bool estaVacia() {
        return top == -1;
    }

    bool estaLlena() {
        return top == MAX - 1;
    }

    void push(int valor) {
        if (estaLlena()) {
            cout << "Error: la pila esta llena.\n";
            return;
        }

        top++;
        datos[top] = valor;

        cout << "se agrego: " << valor << "\n";   
    }

    int pop() {
        if (estaVacia()) {
            cout << "Error: la pila esta vacia." << "\n";
            return -1;
        }
        
        int valor = datos[top];
        top --;

        return valor;
    }

    int peek() {
        if (estaVacia()) {
            cout << "La pila esta Vacia." << "\n";
            return -1;
        }
        
        return datos[top];
    }
};

int main() {
    Pila pila;

    pila.push(10);
    pila.push(20);
    pila.push(30);

    cout << "Elemento superior: " << pila.peek() << "\n";

    cout << "Elemento eliminado: " << pila.pop() << "\n";

    cout << "Nuevo elemento superior: " << pila.peek() << "\n";

    return 0;
}   