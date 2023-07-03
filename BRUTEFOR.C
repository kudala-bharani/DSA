#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void main() {
	int i,j,k,n,m,flag=0,fi,s;
	char text[40], pattern[30];
	clrscr();
	printf("Enter the text : ");
	gets(text);
	printf("Enter pattern : ");
	gets(pattern);
	n = strlen(text);
	m = strlen(pattern);

	for(i=0;i<=n-m;i++) {
		j = 0;k=0;
		while(j < m && pattern[j] == text[j+i]) {
			j++;k++;
			if(k==1) {
				fi=j+i;
			}

			if(j == m) {
				flag = 1;
				s=fi;
			} else {
				flag = 0;
			}
		}
	}
	if(flag == 1) {
		printf("Pattern found at position : %d\n",s);
	} else {
		printf("Pattern not found in text!!\n");
	}
	getch();

}
