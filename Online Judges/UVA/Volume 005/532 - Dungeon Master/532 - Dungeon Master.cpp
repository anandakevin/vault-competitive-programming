#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;

typedef struct{
    int level, baris, kolom;
}node;

int level, baris, kolom;

char map[35][35][35];
int visited[35][35][35];

int bfs(int fromL, int fromR, int fromC){
    queue<node> q;
    memset(visited, 0, sizeof(visited));
    q.push((node){fromL,fromR,fromC});
    for(int moves = 0; q.size()>0; moves++){
        int currentSize = q.size();
        for(int i=0; i<currentSize; i++){
            node currentNode = q.front();
            q.pop();

            int nl = currentNode.level;
            int nr = currentNode.baris;
            int nc = currentNode.kolom;
            //printf("%d %d %d\n",nl,nr,nc);
            if(visited[nl][nr][nc]){
                continue;
            }
            visited[nl][nr][nc] = 1;

            if(map[nl][nr][nc] == 'E'){
               return moves;
            }
            if(nr-1 >= 0 && map[nl][nr-1][nc] != '#'){
                q.push((node){nl, nr-1, nc});
            }
            if(nr+1 < baris && map[nl][nr+1][nc] != '#'){
                q.push((node){nl, nr+1, nc});
            }
            if(nc-1 >= 0 && map[nl][nr][nc-1] != '#'){
                q.push((node){nl, nr, nc-1});
            }
            if(nc+1 < kolom && map[nl][nr][nc+1] !=  '#'){
                q.push((node){nl, nr, nc+1});
            }

            if(nl - 1 >= 0 && map[nl-1][nr][nc] != '#'){
                 q.push((node){nl-1, nr, nc});
               
            }
            if(nl+1 < level && map[nl+1][nr][nc] != '#'){
                q.push((node){nl+1, nr, nc});
            }
        }
    }
    return -1;
}

int main(){
    do{
        scanf("%d %d %d", &level, &baris, &kolom);
        if(level != 0){
            
            for(int i=0; i<level; i++){
                for(int j=0; j<baris; j++){
                        scanf("%s", &map[i][j]);
                }
            }

            int startL = -1;
            int startR = -1;
            int startC = -1;

            for(int i=0; i<level; i++){
                for(int j=0; j<baris; j++){
                    for(int k=0; k<kolom; k++){
                        //printf("%c", map[i][j][k]);
                        if(map[i][j][k] == 'S'){
                                startL = i;
                                startR = j;
                                startC = k;
                        }
                    }
                }
            }

            int ans = bfs(startL, startR, startC);
            if(ans == -1){
                printf("Trapped!\n");
            }else{
                printf("Escaped in %d minute(s).\n", ans);
            }
        }
    }while(level !=0);

    return 0;
}
