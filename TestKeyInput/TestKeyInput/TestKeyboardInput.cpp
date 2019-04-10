#include <conio.h>
#include <iostream>


using namespace std;


int main(void)
{
	int key;

	while (1) {
		system("cls");
		key = _getch();
		if (key == 224)
		{
			key = _getch();

			switch (key)
			{
			case 72:
				cout << "À§ÂÊ ´­·¶À½";
				break;
			case 75:
				cout << "¿ÞÂÊ ´­·¶À½";
				break;
			}

			system("cls");
		}
	}

	return 0;
}
