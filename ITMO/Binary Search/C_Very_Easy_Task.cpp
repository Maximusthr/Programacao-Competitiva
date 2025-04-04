#include <bits/stdc++.h>

using namespace std;

long long n, x, y;

bool ok (long long m){
    long long aux_x = m/x;
    long long aux_y = m/y;

    return aux_x + aux_y >= n-1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> n >> x >> y;

    long long l = 0, r = 2e10+1;
    while(l < r){
        long long mid = l + (r-l)/2;

        if (ok(mid)){
            r = mid;
        }
        else l = mid + 1;
    }

    cout << r + min(x, y) << "\n";
}
