class compare{
  public:
  bool operator()(pair<char,int>a ,pair<char,int>b){
      return a.second<b.second;
  }  
};

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<char,int>, vector<pair<char,int>>, compare> maxHeap;

        if(a>0){
            pair<char,int> p= make_pair('a',a);
            maxHeap.push(p);
        }
        if(b>0){
            pair<char,int> p= make_pair('b',b);
            maxHeap.push(p);
        }
        if(c>0){
            pair<char,int> p= make_pair('c',c);
            maxHeap.push(p);
        }

        string ans="";

        while(maxHeap.size()>1){
            pair<char,int> firstMax= maxHeap.top();
            maxHeap.pop();
            pair<char,int> secondMax= maxHeap.top();
            maxHeap.pop();

            if(firstMax.second>=2){
                ans.push_back(firstMax.first);
                ans.push_back(firstMax.first);
                firstMax.second-= 2;
            }
            else{
                ans.push_back(firstMax.first);
                firstMax.second--;
            }

            if(secondMax.second>=2 && secondMax.second>=firstMax.second){
                ans.push_back(secondMax.first);
                ans.push_back(secondMax.first);
                secondMax.second-= 2;
            }
            else{
                ans.push_back(secondMax.first);
                secondMax.second--;
            }

            if(firstMax.second>0){
                maxHeap.push(firstMax);
            }
            if(secondMax.second>0){
                maxHeap.push(secondMax);
            }

        }

        if(maxHeap.size()==1){
           pair<char,int> first= maxHeap.top();
           maxHeap.pop();

           if(first.second>=2){
                ans.push_back(first.first);
                ans.push_back(first.first);
                first.second-= 2;
            }
            else{
                ans.push_back(first.first);
                first.second--;
            }

        }
        return ans;
    }
};