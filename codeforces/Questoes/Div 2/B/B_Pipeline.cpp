#include <bits/stdc++.h>

using namespace std;

long long sum(long long n){
    return (n * (n+1))/2;
}

long long terms(long long start, long long k){
    
    if (start <= 1) return sum(k);

    return sum(k) - sum(start-1);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    long long n, k; cin >> n >> k;

    // verifying if ans exist
    int ans = 0;
    long long formula = ((k*(k+1))/2 - 1) - (k-2);
    
    if (n > formula){
        cout << -1 << "\n";
        return 0;
    }
    else if (n == 1) {
        cout << 0 << "\n";
        return 0;
    }
    else if (n <= k) {
        cout << 1 << "\n";
        return 0;
    }
    else {
        n--;
        k--;
        // façamos a busca
        // how to access k? without array
        // lets use the formula (n(n+1))/2
        long long l = 1;
        long long r = k;
        while (l < r){
            long long mid = l + (r-l)/2;
            long long s = terms(mid, k);

            if (s == n) {
                ans = k - mid + 1;
                cout << ans << "\n";
                return 0;
            }
            else if (s > n){
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        ans = k - l + 2;
        cout << ans << "\n";
    }
}
