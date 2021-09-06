#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Activity
{
	int startingTime;
	int endTime;
	Activity(int start, int end)
	{
		startingTime = start;
		endTime = end;
	}
};
int main()
{
	vector<Activity> activities = { Activity(1,4),Activity(3,5),Activity(0,6),Activity(5,7),Activity(3,8),Activity(5,9)
		,Activity(6,10),Activity(8,11),Activity(8,12),Activity(2,13),Activity(12,14) };
	vector<Activity>result;
	auto cmp = [](Activity& first, Activity& second)
	{
		return first.endTime < second.endTime;
	};
	sort(activities.begin(), activities.end(),cmp);
	result.push_back(activities[0]);
	int index = 0,current=0;
	for (int i = current+1; i< activities.size(); i++)
	{
		if (result[index].endTime <= activities[i].startingTime)
		{
			result.push_back(activities[i]);
			current = i;
			index++;
		}	
	}
	for (int i = 0; i < result.size(); i++)
	{
		cout << "[ " << result[i].startingTime << "," << result[i].endTime << " )";
	}
	return 0;
}