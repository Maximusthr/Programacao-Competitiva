#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, k;
vector<int> arr;

bool ok(int mid){
    int dist = arr[0];

    int c = 1;
    for (int i = 1; i < n; i++){
        int temp = arr[i] - dist;
        if (temp >= mid){
            dist = arr[i];
            c++;
        }
    }

    return c >= k;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;

    while(t--){
        cin >> n >> k;
    
        arr.resize(n);
        for (auto &i : arr) cin >> i;
        sort(arr.begin(), arr.end());
    
        int l = 0, r = 1e9;
        while (l < r){
            int mid = l + (r-l+1)/2;
    
            if (ok(mid)){
                l = mid;
            }
            else r = mid - 1;
        }
        cout << l << "\n";
    }
}