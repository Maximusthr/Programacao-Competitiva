#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr;

    auto modify = [&](int x){
        arr.push_back(x+1);
        arr.push_back(x);
        arr.push_back(x);
        arr.push_back(x+1);
        arr.push_back(x+1);
        arr.push_back(x);
        arr.push_back(x+1);
        arr.push_back(x);
    };

    for (int i = 1; i < n; i += 2){
        modify(i);
    }

    if (n & 1){
        arr.insert(arr.begin(), n);
        arr.insert(arr.begin() + 1, n);
        arr.insert(arr.begin() + 3, n);
        arr.insert(arr.begin() + 6, n);
    }

    for (auto &i : arr) cout << i << " ";
    cout << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}