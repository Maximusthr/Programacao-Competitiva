#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 1);

    int i = 0, j = n-1, temp = 0;
    bool stop = false;
    vector<int> v;
    while(i <= j){
        while(temp < k-1 && j > i){
            v.push_back(arr[j]);
            j--;
            temp++;
        }
        if (i <= j){
            v.push_back(arr[i]);
            i++;
            temp = 0;
        }
    }

    for (auto &i : v) cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}