#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int qtd; cin >> qtd;

    while(qtd--){
        int h, m;
        char c;
        cin >> h >> c >> m;
        bool hor = false;

        if (h >= 13) {
            h -= 12;
            hor = true;
        }
        else if (h == 12)
            hor = true;
        
        else if (h == 0)
            h += 12;

        if (hor){
            if (h < 10) cout << 0;
            cout << h << ":";
            if (m < 10) cout << 0;
            cout << m << " PM\n";
        }
        else {
            if (h < 10) cout << 0;
            cout << h << ":"; 
            if (m < 10) cout << 0;
            cout << m << " AM\n";
        }
    }
}
