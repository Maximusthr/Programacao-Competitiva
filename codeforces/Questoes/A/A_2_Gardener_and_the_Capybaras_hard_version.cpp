#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        string a; cin >> a;

        string x, y, z;

        if (a[0] == 'a' && a[1] == 'a' || a[0] == 'b' && a[1] == 'b' || a[0] == 'b' && a[1] == 'a'){
            x += a[0];
            y += a[1];
            for (int i = 2; i < a.size(); i++){
                z += a[i];
            }
        }
        else {
            bool ok = false; // check if there is another a on the string
            int pos = 0;
            for (int i = 2; i < a.size(); i++){
                if (a[i] == 'a') {
                    ok = true;
                    pos = i;
                    break;
                }
            }
            if (ok){
                x += a[0];
                for (int i = 1; i < pos; i++){
                    y += a[i];
                }
                for (int i = pos; i < a.size(); i++){
                    z += a[i];
                }
            }
            else {
                for (int i = 0; i < a.size()-2; i++){
                    x += a[i];
                }
                y += a[a.size()-2];
                z += a[a.size()-1];
            }
        }

        cout << x << " " << y << " " << z << "\n";
    }
}
