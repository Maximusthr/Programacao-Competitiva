ll memo[20][2];

ll dp(const string &lim, int idx, int last, bool smaller){
    if (idx == lim.size()) return 1;

    auto &p = memo[idx][smaller];
    if (p != -1) return p;

    int ans =  0;
    for (int i = 0; i <= 9; i++){
        int x = lim[idx] - '0';

        if (!smaller && i > x) break;
        
        bool pode = true;
        if (!smaller && i == x){
            pode = false;
        }
        
        if (last == i) continue;
        ans += dp(lim, i, pode);
    }
    return p = ans;
}


// sem estados smaller ou greater

ll memo[50];
string l, r;
ll dp(int idx = 0, bool smaller = false, bool greater = false){
    if (l.size() == idx){
        return 1;
    }

    auto &p = memo[idx][three][six][nine];
    if (smaller && greater){
        if (p != -1) return p % MOD;
    }

    ll ans = 0;
    for (int i = 0; i <= 9; i++){
        int x = r[idx] - '0';
        int y = l[idx] - '0';

        if (!smaller && i > x) continue;
        if (!greater && i < y) continue;

        bool pode = true;
        if (!smaller && i == x) pode = false;
        bool gr = true;
        if (!greater && i == y) gr = false;

        ans %= MOD;
    }

    if (smaller && greater){
        p = ans % MOD;
    }

    return ans;
}
