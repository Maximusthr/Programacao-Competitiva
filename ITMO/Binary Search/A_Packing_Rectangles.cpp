#include <bits/stdc++.h>

using namespace std;

long long w, h, n; 

bool isGood(long long x){
    return (x/w) * (x/h) >= n;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cin >> w >> h >> n;

    long long ans = -1;
    long long l = 1;
    long long r = 1;

    // find r that is good
    while(!isGood(r)) r *= 2;

    while (l <= r){
        long long mid = l + (r-l)/2;

        if (isGood(mid)){
            ans = mid;
            r = mid-1;
        }
        else l = mid + 1;
    }

    cout << ans << "\n";
}
