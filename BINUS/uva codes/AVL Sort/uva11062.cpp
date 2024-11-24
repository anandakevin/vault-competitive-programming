
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
	char word[100];
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

struct data* newnode(char* kata,struct data *parent){
	struct data *node = (struct data*) malloc(sizeof(struct data));
	strcpy(node->word, kata);
	node->height = 1;
	node->parent = parent;
	node->left = node->right = NULL;
	//printf("Insert %s\n",node->word);
	return node;
}

void insert(char* kata){
	if(root == NULL) root = newnode(kata, root);
	else{
		bool insertFlag = true;
		struct data *curr = root;
		while(insertFlag){
			if(strcmp(kata, curr->word) < 0){
				if(curr->left == NULL){curr->left = newnode(kata, curr); insertFlag = false;}
				curr = curr->left;
			}
			else if(strcmp(kata, curr->word) > 0){
				if(curr->right == NULL){curr->right = newnode(kata, curr); insertFlag = false;}
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

void inorder(struct data* curr){
	if(curr!=NULL){
		inorder(curr->left);
		printf("%s\n", curr->word);
		inorder(curr->right);
	}
}

char kata, temp[50], temp2[50];
int main(){
	int index = 0;
	bool flag = false;
	while(scanf("%c", &kata) != EOF){
		if(kata >= 'A' && kata <='Z'){
			kata = kata-'A'+'a';
		}else if(kata == '-'){
			flag = true;
		}
		
		if(kata == '-' || (kata >= 'a' && kata <= 'z')){
			if((kata >= 'a' && kata <= 'z') && flag){
				flag = false;
			}
			temp2[index] = kata;
			index++;
		}else if(kata == '\n' || kata == ' ' ||(kata < 'a' || kata > 'z')){
			if(!flag && strlen(temp2) != 0){
				insert(temp2);
				memset(temp2, NULL, sizeof(temp2));
				index = 0;
			}else if(strlen(temp2) != 0){
				temp2[strlen(temp2)-1] = '\0';
				index--;
				flag = false;
			}
		}
	}
	
	inorder(root);

	getchar();
	return 0;
}