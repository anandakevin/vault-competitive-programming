#include<stdio.h>
#include<queue>
#include<algorithm>
#include<vector>
#include<strings.h>
 
using namespace std;

struct data{
	vector<int> tujuan;
	vector<int> waktu;
}PETA[105];
 
int dist[250];
int visited[250];

int dijkstra(int b, int exit, int timeLimit , int from) {
 
	priority_queue<pair <int, int> > pq;
	for(int i=1; i<=b; i++) {
			dist[i] = 213124141;
			visited[i] = 0;
	}
	dist[from] = 0;
	int result =0;
	pq.push(make_pair(-dist[from], from));
	while(!pq.empty()) {
 
		pair<int,int> currentNode = pq.top();
		pq.pop();
		int currentTo = currentNode.second;
		int currentCost = -currentNode.first;
		if (visited[currentTo]) continue;
	
		visited[currentTo] = 1;
 
 			for(int i=0;i<PETA[currentTo].tujuan.size();i++){
 				if(currentCost + PETA[currentTo].waktu.at(i) < dist[PETA[currentTo].tujuan.at(i)]){
					dist[PETA[currentTo].tujuan.at(i)] =currentCost + PETA[currentTo].waktu.at(i);
					pq.push(make_pair(-dist[PETA[currentTo].tujuan.at(i)],PETA[currentTo].tujuan.at(i))); 					
 				}
 			}
	}
	if(dist[exit] <= timeLimit){
		return 1;
	}
	return 0;
 
 
}

int main(){
	
	int tc, byknode, nExit, lt, banyak, f, t, time;
	
	scanf("%d", &tc);
	getchar();
	
	for(int i=0; i<tc; i++){
		scanf("%d %d %d %d", &byknode, &nExit, &lt, &banyak);
		getchar();
		if(i!=0){
			printf("\n");
		}
		
		for(int j=0; j<banyak; j++){
			scanf("%d %d %d", &f, &t, &time);
			getchar();
			PETA[f].tujuan.push_back(t);
			PETA[f].waktu.push_back(time);
		}
		int total=0;
		for(int j=1 ;j<=byknode;j++){
			total += dijkstra(byknode,nExit,lt,j);
		}
		printf("%d\n",total);
		bzero(PETA,sizeof(PETA));
	}
	
	
	getchar();
	return 0;
}