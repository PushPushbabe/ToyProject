#include <iostream>
#include "DrawBlock.h"

using namespace std;

int InitGrid(int num,FILE* file, int& row, int **grid);
void DrawGrid(int num);
int Evalsize(FILE * file);


int main()
{
	int maxleng=0;
	int row = 0;
	int col = 0;
	int trueleng = 0;
	int * ptr_grid;
	int ** rptr_grid= &ptr_grid;
	int indexer = 0;
	DrawLong LongBlock;


	FILE * file;
	fopen_s(&file, "Background.txt", "rt");
	if (file == NULL)
		return -1;

	maxleng = Evalsize(file);	
	trueleng = InitGrid(maxleng, file,row, rptr_grid);
	col = trueleng / row;

	cout << "row " << row<<endl;
	cout << "col " << col<<endl;

	getchar();

	//LongBlock.InitDrawLong(ptr_grid, row, col);
	//system("cls");

	//for (int i = 0;i < col;i++)
	//{
	//	for (int j = 0;j < row;j++)
	//	{
	//		cout << ptr_grid[indexer];
	//		indexer++;
	//	}cout << endl;
	//}


	//DrawGrid(maxleng);
	


	return 0;
}

int Evalsize(FILE * file)
{
	fseek(file, 0, SEEK_END);
	return ftell(file);
}





int InitGrid(int maxleng, FILE * file, int& row, int** rptr_grid) //파일에서 읽어온 값으로 그리드 그리기
{
	char * buffer = new char[maxleng];
	int * int_buffer;
	int result;
	int i = 0;
	int count_row=0;
	int int_maxleng=0;
	int indexer=0;
	int  col;

	fseek(file, 0, SEEK_SET);
	result = fread(buffer, 1, maxleng * sizeof(char), file);
	for (i = 0;i < maxleng;i++)
	{
		if (buffer[i] == '1' || buffer[i] == '0' || buffer[i] == '2' || buffer[i] == '3')
		{
			int_maxleng++;
		}
	}

	int_buffer = new int[int_maxleng + 1];
	memset(int_buffer, 0, int_maxleng + 1);
	*rptr_grid = int_buffer;
	do {
		if (buffer[i] == '1' || buffer[i] == '0' || buffer[i] == '2' || buffer[i] == '3')
			count_row++;
		i++;
	} while (buffer[i] != '\n');


	for (i = 0;i < maxleng;i++)
	{
		if (buffer[i] == '1')
		{
			int_buffer[indexer] = 1;
			indexer += 1;
		}
		else if (buffer[i] == '2')
		{
			int_buffer[indexer] = 2;
			indexer += 1;
		}
		else if (buffer[i] == '0')
		{
			int_buffer[indexer] = 0;
			indexer += 1;
		}
		else if (buffer[i] == '3')
		{
			int_buffer[indexer] = 3;
			indexer += 1;
		}
		else
		{
			//정해진 숫자 외의 나머지 문자열들
		}
	}

	row = count_row;
	col = indexer / count_row;
	indexer = 0;
	for (i = 0;i < col;i++)
	{
		for (int j = 0;j < row;j++)
		{
			cout << int_buffer[indexer];
			indexer++;
		}cout << endl;
	}

	return indexer;
}


void DrawGrid(int num)
{
	int row = 40;
	int col = 50;
	int count;
	int * grid;
	grid = new int[num] ;
	
	for (int i = 0;i < num;i++)
		*(grid + i) = 0;

	for (int i = 0; i < col;i++) 
	{
		for (int j = 0; j < row;j++)
		{
			cout << *(grid + sizeof(int));
		}printf("\n");
	}




}