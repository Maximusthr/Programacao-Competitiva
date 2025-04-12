#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int k, n, w; cin >> k >> n >> w;

    long long sum = k * ((w*(w+1))/2);

    if (n - sum >= 0) cout << 0 << "\n";
    else cout << abs(n-sum) << "\n";
}
