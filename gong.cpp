#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool compare(const vector<int>& a, const vector<int>& b) {
	return a[0] < b[0];
}

class Solution {
public:
	int minMeetingRooms(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(), compare);
		priority_queue<int, vector<int>, greater<int>> q;
		for (auto interval : intervals) {
			if (!q.empty() && q.top() <= interval[0]) q.pop();
			q.push(interval[1]);
		}
		return q.size();
	}
};
int main()
{
	Solution sol;
	vector<vector<int>>room{ {15, 20}, {5, 10}, {0, 30} };
	cout << sol.minMeetingRooms(room) << endl;
	return 0;
}

