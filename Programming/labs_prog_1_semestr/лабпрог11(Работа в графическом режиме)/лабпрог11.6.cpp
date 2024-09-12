//6.  f1(x)= sqr(x-2)           f2(x)= 4            жёлтый
#include <graphics.h>
#include <math.h>

const int m = 13;
float f1(float x){
	float y = sqrt(x-2);
	return  m * y;	
}
float f2(float x){
	return m * 4;
} 

int main() {
	initwindow(1000,1000);
	setcolor(5);
	
	moveto(500,1000);
	lineto(500,0);
	
	moveto (0,500);
	lineto (1000,500);
	
	for (float i = 0.0; i <= 40; i += 0.001){
		float x = i;
		float y = f1(x);
		putpixel(m * x + 500 ,-y + 500, 5);
	}
	for (float i = 0; i <= 40; i += 0.01){
		float x = i;
		float y = f2(x);
		putpixel(m * x + 500, -y + 500, 5);
	}
	outtextxy(825, 407, "f1(x) = sqrt(x-2)");
	outtextxy(880, 449, "f2(x) = 4");
	
	setfillstyle(1,14);
	floodfill(501,499,5);
	
	getch();
	return 0;
}
