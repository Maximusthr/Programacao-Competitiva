#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    long long x; cin >> x;
    bool ok = false;

    for (int i = 1; i < 1000000; i++){
        long long l = 1;
        long long r = 1e12;
        while (l <= r){
            long long mid = l + (r-l)/2;

            // long long a = mid;
            // long long b = a + i;
            // long long p = (b*b*b) - (a*a*a);

            __int128_t a = (__int128_t) mid;
            __int128_t b = a + i;
            __int128_t p = (b*b*b)-(a*a*a);

            if (p == x) {
                ok = true;
                cout << mid+i << " " << mid << "\n";
                return 0;
            }
            else if (p < x) l = mid+1;
            else if (p > x) r = mid-1;
        }
    }

    if (!ok) cout << -1 << "\n";
}

// int main(){
//     #define ll long long
//     ll n;scanf("%lld",&n);
//     for(ll i=1;i<=1000000;i++){
//         ll l=1,r=1e12;
//         while(l<=r){
//             ll X=(l+r)>>1;
//             __int128 A=(__int128)X,B=A+i,P=B*B*B-A*A*A;
//             if(P==n){
//                 printf("%lld %lld\n",X+i,X);
//                 return 0;
//             }
//             if(P<n)l=X+1;else r=X-1;
//         }
//         //(x+i)^3-x^3=i(x^2+i^2+xi)
//     }
//     puts("-1");
//     return 0;
// }