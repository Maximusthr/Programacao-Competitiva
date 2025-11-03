#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    map<string, int> mapa;
    for (int i = 0; i < n; i++){
        string s; cin >> s;

        mapa[s]++;
        if (mapa[s] == 1) cout << "OK" << "\n";
        else cout << s << mapa[s]-1 << "\n";
    }
}