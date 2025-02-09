#include <iostream>

using namespace std;

int main(){
    int d; 

    cin >> d;

    if (d <= 800){
        cout << "1" << '\n';
    } else if (d <= 1400){
        cout << "2" << '\n';
    } else { 
        cout << "3" << '\n';
    }
}