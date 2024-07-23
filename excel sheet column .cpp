class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        while(columnNumber>0){
            columnNumber--;
            char ch = (columnNumber % 26) + 'A';
            result  = ch + result;
            columnNumber /= 26;
        }
        return result;
    }
};