#include <bits/stdc++.h>

using namespace std;
//Encontrar os números que possuem no subconjunto.
// Ex: [1, 2, 5] -> 7 faz parte? Sim, valores 2 e 5.

// complexidade dessa função -> O(2^n)
bool func(vector<int> &vetor, int n, int x){
    if (x == 0) return true;
    if (n == 0) return false;
    if (vetor[n] > x) return func(vetor, n-1, x);
    return func(vetor, n-1, x-vetor[n]) || func(vetor, n-1, x);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

}
