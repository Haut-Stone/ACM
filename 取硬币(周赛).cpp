/*
 Description
 
 n个硬币排成一排，你可以取走其中连续的一段硬币，但必须要求这段硬币中正面朝上的个数等于反面朝上的个数，那么你最多可以取走多少枚硬币？
 Input
 
 多组实例测试，每组输入一个01字符串（长度小于1000000），其中0表示反面朝上，1表示正面朝上
 
 Output
 
 对于每组数据，输出能取走的最多硬币数量
 
 Sample Input
 
 10110
 Sample Output
 
 Case #1: 4
 HINT
 
 如果要开一个很大的数组，请将其作为全局变量！
 例如：
 #include
 int p[1000005];
 int main(void)
 {
 ……
 }
 
 Source
 */
/*	令temp为当前1的个数与0的个数的差（可以为负，例如1的个数为5,0的个数为8，那么差就为-3），
	那么只需要从左到右遍历一遍字符串，不停更新temp值即可，只要这个temp值之前出现过，就说明中间这一段0和1的个数一定相等
	比如str[] = "110101111"：
 我们设i=xi表示当前遍历到第xi个字符
 xi=1时，a=1,b=0,temp=1
 xi=2时, a=2,b=0,temp=2
 xi=3时, a=2,b=1,temp=1（和x1=1时相等，那么找到一个01相等串，长度为2）
 xi=4时, a=3,b=1,temp=2（和x1=2时相等，那么又找到一个01相等串，长度也为2）
 ……
 xi=6时, a=4,b=2,temp=2（和x1=2时相等，找到一个01相等串，长度为4！更优）
 xi=7, a=5,b=2,temp=3
 xi=8, a=6,b=2,temp=4  ……
 综上，答案为4！
	PS：用一个数组p[2000005]来存temp的值，因为temp可以为负，所以我们将temp总体+1000000,，p[temp]=5表示temp值最早出现在下标为5的地方
 */
#include<stdio.h>
#include<string.h>
#define max(a, b) a>b?a:b
char str[1000005];
int p[2000005];
int main(void)
{
    int i, ans, a, b, temp, cas = 1;
    while(scanf("%s", str+1)!=EOF)
    {
        memset(p, 0, sizeof(p));
        ans = a = b = 0;
        for(i=1;str[i]!='\0';i++)
        {
            if(str[i]=='1')  a++;
            else b++;
            temp = a-b+1000001;
            if(p[temp] || a==b)
                ans = max(i-p[temp], ans);
            else
                p[temp] = i;
        }
        printf("Case #%d: %d\n", cas++, ans);
    }
    return 0;
}
