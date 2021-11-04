#include<stdio.h>
#define DIM 20
int main(){
    int arr[DIM], noDupl[DIM], i, j, dim2, isDuplicate;
    
    for(i=0; i<DIM; i++){
        scanf("%d", &arr[i]);
    }

    dim2=0;
    isDuplicate = 0;
    j=0;
    for(i=0; i<DIM; i++){
        isDuplicate=0;
        for(j=0; j<dim2 && !isDuplicate; j++){
            if(noDupl[j]==arr[i]){
                isDuplicate=1;
            }
        }
        if(!isDuplicate){
            noDupl[j]=arr[i];
            dim2++;
        }
    }
    printf("\nValori duplicati:");
    for(i=0; i<dim2; i++){
        printf("%d ", noDupl[i]);
    }
    printf("\n");
    return 0;

}
