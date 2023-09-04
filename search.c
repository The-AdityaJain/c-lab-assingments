#include<stdio.h>

int i,j,k,n,key,mid,low,high;

struct student{

    char name[10];
    int div;
    int rno;
    float cgpa;

};

void accept(struct student s[10],int n){

    for(i=0;i<n;i++){

        printf("Enter name :");
        scanf("%s",&s[i].name);
        printf("Enter division :");
        scanf("%d",&s[i].div);
        printf("Enter roll no. :");
        scanf("%d",&s[i].rno);
        printf("Enter cgpa :");
        scanf("%f",&s[i].cgpa);
    }
}

void display(struct student s[10],int n){

    for(i=0;i<n;i++){

        printf("%s\n",s[i].name);
        printf("%d\n",s[i].div);
        printf("%d\n",s[i].rno);
        printf("%f\n",s[i].cgpa);
    }
}

void linear_search(struct student s[10],int n){

    printf("Enter a roll number to search\n");
    scanf("%d", &key);
    for (i = 0; i < n; i++){
        if (s[i].rno == key){
            printf("Information of %d is :\n %s\n %d\n %d\n %f", key, s[i].name,s[i].div,s[i].rno,s[i].cgpa);
            break;

         }
        else{
            printf("%d isn't present in the record.\n", key);
        }

    }   

}

int binary_search(struct student s[10],int low,int high,int n,int key){

    if(low<=high){
        n = (low+high)/2;
        if(s[n].rno == key){
            printf("Information of %d is :\n %s\n %d\n %d\n %f", key, s[n].name,s[n].div,s[n].rno,s[n].cgpa);

        }
        else if(key <= s[n].rno){
            return binary_search(s,low,n+1,n,key);

        }
        else{
            return binary_search(s,n+1,high,n,key);
        }
    }
}

int main(){

    int c;
    struct student s[10];
    printf("Enter the no of student : ");
    scanf("%d",&n);
    accept(s,n);
    display(s,n);
    printf("Select search/sort :\n\t1.Linear Search\n\t2.Binary Search\n\t3.Exit\n");
    printf("Choice : ");
    scanf("%d",&c);
    switch(c){
        case 1:
            linear_search(s,n);
            break;
        case 2:
            printf("Enter a roll number to search\n");
            scanf("%d", &key);
            binary_search(s,0,n-1,n,key);
            break;
        case 3:
            break;
    }
    return 0;
}
