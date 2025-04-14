#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
    char word[10];
    int value, height;
    struct data *parent, *left, *right;
}*root = NULL;

int max(int a, int b){
    if (a > b) return a;
    return b;
}

int get_height(struct data *curr){
    if (curr == NULL) return 0;
    return curr->height;
}

void swap_parent(struct data *c, struct data *p){
    c->parent = p->parent;
    if(p==root)root = c;
    else if(p->parent->left == p)p->parent->left = c;
    else if(p->parent->right == p)p->parent->right = c;
    p->parent = c;
}

void rotate_right(struct data *lc, struct data *p){
    swap_parent(lc, p);
    p->left = lc->right;
    if(p->left!= NULL)p->left->parent = p;
    lc->right = p;
    p->height = max(get_height(p->left), get_height(p->right)) + 1;
    lc->height = max(get_height(lc->left), get_height(lc->right)) + 1;
}

void rotate_left(struct data *rc, struct data *p){
    swap_parent(rc, p);
    p->right = rc->left;
    if(p->right!= NULL)p->right->parent = p;
    rc->left = p;
    p->height = max(get_height(p->left), get_height(p->right)) + 1;
    rc->height = max(get_height(rc->left), get_height(rc->right)) + 1;
}

struct data* newnode(char* kata, int number, struct data *parent){
    struct data *node = (struct data*) malloc(sizeof(struct data));
    node->value = number;
    strcpy(node->word, kata);
    node->height = 1;
    node->parent = parent;
    node->left = node->right = NULL;
    //printf("Insert %s\n",node->word);
    return node;
}

void insert(char* kata, int number){
    if(root == NULL) root = newnode(kata, number, root);
    else{
        bool insertFlag = true;
        struct data *curr = root;
        while(insertFlag){
            if(strcmp(kata, curr->word) < 0){
                if(curr->left == NULL){curr->left = newnode(kata, number, curr); insertFlag = false;}
                curr = curr->left;
            }
            else if(strcmp(kata, curr->word) > 0){
                if(curr->right == NULL){curr->right = newnode(kata, number, curr); insertFlag = false;}
                curr = curr->right;
            }
            else{
                insertFlag = false;
            }
        }
        while(curr!= root){
            if(curr->parent->left == curr){
                int l = curr->height;
                int r = get_height(curr->parent->right);
                curr->parent->height = max(l, r) + 1;
                if(l-r > 1){
                    if(strcmp(kata, curr->word) < 0)rotate_right(curr, curr->parent);
                    else{
                        rotate_left(curr->right, curr);
                        rotate_right(curr->parent, curr->parent->parent);
                    }
                    return;
                }
            }
            else if(curr->parent->right == curr){
                int l = get_height(curr->parent->left);
                int r = curr->height;
                curr->parent->height = max(l, r) + 1;
                if(r-l > 1){
                    if(strcmp(kata, curr->word) > 0)rotate_left(curr, curr->parent);
                    else{
                        rotate_right(curr->left, curr);
                        rotate_left(curr->parent, curr->parent->parent);
                    }
                    return;
                }
            }
            curr=curr->parent;
        }
    }
}

void init(){
    int index=1;
    char ins[6];
    memset(ins,0,sizeof(ins));
    for(int i=0; i<26; i++){
        ins[0] = 97+i;
        insert(ins, index);
        index++;
    }
    memset(ins,0,sizeof(ins));
    for(int j=0; j<26; j++){
        for(int i=j+1; i<26; i++){
            ins[0]=97+j;
            ins[1]=97+i;
            insert(ins, index);
            index++;
        }
    }
    memset(ins,0,sizeof(ins));
    for(int k=0; k<26; k++){
        for(int j=k+1; j<26; j++){
            for(int i=j+1; i<26; i++){
                ins[0]=97+k;
                ins[1]=97+j;
                ins[2]=97+i;
                insert(ins, index);
                index++;
            }
        }
    }
    memset(ins,0,sizeof(ins));
    for(int l=0; l<26; l++){
        for(int k=l+1; k<26; k++){
            for(int j=k+1; j<26; j++){
                for(int i=j+1; i<26; i++){
                    ins[0]=97+l;
                    ins[1]=97+k;
                    ins[2]=97+j;
                    ins[3]=97+i;
                    insert(ins, index);
                    index++;
                }
            }
        }
    }
    memset(ins,0,sizeof(ins));
    for(int m=0; m<26; m++){
        for(int l=m+1; l<26; l++){
            for(int k=l+1; k<26; k++){
                for(int j=k+1; j<26; j++){
                    for(int i=j+1; i<26; i++){
                        ins[0]=97+m;
                        ins[1]=97+l;
                        ins[2]=97+k;
                        ins[3]=97+j;
                        ins[4]=97+i;
                        insert(ins, index);
                        index++;
                    }
                }
            }
        }
    }
}


int findIndex(char *find, struct data* curr){
    if(curr != NULL){
        if(strcmp(find, curr->word) < 0){
            findIndex(find, curr->left);
        }else if(strcmp(find, curr->word) > 0){
            findIndex(find, curr->right);
        }else if(strcmp(find, curr->word) == 0){
            return curr->value;
        }
    }else{
        return 0;
    }
}

int main(){
    init();
    char input[20];
    while(scanf("%[^\n]", input) != EOF){
        getchar();
        printf("%d\n", findIndex(input, root));
        strcpy(input, "");
    }

    getchar();
    return 0;
}