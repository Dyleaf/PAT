#include <bits/stdc++.h>
using namespace std;

struct Node{
  int level;
  int firstChild;
  int nextSbiling;
  int childNum;
};

Node node[101];
void BFS(){

  queue<int> level;
  int NodeTobelevel[101];
  memset(NodeTobelevel,0, sizeof(NodeTobelevel));

  node[1].level = 0;
  level.push(1);
  int curId, tmpId,curlevel = 0;
  while(!level.empty()){

    curId = level.front();
    level.pop();
    int num = node[curId].childNum;
    curlevel = node[curId].level;

    if (num==0)
    {
      NodeTobelevel[node[curId].level]++;
      continue;
    }

    tmpId = node[curId].firstChild;
        node[tmpId].level = node[curId].level+1;
        level.push(tmpId);
        num--;


    while(num--){
      tmpId = node[tmpId].nextSbiling;
      node[tmpId].level = node[curId].level+1;
      level.push(tmpId);
    }
  }
  for (int i = 0; i <= curlevel; ++i){
    if (i==0){
      printf("%d", NodeTobelevel[i]);
    }else{
      printf(" %d", NodeTobelevel[i]);
    }
  }
}

int main(){
  int N,M;
  scanf("%d%d", &N,&M);
  int curId, firstSibling;

  memset(node,0, sizeof(node));

  //input node
  for (int i = 0; i < M; ++i)
  {
    scanf("%d",&curId);
    scanf("%d",&(node[curId].childNum));
    scanf("%d",&(node[curId].firstChild));

    firstSibling = node[curId].firstChild;
    for (int i = 0; i < node[curId].childNum-1; ++i)
    {
      scanf("%d",&(node[firstSibling].nextSbiling));
      firstSibling = node[firstSibling].nextSbiling;
    }
  }
  BFS();
}
