//7.Движение со сменой направления на границах экрана с диагонального на горизонтальное и наоборот.
//4.Виды графических объектов(машина)
//4.Управление клавишами с символами s, d, e, x.

//GNU coding standards
#include <stdio.h>
#include <graphics.h>
#include <locale.h>
#include <conio.h>
#include "altconio.h"


void draw(int x, int y) {    //рисуем машину
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

void freemove() { //вариант движения 1(свободное движение)
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
        
        if (is_horizontal) {  //проверка движения (горизонтальное или диагональное)
            x += derect_x;
        }
        else {
            x += derect_x;
            y += derect_y;
        }
        if ((x > 710 || x < 0) && x != prev_x) { //проверяем достигнута ли граница
            derect_x *= -1;
            is_horizontal = !is_horizontal;
        }
        if ((y > 725 || y < 0) && y != prev_y) {
            derect_y *= -1;
            is_horizontal = !is_horizontal;
        }
        if (kbhit()) {              //закрытие окна если нажат esc
            char ch = getch();
            if (ch == 27)
				break;
        }
    }
    closegraph();
}

void withkey() {          //вариант движения 2(по клавишам)
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
            switch(ch) {       //изменения положения в зависимости от того какая клавиша нажата
                case 'e':     //вверх
                    y -= 5;
                    break;
                case 'd':     //вперед
                    x += 5;
                    break;
                case 's':    //назад
                    x -= 5;
                    break;
                case 'x':    //вниз
                    y += 5;
                    break;
            }
            if (x > 710) {     //проверка достижения границ
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
    for(i = 1; i <= 3; i++) {      //выводим меню
        gotoxy(45, 3 + i * 2);     // формируем отступы пунктов
        switch(i) {     // выводим пункты в консоль
            case 1:
                printf("1.Свободное движение объекта.");
                break;
            case 2:
                printf("2.Движение объекта с помощью клавиатуры.");
                break;
            case 3:
                printf("3.Выход из программы.");
                break;
        }
    }
    
    do {                      //Основной цикл обработки меню
        ch = _getch();     
        gotoxy(45, 3 + i * 2);  //перемещаем курсор
        settextcolor(15, 0);  //дилаем заливку текста
        switch(i) {
            case 1:
                printf("1.Свободное движение объекта.");
                break;
            case 2:
                printf("2.Движение объекта с помощью клавиатуры.");
                break;
            case 3:
                printf("3.Выход из программы.");
                break;
        }
        if(ch == 72) //вниз по меню
			i--;   
        if(ch == 80)    //вверх по меню 
			i++;  
        if(i > 3)     //зацикливание меню
			i = 1;
        if(i < 1)   //зацикливание меню
			i = 3;
        
        gotoxy(45, 3 + i * 2); //перемещаем курсор
        settextcolor(12, 7);  //дилаем заливку текста 
    
        switch(i) {
            case 1:
                printf("1.Свободное движение объекта.");
                break;
            case 2:
                printf("2.Движение объекта с помощью клавиатуры.");
                break;
            case 3:
                printf("3.Выход из программы.");
                break;
        }
    } while(ch != 13);   //пока не нажат enter 
    
    switch(i) {          //выполение программы в завимости какой пункт выбран 
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

