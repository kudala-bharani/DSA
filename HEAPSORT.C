#include <stdio.h>
#include <conio.h>

int n,a[100];

void printAr() {
	int i;
	for(i=0;i<n;++i) {
		printf("%d ",a[i]);
	}
	printf("\n");
}


void heapify(int a[],int n, int i) {

	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if(left < n && a[left] > a[largest]) {
		largest = left;
	}
	if(right < n && a[right] > a[largest]) {
		largest = right;
	}
	if(largest != i) {
		int temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
		heapify(a,n,largest);
	}
	printAr();
}

void heapSort(int a[],int n) {
	int i;
	for(i=(n/2-1);i>=0;i--) {
		heapify(a,n,i);

	}

	for(i=n-1;i>=0;i--) {
		int temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		heapify(a,i,0);
	}
}

int main() {
	int i;
	printf("Enter value of n : ");
	scanf("%d",&n);
	printf("Enter %d values : ",n);

	for(i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}

	printf("Before sorting array elements are : ");
	printAr();
	heapSort(a,n);
	printf("After sorting array elements are : ");
	printAr();
	getch();
	clrscr();
	return 0;

}