#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        double d, h; cin >> d >> h;

        vector<int> arr(n);
        for (auto &i : arr) cin >> i;

        double ans = 0;

        for (int i = 0; i < n-1; i++){
            if (arr[i] + h > arr[i+1]){
                // trapezio
                double new_h = arr[i+1] - arr[i];
                double b = d * (h - new_h)/h; // base menor
                ans += new_h * (d + b)/2;
            }
            else ans += (d*h)/2;
        }

        // area last
        ans += (d*h)/2;

        cout << fixed << setprecision(9) << ans << "\n";
    }
}
