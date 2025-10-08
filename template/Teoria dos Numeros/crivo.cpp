#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX = 1e6;

int main(){
    
    // fatores
    vector<int> crivo(MAX);

    crivo[0] = 0;
    crivo[1] = 1;

    for (ll i = 2; i < MAX; i++){
        if (crivo[i] == 0){
            crivo[i] = i;
            for (ll j = i * i; j < MAX; j += i){
                if (crivo[j] == 0){
                    crivo[j] = i;
                }
            }
        }
    }


    // primo
    vector<int> crivo(MAX, true);

    crivo[0] = 0;
    crivo[1] = 0;

    for (ll i = 2; i < MAX; i++){
        if (crivo[i]){
            for (ll j = i * i; j < MAX; j += i){
                crivo[j] = false;
            }
        }
    }
}   
