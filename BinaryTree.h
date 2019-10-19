#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#define MAX_CHILDREN	2
typedef unsigned int	uint;

using namespace std;

class CDataItemTree
{
	CDataItemTree* m_pParent;
	CDataItemTree* m_pChildren[MAX_CHILDREN];

	int m_ID;
	string m_name;

public:
	CDataItemTree();
	CDataItemTree(uint _ID);
	CDataItemTree(string _name);

	virtual void Print(void);
	virtual string ToString(void);

	friend class CBinaryTree;
};

class CBinaryTree
{
	CDataItemTree* m_pRoot;
	CDataItemTree* m_pCurrentNode;
	uint m_pSize;

public:
	CBinaryTree();
	CBinaryTree(CDataItemTree* pNode);
	~CBinaryTree();

	virtual void Print(void);
	virtual string ToString(void);

	void SetRoot(CDataItemTree* pNode);
	CDataItemTree* GetCurrentNode(void);
	void AddChildToCurrentNode(uint nIndex, CDataItemTree* pNode);
	CDataItemTree* SetCurrentNodeToChild(uint nIndex);
	CDataItemTree* SetCurrentNodeToParent(void);
	CDataItemTree* GetRootNode(void);

	void PrintRecursively(CDataItemTree* pNode);
};