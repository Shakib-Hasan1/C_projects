#include <stdio.h>
int main(void){
	double num,d;
	int limit,i=0,j=0;
	printf("Welcome to the crzy calculator\n\n");
	printf("Enter two numbers and limit: ");
	scanf("%lf %lf %d",&num,&d,&limit);
	int numi=num*100000, di=d*100000;
	if(numi>di && numi%di ==0){ 
		printf("The reault is: %d\n[No precision digits available.]\n",numi/di);
		}
	else if(numi<di){
			printf("The result is: 0.");
	while(j<limit){
		if(numi%di == 0){
			printf("\n[No more precision digits available.]\n");
			break;
			}
			numi*=10;
			printf("%d",numi/di);	
			numi=numi%di;
			j++;
		}
	}
	else{
		printf("The result is: %d.",numi/di);
	while(i<limit){
		if(numi%di == 0){
			printf("\n[No more precision digits available.]\n");
			break;
			}
			numi=numi%di;
			numi*=10;
			printf("%d",numi/di);	
		i++;
		}
	}
	printf("\012");
	return 0;
}
