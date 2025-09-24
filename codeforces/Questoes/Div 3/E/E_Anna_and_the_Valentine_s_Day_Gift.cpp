#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<string> arr(n);
    for (int i = 0; i < n; i++){
        string s; cin >> s;

        reverse(s.begin(), s.end());
        arr[i] = s;
    }

    sort(arr.begin(), arr.end());

    int ans = 0;
    bool foi = false;
    for (int i = 0; i < n; i++){
        if (foi){
            foi ^= 1;
            ans += (int)arr[i].size();
            continue;
        }
        if (arr[i][0] == '0'){
            reverse(arr[i].begin(), arr[i].end());

            while (arr[i].back() == '0') arr[i].pop_back();
            foi = true;
        }
        ans += (int)arr[i].size();
    }

    cout << (ans > m ? "Sasha" : "Anna") << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}