#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;

int main(int argc, char const *argv[])
{
	long long n;
	long long p;
	long long ans = 1;
	scanf("%lld %lld", &n, &p);
	for(int i=1;i<=n;i++){
		ans = ans*i;
		ans = ans%p;
	}
	printf("%lld\n", ans);
	return 0;
}