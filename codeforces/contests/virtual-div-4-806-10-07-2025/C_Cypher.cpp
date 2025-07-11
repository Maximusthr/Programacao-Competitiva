#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    for (int i = 0; i < n; i++){
        int x; cin >> x;
        string s; cin >> s;
        for (int j = 0; j < x; j++){
            if (s[j] == 'D'){
                arr[i]++;
                arr[i] %= 10;
            }
            else if (s[j] == 'U'){
                arr[i]--;
                if (arr[i] < 0){
                    arr[i] = 9;                    
                }
            }
        }
    }

    for (auto i : arr) cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}