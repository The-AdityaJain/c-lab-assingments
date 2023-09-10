#include<iostream>

using namespace std;

int i,j,k;
void accept(int a[],int n){
    cout<<"Enter elements :"<<endl;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
}
void display(int a[],int n){
    cout<<"Sorted array is : ";
    for(i=0;i<n;i++){
        cout<<a[i]<<"\t";
    }
}
/*  
    General Soch :
    a[i] ko a[i+1] se compare karna aur hogaya

    Problem of the soch:
    isse humare sirf pehle ke element sort honge baaki aage koi chote element hue to wo sort nahi honge kyunki
    ek hi loop hai
    
    Solution:
    "j"  ka loop use karo taaki jo element "i" wala loop select karke compare aa hai wo poore loop se
    compare ho aur sort kare. 

    Example:
    Koi loop i=0 se shuru hua to a[0] jo hai "j" ke loop ki madad se pooreaay ko tab tak compare karta rahega 
    jab tak "j" ki condition khatam nahi hoti updation ho ho kar aur fir iske baad i update hoge aur poora "j"
    wala loop firse chalega.

*/
void selection_sort(int a[],int n){
//Select minimums and swap
    for(i=0;i<n-2;i++){
        int minpos = i;
        for(j=i+1;j<n-1;j++){
            if(a[j]<a[minpos]){
                minpos=j;
            }
        }
        if(minpos!=i){
            int temp = a[i];
            a[i]=a[minpos];
            a[minpos]=temp;
        }
    }
}
void insertion_sort(int a[],int n){
//Take an element and place it in its correct order
    for(i=0;i<=n-1;i++){
        j=i;
        while(j>0 && a[j-1]>a[j]){
            int temp = a[j];
            a[j]=a[j-1];
            a[j-1]=temp;
        }
    }

}
void shell_sort(int a[],int n){
    int gap=n/2; 
    int swapped;
    do { 
        do { 
            swapped=0; 
            for(i = 0; i < n- gap ; i++){
                if(a[i] > a[ i + gap ]) { 
                    int temp = a[i+gap];
                    a[i+gap]=a[i];
                    a[i]=temp;
                    swapped=1; 
                } 
            } 
        }while(swapped == 1); 
    }while((gap=gap/2) >= 1);

}
void bucket_sort(int a[],int n){
    int max = a[0];
    for (i=1;i<n;i++) {
        if(a[i]>max) {
            max=a[i];
        }
    } 
    int bucket[max];
    for (i = 0; i <= max; i++){
        bucket[i]=0;
    }
    for(i = 0; i < n; i++){
        bucket[a[i]]++;
    }
    for (i = 0, j = 0; i < max; i++){
        for(;bucket[i]> 0;bucket [i]--){
            a[j] = i; 
            j++; 
        }
    }
}
void radix_sort(int a[],int n){
    
    int large, pass, div, bktno,count[10],bkt[20][20];
        large=a[0];
        for(i=0;i<n;i++){
            if(a[i]>large){
                large=a[i];
        }
    }
    pass=0;
    while(large>0){
        pass++;
        large=large/10;
    }
    div=1;
    for(i=1;i<=pass; i++){
        for(j=0;j<=9;j++){
            count[j]=0;
        }
        for(j=0;j<n;j++){
            bktno=(a[j]/div)%10;
            bkt[bktno][count[bktno]]=a[j]; 
            count[bktno]++; 
        }
        j=0;
        for(bktno=0;bktno<=9;bktno++){ 
            for(k=0;k<count[bktno];k++){
                a[j]=bkt[bktno][k];
                j++;
            }
        }
    div=div*10;
    }
}
void merge_sort(int a[],int n){



}
void bubble_sort(int a[],int n){
//Push the max element to last and min element to first by swapping adjacent elements
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i;j++){
          if(a[j]>a[j+1]){
           int temp = a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
            }
        }
    }
}
void quick_sort(int a[],int n){

}
int main(){

    int i,j,k,n,choice;

    cout<<"Enter the size ofaay: "<<endl;
    cin>>n;

    int a[n];
    accept(a,n);

    cout<<"Choose the sorting algorithm :\n\t1.Selection Sort\n\t2.Insertion Sort\n\t3.Shell Sort\n\t4.Bucket Sort\n\t5.Radix Sort\n\t6.Merge Sort\n\t7.Bubble Sort\n\t8.Quick Sort\n"<<endl;
    cin>>choice;
    switch(choice){
        case 1:
        selection_sort(a,n);
        display(a,n);
        break;
        case 2:
        insertion_sort(a,n);
        display(a,n);
        break;
        case 3:
        shell_sort(a,n);
        display(a,n);
        break;
        case 4:
        bucket_sort(a,n);
        display(a,n);
        break;
        case 5:
        radix_sort(a,n);
        display(a,n);
        break;
        case 6:
        merge_sort(a,n);
        display(a,n);
        break;
        case 7:
        bubble_sort(a,n);
        display(a,n);
        break;
        case 8:
        quick_sort(a,n);
        display(a,n);
        break;
    }
    return 0;
}
