#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};


struct node *tree;
struct node *insertElement(struct node *,int);
struct node *create_tree(struct node *);
void preorderTraversal(struct node *);
void inorderTraversal(struct node *);
void postorderTraversal(struct node *);
struct node *deleteElement(struct node *,int);
struct node *deleteTree(struct node *);

void main() {
	int option,val;
	struct node *ptr;
	tree = create_tree(tree);
	while(1){
		printf("\n**********MAIN MENU***********");
		printf("\n1. Insert Element");
		printf("\n2. Preorder Traversal\n3. Inorder Traversal");
		printf("\n4. Postorder Traversal");
		printf("\n5. Delete an element");
		printf("\n6. Exit");
		printf("\nEnter an option : ");
		scanf("%d",&option);
		switch(option) {
			case 1: printf("Enter the value of new node : ");
				scanf("%d",&val);
				tree = insertElement(tree,val);
				break;
			case 2: printf("Preorder Traversal : ");
				preorderTraversal(tree);
				break;
			case 3: printf("Inorder Traversal : ");
				inorderTraversal(tree);
				break;
			case 4: printf("Postorder Traversal : ");
				postorderTraversal(tree);
				break;
			case 5: printf("Enter the elements to be deleted : ");
				scanf("%d",&val);
				tree = deleteElement(tree,val);
				break;
			case 6: clrscr();
				exit();
		}
	}
}

struct node *create_tree(struct node *tree) {
	tree = NULL;
	return tree;
}

struct node *insertElement(struct node *tree, int val) {
	struct node *ptr, *nodeptr, *parentptr;
	ptr = (struct node *)malloc(sizeof(struct node));
	ptr -> data = val;
	ptr -> left = NULL;
	ptr -> right= NULL;

	if(tree == NULL) {
		tree = ptr;
		tree -> left = NULL;
		tree -> right = NULL;
	} else {
		parentptr = NULL;
		nodeptr = tree;

		while(nodeptr != NULL) {

			parentptr = nodeptr;
			if(val < nodeptr -> data)
				nodeptr = nodeptr -> left;
			else
				nodeptr = nodeptr -> right;

		}

		if(val < parentptr -> data)
			parentptr -> left = ptr;
		else
			parentptr -> right = ptr;

	}
	return tree;
}


void preorderTraversal(struct node *tree) {

	if(tree != NULL) {
		printf("%d ",tree -> data);
		preorderTraversal(tree -> left);
		preorderTraversal(tree -> right);
	}
}

void inorderTraversal(struct node *tree) {

	if(tree != NULL) {
		inorderTraversal(tree -> left);
		printf("%d ",tree -> data);
		inorderTraversal(tree -> right);
	}

}

void postorderTraversal(struct node *tree) {

	if(tree != NULL) {
		postorderTraversal(tree -> left);
		postorderTraversal(tree -> right);
		printf("%d ",tree -> data);
	}

}

struct node *deleteElement(struct node *tree, int val) {

	struct node *cur, *parent, *suc, *psuc, *ptr;
	parent = tree;
	cur = tree -> left;

	if(tree -> left == NULL && tree -> right == NULL) {
		free(tree);
	       //	printf("\nThe tree is empty");
		return(tree);
	}

       //	parent = tree;
       //	cur = tree -> left;

	while(cur != NULL && val != cur-> data) {
		parent = cur;
		cur = (val < cur -> data) ? cur -> left : cur -> right;
	}

	if(cur == NULL) {
		printf("\nThe value to be deleted is not present in the tree");
		return(tree);
	}

	if(cur -> left == NULL)
		ptr = cur -> right;
	else if(cur -> right == NULL)
		ptr = cur -> left;
	else {

		psuc = cur;
		cur = cur -> left;

		while(suc -> left != NULL) {
			psuc = suc;
			suc = suc -> left;
		}

		if(cur == psuc) {
			suc -> left = cur -> right;
		} else {
			suc -> left = cur -> left;
			psuc ->left = suc -> right;
			suc -> right = cur -> right;
		}

		ptr = suc;

	}

	if(parent -> left == cur)
		parent -> left = ptr;
	else
		parent -> right = ptr;

	free(cur);

	return tree;

}