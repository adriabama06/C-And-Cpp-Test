#include <stdio.h>
#include <math.h>

#define precision 6  //precision for decimal digits


int main(int argc, char const *argv[])
{
        
	float f,ff;
	scanf("%f",&f);
	ff = f;
	char str[30];
	int a,b,c,k,l=0,m,i=0,j;
	
	// check for negetive float
	if(f < 0.0)
	{
		
		str[i++]='-';
		f*=-1;
	}
	
	a=f;	// extracting whole number
	f-=a;	// extracting decimal part
	k = precision;
	
	// number of digits in whole number
	while(k>-1)
	{
		l = pow(10,k);
		m = a/l;
		if(m>0)
		{
			break;
		}
	k--;
	}

	// number of digits in whole number are k+1
	
	/*
	extracting most significant digit i.e. right most digit , and concatenating to string
	obtained as quotient by dividing number by 10^k where k = (number of digit -1)
	*/
	
	for(l=k+1;l>0;l--)
	{
		b = pow(10,l-1);
		c = a/b;
		str[i++]=c+48;
		a%=b;
	}
	str[i++] = '.';
	
	/* extracting decimal digits till precision */

	for(l=0;l<precision;l++)
	{
		f*=10.0;
		b = f;
		str[i++]=b+48;
		f-=b;
	}

	str[i]='\0';

	printf("\n orignal printf %f\n",ff);
	printf("\n float string %s\n",str);


	return 0;
}