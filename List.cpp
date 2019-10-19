#include "List.h"

CDataItem::CDataItem()
{
	m_pNext = m_pPrev = NULL;
	m_ID = NULL;
}

void CDataItem::Print(void)
{

}

string CDataItem::ToString(void)
{
	return string("CDataItem");
}


CList::CList()
{
	m_pTop = m_pBot = NULL;
	count = 0;
}

void CList::Print(void)
{
	cout << ToString() << endl;
}

string CList::ToString(void)
{
	return string("CDataItem");
}

void CList::Add(CDataItem* pItem)
{
	pItem->m_ID = ++count;

	if (m_pBot == NULL)
	{
		m_pBot = pItem;
		return;
	}

	m_pTop = pItem;
	m_pBot->m_pNext = m_pTop;
}

CDataItem* CList::GetByIndex(int index)
{
	CDataItem* temp = m_pBot;

	for (int i = 0; i < index; i++)
		temp = temp->m_pNext;

	return temp;
}

CDataItem* CList::GetNextItem(CDataItem* currentItem)
{
	return currentItem->m_pNext;
}

void CList::Remove(CDataItem* pItem)
{
	CDataItem* temp = m_pBot;

	bool itemFound = false;

	for (unsigned int i = 0; i < count; i++)
	{
		std::cout << temp->m_pNext->ToString() << std::endl;

		if (temp == NULL)
			break;

		if (pItem == temp)
		{
			itemFound = true;

			// if in middle
			if (temp->m_pNext != NULL && temp->m_pPrev != NULL)
			{
				temp->m_pNext->m_pPrev = temp->m_pPrev;
				temp->m_pPrev->m_pNext = temp->m_pNext;
			}

			// is first element
			if (temp->m_pPrev == NULL && temp->m_pNext != NULL)
			{
				temp->m_pNext->m_pPrev = NULL;
				m_pBot = temp->m_pNext;
			}

			// is last element
			if (temp->m_pNext == NULL && temp->m_pPrev != NULL)
			{
				temp->m_pPrev->m_pNext = NULL;
				m_pTop = temp->m_pPrev;
			}

			delete temp;
			break;
		}

		temp = temp->m_pNext;
	}

	if (!itemFound)
	{
		cout << ("Couldn't remove item %s: Not found.", pItem->ToString());
		return;
	}

	if (--count < 0)
		count = 0;
}
