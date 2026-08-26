#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s){
        if(s.length()<2)
            return s;
        int start=0;
        int maxLen=1;
        for(int i=0;i<s.length();i++){
            int left=i;
            int right=i;

            while(left>=0 && right<s.length()&&s[left]==s[right]) {
                if(right-left+1>maxLen) {
                    start=left;
                    maxLen=right-left+1;
                }
                left--;
                right++;
            }
            left=i;
            right=i+1;
            while(left>=0 && right<s.length() && s[left] == s[right]) {
                if(right-left+1>maxLen){
                    start=left;
                    maxLen=right-left+1;
                }
                left--;
                right++;
            }
        }
        return s.substr(start,maxLen);
    }
};
int main() {
    Solution obj;
    string s = "babad";
    cout << obj.longestPalindrome(s);
    return 0;
}