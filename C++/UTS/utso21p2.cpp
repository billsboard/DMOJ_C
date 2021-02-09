#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461,
 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541};

int K, S, bst, idx = 0;
vector<int> list;


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> K;
    S = K * 2;
    bst = sqrt(S);

    if(K == 0) {
        cout << 1 << "\n" << 2 << "\n";
        return 0;
    }
        int cnt = 1, ele = 1;
        list.push_back(1);
        while(cnt < K){
            list.push_back(1);
            ele++;
            cnt += ele;
        }
        int diff = cnt - K;
        if(diff < ele){
            int id = 0;
            while(diff){
                diff--;
                list[id] = primes[idx];
                idx++; id++;
            }
        }
    

    cout << list.size() << "\n";
    for(int i : list){
        cout << i << " ";
    }
    cout << "\n";
}