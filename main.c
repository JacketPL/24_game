#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define random(a,b) ( rand( ) % ( b - a ) + a )


#define True 1
#define False 0
typedef int boolean;

boolean flag;
double num[4];
void game( int n ){
	int i = 0;
	int j ;
	if( n == 1 ){
		if( num[0] == 24 ){
			flag = True;
			return;
		}
		return;
	}
	if( flag == True )
		return;
	for(;i<n;i++)
		for(j=i+1;j<n;j++){
			double a = num[i];
			double b = num[j];
			num[j] = num[n-1];
			num[i] = a+b;
			game(n-1);
			num[i] = a - b;
			game(n-1);
			num[i] = b - a;
			game(n-1);
			num[i] = a * b;
			game(n-1);
			if( b != 0 ){
				num[i] = a / b;
				game(n-1);
			}
			if( a != 0 ){
				num[i] = b / a;
				game( n - 1 );
			}
			num[i] = a;
			num[j] = b;
		}
	
} 
void can24( double a, double b,double c,double d ){
	num[0] = a;
	num[1] = b;
	num[2] = c;
	num[3] = d;
	flag = False;
	game(4);
	if( flag ){
		printf("it can work out 24\n");
	}else{
		printf("it can't work out 24\n");
	}
	
}
int main( int argc,char * argv[ ] ){
	int a,b,c,d;
	srand((unsigned)time(NULL));
	a =random(1,14);
	b = random(1,14);
	c = random(1,14);
	d = random(1,14);
	printf("%d %d %d %d\n",a,b,c,d);
	can24(a,b,c,d);
	return 0;
}