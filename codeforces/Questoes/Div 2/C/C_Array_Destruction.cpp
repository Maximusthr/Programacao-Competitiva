#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    n *= 2;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end(), greater<int> ());

    set<int> talvez;
    for (int i = 1; i < n; i++){
        talvez.insert(arr[0] + arr[i]);
    }
    
    for (auto i = talvez.begin(); i != talvez.end(); i++){
        multiset<int> aux = {arr.begin(), arr.end()};
        
        vector<int> oper;
        oper.push_back(*i);
        
        int x = *i;

        while(aux.size() > 0){
            bool ok = false;
            for (auto it = aux.begin(); it != aux.end(); it++){
                int v = *it;
                if (aux.count(x - v)){
                    if (x - v == v && aux.count(v) <= 1) continue;
                    oper.push_back(v);
                    oper.push_back(x - v);

                    aux.erase(aux.find(x - v));
                    aux.erase(aux.find(v));

                    x = max(x - v, v);
                    ok = true;
                    break;
                }
            }
            if (!ok) break;
        }

        if (aux.size() == 0){
            cout << "YES" << "\n";
            cout << oper[0] << "\n";
            for (int i = 1; i < oper.size(); i += 2){
                cout << oper[i] << " " << oper[i+1] << "\n";
            }
            return;
        }
    }

    cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}