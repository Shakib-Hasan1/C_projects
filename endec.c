#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int multi(int n){
	int i,count=0;
	for(i=1;i<=n;i++){
		if(n%i==0)count++;
	}
	if(count<2){
		n=n+1;
		int i,count=0;
			for(i=1;i<=n;i++){
				if(n%i==0)count++;
		}
	}
	return count;
}

int bin(int n){
int rem=0,bin=0;
while(n){
	rem=n%2;
	n=n/2;
	bin=bin+rem;
}
	return bin;
}

int main(void){
char pass[10],inputFile[50], outputFile[50],ch;
int numasci,opt;
FILE *fl1, *fl2;

printf("***** Welcome to cryptography ***** \n\n");
printf("1. Encrypt File\n2. Decrypt File\n");
printf("Enter your choise: ");
scanf("%d",&opt);
if(opt == 1){
	printf("Enter the name of the file with extention:");
	scanf("%s",inputFile);
	printf("Enter the password:");
	scanf("%s",pass);
	printf("Enter the name of the outputfile: ");
	scanf("%s",outputFile);
//password
	int sum=0,i;
	for(i=0;i<strlen(pass)-1;i++){
		sum+=pass[i];
	}
	int num = bin(sum)+multi(sum);
		
	fl1 = fopen(inputFile,"r");
	if(fl1 == NULL){
		printf("No such file exits\n");
		exit(0);
	}
	else{
		
		fl2 = fopen(outputFile,"w");
		ch = fgetc(fl1);
		int j=0;
		while(ch!=EOF){
			if(j==num-1)j=0;
			numasci = (int)ch;
			numasci = numasci+j;
			fprintf(fl2,"%c",numasci);
			ch = fgetc(fl1);
			j++;
		}
		fprintf(fl2,"\n");
		fclose(fl2);
	}
	fclose(fl1);
	printf("File is encrypted as %s\n",outputFile);
}
else if(opt == 2){
	printf("Enter the name of the file with extention:");
	scanf("%s",inputFile);
	printf("Enter the password:");
	scanf("%s",pass);
	printf("Enter the name of the outputfile: ");
	scanf("%s",outputFile);
	//password
				int sum=0,i;
				for(i=0;i<strlen(pass)-1;i++){
					sum+=pass[i];
				}
				int num = bin(sum)+multi(sum);
					
				fl1 = fopen(inputFile,"r");
				if(fl1 == NULL){
					printf("No such file exits\n");
					exit(0);
				}
				else{
					
					fl2 = fopen(outputFile,"w");
					ch = fgetc(fl1);
					int j=0;
					while(ch!=EOF){
						if(j==num-1)j=0;
						numasci = (int)ch;
						numasci = numasci-j;
						fprintf(fl2,"%c",numasci);
						ch = fgetc(fl1);
						j++;
						}
		fprintf(fl2,"\n");
		fclose(fl2);
	}
	fclose(fl1);
	printf("File is decrypted as %s\n",outputFile);
}
else printf("Wrong chhoise.(:\n");
	return 0;
}
