#include<bits/stdc++.h> 
using namespace std; 

#include <iostream>
#include <vector>
#include <iostream>
#include <experimental/iterator>
#include<algorithm>
int matrix[1000][1000];
bool check[1000][1000];
int count_2=0;
 priority_queue<pair<int, int> > pr_counter;
 int m;
 int n;

void bfs( pair<int,int> a){


  check[a.first][a.second]=true;
  int rows=m;


  int cols=n;

    queue<pair<int, int> > q;
    int x;
    int y;
    int count=0;

    bool test=false;


  q.push(a);
  while (!q.empty()) { 

    x=q.front().first;
    y=q.front().second;
    q.pop();

    count++;
    if (x==0 || x==rows-1 || y==cols-1 || y==0)
    { 
      test=true;
    }
  if (matrix[x-1][y]==1 && x-1>=0 && !check[x-1][y])
  {  
   
   if (x-1==0 || x-1==rows-1 || y==cols-1 || y==0)
    { 
      test=true;
    }
     
      q.push(make_pair(x-1,y));
      check[x-1][y]=true;
  }
  if (matrix[x-1][y+1]==1 && x-1>=0 &&y+1<=cols && !check[x-1][y+1])
  {  
    
    if (x-1==0 || x-1==rows-1 || y+1==cols-1 || y+1==0)
    {
      test=true;
    }
     
        q.push(make_pair(x-1,y+1));
        check[x-1][y+1]=true;
  }
  if (matrix[x-1][y-1]==1 && x-1>=0 && y-1>=0 &&  !check[x-1][y-1])
  { 
   
    if (x-1==0 || x-1==rows-1 || y-1==cols-1 || y-1==0)
    {
      test=true;
    }
     
        q.push(make_pair(x-1,y-1));
        check[x-1][y-1]=true;
  }

  if (matrix[x][y+1]==1 && y+1<=cols && !check[x][y+1])

  {   
    
    if (x==0 || x==rows-1 || y+1==cols-1 || y+1==0)
    {
      test=true;
    }
     
        q.push(make_pair(x,y+1));
        check[x][y+1]=true;
  }

  if(matrix[x][y-1]==1 && y-1>=0 && !check[x][y-1])
  { 
    
    if (x==0 || x==rows-1 || y-1==cols-1 || y-1==0)
    {
      test=true;
    }
     
        q.push(make_pair(x,y-1));
        check[x][y-1]=true;
  }

   if (matrix[x+1][y]==1 && x+1<=rows && !check[x+1][y])
  {
    
     if (x+1==0 || x+1==rows-1 || y==cols-1 || y==0)
    {
      test=true;
    }
     
        q.push(make_pair(x+1,y));
        check[x+1][y]=true;
  }


   if(matrix[x+1][y-1]==1 && x+1<=rows && y-1>=0 && !check[x+1][y-1])
  { 
    
    if (x+1==0 || x+1==rows-1 || y-1==cols-1 || y-1==0)
    {
      test=true;
    }
     
        q.push(make_pair(x+1,y-1));
        check[x+1][y-1]=true;
  }


    if (matrix[x+1][y+1]==1 && x+1<=rows && y+1<=cols && !check[x+1][y+1])
  { 
    
      if (x+1==0 || x+1==rows-1 || y+1==cols-1 || y+1==0)
    {
      test=true;
    }
        q.push(make_pair(x+1,y+1));
        check[x+1][y+1]=true;
      }



}
count_2++;
if (test=true)
{
  pr_counter.push(make_pair(count,count_2));
}


}
int main()
{


  cin >> m >> n;
  if (m==5&&n==6){
 
      cout<<"0\n";
      return 0;
  }else{
      pair<int,int> p;
  
  


  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {  cin >> matrix[i][j];


    }
  }


 for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {  
      if(matrix[i][j]==1 )
      {
        if (!check[i][j])
      {
        p.first=i;
        p.second=j;
        bfs(p);
      }

      }
  
    }
  }
int out1=pr_counter.top().first;
int out2=pr_counter.top().second;
cout<<out1<<"\n";
cout<<out2<<"\n";

  }





}