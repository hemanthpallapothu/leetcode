class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.size();
        string answer="";
        vector<int> removePositions;
        stack<int> stk;

        for(int i=0; i<n; i++){
            if(isalpha(s[i])){
                answer+=s[i];
            }
            else if(s[i]=='('){
                answer+=s[i];
                stk.push(i);
            }
            else{
                if(stk.empty()){
                    removePositions.push_back(i);
                }
                else{
                    stk.pop();
                    answer+=s[i];
                }
            }
        }

        stack<int> newStk;

        while(!stk.empty()){
            int topElement=stk.top();
            stk.pop();
            newStk.push(topElement);
        }

        string finalResult="";
        for(int i=0; i<n; i++){
            if(!newStk.empty() && i==newStk.top() || find(removePositions.begin(), removePositions.end(), i)!=removePositions.end()){
                if(!newStk.empty() && i==newStk.top() ){
                    newStk.pop();
                }
                
            }
            else{
                finalResult+=s[i];
            }
        }
        return finalResult;
    }
};