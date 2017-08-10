#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#define MAX_SIZE 1000
using namespace std;


void init(bool prime[]);

int main()
{
	bool prime[MAX_SIZE];
	memset(prime, 1, MAX_SIZE);
	init(prime);
	int n;
	while(scanf("%d", &n) != EOF){
		if(prime[n]){
			printf("%d is prime\n", n);
		}else{
			printf("%d is not prime\n", n);
		}
	}
	return 0;
}

void init(bool prime[])
{
	prime[0] = prime[1] = 0;
	prime[2] = 1;
	for(int i=3;i<=MAX_SIZE;i++){
		prime[i] = i%2 == 0 ? 0:1;
	}
	for(int i=3; i<=sqrt(MAX_SIZE);i++){
		if(prime[i]){
			for(int j=i*i;j<=MAX_SIZE;j+=i*2){
				prime[j] = 0;
			}
		}
	}
}