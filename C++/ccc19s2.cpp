#include <iostream>
#include <math.h>

using namespace std;

bool primes[2000000];

bool isPrime(int n){
	if(!(n & 1)) return false;
	int s = sqrt(n);
	for(int i = 3; i <= s; i += 2){
		if(!(n % i)) return false;
	}
	return true;
}

int main(){
	primes[2] = true;
	for(int i = 3; i < 2000000; i += 2){
		primes[i] = isPrime(i);
	}
	int T;
	cin >> T;
	for(int i = 0; i < T; i++){
		int N;
		cin >> N;
		N *= 2;
		for(int j = 3; j <= N / 2; j++){
			if(primes[j] && primes[N - j]){
				cout << j << " " << N - j << "\n";
				break;
			}
		}
	}
}


