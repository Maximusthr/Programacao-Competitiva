#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, t, k; cin >> n >> t >> k;
    
    int l = 1, r = n;
    while (l < r){
        int mid = l + (r-l)/2;
        
        cout << "? " << l << " " << mid << "\n";
        cout.flush();
        int x; cin >> x;

        int qtd_zeros = mid-l-x+1;

        if (qtd_zeros < k){
            l = mid + 1;
            k -= qtd_zeros;
        } else r = mid;
        
    }

    cout << "! " << l << "\n";
    cout.flush();
}
