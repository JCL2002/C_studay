#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct content{
	char name[513];
	int number;
};

struct binary_tree{
	struct content c;
	struct binary_tree *left,*right;
};

struct binary_tree * buid(){
	struct binary_tree *root,*node;
	root=(struct binary_tree *)malloc(sizeof(struct binary_tree));
	strcpy("F",root->c.name);
	node=(struct binary_tree *)malloc(sizeof(struct binary_tree));
	root->left=node;
	strcpy("C",node->c.name);
	node=(struct binary_tree *)malloc(sizeof(struct binary_tree));
	root->right=node;
	strcpy("E",node->c.name);
	node=(struct binary_tree *)malloc(sizeof(struct binary_tree));
	root->left->left=node;
	strcpy("A",root->left->left->c.name);
	node=(struct binary_tree *)malloc(sizeof(struct binary_tree));
	root->left->right=node;
	strcpy("D",root->left->right->c.name);
	node=(struct binary_tree *)malloc(sizeof(struct binary_tree));
	root->left->right->left=node;
	strcpy("B",root->left->right->left->c.name);
	node=(struct binary_tree *)malloc(sizeof(struct binary_tree));
	root->right->left=node;
	strcpy("H",root->right->left->c.name);
	node=(struct binary_tree *)malloc(sizeof(struct binary_tree));
	root->right->right=node;
	strcpy("G",root->right->right->c.name);
	node=(struct binary_tree *)malloc(sizeof(struct binary_tree));
	root->right->right->left=node;
	strcpy("M",root->right->right->left->c.name);
	root->left->left->left=NULL;
	root->left->left->right=NULL;
	root->left->right->right=NULL;
	root->left->right->left->left=NULL;
	root->left->right->left->right=NULL;
	
	
	
	
	return root;
}

void find_l(struct binary_tree *root){
	
}

int main(){
	struct binary_tree *root;
	root=buid();
	
	
	
	return 0;
}