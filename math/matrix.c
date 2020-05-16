/*Computations of matrices on a float field. 
All indices start from 0. 
Operations that are expected to return a matrix require a result matrix as an argument. 
Memory for such result matrices must be allocated before-hand.*/

#include<stdio.h>
#include<math.h>

//Maximum size of Matrices.
#define MAX 5

//Diplays a matrix M. M is an m x n matrix.
void display(float M[][MAX], int m, int n);

//Calculates A+B and stores in sum. A,B are m x n matrices.
void Sum(float A[][MAX], float B[][MAX], float sum[][MAX], int m, int n);

//Calculates cM and stores in result. M is an m x n matrix. 
void ScalarMultiply(float M[][MAX], float c, float result[][MAX], int m, int n);

//Stores Transpose of M in result. M is an m x n matrix.
void Trans(float M[][MAX], float result[][MAX], int m, int n);

//Calculates AB and stores in result. A is m x n and B is n x p.
void Product(float A[][MAX], float B[][MAX], float result[][MAX], int m, int n, int p);

//Finds the submatrix formed by removing ith row and jth column of M(m x n) and stores in result.
void SubMatrix(float M[][MAX], int i, int j, float result[][MAX], int m, int n);

//Returns |M|. M is a n x n matrix.
float Det(float M[][MAX], int n);

//Returns cofactor of M[i][j]. M is a n x n matrix.
float Cofactor(float M[][MAX], int i, int j, int n);

//Finds the adjugate of M(n x n) and stores in result.
void Adj(float M[][MAX], float result[][MAX], int n);

//Finds the inverse of M(n x n) and stores in result.
void Inv(float M[][MAX], float result[][MAX], int n);

int main(void)
{
    /*float A[2][MAX] = {{1,2},{3,4}}, B[2][MAX] = {{0,-6},{7,2}}, result[4][MAX];
    float M[4][MAX] = {{1,0,3,-1},{-1,0,0,1},{-2,1,-1,3},{-2,-1,2,0}};

    Inv(M,result,4);
    printf("%d\n", Det(M,4));
    display(result,4,4);*/
    return 0;
}

void display(float M[][MAX], int m, int n)
{
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            printf("%0.2f\t", M[i][j]);
        }
        printf("\n");
    }
}

void Sum(float A[][MAX], float B[][MAX], float sum[][MAX], int m, int n)
{
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            sum[i][j] = A[i][j]+B[i][j];
        }
    }
}

void ScalarMultiply(float M[][MAX], float c, float result[][MAX], int m, int n)
{
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            result[i][j]=c*M[i][j];
        }
    }
}

void Trans(float M[][MAX], float result[][MAX], int m, int n)
{
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            result[i][j]=M[j][i];
        }
    } 
}

void Product(float A[][MAX], float B[][MAX], float result[][MAX], int m, int n, int p)
{
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<p;++j)
        {
            result[i][j]=0;
            for(int k=0;k<n;++k)
            {
                result[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
}

void SubMatrix(float M[][MAX], int i, int j, float result[][MAX], int m, int n)
{
    int p=0,q=0;
    for(int k=0;k<m;++k)
    {
        if(k != i)
        {
            for(int l=0;l<n;++l)
            {
                if(l != j)
                {
                    result[p][q] = M[k][l];
                    ++q;
                }
            }
            ++p;
            q=0;
        }
    }
}

float Det(float M[][MAX], int n)
{
    float temp[n][MAX], D=0, c=1;
    if(n==1)
    {
        return M[0][0];
    }
    if(n==2)
    {
        return M[0][0]*M[1][1] - M[1][0]*M[0][1];
    }
    for(int j=0;j<n;++j)
    {
       SubMatrix(M, 0, j, temp, n, n);
       D += c * M[0][j] * Det(temp,n-1);
       c = -c; 
    }
    return D;
}

float Cofactor(float M[][MAX], int i, int j, int n)
{
    float temp[n][MAX];
    SubMatrix(M, i, j, temp, n, n);
    return (int)pow(-1,i+j) * Det(temp,n-1);
}

void Adj(float M[][MAX], float result[][MAX], int n)
{
   for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            result[i][j]=Cofactor(M,j,i,n);
        }
    } 
}

void Inv(float M[][MAX], float result[][MAX], int n)
{
    float temp[n][MAX], c = 1/Det(M,n);
    if(Det(M,n)==0)
    {
        printf("Matrix is not invertible.\n");
        return;
    }
    Adj(M,temp,n);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            result[i][j]=temp[i][j];
        }
    }
    ScalarMultiply(temp,c,result,n,n);
}