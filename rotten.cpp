
#include <vector>
#include <iostream>
using namespace std;


class Solution {
vector<vector<int>> grid;
public:
    void make(vector<vector<int>> vec){
        grid=vec;
    }
    int orangesRotting() {
        int min=0,last=0;
        int m=grid.size(),n=grid[0].size();
            
        while(true){
            int k=0,x=0;  
            vector<pair<int,int>> temp;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==2){
                        k++;
                        if(i>0&&grid[i-1][j]==1){
                            pair<int,int> p;
                            p.first=i-1;
                            p.second=j;
                            temp.push_back(p);
                        }
                        if(j>0&&grid[i][j-1]==1){
                            pair<int,int> p;
                            p.first=i;
                            p.second=j-1;
                            temp.push_back(p);
                           
                        }
                        if(i<m-1&&grid[i+1][j]==1){
                            pair<int,int> p;
                            p.first=i+1;
                            p.second=j;
                            temp.push_back(p);
                           
                        }
                        if(j<n-1&&grid[i][j+1]==1){
                            pair<int,int> p;
                            p.first=i;
                            p.second=j+1;
                            temp.push_back(p);
                        }
                    }
                    if(grid[i][j]==1){
                        x++;
                    }

                }
            }
            for(int i=0;i<temp.size();i++){
                grid[temp[i].first][temp[i].second]=2;
            }
            if(last==k){
                if(min!=0)min--;
                if(x!=0)min=-1;
                break;
            }else{
                last=k;
            }
            min++;
        }
       
        return min;
    }
};
int main(){
    Solution S1;
    vector<vector<int>> v1={{2,1,1},{1,1,0},{0,1,1}};
    S1.make(v1);
    
    Solution S2;
    vector<vector<int>> v2={{2,1,1},{0,1,1},{1,0,1}};
    S2.make(v2);
    
    cout<<S1.orangesRotting()<<endl;//4
    cout<<S2.orangesRotting()<<endl;//-1
}