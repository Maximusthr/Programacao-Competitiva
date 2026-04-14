#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s; cin >> s;
    string d; cin >> d;

    int n = s.size();

    struct P {
        int qtd;
        int idx;
        bool pode;
    };

    queue<P> q;
    
    for (int i = 0; i < n; i++){
        if (s[i] == d[0]){
            q.push({1, i, 1});
        }
    }

    while(!q.empty()){
        int qtd = q.front().qtd;
        int idx = q.front().idx;
        bool pode = q.front().pode;
        q.pop();

        if (qtd == d.size()){
            cout << "YES" << "\n";
            return;
        }

        int len = qtd;
        if (idx + 1 < n && pode){
            if (s[idx + 1] == d[len]){
                q.push({qtd+1, idx+1, 1});
            }
        }
        if (idx - 1 >= 0){
            if (s[idx - 1] == d[len]){
                q.push({qtd+1, idx-1, 0});
            }
        }
    }
    cout << "NO" << "\n";
}   

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}