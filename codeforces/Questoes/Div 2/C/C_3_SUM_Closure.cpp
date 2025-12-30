#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    int pos = 0, neg = 0;
    for (auto &i : arr) {
        cin >> i;
        if (i > 0) pos++;
        else if (i < 0) neg++;
    }

    if (pos >= 3 || neg >= 3){
        cout << "NO" << "\n";
        return;
    }

    vector<int> new_arr;
    int count = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] == 0 && count < 2){
            count++;
            new_arr.push_back(arr[i]);
        }
        else if (arr[i] != 0) new_arr.push_back(arr[i]);
    }

    n = new_arr.size();

    multiset<int> aux = {new_arr.begin(), new_arr.end()};

    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            for (int k = j + 1; k < n; k++){
                if (!aux.count(new_arr[i] + new_arr[j] + new_arr[k])){
                    cout << "NO" << "\n";
                    return;
                }
            }
        }
    }

    cout << "YES" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}