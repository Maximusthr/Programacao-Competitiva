#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    string ans;
    int i = 0, j = n-1;
    bool alterna = false;

    while (i < j){

        if (alterna){
            if (arr[i] > arr[j]){
                ans += 'L';
                i++;
            }
            else if (arr[j] > arr[i]){
                ans += 'R';
                j--;
            }
        }
        else {
            if (arr[i] < arr[j]){
                ans += 'L';
                i++;
            }
            else if (arr[j] < arr[i]){
                ans += 'R';
                j--;
            }
        }
        alterna ^= 1;
    }
    if (i == j){
        ans += 'L';
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