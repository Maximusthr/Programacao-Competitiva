#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    long long x, y; cin >> x >> y;

    int ans = 0;
    while(x--){
        char c; cin >> c;
        //char space; cin >> space;
        long long num; cin >> num;
        if (c == '+') y += num;
        else {
            if (num > y) {
                ans++;
                continue;
            }
            else 
                y -= num;
        }
    }
    
    cout << y << " " << ans << "\n";
}
