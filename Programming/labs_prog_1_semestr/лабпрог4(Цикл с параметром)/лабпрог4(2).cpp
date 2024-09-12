//2)   S= sin1 + sin 2 +...+ sin25;  (s=-0.058)
#include <math.h>
#include <stdio.h>

int main()
{
 int i; 
 float a, s;
 for (i = 1; i<26; i++) {
  a = sin(i);
  s += a;
 }
 printf("%0.3f", s);
 return 0;
}
