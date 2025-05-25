#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int n, x; cin >> n >> x;
        
        vector<int> arr(n);
        for (auto &i: arr) cin >> i;

        sort(arr.begin(), arr.end(), greater<int>());

        long long aux = 0;
        int sum = 0;
        int contador = 0;
        int menor = 1e9+1;
        for (int i = 0; i < n; i++){
            if (arr[i] >= x) sum++;
            else {
                aux += arr[i];
                menor = min(menor, arr[i]);
                contador++;
                if (menor * contador >= x) {
                    sum++;
                    contador = 0;
                    aux = 0;
                }
            }
        }

        cout << sum << "\n";
    }

}
