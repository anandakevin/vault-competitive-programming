#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

char map[40][40][40];
int visited[40][40][40];

struct node{
	int x,y,z;
};

void djikstra(int level , int row , int coloumn,node start , node end){
	queue <pair<int , pair<int , pair <int,int>>>> q;
	for(int i=0;i<level;i++){
		for(int j =0;j<row;j++){
			for(int k=0;k<coloumn ;k++){
				visited[i][j][k]=0;
			}
		}
	}
	//printf("%d %d %d\n",end.z, end.y, end.x);
	q.push(make_pair(0,make_pair(start.z , make_pair(start.y,start.x))));
	int result=0;
	while(visited[end.z][end.y][end.x]==0 &&!q.empty()){
		pair<int ,pair<int, pair<int,int>>> temp;
		temp = q.front();
		q.pop();
		int value = temp.first;
		int z = temp.second.first;
		int y = temp.second.second.first;
		int x = temp.second.second.second;
		
		if(visited[z][y][x]!=0){
			continue;
		}
		
		result = value;
		visited[z][y][x] =1;
		
		if(visited[end.z][end.y][end.x]!=0 ){
			break;
		}
		if(x<coloumn-1 && map[z][y][x+1]=='.' && visited[z][y][x+1]==0){
			q.push(make_pair(value+1, make_pair(z,make_pair(y,x+1))));
		}
		if(x>0 && map[z][y][x-1]=='.' && visited[z][y][x-1]==0){
			q.push(make_pair(value+1, make_pair(z,make_pair(y,x-1))));
		}
		if(y<row-1 && map[z][y+1][x]=='.' && visited[z][y+1][x]==0){
			q.push(make_pair(value+1, make_pair(z,make_pair(y+1,x))));
		}
		if(y>0 && map[z][y-1][x]=='.' && visited[z][y-1][x]==0){
			q.push(make_pair(value+1, make_pair(z,make_pair(y-1,x))));
		}
		if(z<level-1 && map[z+1][y][x]=='.' && visited[z+1][y][x]==0){
			q.push(make_pair(value+1, make_pair(z+1,make_pair(y,x))));
		}
		if(z>0 && map[z-1][y][x]=='.' && visited[z-1][y][x]==0){
			q.push(make_pair(value+1, make_pair(z-1,make_pair(y,x))));
		}
		
		
	}
	if(result ==0 ) printf("Trapped!\n");
	else
		printf("Escaped in %d minute(s).\n",result);
	
	
	
	
	
	
	
	
	
}

int main(){
	int level =0;
	int row =0;
	int coloumn = 0;
	struct node start;
	struct node end;
	while(scanf("%d %d %d",&level,&row,&coloumn)){
		
		
		if(level ==0 && row ==0 && coloumn ==0 ){
			break;
		}
		
		for(int i =0 ;i<level;i++){
			for(int j=0;j<row;j++ ){
				scanf("%s",&map[i][j]);
			}
		}
		for(int i =0 ;i<level;i++){
			for(int j=0;j<row;j++ ){
				for(int k=0;k<coloumn;k++){
					if(map[i][j][k]=='S'){
						start.z =i;
						start.y=j;
						start.x = k;
					}if(map[i][j][k]=='E'){
						//printf("asdasd");
						end.z=i;
						end.y=j;
						end.x=k;
					}
				}
			}
		}
		djikstra(level, row , coloumn, start , end);
		
		
		
	}


	getchar();
	return 0;

}