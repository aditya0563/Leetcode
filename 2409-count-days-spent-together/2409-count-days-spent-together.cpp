class Solution {
public:
    int daysBefore[12]={0,31,59,90,120,151,181,212,243,273,304,334};
    
    int toDayOfYear(const string& date) {
        int month = (date[0]-'0')*10+(date[1]-'0');
        int day = (date[3]-'0')*10+(date[4]-'0');
        return daysBefore[month-1]+day;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int arrive = max(toDayOfYear(arriveAlice),toDayOfYear(arriveBob));
        int leave = min(toDayOfYear(leaveAlice),toDayOfYear(leaveBob));
        
        return max(0,leave-arrive+1);
    }
};