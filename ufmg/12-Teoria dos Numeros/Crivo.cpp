#include <bits/stdc++.h>

using namespace std;

//crivo n log (n)
const int MAX = 1e6+1;

vector<bool> is_prime(MAX, true);

void prime(vector<bool> arr){
    for (int i = 2; i < (int)is_prime.size(); i++){
        if (!is_prime[i]) continue;
        for (int j = i*i; j < (int)is_prime.size(); j += i){
            is_prime[j] = true;
        }
    }
}

int main(){
    int x; cin >> x;

    // Crivo de Eratóstenes -> Verifica se todos são primos ou não
    prime(is_prime);
    return 0;
}
