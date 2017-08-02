#include <iostream>
#include <vector>

using namespace std;

//1
int fibonacciEven(int n){
	long long ans = 0;
	int n0 = 1;
	int n1 = 1;
	int n2;
	while(n2 < n){
		n2 = n0 + n1;
		n0 = n1;
		n1 = n2;
		if(n2%2==0)
			ans+= n2;
	}
	return ans;
}

//2
int fibonacci(int n){
	if(n == 0) return 1;
	if(n == 1) return 1;
	return fibonacci(n-1) + fibonacci(n-2);
}

int solve(){
	int ans = 0;
	int fib;
	for(int i = 0; i < 40; i++){
		fib = fibonacci(i);
		if(fib > 4000000) break;
		if((fib % 2) == 0){
			ans+= fib;
		}
	}
	return ans;	
}

int main(){
	
	cout << fibonacciEven(4000000) << endl;
	return 0;
}
