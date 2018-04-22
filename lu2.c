#include <stdlib.h>

int Doolittle_LU_Decomposition(double *A, int n)
{
   int i, j, k, p;
   double *p_k, *p_row, *p_col;

//         For each row and column, k = 0, ..., n-1,
//            find the upper triangular matrix elements for row k
//            and if the matrix is non-singular (nonzero diagonal element).
//            find the lower triangular matrix elements for column k. 
 
   for (k = 0, p_k = A; k < n; p_k += n, k++) {
      for (j = k; j < n; j++) {
         for (p = 0, p_col = A; p < k; p_col += n,  p++)
            *(p_k + j) -= *(p_k + p) * *(p_col + j);
      }
      if ( *(p_k + k) == 0.0 ) return -1;
      for (i = k+1, p_row = p_k + n; i < n; p_row += n, i++) {
         for (p = 0, p_col = A; p < k; p_col += n, p++)
            *(p_row + k) -= *(p_row + p) * *(p_col + k);
         *(p_row + k) /= *(p_k + k);
      }  
   }
   return 0;
}

double* createMatrix (double A[], int n) {
	int i, j;
	for(i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			A[i*n + j] = 1;
		}
	}
	return A;
}

int main(int argc, char** argv) {
    int n = 5;
    double A[25];
    createMatrix(A, n);
    Doolittle_LU_Decomposition(A, n);
    return (EXIT_SUCCESS);
}