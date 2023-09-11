#include<stdio.h>

void accept(int sparse[10][10],int m,int n){
    int i,j,k;
    printf("Enter the elements : \n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++)
            scanf("%d",&sparse[i][j]);
    }
}
void display(int sparse[10][10],int m,int n){
    int i,j,k;
    printf("Sparse : \n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d\t",sparse[i][j]);
        }
        printf("\n");
    }

}

void compact_mat(int sparse[10][10],int m,int n){
    int i,j,k;
    int comp[10][10];
    comp[0][0]=m;
    comp[0][1]=n;
    int t=1;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(sparse[i][j]!=0){
                comp[t][0]=i;
                comp[t][1]=j;
                comp[t][2]=sparse[i][j];
                t++;
            }
        }
    }
    comp[0][2]=t-1;
    printf("Compact Matrix : \n");
    for(i=0;i<m+1;i++){
        for(j=0;j<n;j++){
            printf("%d\t",comp[i][j]);
        }
        printf("\n");
    }
    int q=1;
    m=sparse[0][0];
	n=sparse[0][1];
	t=sparse[0][2];
	
	n=comp[0][0];
	m=comp[0][1];
	t=comp[0][2];
	
	if(t<=0){
	int q = 1;
	}
	for(n=0;n<n-1;n++){
		for(int p=1;p<t;p++){
			if(sparse[p][1]=n){
				comp[q][0]=sparse[p][1];
				comp[q][1]=sparse[p][0];
				comp[q][2]=sparse[p][2];
				q=q+1;
			}
		}
	}
	printf("Transpose Matrix : \n");
    	for(i=0;i<m+1;i++){
        	for(j=0;j<n;j++){
            	printf("%d\t",comp[i][j]);
        }
        printf("\n");
    }
	
}

int main(){
    int m,n;
    int i,j,k;
    printf("Enter no of rows : \n");
    scanf("%d",&m);
    printf("Enter no of column : \n");
    scanf("%d",&n);
    int sparse[m][10];
    accept(sparse,m,n);
    display(sparse,m,n);
    compact_mat(sparse,m,n);
    
    
}
