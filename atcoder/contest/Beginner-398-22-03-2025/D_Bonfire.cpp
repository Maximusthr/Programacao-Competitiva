#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, r, c; cin >> n >> r >> c;

    pair<int, int> par = {r, c};
    pair<int, int> fog = {0, 0};

    string s; cin >> s;

    set<pair<int, int>> pos;
    pos.insert(fog);

    for (int i = 0; i < n; i++){
        if (s[i] == 'N') {
            fog.first++;
            par.first++;
        }
        else if (s[i] == 'S') {
            fog.first--;
            par.first--;
        }
        else if (s[i] == 'W') {
            fog.second++;
            par.second++;
        }
        else {
            fog.second--;
            par.second--;
        }

        pos.emplace(fog);
        if (pos.count(par)){
            cout << 1;
        }
        else cout << 0;
    }
    cout << "\n";
}