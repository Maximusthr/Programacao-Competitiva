// Busca binária: Lower bound
// Dado um x, encontrar o menor valor que seja maior ou igual a x;

// EXISTE A FUNÇÃO LOWER BOUND QUE FAZ ISSO.
// A FUNÇÃO UPPER BOUND encontra o PRIMEIRO elemento estritamente maior que x.

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;

int n, m;
int v[maxn];

int busca(int x){
    int ini = 1, fim = n;
    int ans = -1;

    while (ini <= fim){
        int mid = (ini+fim)/2;
        if (v[mid] >= x){
            ans = v[mid];
            fim = mid-1;
        }
        else ini = mid+1;
    }

    return ans;
}

int main(){

}
