#include<stdio.h>
#include<math.h>
int main()
{
	long n,x,y,m=0,i=0,num=0,vbnm;
	if(scanf("%ld %ld %ld", &n, &x, &y)!=0)
	{	
		while(n>0)
		{
			vbnm=n%10;
			num= num+(vbnm*pow(x,i));
			n=n/10;
			i++;
		}
		i=0;
		vbnm=0;
		while(num>0)
		{	
			vbnm=num%y;
			m=m+(vbnm*pow(10,i));
			num=num/y;
			i++;
		}
		printf("%ld", m);
		return 0;
	}	
}	

			
		
			
