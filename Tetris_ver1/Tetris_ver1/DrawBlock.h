#pragma once

using namespace std;

class DrawBlock
{
protected: 
	int xPos;
	int yPos;
	int row;
	int col;
	int * grid;
	virtual void PrintBlock()=0;
	virtual void RotateBlock() = 0;
	virtual void MoveDown() = 0;
	virtual void MoveLeft() = 0;
	virtual void MoveRight() = 0;
	DrawBlock();
	virtual ~DrawBlock();
	
};

DrawBlock::DrawBlock()
{

}

DrawBlock::~DrawBlock()
{

}


class DrawRightBend : DrawBlock
{
public :
	DrawRightBend();



};

class DrawLeftBend : DrawBlock
{
public:
	DrawLeftBend();



};


class DrawCross : DrawBlock
{
public:
	DrawCross();



};

class DrawLong : DrawBlock
{
public:
	DrawLong();
	DrawLong(int * grid, int row, int col);
	void InitDrawLong(int * grid, int row, int col);
	virtual void PrintBlock();
	virtual void RotateBlock();
	virtual void MoveDown();
	virtual void MoveLeft();
	virtual void MoveRight();
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

void DrawLong::MoveLeft()
{
	
	for (int i = 0; i < 4; i++)
		this->grid[xPos + i + (yPos*row)] = 0;		

	this->xPos -= 1;
	cout << "xPos" << xPos<<endl;
	
	

}

void DrawLong::MoveRight()
{
	for (int i = 0; i < 4; i++)
		this->grid[xPos + i + (yPos*row)] = 0;
	this->xPos = +1;

}


void DrawLong::MoveDown()
{
	for (int i = 0; i < 4; i++)
	{		this->grid[xPos + i + (yPos*row)] = 0;
			//cout << "index " << xPos + i + (yPos*row) << endl;
	}
	cout << "xPos" << xPos << endl;
	this->yPos += 1;
}

void DrawLong::PrintBlock()
{
	for (int i = 0; i < 4; i++) {
	this->grid[xPos + i +(yPos*row)] = 3;
	cout << "index " << xPos + i + (yPos*row) << endl;
	}

}

void DrawLong::RotateBlock()
{

}