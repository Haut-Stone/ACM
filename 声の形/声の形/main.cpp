#include <stdio.h>

int main()
{
	int a, k, n;
	scanf("%d%d%d", &a, &k, &n);
	int sum = 0;
	while(true) {
		sum++;
		n-=a;
		if(sum % k == 0)
			n+=a;
		if(n < 0)
			break;
	}
	printf("%d\n", sum);
	return 0;
}

