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
    int minMeetingRooms(vector<Interval>& in) {
        map<int,int>mp;
        for(auto &[st,en]:in){
            mp[st]+=1;
            mp[en]-=1;
        }
        int cnt =0;
        int maxi =0;
        for(auto it:mp){
            cnt +=it.second;
            maxi =max(maxi,cnt);
        }
        return maxi;
    }
};
