#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<string> s(n);
    for (auto &i : s) cin >> i;

    vector<int> deg(26);
    vector<vector<int>> g(26);

    for (int i = 0; i < n-1; i++){
        // verifico a atual com a posterior
        int sz = (int)s[i+1].size();

        bool flag = 0;
        for (int j = 0; j < min((int)s[i].size(), sz); j++){
            if (s[i][j] != s[i+1][j]){
                deg[s[i+1][j]-'a']++;
                g[s[i][j]-'a'].push_back(s[i+1][j]-'a');
                flag = 1;
                break;
            }
        }
        if (flag) continue;

        // os caracteres são iguais
        if (s[i].size() > sz){
            // abcd
            // abc
            cout << "Impossible" << "\n";
            return;
        }
    }

    queue<char> q;
    for (char i = 'a'; i-'a' < 26; i++){
        if (deg[i-'a'] == 0){
            q.push(i);
        }
    }
    
    string ans;
    
    while(!q.empty()){
        char c = q.front();
        q.pop();
        ans.push_back(c);

        for (auto v : g[c-'a']){
            deg[v]--;
            if (deg[v] == 0){
                q.push('a' + v);
            }
        }
    }

    // pode cair em ciclo ai é false s -> o -> s
    if (ans.size() != 26){
        cout << "Impossible" << "\n";
        return;
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}