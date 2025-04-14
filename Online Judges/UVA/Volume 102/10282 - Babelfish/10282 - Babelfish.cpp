#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
    char word[15], value[15];
    int height;
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

struct data* newnode(char* arti, char* kata, struct data *parent){
    struct data *node = (struct data*) malloc(sizeof(struct data));
    strcpy(node->word, kata);
    strcpy(node->value, arti);
    node->height = 1;
    node->parent = parent;
    node->left = node->right = NULL;
    //printf("Insert %s\n",node->word);
    return node;
}

void insert(char* arti, char* kata){
    if(root == NULL) root = newnode(arti, kata, root);
    else{
        bool insertFlag = true;
        struct data *curr = root;
        while(insertFlag){
            if(strcmp(kata, curr->word) < 0){
                if(curr->left == NULL){curr->left = newnode(arti, kata, curr); insertFlag = false;}
                curr = curr->left;
            }
            else if(strcmp(kata, curr->word) > 0){
                if(curr->right == NULL){curr->right = newnode(arti, kata, curr); insertFlag = false;}
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

char* findIndex(char *find, struct data* curr){
    if(curr != NULL){
        if(strcmp(find, curr->word) < 0){
            findIndex(find, curr->left);
        }else if(strcmp(find, curr->word) > 0){
            findIndex(find, curr->right);
        }else if(strcmp(find, curr->word) == 0){
            return curr->value;
        }
    }else{
        return "eh";
    }
}
char input[30];
char * arti;
char kata1[15];
int main(){
    strcpy(kata1, " ");
    while(scanf("%[^\n]", input) != EOF){
        getchar();
        if(strcmp(input, kata1) != 0){
            if(strlen(input) != 0 && strstr(input, " ") == NULL){
                printf("%s\n", findIndex(input, root));
                memset(input, 0 , sizeof(input));
            }else{
                arti = strtok(input, " ");
                
                strcpy(kata1, arti);
                arti = strtok(NULL, " ");
                insert(kata1, arti);
            }
        }
    }

    getchar();
    return 0;
}