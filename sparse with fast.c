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

void compact_mat(int sparse[10][10],int comp[10][10],int m,int n){
    int i,j,t;
    
    comp[0][0]=m;
    comp[0][1]=n;
    t=1;
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
    for(i=0;i<t;i++){
        for(j=0;j<n;j++){
            printf("%d\t",comp[i][j]);
        }
        printf("\n");
    }
}
void transpose(int trans[10][10],int comp[10][10],int m,int n){
    int i,j,t,k;
    int q;
    m=comp[0][0];
	n=comp[0][1];
	t=comp[0][2];
	
	trans [0][0]=n;
	trans[0][1]=m;
	trans[0][2]=t;
	
	if(t<=0){
	return;
	}
	q=1;
	for(k=0;k<n;k++){
		for(int p=1;p<=t;p++){
			if(comp[p][1]==k){
				trans[q][0]=comp[p][1];
				trans[q][1]=comp[p][0];
				trans[q][2]=comp[p][2];
				q=q+1;
			}
		}
	}
	printf("Transpose Matrix : \n");
    	for(i=0;i<q;i++){
        	for(j=0;j<3;j++){
            	printf("%d\t",trans[i][j]);
        }
        printf("\n");
    }
	
}
void fast(int trans[10][10],int comp[10][10],int m,int n){
int i,j,k,t,p,q;
int S[10],T[10];
(m,n,t)==(comp[0][0],comp[0][1],comp[0][2]);
(trans[0][0],trans[0][1],trans[0][2])==(n,m,t);

	if(t<=0){
		return;
	}
	for(i=0;i<n;i++){
	S[i]=0;
	}
	for(i=1;i<t;i++){
	S[comp[i][1]]=S[comp[i][1]]+1;
	}
	T[0]=1;
	for(i=1;i<n;i++){
	T[i]=T[i-1]+S[i-1];
	}
	for(i=0;i<t;i++){
	j=comp[i][1];
	trans[q][0]=comp[p][1];
	trans[q][1]=comp[p][0];
	trans[q][2]=comp[p][2];
	T[j]=T[j]+1;
	}
	printf("Transpose Matrix : \n");
    	for(i=0;i<q;i++){
        	for(j=0;j<3;j++){
            	printf("%d\t",trans[i][j]);
        }
        printf("\n");
    }
	
}

int main(){
    int m,n;
    int i,j,k,t;
    int comp[10][10];
    int trans[10][10];
    printf("Enter no of rows : \n");
    scanf("%d",&m);
    printf("Enter no of column : \n");
    scanf("%d",&n);
    int sparse[m][10];
    accept(sparse,m,n);
    display(sparse,m,n);
    compact_mat(sparse,comp,m,n);
    //transpose(trans,comp,m,n);
    fast(trans,comp,m,n);
    
    
}
