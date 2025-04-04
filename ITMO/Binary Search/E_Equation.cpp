#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    double c; cin >> c;

    double l = 0, r = 1e18;
    while (r - l > 1e-8){
        double mid = l + (r-l)/2;

        if ((mid*mid + sqrt(mid) - c) > 1e-8){
            r = mid;
        }
        else l = mid;
    }

    cout << fixed << setprecision(10);
    cout << r << "\n";
}
