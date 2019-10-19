#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

class CDataItem
{
	CDataItem* m_pPrev;
	CDataItem* m_pNext;

	int m_ID;

public:
	CDataItem();

	virtual void Print(void);
	virtual string ToString(void);

	friend class CList;
};

class CList
{
	CDataItem* m_pTop;
	CDataItem* m_pBot;

	unsigned int count;

public:
	CList();

	virtual void Print(void);
	virtual string ToString(void);

	virtual void Add(CDataItem* pItem);
	CDataItem* GetByIndex(int index);
	CDataItem* GetNextItem(CDataItem* currentItem);
	virtual void Remove(CDataItem* pItem);
};
