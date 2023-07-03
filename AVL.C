#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct tree {
	int data;
	struct tree *left,*right;
	int ht;
}*node;

node root = NULL;
node rotateleft(node t);
node rotateright(node t);
int BF(node t);
node RR(node t);
node RL(node t);
node LL(node t);
node LR(node t);
int height(node t);
void postorder(node t);
void inorder(node t);
void preorder(node t);

node insert(node t, int x) {
	if(t == NULL) {
		t = (node)malloc(sizeof(node));
		t -> data = x;
		t -> left = NULL;
		t -> right = NULL;
	} else if(x > t -> data) {

		t -> right = insert(t -> right,x);
		if(BF(t) == -2) {
			if(x > t -> right -> data)
				t = RR(t);
			else
				t = RL(t);
		}

	} else if(x < t -> data) {
		t -> left = insert(t -> left,x);
		if(BF(t) == 2) {
			if(x < t -> left -> data)
				t = LL(t);
			else
				t = LR(t);
		}
	}
	t -> ht = height(t);
	return t;
}

int height(node t) {
	int lh,rh;
	if(t == NULL)
		return 0;
	if(t -> left == NULL)
		lh = 0;
	else
		lh = 1 + t-> left -> ht;
	if(t -> right == NULL)
		rh = 0;
	else
		rh = 1 + t -> right -> ht;
	if(lh > rh)
		return lh;
	return rh;
}

node rotateright(node x) {
	node y;
	y = x -> left;
	x -> left = y -> right;
	y -> right = x;
	x -> ht = height(x);
	y -> ht = height(y);
	return y;
}

node rotateleft(node x) {
	node y;
	y = x -> right;
	x -> right = y -> left;
	y -> left = x;
	x -> ht = height(x);
	y -> ht = height(y);
	return y;
}

node RR(node t) {
	t = rotateleft(t);
	return t;
}

node LL(node t) {
	t = rotateright(t);
	return t;
}

node LR(node t) {
	t -> left = rotateleft(t -> left);
	t = rotateright(t);
	return t;
}

node RL(node t) {
	t -> right = rotateright(t -> right);
	t = rotateleft(t);
	return t;
}

int BF(node t) {
	int lh,rh;
	if(t == NULL)
		return 0;
	if(t -> left == NULL)
		lh = 0;
	else
		lh = 1 + t -> left -> ht;
	if(t -> right == NULL)
		rh = 0;
	else
		rh = 1 + t -> right -> ht;
	return (lh - rh);

}

void preorder(node t) {
	if(t != NULL) {
		printf("%dBF = (%d) ",t -> data,BF(t));
		preorder(t -> left);
		preorder(t -> right);
	}
}

void inorder(node t) {
	if(t != NULL) {
		inorder(t -> left);
		printf("%dBF = (%d) ",t -> data,BF(t));
		inorder(t -> right);
	}
}
void postorder(node t) {
	if(t != NULL) {
		postorder(t -> left);
		postorder(t -> right);
		printf("%dBF = (%d) ",t -> data,BF(t));
	}

}

int main() {
	int ch,x;
	do {
		printf("1)Insert 2)Preorder 3)Inorder 4)Postorder 5)Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);

		switch(ch) {
			case 1: printf("Enter an element to insert : ");
				scanf("%d",&x);
				root = insert(root,x);
				break;
			case 2: if(root) {
					printf("Preorder : ");
					preorder(root);
					printf("\n");
				} else {
					printf("Tree is empty!\n");
				}
				break;
			case 3: if(root) {
					printf("Inorder : ");
					inorder(root);
					printf("\n");
				} else {
					printf("Tree is empty!\n");
				}
				break;
			case 4: if(root) {
					printf("Postorder : ");
					postorder(root);
					printf("\n");
				} else {
					printf("Tree is empty!\n");
				}
				break;
			default : printf("Choose correct option\n");
		}

	}while(ch < 5);
	clrscr();
	return 0;
}