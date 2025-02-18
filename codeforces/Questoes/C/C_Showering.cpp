#include <bits/stdc++.h>

using namespace std;

int main(){
    int qtd; cin >> qtd;

    while(qtd--){
        ios_base::sync_with_stdio(0); cin.tie(NULL);
        int n, s, m; cin >> n >> s >> m;
        
        vector<int> arr;
        bool ok = false;

        for (int i = 0; i < n; i++){
            int a, b; cin >> a >> b;
            if (i == 0 && a != 0){
                if (a >= s) ok = true;
            }
            if (i == n-1 && b != 10){
                if (m - b >= s) ok = true;
            }
            arr.push_back(a);
            arr.push_back(b);
        }

        if (!ok){
            for (int i = 0, j = 1; i < (int)arr.size(); i++, j+= 2){
                if (j + 2 >= (int)arr.size()) break;
                if (arr[j+1] - arr[j] >= s) {
                    ok = true;
                    break;
                }
            }
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }
}
