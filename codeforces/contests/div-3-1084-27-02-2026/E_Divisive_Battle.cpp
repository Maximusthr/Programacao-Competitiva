    #include <bits/stdc++.h>

    using namespace std;
    using ll = long long;
    const int INF = 0x3f3f3f3f;
    const ll LINF = 0x3f3f3f3f3f3f3f3fll;

    vector<int> crivo;
    const int MAX = 1e6+5;

    void solve(){
        int n; cin >> n;

        vector<int> arr(n);
        for (auto &i : arr) cin >> i;

        if (is_sorted(arr.begin(), arr.end())){
            cout << "Bob" << "\n";
            return;
        }

        vector<int> copy = arr;

        int maior = 0;
        int primo = 0;
        for (int i = 0; i < n; i++){
            if (primo > copy[i]){
                cout << "Alice" << "\n";
                return;
            }

            multiset<int, greater<int>> fact;
            while(copy[i] > 1){
                fact.insert(crivo[copy[i]]);
                copy[i] /= crivo[copy[i]];
            }

            if (fact.size() == 1 || fact.size() == 0){
                if (fact.size() == 1) primo = max(primo, arr[i]);
                if (maior > arr[i]){
                    cout << "Alice" << "\n";
                    return;
                }
                continue;
            }

            int x = *fact.begin();
            if (maior > x){
                cout << "Alice" << "\n";
                return;
            }
            maior = max(maior, x);
            
            vector<int> fatores = {fact.begin(), fact.end()};

            for (int i = 1; i < fatores.size(); i++){
                if (maior > fatores[i] || primo > fatores[i]){
                    cout << "Alice" << "\n";
                    return;
                }
            }
        }
        if (maior == 0) cout << "Alice" << "\n";
        else cout << "Bob" << "\n";
    }

    int main(){
        ios_base::sync_with_stdio(0); cin.tie(NULL);

        crivo.resize(MAX);

        crivo[0] = 0;
        crivo[1] = 1;

        for (ll i = 2; i < MAX; i++){
            if (crivo[i] == 0){
                crivo[i] = i;
                for (ll j = i * i; j < MAX; j += i){
                    if (crivo[j] == 0){
                        crivo[j] = i;
                    }
                }
            }
        }

        int t; cin >> t;
        while(t--){
            solve();
        }
    }