/*Numero di Amstrong*/

#include<stdio.h>
#include<math.h>
#define N 10
int isAmstrong(int);

int main(){
	
	int i, max, nums[N];
	max = 0;
	printf("Numeri di Amstrong: ");	
	for (i=0; i<N; i++){
		scanf("%d", &nums[i]);
		if (isAmstrong(nums[i]) && max<nums[i])
			max=nums[i];
	}
	if(!max){
		printf("Il massimo numero di Amstrong e': %d\n", max);
	}else{
		printf("Non esiste un numero di Amstrong\n");
	}
	
	return 0;
}

int isAmstrong(int num){
        int lastDigit, sum, originalNum, digits;

        sum = 0;
        originalNum = num;

        /*Troviamo il numero di cifre*/

        digits = 0;

        while(num>0){
                digits++;
                num=num/10;
        }


        /*Calcoliamo la potenza*/

        num=originalNum;

        while(num>0){
                lastDigit = num % 10;
                sum = sum + pow(lastDigit, digits);
                num /= 10;
        }

        return (sum==originalNum);
}
