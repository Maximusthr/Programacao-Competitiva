#include <iostream>

using namespace std;

const int MAX_TAMANHO = 1000001; // tamanho máximo a ser definido, nesse caso coloquei 10^6
int v[MAX_TAMANHO];

int main() {
  int tamanho = 0, qtd_op;
  cin >> qtd_op;
  // Caso a operação seja do formato:
  // 0 X
  // Adiciono o elemento X no fim do vetor
  // Caso seja:
  // 1
  // Removo o elemento que está no fim do vetor
  for (int i = 0; i < qtd_op; i++) {
    int tipo;
    cin >> tipo;
    if (tipo == 0) {
      int x;
      cin >> x;
      v[tamanho] = x;
      tamanho++;
    } else {
      tamanho--;
    }
  }
  // Imprimo o vetor
  for (int i = 0; i < tamanho; i++) {
      cout << v[i] << " ";
  }
  cout << "\n";
}