#include <iostream>
using namespace std;

const int beg = (true + true) * (true + true) * (true + true) * (true + true) * (true + true) * (true + true + true);
const int ten = (true + true) * (true + true + true + true + true);

int main(){
   cout << (char) (beg - ten - ten - true - true - true - true);
   cout << (char) (beg + true + true + true + true + true);
   cout << (char) (beg + ten + true + true);
   cout << (char) (beg + ten + true + true);
   cout << (char) (beg + ten + true + true + true + true + true);
   cout << (char) (ten + ten + ten + ten + true + true + true + true);
   cout << (char) (ten + ten + ten + true + true);
   cout << (char) (beg - ten + true);
   cout << (char) (beg + ten + true + true + true + true + true);
   cout << (char) (beg + ten + ten - true - true);
   cout << (char) (beg + ten + true + true);
   cout << (char) (beg + true + true + true + true);
   cout << (char) (ten + ten + ten + true + true + true);
}