#include "BinaryTree.h"

CDataItemTree::CDataItemTree()
{
	m_ID = 0;
	m_pParent = NULL;
	memset(m_pChildren, 0, sizeof(m_pChildren));
}

CDataItemTree::CDataItemTree(uint ID)
{
	m_ID = ID;
	m_pParent = NULL;
	m_name = "default node name";
	memset(m_pChildren, 0, sizeof(m_pChildren));
}

CDataItemTree::CDataItemTree(string _name)
{
	m_ID = 0;
	m_pParent = NULL;
	memset(m_pChildren, 0, sizeof(m_pChildren));
	m_name = _name;
}

void CDataItemTree::Print(void)
{
	cout << m_name << endl;
}

string CDataItemTree::ToString(void)
{
	return string("CDataItemTree");
}


CBinaryTree::CBinaryTree()
{
	m_pRoot = m_pCurrentNode = NULL;
	m_pSize = 0;
}

CBinaryTree::CBinaryTree(CDataItemTree* pNode)
{
	m_pRoot = m_pCurrentNode = NULL;
	m_pSize = 0;

	SetRoot(pNode);
}

CBinaryTree::~CBinaryTree()
{

}

void CBinaryTree::Print(void)
{
	cout << ToString() << endl;
}

string CBinaryTree::ToString(void)
{
	return string("CBinaryTree");
}

void CBinaryTree::SetRoot(CDataItemTree* pNode)
{
	m_pRoot = pNode;
	m_pCurrentNode = pNode;
}

CDataItemTree* CBinaryTree::GetCurrentNode(void)
{
	return m_pCurrentNode;
}

void CBinaryTree::AddChildToCurrentNode(uint nIndex, CDataItemTree* pNode)
{
	if (nIndex > MAX_CHILDREN - 1)
		return;

	m_pCurrentNode->m_pChildren[nIndex] = pNode;
}

CDataItemTree* CBinaryTree::SetCurrentNodeToChild(uint nIndex)
{
	if (nIndex >= MAX_CHILDREN)
		return m_pCurrentNode;

	return m_pCurrentNode = m_pCurrentNode->m_pChildren[nIndex];
}

CDataItemTree* CBinaryTree::SetCurrentNodeToParent(void)
{
	return m_pCurrentNode = m_pCurrentNode->m_pParent;
}

CDataItemTree* CBinaryTree::GetRootNode(void)
{
	return m_pRoot;
}

void CBinaryTree::PrintRecursively(CDataItemTree* pNode)
{
	pNode->Print();

	for (uint i = 0; i < MAX_CHILDREN; i++)
	{
		if (pNode->m_pChildren[i] == NULL)
			continue;

		PrintRecursively(pNode->m_pChildren[i]);
	}
}
