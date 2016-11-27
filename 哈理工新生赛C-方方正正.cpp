#include <cstdio>
#include <algorithm>
using namespace std;

const int size = 100000;//数组的最大长度
int a[size], b[size];//开行，列数组

int main(int argc, char const *argv[])
{
	int r, c, i, j;//行数，列数，以及计数变量
	long long s, t;//矩阵的总和

	while(scanf("%d%d", &r, &c) == 2){
		for(i=0,s=0;i<r;i++){
			scanf("%d", &a[i]);//储存行的和
			s += a[i];
		}
		for(i=0,t=0;i<c;i++){
			scanf("%d", &b[i]);//列的和
			t += b[i];
		}
		if(s != t){
			printf("NO\n");//如果矩阵总和不等，直接输出NO
			continue;//下一波
		}
		sort(a, a+r);//对行和排序
		sort(b, b+r);//列和排序
		for(i=j=0,t=s=0; i<c; i++){//核心算法，不懂。。。
			t += b[c-i-1];
			s += r-j;
			while(j<r && a[j] < i+1){
				s -= i+1-a[j];
				j++;
			}
			if(s<t) break;
		}
		printf(i == c?"YES\n":"NO\n");
	}
	return 0;
}