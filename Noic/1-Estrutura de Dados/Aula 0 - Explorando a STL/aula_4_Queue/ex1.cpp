#include <iostream>
#include <queue> // Biblioteca da fila

using namespace std;

int main() 
{
	queue<int> fila; // Declaração de uma queue do tipo int

	fila.push(1); // Insiro o elemento 1 atrás na fila
	fila.push(3); // Insiro o elemento 3 atrás na fila
	fila.push(4); // Insiro o elemento 4 atrás na fila
	fila.push(9); // Insiro o elemento 9 atrás na fila

  	printf("%d\n", fila.front()); // Imprimo o 1º valor da fila = 1
	fila.pop(); // Removo o 1
	printf("%d\n", fila.front()); // Imprimo o 1º valor da fila = 3
	fila.pop(); // Removo o 3
	printf("%d\n", fila.front()); // Imprimo o 1º valor da fila = 4
	fila.pop(); // Removo o 4
	printf("%d\n", fila.front()); // Imprimo o 1º valor da fila = 9
	fila.pop(); // Removo o 9

	// Fila vazia
	return 0;
}
