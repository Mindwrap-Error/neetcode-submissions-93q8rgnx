/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;

        for(int i = 0; i < intervals.size(); i++)
        {
            pq.push({intervals[i].start, +1});
            pq.push({intervals[i].end, -1});
        }

        int ans = 0;
        int maxi = 0;
        while(!pq.empty())
        {
            pair<int, int> t = pq.top();
            pq.pop();

            ans += t.second;
            maxi = max(ans, maxi);
        }

        return maxi;
    }
};
