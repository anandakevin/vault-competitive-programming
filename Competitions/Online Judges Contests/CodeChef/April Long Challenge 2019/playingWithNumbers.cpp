#include <iostream>
using namespace std;

struct node{
  int val, leftChild, rightChild, m;
} ns[100001];

int ttlNode;

void reset(){
  for(int i = 0; i <= ttlNode; i++) {
    ns[i].val = 0;
    ns[i].leftChild = -1;
    ns[]
  }
}

void addChild(int parent, int child){
  if(ns[parent - 1].leftChild == -1) ns[parent].leftChild = child - 1;
  else ns[parent - 1].rightChild = child - 1;
}

int main(){
  int rep; cin >> rep;

  while(rep--){
    cin >> ttlNode;
    reset();
    for(int i = 0; i < ttlNode - 1; i++){
      int a, b; cin >> a >> b;
      addChild(a, b);
    }
    for(int i = 0; i < ttlNode; i++) cin >> ns[i].val;
    for(int i = 0; i < ttlNode; i++) cin >> ns[i].m;

  }
  return 0;
}
