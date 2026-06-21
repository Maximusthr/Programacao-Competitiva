#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s;

    vector<string> arr;
    
    while(cin >> s){
        if (s[0] == '#') break;
        arr.push_back(s);
    }

    vector<bool> tem(26);

    vector<int> deg(26);
    vector<vector<int>> g(26);

    int n = arr.size();

    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < arr[i].size(); j++){
            tem[arr[i][j]-'A'] = true;
            tem[arr[i+1][j]-'A'] = true;

            if (arr[i][j] != arr[i+1][j]){
                g[arr[i][j]-'A'].push_back(arr[i+1][j]-'A');
                deg[arr[i+1][j]-'A']++;
                break;
            }
        }
    }

    queue<int> q;
    for (int i = 0; i < 26; i++){
        if (deg[i] == 0 && tem[i]) q.push(i);
    }

    vector<int> topo;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        topo.push_back(u);

        for (auto v : g[u]){
            deg[v]--;
            if (deg[v] == 0) {
                q.push(v);
            }
        }
    }

    for (int i = 0; i < topo.size(); i++){
        char c = topo[i] + 'A';
        cout << c;
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}