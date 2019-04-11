#pragma once

using namespace std;

class DrawBlock  //��Ʈ���� �� �θ�Ŭ����
{
protected: 
	int xPos;
	int yPos;
	int row;
	int col;
	int * grid;	
	DrawBlock(); //������
	virtual ~DrawBlock();  //���Ŭ���� �Ҹ��� ȣ��뵵 �Ҹ��� ����
public:
	void RotateBlock();	//����Լ��� �ڽ�Ŭ���������� ����� �� �ְ� �Ϸ��� public���� �����ؾ��Ѵ�.
	void MoveLeft();
	void MoveRight();
	void MoveDown();
	void PrintBlock();
};

DrawBlock::DrawBlock()
{

}

DrawBlock::~DrawBlock() 
{

}

void DrawBlock ::MoveLeft()
{
	for (int i = 0; i < 4; i++)
	{	
		grid[xPos + i + (yPos* row)] = 0;		
	}
	if(grid[xPos-1 + (yPos* row)] != 1)
		xPos -= 1;
}

void DrawBlock ::MoveRight()
{
	for (int i = 0; i < 4; i++)
	{		
		grid[xPos + i + (yPos* row)] = 0;		
	}
	if (grid[xPos+4+ (yPos* row)] != 1)
		xPos += 1;
}


void DrawBlock ::MoveDown()
{
	for (int i = 0; i < 4; i++)
	{		
		grid[xPos + i + (yPos*row)] = 0;		
	}	
	if (grid[xPos + ((yPos+1)* row)] != 1)
		yPos += 1;
}


void DrawBlock ::PrintBlock()
{
	for (int i = 0; i < 4; i++)
	{		
		grid[xPos + i + (yPos*row)] = 3;		
	}

}
void DrawBlock::RotateBlock()
{
	cout << "Rotate" << endl;
}

class DrawRightBend : DrawBlock   //�⿪�� ��� ��� ��� ��� Ŭ����
{
public :
	DrawRightBend();



};

class DrawLeftBend : DrawBlock   //������ ��� ��� ��� ��� Ŭ����
{
public:
	DrawLeftBend();



};


class DrawCross : DrawBlock    //���ڸ�� ���� ��� ��� Ŭ����
{
public:
	DrawCross();



};

class DrawLong : public DrawBlock	//������ ��� Ŭ����, �θ������ͷ� ��ĳ���� �Ϸ��� public�� �ʿ��ϴ�.
{
public:
	DrawLong();
	DrawLong(int * grid, int row, int col);
	void InitDrawLong(int * grid, int row, int col);
};

DrawLong::DrawLong()
{

}

DrawLong::DrawLong(int * grid, int row, int col)
{
	this->grid = grid;
	this->row = row;
	this->col = col;
	this->xPos = (row / 2) - 2;
	this->yPos = 1;
}

void DrawLong::InitDrawLong(int * grid, int row, int col)
{
	this->grid = grid;
	this->row = row;
	this->col = col;
	this->xPos = (row / 2) - 2;
	this->yPos = 1;
}
