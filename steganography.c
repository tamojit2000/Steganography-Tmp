#include<stdio.h>
#include "converter.c"



int main(int argc, char *argv[]){
	
	
	//char opt[100],int_ppm[100],int_payload[100],out_ppm[100],out_payload[100];
	
	if (argc==5){
		//opt=argv[1];
		//int_ppm=argv[2];
		//int_payload=argv[3];
		//out_ppm=argv[4];
		
		if (check_unique3(argv[2],argv[3],argv[4])==0){
			printf("Give unique names.");exit(0);
		}
		
		encrypt(argv[3],argv[2],argv[4]);
		
		printf("Successful");
		
	}else if (argc==4){
		//opt=argv[1];
		//int_ppm=argv[2];
		//out_payload=argv[3]; 
		
		if (check_unique2(argv[2],argv[3])==0){
			printf("Give unique names.");exit(0);	
		}
		
		decrypt(argv[2],argv[3]);
		
		printf("Successful");
		
	}else{
		printf("Check command and try and again.");
	}
	
	//steganography encode input.ppm payload.ext output.ppm
	
	
	
	//steganography decode input.ppm output.ext
	
	
	return 0;	
}
