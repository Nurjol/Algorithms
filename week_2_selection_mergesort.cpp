//
//  ALGORITH.cpp
//  exercise
//
//  Created by Nurjol Badyelkhan on 2021/03/10.
//

#include <iostream>
#include<ctime>
using namespace std;
void selectionSort(int a[],int n){
    for(int i=0;i<n;i++){
        int idx = i;
        for(int j=i+1;j<n;j++){
            if (a[idx] > a[j]){
                idx = j;
            }
        }
        int temp = a[idx];
        a[idx]=a[i];
        a[i]= temp;
    }
    
}
void merge(int a[], int l ,int m,int r)
{
    int i = l;
    int j = m+1;
    int k = l;
    int temp[100000];
    while(i<=m && j<=r)
    {
        if(a[i]<=a[j]){
            temp[k] = a[i];
            i++;
            k++;
        }
        else{
            temp[k] = a[j];
            j++;
            k++;
        }
    }
        while(i<=m)
        {
            temp[k] = a[i];
            i++;
            k++;
        }
        while(j<=r)
        {
            temp[k] = a[j];
            j++;
            k++;
        }
    
    for(int w= l; w<=r; w++)
    {
        a[w] = temp[w];
    }
}
void mergeSort(int a[], int l ,int r){
    if (r>l){
        int m = (r+l)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }
}
 



void checkSort(int a[],int n){
  bool sorted;
    sorted = true;
    for(int i = 1 ; i<n;i++){
        if (a[i-1]>a[i]){
            sorted = false;
            cout<<i-1<<" "<<i<<endl;
        }
        if(!sorted){
            break;
        }
    }
    if (sorted){
        cout<<"sorting complete"<<endl;
        
    }
    else {
        cout<<"Error during sorting..."<<endl;
    }
}
int main(){
  
    int array[10] = {6,2,8,1,3,9,4,5,10,7} ;
    selectionSort(array, 10);
    cout<<"1st question answer: after sorting with selection sort : "<<endl;
    for(int i=0;i<10;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    
    
    int array1[10] = {6,2,8,1,3,9,4,5,10,7} ;
    mergeSort(array1,0,9);
    cout<<"2nd question answer: after sorting with merge sort : "<<endl;
    for(int i=0;i<10;i++){
        cout<<array1[i]<<" ";
    }
    cout<<endl;
    int a[100000],b[100000];
    srand(time(NULL));
    for(int i =0 ;i<100000;i++){
        a[i]= rand()%100000;
        b[i]= rand()%100000;
    }

        clock_t start1,end1;
        float res1;
        start1= clock();
    selectionSort(a, 100000);
        end1 = clock();
        res1=(float)(end1-start1);
        cout<<"selection sort time : " <<res1<<"ms"<<endl;





        clock_t start,end;
        float res;
        start= clock();

    mergeSort(b, 0, 99999);

        end = clock();
        res=(float)(end-start);
        cout<<"merge sort time: "<<res<<"ms"<<endl;

    checkSort(a, 100000);
    checkSort(b, 100000);

        cout<<"Nurjol 12190180"<<endl;
    

    return 0;
}
