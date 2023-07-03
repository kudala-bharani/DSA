#include <stdio.h>
#include <conio.h>

int f=-1,r=-1,q[25];

void ins(int n) {
	if(r == -1)
		f=r=0;
	else
		r++;
	q[r] = n;
}

int del() {
	if(f == -1)
		return -1;
	else {
		int t = q[f];
		if(f == r)
			f = r = -1;
		else
			f++;
		return t;
	}
}

void main() {
	int cost[100][100],nv,v,ne,visit[100],i,j,k,flag=1;
	printf("Enter the number of vertices : ");
	scanf("%d",&nv);

	for(i=1;i<=nv;i++) {
		for(j=1;j<=nv;j++) {
			cost[i][j] = 0;
		}
	}

	for(i=1;i<=nv;i++) {
		visit[i] = 0;
	}

	printf("Enter the number of edges : ");
	scanf("%d",&ne);
	printf("Enter the edges (i,j) : ");
	for(k=1;k<=ne;k++) {
		scanf("%d %d",&i,&j);
		cost[i][j] = 1;
	}
	printf("Enter the source vertex : ");
	scanf("%d",&v);
	printf("According to BFS, the visiting sequence of the vertices are : ");
	printf("%d ",v);

	visit[v] = 1;

	while(flag) {
		for(j=1;j<=nv;j++) {
			if(cost[v][j] != 0 && visit[j] == 0) {
				visit[j] = 1;
				printf("%d ",j);
				ins(j);
			}
		}

		v = del();
		if(v == -1)
			flag = 0;
	}

	getch();
	clrscr();
}