#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5 + 5;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    vector<int> freq(MAX);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        freq[arr[i]]++;
    }

    vector<int> zero, um;

    for (int i = 0; i < MAX; i++){
        if (freq[i] == 0) {
            zero.push_back(i);
            break;
        }
        else if (freq[i] == 1) um.push_back(i);
    }

    int ans = (zero.size() > 0 ? zero[0] : 0);
    bool tem = ((int)um.size() >= 2);

    for (int i = 0; i <= min(zero[0], (tem ? um[1] : INF)); i++){
        if (freq[i] >= 0) ans = i;
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}