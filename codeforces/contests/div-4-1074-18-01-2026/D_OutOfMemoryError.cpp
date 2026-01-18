#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m, h; cin >> n >> m >> h;

    vector<pair<int, int>> arr(n);
    map<int, pair<ll, int>> mapa;
    for (int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = 0;
        mapa[i].first = arr[i].first;
    }

    int ativou = 0;
    while(m--){
        int idx, v; cin >> idx >> v;
        idx--;

        if (mapa[idx].second != ativou){
            mapa[idx].first = arr[idx].first;
            mapa[idx].second = ativou;

        }
        mapa[idx].first += v;

        if (mapa[idx].first > h){
            ativou++;
        }
    }

    for (int i = 0; i < n; i++){
        if (mapa[i].second != ativou){
            cout << arr[i].first << " ";
        }
        else cout << mapa[i].first << " ";
    }
    cout << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}