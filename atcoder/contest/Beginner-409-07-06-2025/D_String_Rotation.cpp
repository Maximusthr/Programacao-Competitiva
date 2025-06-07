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

        string s; cin >> s;

        for (int i = 0; i < n-1; i++){
            if (s[i] > s[i+1]){
                int j = i;
                while (j < n-1 && s[j] >= s[j+1]){
                    swap(s[j], s[j+1]);
                    j++;
                }
                break;
            }
        }

        cout << s << "\n";
    }
}