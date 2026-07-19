#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int sum = accumulate(arr.begin(), arr.end(), 0);
    if (sum == 0){
        cout << "YES" << "\n";
        return;
    }

    for (int i = 0; i < n-1; i++){
        if (sum > 0){
            if (arr[i] > 0 && arr[i+1] > 0){
                sum -= 4;
                arr[i] = -1;
                arr[i+1] = -1;
            }
        }
        else if (sum < 0){
            if (arr[i] < 0 && arr[i+1] < 0){
                sum += 4;
                arr[i] = 1;
                arr[i+1] = 1;
            }
        }

        if (sum == 0){
            cout << "YES" << "\n";
            return;
        }
    }
    cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}