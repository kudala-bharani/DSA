#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int HashTable[100],n;
int count = 0;
int hash(int x) {
	return x%n;
}
void print() {
	int i;
	if(count == 0) {
		printf("HashTable is empty\n");
		return;
	}
	printf("Linear Probing:\n");
	for(i=0;i<n;i++) {

			printf("[%d] => %d\n",i,HashTable[i]);
	}
	printf("\n");
}

void insert(int x) {
	int index, start;
	index = hash(x);
	start = index;
	while(HashTable[index] != -1) {
		if(HashTable[index] == -1)
			break;
		index = (index + 1) % n;
		if(index == start) {
			printf("Hash table is full. So cannot insert\n");
			return;
		}
	}
	HashTable[index] = x;
	count++;
	print();
	printf("Successfully inserted\n");
}

void search(int x) {
	int index, start;
	index = hash(x);
	start = index;
	while(HashTable[index] != x) {
		if(HashTable[index] == x) {
			break;
		}
		index = (index+1)%n;
		if(index == start) {
			printf("Element not found!\n");
			return;
		}
	}
	printf("Element found at index %d\n",index);
}

int main() {
	int op,x,i;
	printf("Enter size of Hash Table : ");
	scanf("%d",&n);

	for(i=0;i<n;i++) {
		HashTable[i] = -1;
	}

	do {
	printf("1.Insert 2.Search 3.Print 4.Exit\n");
	printf("Enter your option : ");
	scanf("%d",&op);

	switch(op) {
		case 1: printf("Enter a value to be inserted : ");
			scanf("%d",&x);
			insert(x);
			break;
		case 2: printf("Enter a value to be searched : ");
			scanf("%d",&x);
			search(x);
			break;
		case 3: print();
			break;

	}
	}while(op < 4);

	clrscr();
	return 0;
}