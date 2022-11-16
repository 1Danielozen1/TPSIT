#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	int a[3] = {1,2,3};
int i;
int *p;
p = a;
	for(i = 0; i < 3; i++){ //modo da terza
	printf("%d",a[i]);
	}
	printf("\n");
	for(i = 0; i < 3; i++){ //modo da fine terza
	printf("%d",*(a+i));
	}
	printf("\n");
	for(p = a; p<a+3;p++){ //modo da quarta
	printf("%d",*p);
	}
	printf("\n");
	return 0;
}
