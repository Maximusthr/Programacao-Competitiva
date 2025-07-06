#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    vector<int> aux = arr;
    sort(aux.begin(), aux.end());

    bool ok = false;
    for (int i = 0; i < n; i++){
        if (aux[i] == arr[i]){
            ok = true;
            break;
        }
    }
    if (!ok) {
        cout << "YES" << "\n";
        cout << arr.size() << "\n";
        for (auto &i : arr) cout << i << " ";
        cout << "\n";
        return;
    }
    else {
        while(arr.size() > 0){
            ok = false;
            for (int i = 0; i < arr.size(); i++){
                if (aux[i] == arr[i]){
                    aux.erase(aux.begin()+i, aux.begin()+i+1);
                    arr.erase(arr.begin()+i, arr.begin()+i+1);
                    ok = true;
                    break;
                }
            }
            if (!ok){
                cout << "YES" << "\n";
                cout << arr.size() << "\n";
                for (auto &i : arr) cout << i << " ";
                return;
            }
        }
        cout << "NO" << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}