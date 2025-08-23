// inspiração https://github.com/jonh14lk/Competitive_Programming/blob/master/Problem%20Solving/Subregional%202023/e.cpp

// UP-SOLVE

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e6 + 5;

int sum(int x){
    int ans = 0;

    while(x > 0){
        ans += x % 10;
        x /= 10;
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, k; cin >> n >> k;

    vector<int> freq(MAX);
    vector<int> lance(MAX);

    for (int i = 0; i < n; i++){
        int x; cin >> x;
        freq[x]++;
    }

    for (int i = 0; i < MAX; i++){
        lance[i] = i - sum(i);
    }

    int ans = 0;
    for (int i = MAX-1; i > 0; i--){
        k -= freq[i];
        freq[lance[i]] += freq[i];
        if (k <= 0){
            ans = i;
            break;
        }
    }

    cout << sum(ans) << "\n";
}