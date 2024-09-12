#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
 int m=-1;
 double e = 0.00001;
 double pi= 1;
 double pred;
 int i = 3;
 do {
  	pred = pi;
  	pi = pi + m * (1. / i);
  	i += 2;
  	m=-m;
} 	while(e < fabs(4 *pi -  4*pred));
 
 
 
 printf("%f", 4*pi);
 return 0;
}
