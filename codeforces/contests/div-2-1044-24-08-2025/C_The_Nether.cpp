// UPSOLVE

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<pair<int, int>> arr(n+1);

    for (int i = 1; i <= n; i++){
        cout << "? " << i << " " << n << " ";
        for (int j = 1; j <= n; j++){
            cout << j << " ";
        }
        cout << endl;

        int x; cin >> x;
        arr[i] = {x, i};
    }

    sort(arr.begin(), arr.end(), greater<pair<int, int>>());

    vector<int> caminho;
    caminho.push_back(arr[0].second);

    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (arr[i].first == arr[j].first) continue;
            cout << "? " << arr[i].second << " " << 2 << " " << arr[i].second << " " << arr[j].second << endl;

            int x; cin >> x;
            if (x == 2){
                caminho.push_back(arr[j].second);
                i = j-1;
                break;
            }
        }
    }

    cout << "! " << caminho.size();
    for (auto v : caminho) cout << " " << v;
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}