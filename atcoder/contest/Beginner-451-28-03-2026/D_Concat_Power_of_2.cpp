#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// upsolve

const int MAX = 1e9+1;

void solve(){
    int n; cin >> n;

    vector<string> arr;
    for (int i = 1; i < MAX ; i *= 2){
        arr.push_back(to_string(i));
    }
    
    vector<int> ans;
    queue<string> q;
    set<string> vis;

    for (int i = 0; i < arr.size(); i++){
        q.push(arr[i]);
        vis.insert(arr[i]);
        ans.push_back(stoi(arr[i]));
    }

    while(!q.empty()){
        string s = q.front();
        q.pop();

        for (int i = 0; i < arr.size(); i++){
            string t = arr[i] + s;
            if (t.size() >= 10) continue;

            int valor = stoi(t);
            if (valor >= MAX || vis.count(t)) continue;

            ans.push_back(valor);
            vis.insert(t);
            q.push(t);
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans[n-1] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}