#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int k = 1;
    int maior = n;
    bool ok = false;
    for (int i = 0; i < n; i++){
        int apareceu = -1;
        for (int j = 0; j < n; j++){
            if (arr[j] == maior){
                if (apareceu == -1){
                    apareceu = j;
                }
                if (j+1 < n && arr[j+1] == arr[j] - 1){
                    ok = true;
                }
                else if (j-1 >= 0 && arr[j-1] == arr[j] - 1){
                    ok = true;
                }
                else if (maior == 1){
                    ok = true;
                }

                if (ok){
                    int aux = 0;
                    int aux2 = apareceu;
                    while(aux < k){
                        arr[aux2++]--;
                        aux++;
                    }
                    k++;
                    maior--;
                }
                else continue;

                break;
            }
        }        
        if (ok){
            ok = false;
        }
        else {
            cout << "NO" << "\n";
            return;
        }
    }

    for (int i = 0; i < n; i++){
        if (arr[i] != 0){
            cout << "NO" << "\n";
            return;
        }
    }

    cout << "YES" << "\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}