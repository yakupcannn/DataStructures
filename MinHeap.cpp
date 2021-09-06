#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct MyNode
{
	MyNode *left,*right;
	int freq;
	MyNode()
	{
		left = right = NULL;
		freq = 0;
	}
};
struct CompareFreq {
	bool operator () (MyNode* const left, MyNode* const right)
	{
		return left->freq > right->freq;
	}
};
int main()
{
	string str;
	vector<int> count(4,0);
	cout << "Enter a string including only a,b,c and d:";
	cin >> str;
	for (int i = 0; i < count.size(); i++)
	{
		for (int j = 0; j < str.length(); j++)
		{
			if (i == str[j] - 'a')
			{
				count[i]++;
			}
		}
	}
	priority_queue<MyNode*, vector<MyNode*>,CompareFreq>minHeap;
	for (int i = 0; i < count.size(); i++)
	{
		MyNode *node=new MyNode();
		node->freq = count[i];
		minHeap.push(node);
	}
	while (minHeap.size() > 1)
	{
		MyNode *superNode=new MyNode();
		superNode->left =minHeap.top();
		minHeap.pop();
		superNode->right = minHeap.top();
		minHeap.pop();
		superNode->freq = superNode->left->freq + superNode->right->freq;
		minHeap.push(superNode);
	}
	cout << endl<<endl;
	return 0;
}