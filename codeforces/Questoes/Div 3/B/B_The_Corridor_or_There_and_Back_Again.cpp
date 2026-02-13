#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<pair<int, int>> traps(n);
    map<int, int> mapa;
    for (int i = 0; i < n; i++){
        cin >> traps[i].first >> traps[i].second;
        if (mapa[traps[i].first] > 0) mapa[traps[i].first] = min(mapa[traps[i].first], traps[i].second);
        else mapa[traps[i].first] = traps[i].second;
    }

    auto ok = [&](int mid) -> bool {
        map<int, int> aux;

        for (int i = 1; i <= mid; i++){
            if (mapa[i] > 0){
                aux[i] = i-1 + mapa[i];
            }
        }
        int count = mid;
        for (int i = mid; i >= 0; i--){
            if (aux[i] > 0){
                if (count > aux[i]){
                    return false;
                }
            }
            count++;
        }

        return true;
    };

    int l = 0, r = 450;
    while(l < r){
        int mid = l + (r-l+1)/2;

        if (ok(mid)){
            l = mid;
        }
        else r = mid - 1;
    }    

    cout << l << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}