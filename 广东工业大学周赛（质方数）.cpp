#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define maxn 1000;
using namespace std;
int a[maxn];
void init();

int main(int argc, char const *argv[])
{
	int T;
	int n;
	int temp;
	int cot1;
	int cot2;

	init();
	scanf("%d", &T);
	for(int i=0;i<T;i++){
		scanf("%d", &n);
		temp = 2;
		for(int j=2;j<maxn;j++){
			if(a[i] == 1 && n < a[i]*a[i]){
				cot1 = a[i]*a[i] - n;
				cot2 = n - temp*temp;
				if(cot2 > cot1){
					printf("%d\n", a[i]*a[i]);
				}else{
					printf("%d\n", temp*temp);
				}
				break;
			}else{
				temp = a[i];
			}
		}
	}
	return 0;
}

void init()
{
	a[0] = a[1] = 0;
	a[2] = 1;
	for(int i=3;i<=maxn;i++){
		a[i] = i%2 == 0 ? 0:1;
	}
	for(int i=3;i<=maxn;i++){
		if(a[i]){
			for(int j=i*i;j<=maxn;j+=2*i){
				a[j] = 0;
			}
		}
	}
}