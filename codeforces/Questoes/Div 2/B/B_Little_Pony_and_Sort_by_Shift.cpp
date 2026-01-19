#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    if (is_sorted(arr.begin(), arr.end())){
        cout << 0 << "\n";
        return;
    }

    // if (n == 2){
    //     cout << 1 << "\n";
    //     return;
    // }

    int ans = 0;
    int type = -1;
    vector<int> new_arr;
    for (int i = 0; i < n; i++){
        if (arr[i] > arr[(i+1)%n] && arr[i] >= arr[(i-1 == -1 ? n-1 : i-1)]){
            ans = n-i-1;
            int j = i+1;
            do {
                new_arr.push_back(arr[j]);
                j++;
                j %= n;
            }
            while (j != (i+1)%n);
            break;
        }
    }
    if (is_sorted(new_arr.begin(), new_arr.end())){
        cout << ans << "\n";
    }
    else cout << -1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}