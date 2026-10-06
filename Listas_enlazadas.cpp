#include <iostream>
using namespace std;

const int CAPACIDAD = 10;     //Tamaño fijo de los arreglos (memoria simulada)
const int NULO = -1;          // Representa "puntero nulo" usando -1

class ListaCursores {
private:
    int data[CAPACIDAD];      // Arreglo paralelo: valores
    int next[CAPACIDAD];      // Arreglo paralelo:  cursor al siguiente 
    int head;                 // Cursor al primer nodo de la lista
    int free_;                // Cursor al primer espacio libre

public:
    // Constructor: inicializa todos los espacios como libres,
    // Enlazados entre si (0 -> 1 -> 2 -> ... -> CPACIDAD-1 -> NULO)
    ListaCursores() {
        for (int i = 0; i < CAPACIDAD; i++) {
            next[i] = i +  1;
        }
        next[CAPACIDAD - 1] =  NULO;
        free_ = 0;       // El primer libre es la posicion 0
        head = NULO;     // La lista empieza vacia
    }

// Toma un espacio libre del arreglo (equivalente a "new" / "malloc")
int asignarNodo() {
    if (free_ == NULO) {
        cout << "¡Sin espacio disponible! (arreglo lleno)\n";
        return NULO;
    }
    int nodo = free_;      // Tomamos el primer libre
    free_ = next[free_];   // Avanzamos el curso
    return nodo; 
}

// Devuelve un espacio al "monton" de libres (equivalente a "delete" / "free")
void liberarNodo(int idx) {
    next[idx] = free_;    // El nodo liberado apunta al antiguo libre
    free_ = idx;          // Ahora el primer libre es este nodo
}

// Inserta un valor al INICIO de la lista
void insertarinicio(int valor) {
    int nuevo = asignarNodo();
    if (nuevo == NULO) return;

    data[nuevo] = valor;
    next[nuevo] = head;     // El nuevo nodo apunta al antiguo head
    head = nuevo;           // El head ahora es el nuevo nodo
}

// Elimina la PRIMERA ocurrencia de un valor en la lista
void eliminarValor(int valor) {
    int actual = head;
    int anterior = NULO;

    while (actual != NULO && data[actual] != valor) {
        anterior = actual;
        actual = next[actual];
    }

    if (actual == NULO) {
        cout << "Valor " << valor << " no encontrado. \n";
        return;
    }

    // Desconectar el nodo "actual" de la lista
    if (anterior == NULO) {
        head = next[actual];
    } else {
        next[anterior] = next[actual]; // Saltar el nodo eliminado

    }

    liberarNodo(actual);    // Regresar el espacio a la lista de libred
}

// Recorre e imprime la lista siguiendo los cursores desde head
void imprimir() {
    int actual = head;
    cout << "Lista: ";
    if (actual ==  NULO) cout << "(vacia)";
    while (actual != NULO) {
        cout << data[actual];
        if (next[actual] != NULO) cout << " -> ";
        actual = next[actual];    
    }
    cout << "\n";
}

// Muestra el estado interno de los arreglos paralelos (para depurar
// y comparar con la traza hacha a mano / con la IA)
void mostrarEstadoInterno() {
    cout << "\n idx : ";
    for (int i = 0; i < CAPACIDAD; i++) cout << i << " ";
    cout << "\n data : ";
    for (int i = 0; i < CAPACIDAD; i++) cout << data[i] << " ";
    cout << "\n next : ";
    for (int i = 0; i < CAPACIDAD; i++) cout << next[i] << " ";
    cout << "\n head : " << head << " | free = " << free_ << "\n\n";
    }
};

int main() {
    ListaCursores lista;

    cout << "== Insertando 30, 20, 10 al inicio ==\n";
    lista.insertarinicio(30);
    lista.insertarinicio(20);
    lista.insertarinicio(10);
    lista.imprimir();
    lista.mostrarEstadoInterno();

    cout << "== eliminando el valor 20 ==\n";
    lista.eliminarValor(20);
    lista.imprimir();
    lista.mostrarEstadoInterno();

    cout << "== Insertando 40 al inicio (reutiliza al espacio liberado) ==\n";
    lista.insertarinicio(40);
    lista.imprimir();
    lista.mostrarEstadoInterno();

    return 0;
}