// CS. TLE

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        string s; cin >> s;
        int tam = (int)s.size();

        int q; cin >> q;
        vector<pair<int, int>> index;
        for (int i = 0; i < q; i++){
            int x, y; cin >> x >> y;
            x--;
            index.push_back({x, y});
        }

        for (int i = 0; i < q; i++){

            s[index[i].first] = index[i].second + '0';

            bool ok = false;
            for (int j = 0; j < tam-3; j++){
                if (s[j] == '1' && s[j+1] == '1' && s[j+2] == '0' && s[j+3] == '0') {
                    ok = true;
                    break;
                }
            }

            cout << (ok ? "YES" : "NO") << "\n";
        }
    }
}
