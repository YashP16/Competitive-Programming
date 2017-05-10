#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#define FOR(i,a,b,c) for(i=a;i<b;i += c)
#define FORd(i,a,b,c) for(i=a;i>=b;i -=c)
#define ll long long int
using namespace std;
bool isprime(int n){
  for(int i = 2; i<= sqrt(n); i++){
    if(n%i == 0){
      return false;
    }
  }
    return true;
}
int main(){
	ll n;
	cin >> n;
	ll a[n];
	int i=2; 
	int count =0; 
	while(count !=n){
		if(isprime(i)) {
			cout << i << " ";
			count++;
		}
		i++;

	}
	return 0;
}

/* Suppose we are given the number N. 
We can observe that for big enough consecutive numbers, the array is always hungry.
For example, we can print 3 * N + 0, 3 * N + 1, 3 * N + 2, …, 3 * N + (N – 1). 
Magic, isn’t it? Why does it work now? Pick an arbitrary a[i]. 
The solution would be bad if one of numbers 2 * a[i], 3 * a[i], 4 * a[i] and so on would be in a[] array. 
However, it will never happen. The smallest multiple from that ones will be 2 * 3 * N = 6 * N.
There is not possible to obtain a smallest multiple than that one. 
On the other hand, the biggest number from a[] array would be 3 * N + N – 1 = 4 * N — 1. Since smallest multiple is bigger than biggest term of the array,
it (and of course other multiples bigger than it) will never exist in a[] array. So the above solution is correct also.*/