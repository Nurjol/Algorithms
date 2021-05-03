//
//  week_4.cpp
//  exercise
//
//  Created by Nurjol Badyelkhan on 2021/03/24.
//

#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;
void heapify(int a[],int h,int m){
    int v = a[h];
    int j;
    for ( j = 2*h;j<=m;j=j*2){
        if ((j<m)&&(a[j]<a[j+1])){
            j++;
        }
        if (v >= a[j]) break;
        
        else a[j/2] = a[j];
        
    }
    
            a[j/2] = v;
}
void HeapSort(int a[], int k){
    int n = k-1;
    for (int i = n/2; i >= 1; i--){
        heapify(a,i,n);
    
    }
    
    for (int i = n-1; i >= 1; i--){
        int temp = a[1];
        a[1] = a[i+1];
        a[i+1] = temp;
        heapify(a,1,i);
        
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
    int n = (sizeof(array)/sizeof(*array));
    HeapSort(array,n);
    cout<<"1st question answer: after heap sort : "<<endl;
    for(int i=0;i<10;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    
//
//    int array1[10] = {6,2,8,1,3,9,4,5,10,7} ;
//    QuickSort_with_partition(array1,0,9);
//    cout<<"2nd question answer: after sorting with quicksort with partitition : "<<endl;
//    for(int i=0;i<10;i++){
//        cout<<array1[i]<<" ";
//    }
//    cout<<endl;
    int a[100000],b[100000];
    srand(time(NULL));
    for(int i =0 ;i<100000;i++){
        a[i]= rand()%100000;
        b[i]= rand()%100000;
    }
//
//        clock_t start1,end1;
//        float res1;
//        start1= clock();
//    QuickSort(a, 0, 99999);
//        end1 = clock();
//        res1=(float)(end1-start1);
//        cout<<"quicksort time : " <<res1<<"ms"<<endl;
//
//
//
//
//
//        clock_t start,end;
//        float res;
//        start= clock();
//
//    QuickSort_with_partition(b, 0, 99999);
//
//        end = clock();
//        res=(float)(end-start);
//        cout<<"quicksort with partition time: "<<res<<"ms"<<endl;
//
    HeapSort(a, 99999);
    cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
//    checkSort(a, 100000);
//    checkSort(b, 100000);

        cout<<"Nurjol 12190180"<<endl;
    

    return 0;
}
