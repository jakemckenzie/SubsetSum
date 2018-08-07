#include <stdio.h>

int subsetSum(int *Z,int target,int size){
	int i, j;
	int sol[size][target];

	for(i = 0;i < size; i++) 
        sol[i][0] = 1;

	for(j = 1;j < target; j++){
		sol[0][j] = 0;

		for(i = 1;i < size; i++){
			int s = sol[i - 1][j];
			if(s == 0 && Z[i] <= j){
                s = sol[i - 1][j - Z[i]];
                
            }
			sol[i][j] = s;
		}
        
	}
	return sol[size - 1][target - 1];
}


int main(){
    // int A[] = {1,1};
    // printf("\nresult: %d\n\n",subsetSum(A,2,2));
	// int B[] = {1,2,3};
	// printf("\nresult: %d\n\n",subsetSum(B,3,3));
    int C[] = {10,6,1,1,1,3,7,3};
    printf("\nresult: %d\n\n",subsetSum(C,13,8));
	return 0;

}