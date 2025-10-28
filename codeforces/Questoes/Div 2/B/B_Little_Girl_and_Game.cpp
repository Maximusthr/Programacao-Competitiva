#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    string s; cin >> s;

    int n = s.size();

    bool ok = true;
    map<char, int> mapa;
    for (int i = 0; i < n; i++){
        mapa[s[i]]++;
        if (s[i] != s[n-i-1]) {
            ok = false;
        }
    }

    if (ok){
        cout << "First" << "\n";
        return 0;
    }

    int odd = 0;
    for (auto [x, y] : mapa){
        if (y % 2) odd++;
    }

    if (odd % 2 || odd == 0){
        cout << "First" << "\n";
        return 0;
    }
    cout << "Second" << "\n";
}