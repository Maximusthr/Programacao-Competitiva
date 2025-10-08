#include <bits/stdc++.h>

using namespace std;

// funcao em raiz(n)
int phi(int n){
    int result = n;

    for (int i = 2; i * i <= n; i++){
        if (n % i == 0){
            while (n % i == 0){
                n /= i;
            }
            result -= result/i;
        }
    }

    if (n > 1) result -= result/n;

    return result;
}

const int MAX = 1e6;

int main(){
    
    // Totiente
    vector<int> phi(MAX);
    for (int i = 0; i < MAX; i++){
        phi[i] = i;
    }
    for (int i = 2; i < MAX; i++){
        if (phi[i] == i){
            for (int j = i; j < MAX; j += i){
                phi[j] -= phi[j]/i;
            }
        }
    }

}