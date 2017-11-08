#include<stdio.h>

const int N = 20010;
int a[N];

int max(int a, int b)
{
	if(a > b){
		return a;
	}else{
		return b;
	}
}

int main(void)
{
	int n;
	while(scanf("%d", &n) != EOF){
		int sum = 0;
		for(int i=1;i<=n;i++){
			scanf("%d", &a[i]);
			sum += a[i];
		}
		int ans = sum;
		for(int i=3;i<=n/2;i++){
			if(n%i) continue;
			int step = n / i;
			for(int k=1;k<=step;k++){
				int temp = 0;
				for(int j=k;j<=n;j+=step){
					temp += a[j];
				}
				ans = max(ans, temp);
			}
		}
		printf("%d\n", ans);
	}
}
