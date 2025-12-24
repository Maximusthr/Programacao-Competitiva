#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    queue<int> q;
    set<int> used;
    for (int i = 0; i < n; i++){
        int x; cin >> x;

        if (used.count(x)) continue;

        if (q.size() == k){
            int y = q.front();
            used.erase(y);
            q.pop();
            q.push(x);
            used.insert(x);
        }
        else {
            q.push(x);
            used.insert(x);
        }
    }

    vector<int> ans;
    while(!q.empty()){
        ans.push_back(q.front());
        q.pop();
    }

    reverse(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for (auto &i : ans) cout << i << " ";

    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}