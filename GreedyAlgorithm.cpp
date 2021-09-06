#include<iostream>
#include<vector>
using namespace std;

int main()
{
	//Greedy Algorithm
	vector<vector<int>>matrix = { {0,1,3},{2,4,2},{1,3,0}};
	int cost = 0,iterations=0,i,j;
	for (i = 0, j = 0;i != matrix.size()-1 ||j != matrix.size()-1;)
	{
		int down=101, right=101;
		iterations++;
		if (i + 1 <= matrix.size() - 1)
		{
			down = matrix[i + 1][j];
		}
		else if (j + 1 <= matrix.size() - 1)
		{
			right = matrix[i][j + 1];
		}
		if (down <= right)
		{
			cost += down;
			i++;
		}
		else
		{
			cost += right;
			j++;
		}
	}
	cout << "Cost: " << cost<<endl;
	cout << "Iterations: " << iterations;
	cout << endl << endl;
	return 0;
}