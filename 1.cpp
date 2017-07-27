#include <iostream>

/* If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000. */


using namespace std;

/* a clever improvisation of the formulae for arithmetic progressions. For example, to find the sum of the terms 3,6,9,12,..., you would use (n/2)(a+l), where n is the number of terms, a is the first term, and l is the last term. But to find the last term requires a bit of work. The nth term is given by a+(n-1)d, where d is the common difference. So we need to solve 3+3(n-1)=1000, giving 3(n-1)=997, and n=997/3+1=333.333... However, n must be integer, so int(333.333...)=333, and checking, 3+3(333-1)=999; this is the last term before 1000.

In general, a+(n-1)d=x, gives n=int((x-a)/d+1).

But for this problem we can improve even further, as a=d we get n=int(x/d-d/d+1)=int(x/d).

The nth (last) term, l=a+(n-1)d=d+(int(x/d)-1)*d=d*int(x/d).

Combining this to find the sum, S=(n/2)(a+l)=(int(x/d)/2)*(d+d*int(x/d)).

Simplifying, S=d*int(x/d)*(1+int(x/d))/2.

As the problem asks for the sum of multiples of 3 and 5 we find the sum of each series, but as 3,6,9,... and 5,10,15,... have multiples of 15 in common, we need to subtract the series for 15,30,45,...

However, caution is needed. The problem states below then 1000, so we must use 999 in the formula (otherwise it would include 1000 in the sum, as a multiple of 5):

T = 3*int(999/3)*(1+int(999/3))/2 + 5*int(999/5)*(1+int(999/5))/2 - 15*int(999/15)*(1+int(999/15))/2

Therefore, T = 3*333*(1+333)/2 + 5*199*(1+199)/2 - 15*66*(1+66)/2 = 233168. */

int arithmeticalWay(int x){
	return 1.5*(int)((x-1)/3)*(int)((x+2)/3) + 2.5*(int)((x-1)/5)*(int)((x+4)/5) - 7.5*(int)((x-1)/15)*(int)((x+14)/15);	
}

int solve(){
	int x = 0;
	for(int i = 3; i < 1000; i+= 3)
		x += i;
	for(int i = 5; i < 1000; i+= 5)
		if(i % 3 != 0)
			x += i;
	return x;
}

int main(){

	cout << solve() << endl;
	
	cout << arithmeticalWay(1000) << endl;
}