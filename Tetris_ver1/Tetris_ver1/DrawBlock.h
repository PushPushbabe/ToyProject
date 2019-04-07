#pragma once


class DrawBlock
{
protected: 
	int xPos;
	int yPos;
	int row;
	int col;
	int * gird;
	virtual void PrintBlock()=0;
	virtual void RotateBlock() = 0;
};



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
};

DrawLong::DrawLong()
{

}

DrawLong::DrawLong(int * grid, int row, int col)
{
	this->gird = grid;
	this->row = row;
	this->col = col;
	this->xPos = (row / 2) - 2;
	this->yPos = 0;
}

void DrawLong::InitDrawLong(int * grid, int row, int col)
{
	this->gird = grid;
	this->row = row;
	this->col = col;
	this->xPos = (row / 2) - 2;
	this->yPos = 0;
}



void DrawLong::PrintBlock()
{
	for(int i =0; i < 4; i++)
	this->gird[xPos+i] = 3;


}

void DrawLong::RotateBlock()
{

}