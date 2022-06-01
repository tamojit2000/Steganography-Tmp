#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include<math.h>

#define pf(x) printf("\n%d\n",x)
#define br printf("\n");

int get_file_content_and_size(char name[]) {
  char buffer[20000]; // Buffer to store data
  FILE * stream;
  stream = fopen(name, "r");
  int count = fread(&buffer, sizeof(char), 20000, stream);
  fclose(stream);
  // Printing data to check validity
  //printf("Data read from file: %s \n", buffer);
  //printf("Elements read: %d", count);
  //printf("\n");
  int x=0;
  for(x=0;x<count;x++){
  	//printf("%c\n",buffer[x]);
  }
  return 0;
}




void binaer(int i) {
	const int BIT = 16;
    char str[BIT];
    char ans[BIT];
    int j = 0,x,in;
    if(0 <= i && i <= 65535) {
        for(j = 0; j < BIT + 1; j++) {
            if (i % 2 == 0) {
                str[j] = '0';
            } else {
                str[j] = '1';
            }
            i = i / 2;
        }
    }
    
    
    for(in = BIT-1; in >= 0; in--){
    	//printf("%c",str[in]);
	}
	
	
}

void make_same(int *g, int *b){
	*b=*g;
}

void make_consecutive(int *g,int *b){
	if (*g==255){
		*b=254;
		return;
	}
	if (*b==255){
		*g=254;
		return;
	}
	if (*b==0){
		*g=1;
		return;
	}
	if (*g==0){
		*b=1;
		return;
	}
	if (*g<*b){
		if (*g%2==0){
			*b=*g+1;
		}else{
			*g=*g-1;
			*b=*g+1;
		}
	}else if(*g>*b){
		if (*b%2==0){
			*g=*b+1;
		}else{
			*b=*b-1;
			*g=*b+1;
		}
	}else{
		*b=*g+1;
	}
}


int bin_to_dec(char binaryNumber[]){
	
    int bin, dec = 0,i;
     
    bin = atoi(binaryNumber);
 
    for(i = 0; bin; i++, bin /= 10)
        if (bin % 10)
            dec += pow(2, i);
 
    return dec;
}

/*
void main() {

    int value;
    //printf("Enter\n");
    //scanf("%d", &value);
    //binaer(value);
    int G=31,B=0;
    //make_consecutive(&G,&B);
    //pf(G);pf(B);
    
    get_file_content_and_size("file.ext");


    
}
*/


