#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e7+1;
vector<bool> prime(MAX, true);

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;
    
    prime[1] = false;
    for (long long i = 2; i < MAX; i++){
        if (!prime[i]) continue;
        for (long long j = i * i; j < MAX; j += i){
            prime[j] = false;
        }
    }

    while(t--){
        int x; cin >> x;
        int ans = 0;

        for (int i = 2; i <= x; i++){
            if (prime[i]) ans += x/i;
        }

        cout << ans << "\n";
    }

}
