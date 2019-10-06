#include<stdio.h>
int main(){
	long long int fib[100000], a ,b, c;
	fib[1]=1;
	fib[0]=0;
	for (long long int i = 2; i < 100000; ++i)
	{
		fib[i]=fib[i-1]+fib[i-2];
		

	}
	

	
			a--;
			c=0;
			scanf("%lld",&b);
			c=fib[b];
			printf("%lld\n", c);
		
	return 0;
}
