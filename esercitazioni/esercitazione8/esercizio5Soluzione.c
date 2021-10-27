#include<math.h>

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