#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "functions.c"
#include "ppm_functions.c" 
#include "checkers.c"



void encrypt(char FILENAME[],char IMAGE[], char OUT[]){
	char buffer[20000]; // Buffer to store data
  	FILE * stream;
  	stream = fopen(FILENAME, "r");
  	int count = fread(&buffer, sizeof(char), 20000, stream);
  	fclose(stream);
  	// Printing data to check validity
  	//printf("Data read from file: %s \n", buffer);
  	//printf("Elements read: %d", count);
  	//printf("\n");
  	
  	int i=count;
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
    /*
    for(in = BIT-1; in >= 0; in--){
    	printf("%c",str[in]);
	}
	*/
	
	PPMImage *image;
    image = readPPM(IMAGE);
	
	
	int index=0;
	int tmp_B,tmp_G;
	int end_index=image->x * image->y;
	
	if (check_payload_size(count,image->x,image->y)==0){
		printf("Payload size exceeded than ppm size");
		exit(0);
	}

	for(in = BIT-1; in >= 0; in--){
		tmp_B=image->data[index].blue;
    	tmp_G=image->data[index].green;
    	
    	//printf("\nSTR %c G %d B %d",str[in],tmp_G,tmp_B);
    	
		if (str[in]=='0'){
			make_same(&tmp_G,&tmp_B);
		}else if (str[in]=='1'){
			make_consecutive(&tmp_G,&tmp_B);
		}
		image->data[index].blue=tmp_B;
		image->data[index].green=tmp_G;
		//printf("\nSTR %c G %d B %d",str[in],tmp_G,tmp_B);
		//printf("Done");
    	index++;
	}
	
	//printf("Enter");
	//printf("\n\n");
	//printf("%s",buffer);
	
	char tmp;
	for(in=0;in<count;in++){
		tmp_B=image->data[index].blue;
    	tmp_G=image->data[index].green;
		tmp=buffer[in];
		
		//printf("\nSTR %c G %d B %d",tmp,tmp_G,tmp_B);
		
		if (tmp=='0'){
			make_same(&tmp_G,&tmp_B);
		}else if (tmp=='1'){
			make_consecutive(&tmp_G,&tmp_B);
		}
		image->data[index].blue=tmp_B;
		image->data[index].green=tmp_G;
		
		//printf("\nSTR %c G %d B %d",tmp,tmp_G,tmp_B);
		//printf("Done");
		
    	index++;
	}
	
	writePPM(OUT,image);
				
	
}

void decrypt(char IMAGE[],char OUTPUT[]){
	
	PPMImage *image;
    image = readPPM(IMAGE);
    
    char buffer1[16]; 
    char buffer2[20000];
    
    int index=0;
	int tmp_B,tmp_G,XOR;
	int end_index=image->x * image->y;
	int size=0;
	
	
	FILE *fileAddress;
	fileAddress = fopen(OUTPUT, "w");
	
	while(index<16){
		tmp_B=image->data[index].blue;
    	tmp_G=image->data[index].green;
		XOR=tmp_G ^ tmp_B;
		//pf(XOR);
		size=size+ XOR*pow(2,16-1-index);
		index++;
	}
	
	
	
	//printf("Size: %d",size);
	
	if (check_payload_size(size,image->x,image->y)==0){
		printf("Invalid encrypted PPM. Size gt than payload");
		exit(0);
	}
	
	int i;
	for(i=0;i<size;i++){
		tmp_B=image->data[index].blue;
    	tmp_G=image->data[index].green;
		XOR=tmp_G ^ tmp_B;
		//pf(XOR);

   		if (fileAddress != NULL) {
			
	   		fputc (XOR+'0', fileAddress);
		}
				
		index++;
	}
	
	
	
	fclose(fileAddress);	
	
	
	
}



