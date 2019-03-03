// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int start = 1;
        int end = n;
        int mid;
        while(1)
        {
            mid = start + (end-start)/2;
            int status = guess(mid);
            if(status == 0)
            {
                return mid;
            }else if(status == 1) {
                start = mid + 1;
            } else if(status == -1) {
                end = mid;
            }
            
        }
    }
};