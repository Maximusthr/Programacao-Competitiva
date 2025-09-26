#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    vector<int> pos(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        pos[arr[i]-1] = i;
    }

    vector<int> ans;
    vector<int> rel;
    for (int i = n-1; i >= 0; i--){
        int new_pos = pos[i];
        for (int j = 0, k = n; j < rel.size(); j++, k--){
            new_pos = (k*1000 + new_pos - rel[j]) % k;
        }
        if (new_pos+1 == i+1) {
            rel.push_back(0);
        }
        else rel.push_back(new_pos + 1);
    }

    reverse(rel.begin(), rel.end());
    for (auto &i : rel) cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}