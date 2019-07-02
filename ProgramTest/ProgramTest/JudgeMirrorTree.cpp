#include <iostream>
#include "oj.h"
#include <stack>
#include <vector>
using namespace  std;

struct BSTreeNode
{
	int m_nValue;         // value of node
	BSTreeNode *m_pLeft;  // left child of node
	BSTreeNode *m_pRight; // right child of node
};

bool JudgeSymmetricalArray(vector<int> &dataVector) {
	size_t length = dataVector.size();

	if ((length & 0x1) == 0)
	{
		return false;
	}
	for (int i = 0; i < length / 2; ++i)
	{
		if (dataVector[i] != dataVector[length-i-1])
		{
			return false;
		}
	}
	return true;
}
bool symmetricalBinaryTree(BSTreeNode *root) 
{
	if (NULL == root)
		return false;
	stack<BSTreeNode*> stack_node;
	vector<int> dataVector;
	BSTreeNode *pTemp;
	while (NULL != root || !stack_node.empty()) {
		while (NULL != root) {
			stack_node.push(root);
			root = root->m_pLeft;
		}
		pTemp = stack_node.top();
		stack_node.pop();
		cout << pTemp->m_nValue << " ";
		root = pTemp->m_pRight;
		dataVector.push_back(pTemp->m_nValue);
	}
	return JudgeSymmetricalArray(dataVector);
}

void TestsymmetricalBinaryTree() {
	vector<int> aa1 = {1};
	vector<int> aa2 = {2,2};
	vector<int> aa3 = {1,2,3};
	vector<int> aa4 = {2,2,2};
	vector<int> aa5 = {1,2,1};
	vector<int> aa6 = {1,2,2,1};
	vector<int> aa7 = {1,2,3,2,1};

	cout << JudgeSymmetricalArray(aa1) << endl;
	cout << JudgeSymmetricalArray(aa2) << endl;
	cout << JudgeSymmetricalArray(aa3) << endl;
	cout << JudgeSymmetricalArray(aa4) << endl;
	cout << JudgeSymmetricalArray(aa5) << endl;
	cout << JudgeSymmetricalArray(aa6) << endl;
	cout << JudgeSymmetricalArray(aa7) << endl;

}