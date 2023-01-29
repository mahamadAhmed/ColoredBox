//Rana abdulsalam mohammed 20200752 S35
//Mohammed Ahmed Saleh 20200693 S35

#include <iostream>
#include<windows.h>
void SetColor(int ForgC)
{
	WORD wColor;

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	//We use csbi for the wAttributes word.
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		//Mask out all but the background attribute, and add in the forgournd color
		wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
	return;
}
using namespace std;
class ColoredBox
{
	int length, width;
	int color = 15;
	char  character = '#';
	char** box;
	void addArr(int len, int wid, int col, char boxChar = '#');

public:

	ColoredBox(int len, int wid, int col = 15, char boxChar = '#');
	~ColoredBox();
	void display();
	void displayTransposed();
	void displayWider();
	void displayChess(int col2);
	int getArea();
	static int getMaxArea();
	static int MaxAreaCount;
	void setColor(int col);
	int getColor()
	{
		return color;
	}
	void setChar(char ch)
	{
		character = ch;
	}
	char getChar()
	{
		return character;
	}
};

void ColoredBox::addArr(int len, int wid, int col, char boxChar)
{


	box = new char* [len];
	for (int i = 0; i < len; i++) {
		box[i] = new char[wid];
	}

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < wid; j++)
		{
			box[i][j] = boxChar;
		}
	}
}
	


ColoredBox::ColoredBox(int len, int wid, int col, char boxChar)
{
	addArr(len, wid, col, boxChar);
	length = len;
	width = wid;
	color = col;
	character = boxChar;
	if (length * width > MaxAreaCount) { MaxAreaCount = length * width; }

}

ColoredBox::~ColoredBox()
{
	for (int i = 0; i < length; i++)
	{
		delete[] box[i];
	}
}

void ColoredBox::display()
{
	SetColor(color);
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{

			cout << box[i][j];
		}
		cout << endl;
	}
	SetColor(15);
}

void ColoredBox::displayTransposed()
{
	SetColor(color);
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < length; j++)
		{
			cout << box[j][i];
		}
		cout << endl;
	}
	SetColor(15);

}

void ColoredBox::displayWider()
{
	SetColor(color);
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << box[i][j] << " ";
		}
		cout << endl;
	}

	SetColor(15);
}

void ColoredBox::displayChess(int col2)
{
	int count = 0;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (count % 2 == 0) { SetColor(color); }
			else
			{
				SetColor(col2);
			}
			cout << box[i][j];
			count++;
		}
		cout << endl;
	}
	SetColor(15);
}

int ColoredBox::getArea()
{
	return length * width;
}

int ColoredBox::getMaxArea()
{
	return MaxAreaCount;
}

void ColoredBox::setColor(int col)
{
	color = col;
}

int ColoredBox::MaxAreaCount = 0;

int main()
{
	int len, wid, col, col2;
	char boxChar;
	cout << "Enter length and width of the box separated by a space: ";
	cin >> len >> wid;
	ColoredBox* cb1;
	cb1 = new ColoredBox(len, wid);
	cb1->display();
	cout << "Set the box to another color: ";
	cin >> col;
	cb1->setColor(col);
	cout << "Displaying Transposed: " << endl;
	cb1->displayTransposed();
	cout << "Displaying Wider: " << endl;
	cb1->displayWider();
	cout << "Displaying Chess, enter the other color: " << endl;
	cin >> col2;
	cb1->displayChess(col2);
	cout << endl << "Area=" << cb1->getArea();
	cout << endl << "Max Area=" << cb1->getMaxArea() << endl;
	delete cb1;
	cout << "Enter length,width,color,character of the box separated by spaces: ";
	cin >> len >> wid >> col >> boxChar;
	ColoredBox* cb2;
	cb2 = new ColoredBox(len, wid, col, boxChar);
	cb2->display();
	cout << "Displaying Transposed: " << endl;
	cb2->displayTransposed();
	cout << "Displaying Wider: " << endl;
	cb2->displayWider();
	cout << "Displaying Chess, enter the other color: " << endl;
	cin >> col2;
	cb2->displayChess(col2);
	cout << "Displaying original again:" << endl;
	cb2->display();
	cout << endl << "Area=" << cb2->getArea();
	cout << endl << "Max Area=" << cb2->getMaxArea();
	delete cb2;
	return 0;
}