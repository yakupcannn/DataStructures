#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int solveKnapsack(vector<int>&, vector<int>&,int);
int solveKnapsackRecursive(vector<int>&, vector<int>&,int,int);
int solveKnapsackTopDownDP(vector<int>&, vector<int>&,int,int);
int solveKnapsackBottomUPDP(vector<int>&, vector<int>&,int,int);
int solveKnapsackMemoize(vector<int>&, vector<int>&,int,int,vector<vector<int>>&);
int main()
{
	//vector<int>value = { 30,20,100,90,160 };
	vector<int>value = { 10,40,30,50};
	//vector<int>weight = { 5,10,20,30,40 };
	vector<int>weight = { 5,4,6,3};
	int totalWeight = 10;
	cout<<"Total Value: "<<solveKnapsack(value, weight, totalWeight)<<endl;
	cout << "Total Value: " << solveKnapsackRecursive(value, weight, value.size() - 1, totalWeight) << endl;
	cout<<"Total Value: "<<solveKnapsackTopDownDP(value, weight, value.size()-1, totalWeight)<<endl;
	cout<<"Total Value: "<<solveKnapsackBottomUPDP(value, weight, value.size(), totalWeight)<<endl;

	cout << endl << endl;
	return 0;
}
int solveKnapsack(vector<int>& value, vector<int>& weight,int totalWeight)
{
	vector<pair<double,int>>unitPrice(value.size());
	for (int i = 0; i < unitPrice.size(); i++)
	{
		unitPrice[i].first = (double)value[i] / weight[i];
		unitPrice[i].second = i;
	}
	auto cmp = [](pair<double, int>& first, pair<double, int>second)
	{
		return first.first > second.first;
	};
	sort(unitPrice.begin(), unitPrice.end(), cmp);
	int totalValue = 0;
	for (int i = 0; i < unitPrice.size(); i++)
	{
		if (weight[unitPrice[i].second] <= totalWeight)
		{
			totalValue += value[unitPrice[i].second];
			totalWeight -= weight[unitPrice[i].second];
		}
	}
	return totalValue;
}
int solveKnapsackRecursive(vector<int>& value, vector<int>&weight,int size, int totalWeight)
{
	if (totalWeight == 0)return 0;
	if (size == 0)return 0;
	int take_it = 0;
	if (weight[size] <= totalWeight)
	{
		take_it = value[size]+solveKnapsackRecursive(value, weight, size - 1, totalWeight - weight[size]);
	}
	int leave_it = solveKnapsackRecursive(value, weight, size - 1, totalWeight);
	return take_it > leave_it ? take_it : leave_it;
}
int solveKnapsackTopDownDP(vector<int>&value, vector<int>&weight, int size, int totalWeight)
{
	vector<vector<int>>solTable(size);
	for (int i = 0; i < solTable.size(); i++)
	{
		for (int j = 0; j < totalWeight+1; j++)
		{
			solTable[i].push_back(-1);
		}
	}
	return solveKnapsackMemoize(value, weight, size, totalWeight, solTable);
}
int solveKnapsackBottomUPDP(vector<int>&value, vector<int>&weight, int size, int totalWeight)
{
	vector<vector<int>>solTable(size);
	for (int i = 0; i < solTable.size(); i++)
	{
		for (int j = 0; j < totalWeight + 1; j++)
		{
			solTable[i].push_back(-1);
		}
	}
	for (int j = 0; j <= totalWeight; j++)
	{
		solTable[0][j] = 0;
	}
	for (int i = 1; i < solTable.size(); i++)
	{
		for (int j = 0; j <= totalWeight; j++)
		{
			int leave_it = solTable[i - 1][j];
			int take_it = -1;
			if (weight[i] <= j)
			{
				take_it = value[i] + solTable[i - 1][j - weight[i]];
			}
			if (leave_it > take_it)
			{
				solTable[i][j] = leave_it;
			}
			else
			{
				solTable[i][j] = take_it;	
			}
		}
	}
	return solTable[size-1][totalWeight];
}
int solveKnapsackMemoize(vector<int>&value, vector<int>&weight, int size, int totalWeight, vector<vector<int>>&solTable)
{
	if (size == 0) { solTable[0][totalWeight] = 0; return 0; }
	int take_it=0;
	if (weight[size] <= totalWeight)
	{
		if (solTable[size - 1][totalWeight - weight[size]] < 0)
		{
			solTable[size - 1][totalWeight - weight[size]] =solveKnapsackMemoize(value, weight, size - 1, totalWeight - weight[size],solTable);
		}
		take_it = value[size]+solTable[size - 1][totalWeight - weight[size]];
	}
	if (solTable[size - 1][totalWeight] < 0)
	{
		solTable[size - 1][totalWeight] = solveKnapsackMemoize(value, weight, size - 1, totalWeight, solTable);
	}
	int leave_it = solTable[size - 1][totalWeight];
	return leave_it > take_it ? leave_it : take_it;
}