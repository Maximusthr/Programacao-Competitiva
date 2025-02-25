#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        int x; cin >> x;
        string word; cin >> word;

        int traco = 0;
        int underline = 0;

        for (int i = 0; i < x; i++){
            if (word[i] == '_') underline++;
            else traco++;
        }
        
        if (traco <= 1 || underline == 0) cout << 0;
        else if (traco == 2){
            cout << underline;
        }
        else if (traco > underline){
            cout << (underline*traco) + (underline*traco)/2;
        }

        else if (underline == traco){
            cout << underline*traco + underline;
        }

        else if (underline > traco){
            cout << (underline * traco);
        }

        cout << "\n";
    }

}
