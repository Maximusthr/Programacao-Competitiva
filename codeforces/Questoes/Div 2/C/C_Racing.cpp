#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    pair<int, int> ini = {0, 0};

    vector<pair<int, int>> jump(n);
    for (auto &i : jump){
        cin >> i.first >> i.second;
    }

    bool ok = true;
    vector<pair<int, int>> pos(n);
    for (int i = 0; i < n; i++){
        auto [x, y] = jump[i];

        if (arr[i] == -1){
            ini.second++;
        }
        else if (arr[i] == 0){

        }
        else {
            ini.first++;
            ini.second++;
        }
        if (x > ini.second || ini.first > y){
            cout << -1 << "\n";
            return;
        }
        ini.second = min(ini.second, y);
        ini.first = max(ini.first, x);
        pos[i] = {ini.first, ini.second};
    }


    // restaurar de tras pra frente
    int h = ini.first;
    for (int i = n-1; i >= 0; i--){
        int l = 0, r = 0;
        if (i > 0){
            l = pos[i-1].first;
            r = pos[i-1].second;
        }

        if (arr[i] == 1) h--;
        if (arr[i] == -1){
            if (h > r || h < l){
                h--;
                arr[i] = 1;
            }
            else arr[i] = 0;
        }
    }

    // cout << ini.first << " " << ini.second << "\n";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " \n"[i == n-1];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}