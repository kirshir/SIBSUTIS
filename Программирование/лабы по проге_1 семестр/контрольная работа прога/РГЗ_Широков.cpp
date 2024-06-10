//7.�������� �� ������ ����������� �� �������� ������ � ������������� �� �������������� � ��������.
//4.���� ����������� ��������(������)
//4.���������� ��������� � ��������� s, d, e, x.

//GNU coding standards
#include <stdio.h>
#include <graphics.h>
#include <locale.h>
#include <conio.h>
#include "altconio.h"


void draw(int x, int y) {    //������ ������
    line(x, y + 40, x + 80, y + 40);
    circle(x + 15, y + 50, 10);
    circle(x + 65, y + 50, 10);
    line(x, y + 40, x, y + 25);
    line(x, y + 25, x + 10, y + 25);
    line(x + 10, y + 25, x + 30, y);
    line(x + 30, y, x + 50, y);
    line(x + 50, y, x + 60, y + 25);
    line(x + 60, y + 25, x + 80, y + 25);
    line(x + 80, y + 25, x + 80, y + 40);
}

void freemove() { //������� �������� 1(��������� ��������)
    initwindow(800, 800);
    setfillstyle(1, 0); 
    int x = 0, y = 0;
    int derect_x = 5, derect_y = 5;
    bool is_horizontal = false;
    int prev_x, prev_y;
    
    while(1) {
        cleardevice();
        draw(x, y);
        delay(20);
        prev_x = x;
        prev_y = y;
        
        if (is_horizontal) {  //�������� �������� (�������������� ��� ������������)
            x += derect_x;
        }
        else {
            x += derect_x;
            y += derect_y;
        }
        if ((x > 710 || x < 0) && x != prev_x) { //��������� ���������� �� �������
            derect_x *= -1;
            is_horizontal = !is_horizontal;
        }
        if ((y > 725 || y < 0) && y != prev_y) {
            derect_y *= -1;
            is_horizontal = !is_horizontal;
        }
        if (kbhit()) {              //�������� ���� ���� ����� esc
            char ch = getch();
            if (ch == 27)
				break;
        }
    }
    closegraph();
}

void withkey() {          //������� �������� 2(�� ��������)
    initwindow(800, 800);
    setfillstyle(1, 0);
    int x = 0, y = 0;
    char ch;
    while(1) {
        cleardevice();
        draw(x, y);
        delay(10);
        
        if (kbhit()) { 
            ch = getch();
            if (ch == 27) 
				break;
            switch(ch) {       //��������� ��������� � ����������� �� ���� ����� ������� ������
                case 'e':     //�����
                    y -= 5;
                    break;
                case 'd':     //������
                    x += 5;
                    break;
                case 's':    //�����
                    x -= 5;
                    break;
                case 'x':    //����
                    y += 5;
                    break;
            }
            if (x > 710) {     //�������� ���������� ������
                x = 710;
            }
            else if (x < 0) {
                x = 0;
            }
            if (y > 725) {
                y = 725;
            }
            else if (y < 0) {
                y = 0;
            }
        }
    }
    closegraph();
}

int main() {
    setlocale(LC_ALL, "Rus");
    int x, y, i, ch;
    for(i = 1; i <= 3; i++) {      //������� ����
        gotoxy(45, 3 + i * 2);     // ��������� ������� �������
        switch(i) {     // ������� ������ � �������
            case 1:
                printf("1.��������� �������� �������.");
                break;
            case 2:
                printf("2.�������� ������� � ������� ����������.");
                break;
            case 3:
                printf("3.����� �� ���������.");
                break;
        }
    }
    
    do {                      //�������� ���� ��������� ����
        ch = _getch();     
        gotoxy(45, 3 + i * 2);  //���������� ������
        settextcolor(15, 0);  //������ ������� ������
        switch(i) {
            case 1:
                printf("1.��������� �������� �������.");
                break;
            case 2:
                printf("2.�������� ������� � ������� ����������.");
                break;
            case 3:
                printf("3.����� �� ���������.");
                break;
        }
        if(ch == 72) //���� �� ����
			i--;   
        if(ch == 80)    //����� �� ���� 
			i++;  
        if(i > 3)     //������������ ����
			i = 1;
        if(i < 1)   //������������ ����
			i = 3;
        
        gotoxy(45, 3 + i * 2); //���������� ������
        settextcolor(12, 7);  //������ ������� ������ 
    
        switch(i) {
            case 1:
                printf("1.��������� �������� �������.");
                break;
            case 2:
                printf("2.�������� ������� � ������� ����������.");
                break;
            case 3:
                printf("3.����� �� ���������.");
                break;
        }
    } while(ch != 13);   //���� �� ����� enter 
    
    switch(i) {          //��������� ��������� � ��������� ����� ����� ������ 
        case 1: {
            freemove();
            break;
        }
        
        case 2: {
            withkey();
            break;
        }
        case 3: {
            return 0; 
            break;
        }
    }
}

