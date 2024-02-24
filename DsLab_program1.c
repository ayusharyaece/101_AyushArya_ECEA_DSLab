#include<stdio.h>

void LinearSearch(int a, int arr[]);
void Inserte(int a, int arr[]);
void Delete(int a, int arr[]);
void Reverse(int a, int arr[]);
void Update(int a, int arr[]);


int main(){
    int a;
    printf("enter size of array:");
    scanf("%d", &a);

    int arr[a];

    printf("enter element of array:");

    for(int i=0; i<a; i++){
        scanf("%d", &arr[i]);
    }

    printf("array is:\t");

    for(int i=0; i<a; i++){
        printf("%d\t", arr[i]);
    }

    printf("\n");



    int number;
    printf("enter 1 for linear search\n");
    printf("enter 2 for inserting an element in array\n");
    printf("enter 3 for deleting an element from an array\n");
    printf("enter 4 for reversing array\n");
    printf("enter 5 for updating array\n");
    
    scanf("%d", &number);

    switch(number){
        case 1 : 
            LinearSearch(a , arr);
            break;
        case 2 :
            Inserte(a, arr);
            break;
        case 3 :
            Delete(a, arr);
            break;
        case 4 :
            Reverse(a, arr);
            break;
        case 5 : 
            Update(a, arr);
            break;  
        }
    }



void LinearSearch(int a, int arr[a]){
    int b;
    printf("enter element you want to seach:");
    scanf("%d", &b);
    for(int i=0; i<a; i++){
        int x = arr[i];
        if(x==b){
            printf("element is found at %d index\n", i);
        }      
    }
}

void Inserte(int a, int arr[a]){
    int b;
    printf("enter position where you want to store number:");
    scanf("%d", &b);
    a=a+1;
    for(int i=a; i>=b; i--){
        arr[i]=arr[i-1];
    }

    int c;

    printf("enter number you want to store:");
    scanf("%d", &c);

    arr[b-1]=c;

    printf("new array is:");

    for(int i=0; i<a; i++){
        printf("%d\t", arr[i]);
    }


}

void Delete(int a, int arr[a]){
    int del;
    printf("enter position of element you want to delete:");
    scanf("%d", &del);

    for(int i=del; i<a; i++){
        arr[i-1]=arr[i];
    }

    a=a-1;

    printf("new array is:\t");

    for(int i=0; i<a; i++){
        printf("%d\t", arr[i]);
    }

}

void Reverse(int a, int arr[a]){
    
    int first=0;
    int last=a-1;
    while(first<last){
        int temp;
        temp=arr[first];
        arr[first]=arr[last];
        arr[last]=temp;
        first++;
        last--;
    }

    printf("new array is:\t");

    for(int i=0; i<a; i++){
        printf("%d\t", arr[i]);
    }

}

void Update(int a, int arr[]){
    for(int i=0; i<a; i++){
        if(arr[i]%2==0){
            arr[i]=arr[i]+5;
        }
        else{
            arr[i]=arr[i]*2;
        }
    }

    printf("new array is:\t");

    for(int i=0; i<a; i++){
        printf("%d\t", arr[i]);
    }
}