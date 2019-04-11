#pragma once

using namespace std;

class DrawBlock  //테트리스 블럭 부모클래스
{
protected: 
	int xPos;
	int yPos;
	int row;
	int col;
	int * grid;	
	DrawBlock(); //생성자
	virtual ~DrawBlock();  //상속클래스 소멸자 호출용도 소멸자 정의
public:
	void RotateBlock();	//멤버함수를 자식클래스에서도 사용할 수 있게 하려면 public으로 선언해야한다.
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

class DrawRightBend : DrawBlock   //기역자 모양 블록 모양 블록 클래스
{
public :
	DrawRightBend();



};

class DrawLeftBend : DrawBlock   //니은자 모양 블록 모양 블록 클래스
{
public:
	DrawLeftBend();



};


class DrawCross : DrawBlock    //십자모양 절반 모양 블록 클래스
{
public:
	DrawCross();



};

class DrawLong : public DrawBlock	//길쭉한 블록 클래스, 부모포인터로 업캐스팅 하려면 public이 필요하다.
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
