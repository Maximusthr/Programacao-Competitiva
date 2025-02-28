#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    string keyboard = "qwertyuiopasdfghjkl;zxcvbnm,./";

    char direction; cin >> direction;
    string word; cin >> word;

    string ans;
    for (int i = 0; i < (int)word.size(); i++){
        if (direction == 'R') {
            for (int j = 0; j < (int)keyboard.size(); j++){
                if (word[i] == keyboard[j]) {
                    ans += keyboard[j-1];
                }
            }
        }
        else {
            for (int j = 0; j < (int)keyboard.size(); j++){
                if (word[i] == keyboard[j]) {
                    ans += keyboard[j+1];
                }
            }
        }
    }

    cout << ans << "\n";
}
