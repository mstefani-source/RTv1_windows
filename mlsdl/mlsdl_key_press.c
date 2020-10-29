#include "mlsdl.h"

void key_press(int keyi, void (*ptr)(void))
{
	int key[500];
  	
	if (key[keyi]) ptr; //Точно не помню, верно ли это, но, если зажатая клавиша имеет состояние 1, то выполняется функция ptr
}