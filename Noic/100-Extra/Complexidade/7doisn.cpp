#include <bits/stdc++.h>

using namespace std;

int main(){
  //Soma de conjunto, O(n*2^n)

  int n, v[20], m;
  cin >> n >> m;
  for(int i = 0; i < n; ++i){
    cin >> v[i]; //leitura, O(n) 
  }
  for(int mask = 0; mask < (1 << n); ++mask){ //passa por todos os subconjuntos O(2^n)
    int soma = 0;
    for(int i = 0; i < n; ++i){ //loop O(n)
      if((1 << i)&mask){ //checa se um elemento está nesse subconjunto
        soma += v[i];
      }
    }
    if(m == soma){
      for(int i = 0; i < n; ++i){
        if((1 << i)&mask){
          cout << i << " ";
        }
      }
      cout << "\n";
      break;
    }
  }
}