//снежная карусель
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>

void snej(int snej_x[], int snej_y[], int snej_color[]) {
	for (int i = 0; i < 100; i++) {
		snej_x[i] = rand() % 740 + 20;
		snej_y[i] = rand() % 740 + 20;
		snej_color[i] = rand() % 15 + 1;
	}
}
void draw(int x, int y, int color) {
	setcolor(color);
	setfillstyle(1, color);
	circle(x, y, 10);
	floodfill(x, y, color);
	for (int i = 0; i < 16; i++) {
		putpixel(x - 10 - i, y, color);
		putpixel(x + 10 + i, y, color);
		putpixel(x, y + 10 + i, color);
		putpixel(x, y - 10 - i, color);
	}
	for (int i = 0; i < 8; i++) {
		putpixel(x - 10 - i - 8, y - i, color);
		putpixel(x - 10 - i - 8, y + i, color);
		putpixel(x + 10 + i + 8, y + i, color);
		putpixel(x + 10 + i + 8, y - i, color);
		putpixel(x + i, y + 10 + i + 8, color);
		putpixel(x - i, y + 10 + i + 8, color);
		putpixel(x + i, y - 10 - i - 8, color);
		putpixel(x - i, y - 10 - i - 8, color);
	}
}
int main() {
	int snej_x[100];
	int snej_y[100]; 
	int snej_color[100];
	
	initwindow(800,800);
	setfillstyle(1,0);
	bar (0,0,799,799);
	
	while (!kbhit()) { 
		snej(snej_x, snej_y, snej_color);
		
		for (int i = 0; i < 100; i++) {
			draw(snej_x[i], snej_y[i], snej_color[i]);
			snej_x[i] = (snej_x[i] + rand() % 3 + 740 + 20) % 740 + 20;
			snej_y[i] = (snej_y[i] + rand() % 3 + 740 + 20) % 740 + 20;
			snej_color[i] = rand() % 15 + 1;
		}
		delay(200);
		cleardevice();  
	}
	getch();
	closegraph();
	return 0;
}  

