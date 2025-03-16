#include <bits/stdc++.h>

using namespace std;

bool val(double x, double &k, vector<double> &v){
    int sum = 0;
    for (int i = 0; i < (int)v.size(); i++){
        sum += (v[i]/x);
    }
    return (sum >= k);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    double n, k; cin >> n >> k;

    vector<double> v(n);
    for (auto &i : v) cin >> i;

    double l = 0, r = 1e9;

    while(r - l > 1e-7){ // you can use for (int i = 0; i < 100; i++)
        double mid = l + (r-l)/2;

        if (val(mid, k, v)){
            l = mid;
        }
        else r = mid;
    }

    cout << fixed << setprecision(10);
    cout << r << "\n";
}
