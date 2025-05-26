//CS because of line 32 (I was using n-1 instead of aux.size()-1)

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        set<int> aux;
        for (int i = 0; i < n; i++){
            int x; cin >> x;
            aux.insert(x);
        }

        vector<int> arr;
        auto it = aux.begin();
        for (int i = 0; i < (int)aux.size(); i++, it++){
            arr.push_back(*it);
        }

        int sub = 1;
        int ans = (int)aux.size();
        for (int i = 0; i < aux.size()-1; i++){
            if (arr[i] + 1 == arr[i+1]) sub++;
            else {
                ans -= (sub/2);
                sub = 1;
            }
        }

        ans -= sub/2;
        cout << ans << "\n";
    }
}
