#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n*2);
    iota(arr.begin(), arr.end(), 1);

    n *= 2;

    vector<int> up, down;

    // up.push_back(arr.back());
    // arr.pop_back();
    
    for (int i = 0, j = n/2; i < n/2 && j < n; i += 2, j += 2){
        up.push_back(arr[i]);
        up.push_back(arr[j]);
    }
    for (int i = 1, j = n/2 + 1; i < n/2 && j < n; i += 2, j += 2){
        down.push_back(arr[i]);
        down.push_back(arr[j]);
    }


    // reverse(up.begin(), up.end());
    reverse(down.begin(), down.end());

    for (int i = 1; i < n/4; i += 2){
        swap(down[i], down[(n/2)-i]);
    }

    for (auto &i : down) cout << i << " ";
    cout << "\n";
    for (auto &i : up) cout << i << " ";
    cout << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}