#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, k;
vector<int> arr;
const int MAX = 2e5+1;

bool ok(int mid){
    int seg = 0;
    int mex = 0;

    vector<bool> teste(MAX);

    for (int i = 0; i < n; i++){
        if (arr[i] < mid){
            if (teste[arr[i]]) continue;
            teste[arr[i]] = true;

            if (teste[mex]){
                for (int j = mex+1; j <= mid; j++){
                    if (!teste[j]){
                        mex = j;
                        break;
                    }
                }
            }
        }

        if (mex >= mid){
            seg++;
            teste.assign(MAX, false);
            mex = 0;
        }
    }

    return (seg >= k);
}

void solve(){
    cin >> n >> k;

    arr.resize(n);
    for (auto &i : arr) cin >> i;

    int l = 0, r = 2e5+1;
    while(l < r){
        int mid = l + (r-l + 1)/2;

        if (ok(mid)){
            l = mid;
        }
        else r = mid - 1;
    }

    cout << l << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}