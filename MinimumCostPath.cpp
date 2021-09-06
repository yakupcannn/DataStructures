#include<iostream>
#include<vector>
using namespace std;
int fibonacciDP(int n);
int minimumCostRecursively(vector<vector<int>>&,int,int);
void minumumCostPath_TopDownDp(vector<vector<int>>&);
int minumumCostPath_TopDownDp_Aux(vector<vector<int>>&,int,int,vector<vector<int>>&);
int main()
{
	cout<<fibonacciDP(6)<<endl;
	vector<vector<int>>matrix = { {0,1,5},{2,4,2},{1,3,5} };
	cout<<"Minimum Cost: "<<minimumCostRecursively(matrix, 0, 0)<<endl;
	minumumCostPath_TopDownDp(matrix);
	cout << endl << endl;
	return 0;
}
int fibonacciDP(int n)
{
	int first = 0,second=1;
	int result = 0;
	for (int i = 2; i <= n; i++)
	{
	   result = first + second;
	   first = second;
	   second = result;

	}
	return result;
}
int minimumCostRecursively(vector<vector<int>>&matrix,int i,int j)
{
	if (i == matrix.size() - 1 && j == matrix.size() - 1)return 0;
	int downCost=INT_MAX,rightCost=INT_MAX;
	if (i + 1 <= matrix.size() - 1)
		downCost = minimumCostRecursively(matrix, i + 1, j);
	else if (j + 1 <= matrix.size() - 1)
		rightCost = minimumCostRecursively(matrix, i, j + 1);
	int minimumCost = downCost;
	if (rightCost < minimumCost)minimumCost = rightCost;
	return matrix[i][j] + minimumCost;
}
void minumumCostPath_TopDownDp(vector<vector<int>>&matrix)
{
	vector<vector<int>>solutionTable(matrix.size(),vector<int>(matrix.size()));
	for (int i = 0; i < solutionTable.size(); i++)
	{
		for (int j = 0; j < solutionTable[i].size(); j++)
		{
			solutionTable[i][j]=-1;
		}
	}
	int result = minumumCostPath_TopDownDp_Aux(matrix, 0, 0, solutionTable);
	cout << "Minimum Cost: " << result<<endl;
}
int minumumCostPath_TopDownDp_Aux(vector<vector<int>>&matrix, int i, int j, vector<vector<int>>&solTable)
{
	int N = matrix.size() - 1;
	if (i == N && j == N)return 0;
	int rightCost=INT_MAX,downCost = INT_MAX;
	if (i + 1 <= N)
	{
		if (solTable[i + 1][j] < 0)
		{
			solTable[i + 1][j] = minumumCostPath_TopDownDp_Aux(matrix, i + 1, j, solTable);
		}
		downCost = solTable[i + 1][j];
	}
	else if (j + 1 <= N)
	{
		if (solTable[i][j + 1] < 0)
		{
			solTable[i][j+1] = minumumCostPath_TopDownDp_Aux(matrix, i, j + 1, solTable);
		}
		rightCost = solTable[i][j + 1];
	}
	int mininumCost = downCost;
	if (rightCost < mininumCost)mininumCost = rightCost;
	return matrix[i][j]+mininumCost;
}