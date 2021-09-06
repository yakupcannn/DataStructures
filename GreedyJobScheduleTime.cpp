#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int greedyJobs(vector<int>&);
int greedy2Jobs(vector<int>&);
int main()
{
	vector<int>jobs = { 15,8,3,10 };
	int totalTime = greedyJobs(jobs);
	int total2Time = greedy2Jobs(jobs);
	cout << "Average Time: " << (double)totalTime /jobs.size()<<endl;
	cout << "Average Time: " << (double)total2Time /jobs.size();
	return 0;
}
int greedyJobs(vector<int>& jobs)
{
	sort(jobs.begin(), jobs.end());
	int totalTime = 0, current = 0;
	for (int i = 0; i < jobs.size(); i++)
	{
		current += jobs[i];
		totalTime += current;
	}
	return totalTime;
}
int greedy2Jobs(vector<int>& jobs)
{
	priority_queue<int, vector<int>, greater<int>>heap(jobs.begin(), jobs.end());
	int totalTime = 0, current = 0;
	while (!heap.empty())
	{
		current += heap.top();
		heap.pop();
		totalTime += current;
	}
	return totalTime;
}