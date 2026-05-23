#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<string> arr(n);
    for (auto &i : arr) cin >> i;

    map<char, int> mapa;
    int x = 2;
    int count = 1;
    for (char i = 'a'; i < 'p'; i++){
        if (count == 4) {
            count = 1;
            x++;
        }
        mapa[i] = x;
        count++;
    }

    mapa['p'] = mapa['q'] = mapa['r'] = mapa['s'] = ++x;
    mapa['t'] = mapa['u'] = mapa['v'] = ++x;
    mapa['w'] = mapa['x'] = mapa['y'] = mapa['z'] = ++x;

    string ans;
    for (int i = 0; i < n; i++){
        ans.push_back(mapa[arr[i][0]] + '0');
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}