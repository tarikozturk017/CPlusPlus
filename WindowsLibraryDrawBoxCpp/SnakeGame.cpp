#include <iostream>
#include<Windows.h>

using namespace std;

const int width = 80;
const int height = 20;

//WINDOWS FUNCTION
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


int main() 
{
	//draw to the right
	for (int i = 0; i < width; i++)
	{	
		cout << "a";
		Sleep(50);		
	}
	//draw to the bottom
	for (int i = 0; i < height; i++)
	{
		gotoxy(width - 1, i);
		cout << "a";
		Sleep(50);
	}

	//draw to the left
	for (int i = 0; i < width; i++)
	{
		gotoxy(width -i - 1, height - 1);
		cout << "a";
		Sleep(50);
	}


	return 0;
}