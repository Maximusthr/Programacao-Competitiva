#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+5;

void solve(){
    int n, k; cin >> n >> k;
    
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end());

    vector<int> new_arr;
    vector<bool> elem(MAX);
    int oper = 0;
    for (int i = 0; i < n; i++){
        if (elem[arr[i]] && oper <= n-k+1) {
            oper++;
            continue;
        }

        new_arr.push_back(arr[i]);
        elem[arr[i]] = 1;
    }

    arr.clear();
    for (int i = new_arr.size()-1; i >= 0; i--){
        if (oper < n-k+1) {
            elem[new_arr[i]] = 0;
            oper++;
            continue;
        }

        arr.push_back(new_arr[i]);
    }

    int i = 0;
    while (elem[i]){
        i++;
    }

    cout << i << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}