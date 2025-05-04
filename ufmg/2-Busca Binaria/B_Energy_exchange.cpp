#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    double l = 0, r = 1001;
    while (abs(l-r) > 1e-7){
        double mid = l + (r-l)/2;

        double send = 0, need = 0;
        for (int i = 0; i < n; i++){
            if (arr[i] > mid) send += (arr[i]-mid) * (100-k)/100;
            else need += (mid-arr[i]);
        }
        if (send > need){
            l = mid;
        }
        else r = mid;
    }
    cout << fixed << setprecision(8) << l << "\n";
}
