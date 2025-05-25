#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int x; cin >> x;

        vector<int> arr(x);

        for (auto &i: arr) cin >> i;

        map<int, int> lista;
        
        bool ok = false;
        for (int i = 0; i < (int)arr.size(); i++){
            lista[arr[i]]++;
            if (lista[0] >= 3 && lista[1] >= 1 && lista[2] >= 2 && lista[3] >= 1 && lista[5] >= 1) {
                cout << i+1 << "\n";
                ok = true;
                break;
            }
        }

        if (!ok) cout << 0 << "\n";
    }
}