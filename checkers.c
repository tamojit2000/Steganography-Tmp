#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int check_unique3(char s1[],char s2[], char s3[]){
	return strcmp(s1,s2) && strcmp(s2,s3) && strcmp(s1,s3);  
}

int check_unique2(char s1[],char s2[]){
	return strcmp(s1,s2);
}


int check_payload_size(int count,int X, int Y){
	return count<X*Y-16;
}



