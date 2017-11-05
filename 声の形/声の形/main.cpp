#include<stdio.h>
#include<iostream>
#define INPUT_TEST freopen("/Users/li/Desktop/in.txt", "r", stdin)
#define OUTPUT_TEST freopen("/Users/li/Desktop/in.txt", "w", stdout)
using namespace std;

int main()
{
//	OUTPUT_TEST;
	srand((unsigned)time(NULL));
	int n;
	n = 1000;
	int t = (rand() % (n - 0)) + 0;
	printf("%d\n", t);
	for(int i=0;i<t;i++){
		printf("%d", (rand() % (10 - 0)) + 0);
	}
	printf("\n");
	return 0;
}
