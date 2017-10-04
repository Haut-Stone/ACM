#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const long long INF = 4e9 + 10;

long long negativeNumber1;
long long negativeNumber2;
long long positiveNumber1;
long long positiveNumber2;
long long a, b;

int main(void)
{
	long long T;
	scanf("%lld", &T);
	while(T--){
		long long n;
		negativeNumber1 = negativeNumber2 = 0;
		positiveNumber1 = positiveNumber2 = 0;
		scanf("%lld", &n);
		long long solo;
		for(long long i=0;i<n;i++){
			scanf("%lld", &solo);
			if(solo < 0){
				negativeNumber2 = min(solo, negativeNumber2);
				if(negativeNumber2 < negativeNumber1){
					swap(negativeNumber1, negativeNumber2);
				}
			}else if(solo > 0){
				positiveNumber2 = max(solo, positiveNumber2);
				if(positiveNumber2 > positiveNumber1){
					swap(positiveNumber2, positiveNumber1);
				}
			}
		}
		if(negativeNumber1 == 0 || negativeNumber2 == 0){
			a = INF;
		}
		if(positiveNumber1 == 0 || positiveNumber2 == 0){2
			b = INF;
		}
		if(a == INF && b == INF){
			printf("%d\n", 0);
		}else if(a == INF && b != INF){
			printf("%lld\n", positiveNumber2*positiveNumber1);
		}else if(a != INF && b == INF){
			printf("%lld\n", negativeNumber1*negativeNumber2);
		}else{
			printf("%lld\n", max(positiveNumber1*positiveNumber2, negativeNumber1*negativeNumber2));
		}
	}
	return 0;
}

