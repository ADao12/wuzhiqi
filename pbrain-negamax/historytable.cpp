#include "historytable.h"



void initHistoryTable(int width,int height)
{
	for (int j = 0; j < 2; j++)
	{
		m_HistoryTable[j] = new int* [width];
		for (int i = 0; i < width; i++)
		{
			m_HistoryTable[j][i] = new int[height];
		}
	}
}
void reSetHistoryTable(int width,int height)
{
	for (int k = 0; k < 2; k++)
	{
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++)
			{
				m_HistoryTable[k][i][j] = 10;
			}
		}
	}
}
int getHistoryScore(Mov move,int player)
{
	return m_HistoryTable[player][move.x][move.y];
}
void enterHistoryScore(Mov move,int depth,int player)
{
	m_HistoryTable[player][move.x][move.y] += 2<<depth;
}


void freeHistoryTable()
{
	delete[] m_HistoryTable[0];
	delete[] m_HistoryTable[1];
	m_HistoryTable[0] =NULL;
	m_HistoryTable[1] = NULL;
}