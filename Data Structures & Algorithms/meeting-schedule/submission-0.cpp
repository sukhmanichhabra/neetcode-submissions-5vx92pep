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

    bool canAttendMeetings(vector<Interval>& inte) {
      map<int,int>mp;
      for(auto [it, is]:inte){
        mp[it]++;
        mp[is]--;

      }
      int cnt=0;
      for(auto it:mp){
        cnt+=it.second;
        if(cnt>1)return false;
      }
      return true;
    }
};
