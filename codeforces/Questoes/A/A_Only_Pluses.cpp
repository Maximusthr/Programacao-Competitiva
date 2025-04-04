#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int a, b, c; cin >> a >> b >> c;

        int menor = 0;
        for (int i = 0; i < 5; i++){
            menor = min(a, min(b, c));

            if (a == menor) a++;
            else if (b == menor) b++;
            else if (c == menor) c++;
        }

        cout << a * b * c << "\n";
    }
}