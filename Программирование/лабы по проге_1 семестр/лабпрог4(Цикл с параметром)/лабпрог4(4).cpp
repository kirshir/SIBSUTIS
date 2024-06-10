//4)   S= ln 0.1 + ln 0.3 +...+ ln1.9  (s=-2.726)
#include <math.h>
#include <stdio.h>

int main()
{
	float s = 0, i;
 	for (i = 0.1; i <= 2; i += 0.2){
  	s += log(i);
 	}
 printf("s=%0.3f", s);
 return 0;
}
