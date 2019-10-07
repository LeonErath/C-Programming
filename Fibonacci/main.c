#include<stdio.h>

int fibonacci(int n) {
	// Recursive bases.
	if(n==0) {
		return 0;
	}else if(n==1) {
		return 1;
	}
	
	// Recursive definition of Fibonacci's Sequence.
	else{
		return fibonacci(n-1)+fibonacci(n-2);
	}
}

int main(){
	int n;
	printf("Enter a number (n) to get the n-th Fibonacci number: ");
	scanf("%d", &n);
	
	printf("%d\n", fibonacci(n));
		
	return 0;
}
