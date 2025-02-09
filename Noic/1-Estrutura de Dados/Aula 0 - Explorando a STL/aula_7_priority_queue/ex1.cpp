#include <iostream> // Biblioteca iostream necessária para funcionar
#include <algorithm>
#include <queue> // Biblioteca da queue
using namespace std;

// int main()
// {
// 	priority_queue<int> fila; // Fila de prioridade fila1 armazenando elementos do tipo int
    
//     fila.push(3);
//     fila.push(4);

//     printf("%d", fila.top());
  
//   	return 0;
// }

int main(){
    priority_queue<int, vector<int>, greater<int>> fila;

    fila.push(3);
    fila.push(4);

    printf("%d", fila.top());

}