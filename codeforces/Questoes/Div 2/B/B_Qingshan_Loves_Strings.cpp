#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int n, m; cin >> n >> m;

        string s, u; cin >> s >> u;

        bool ok = false;
        vector<pair<char, char>> val;
        for (int i = 1; i < n; i++){
            if (s[i] == s[i-1]) {
                val.push_back({s[i-1], s[i]});
                ok = true;
            }
        }

        if (!ok) cout << "YES" << "\n";
        else {
            bool u_good = false;

            for (int i = 1; i < m; i++){
                if (u[i] == u[i-1]) {
                    u_good = true;
                    break;
                }
            }
            if (u_good) cout << "NO" << "\n";
            else {
                bool good = true;
                for (int i = 0; i < (int)val.size(); i++){
                    if (val[i].first == u[0] || val[i].second == u[m-1]) good = false;
                }
                if (good) cout << "YES" << "\n";
                else cout << "NO" << "\n";
            }
        }
    }
}