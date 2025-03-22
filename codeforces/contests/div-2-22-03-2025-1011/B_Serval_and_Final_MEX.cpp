// Couldn't solve

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;

        vector<int> arr(n);
        for (auto &i : arr) cin >> i;

        int contador = 0;
        for (int i = 0; i < n; i++){
            if (arr[i] == 0) {
                contador++;
                break;
            }
        }

        bool ok = false;
        if (contador == 0) {
            cout << "1" << "\n";
            cout << "1 " << n << "\n";
            ok = true;
        }

        vector<int> copy = arr;
        vector<pair<int, int>> pares;
        int count = 0;

        if (!ok){
            while((int)copy.size() > 1){
                int tam = (int)copy.size();
    
                // for (int i = tam-1; i >= 0; i--){
                //     if (arr[i] == arr[i-1] && arr[i] == 0){
                //         count++;
                //         pares.push_back({i-1, i});
                //         copy[i-1] = 1;
                //         i--;
                //     }
                // }
    
                for (int i = tam-1; i >= 0; i--){
                    if (copy[i] != 0 && copy[i-1] != 0){
                        count++;
                        copy[i-1] = 0;
                        pares.push_back({i-1, i});
                        copy.pop_back();
                        tam--;
                    }
                }
    
                for (int i = tam-1; i >= 0; i--){
                    if (copy[i] == 0 && copy[i-1] != 0 || copy[i-1] != 0 && copy[i] == 0){
                        count++;
                        if (copy[i] == 1 || copy[i-1] == 1) copy[i-1] = 2;
                        pares.push_back({i-1, i});
                        copy.pop_back();
                        tam--;
                    }
                }   
            }
    
            cout << count << "\n";
            for (int i = 0; i < (int)pares.size(); i++){
                cout << pares[i].first << " " << pares[i].second << "\n";
            }
        }
    }
}
