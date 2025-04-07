#include <bits/stdc++.h>

using namespace std;

const int MAX = 10000001;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    vector<int> crivo(MAX);

    crivo[1] = 1;
    for (long long i = 2; i < MAX; i++){
        if (crivo[i] == 0) {
            crivo[i] = i;
            for (long long j = i * i; j < MAX; j += i){
                if (crivo[j] == 0) crivo[j] = i;
            }
        }
    }

    int x; 

    while(cin >> x){
        cout << 1;
        while (x > 1){
            cout << " x " << crivo[x];
            x /= crivo[x];
        }
        cout << "\n";
    }
}

