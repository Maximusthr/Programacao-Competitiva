#include <iostream>
#include <set>

using namespace std;

// int main(){
//     set<int> exemplo;

//     exemplo.insert(5);
//     exemplo.insert(12);
//     exemplo.insert(3);
//     exemplo.insert(5);

//     exemplo.erase(12);

//     if(exemplo.find(5) != exemplo.end()){
//         printf("5");
//     }
// }

int main(){
    set<int> t;

    for (int i = 10; i >= 1; i--){
        t.insert(i);
    }

    set<int>::iterator it; // -> Declaração do iterator
    for(it = t.begin(); it != t.end(); it++){
        printf("%d ", *it);
    }
}
