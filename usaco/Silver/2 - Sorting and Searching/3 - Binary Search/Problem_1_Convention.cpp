#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, b, c;
vector<int> arr;

bool ok(int mid){
    int aloc = 1, dif = arr[0], bus = 1;

    int j = 1;
    while (j < n){
        if (aloc == c || arr[j] - dif > mid){
            dif = arr[j];
            aloc = 1;
            bus++;
        }
        else aloc++;
        j++;
    }

    return bus <= b;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);

    cin >> n >> b >> c;

    arr.resize(n);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end());

    int l = 0, r = 1e9+1;
    while(l < r){
        int mid = l + (r-l)/2;

        if (ok(mid)){
            r = mid;
        }
        else l = mid + 1;
    }

    cout << l << "\n";
}