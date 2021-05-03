//
//  week_3.cpp
//  exercise
//
//  Created by Nurjol Badyelkhan on 2021/03/24.
//

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
void swap(int a[],int l,int r){
    int temp = a[l];
    a[l] = a[r];
    a[r] = temp;
    
}
int partition (int a[], int l, int r){
    int i,pindex;
    int pivot;
    pivot = a[r];
    pindex = l;
    for(i = l; i<r;i++){
        if(a[i]<=pivot){
            swap(a,i,pindex);
            pindex++;
        }
    }
    swap(a,r,pindex);
    return pindex;
}
void QuickSort(int a[],int l,int r){
    int i,j,m,v;
    v = r;
    if(r-l > 1){
        m = (l+r) / 2;
        if(a[l] > a[m]) swap(a,l,m);
        if(a[l] > a[r]) swap(a,l,r);
        if(a[m] > a[r]) swap(a,m,r);
        swap(a,m,r-1);
        v = a[r-1];i = l; j=r-1;
        for(;;){
            while(a[++i] < v);
            while(a[--j] > v);
            if(i >= j)break;
            swap(a,i,j);
        }
        swap(a,i,r-1);
        QuickSort(a,l,i-1);
        QuickSort(a, i+1, r);
    }
    else if(a[l] > a[r]){
        swap(a,l,r);
    }
}
void QuickSort_with_partition(int a[],int l,int r){
    int m;
    if(l<r){
        m = partition(a, l, r);
        QuickSort_with_partition(a, l, (m-1));
        QuickSort_with_partition(a, (m+1), r);
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
   QuickSort(array,0, 9);
    cout<<"1st question answer: after sorting with quicksort : "<<endl;
    for(int i=0;i<10;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    

    int array1[10] = {6,2,8,1,3,9,4,5,10,7} ;
    QuickSort_with_partition(array1,0,9);
    cout<<"2nd question answer: after sorting with quicksort with partitition : "<<endl;
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
    QuickSort(a, 0, 99999);
        end1 = clock();
        res1=(float)(end1-start1);
        cout<<"quicksort time : " <<res1<<"ms"<<endl;





        clock_t start,end;
        float res;
        start= clock();

    QuickSort_with_partition(b, 0, 99999);

        end = clock();
        res=(float)(end-start);
        cout<<"quicksort with partition time: "<<res<<"ms"<<endl;

    checkSort(a, 100000);
    checkSort(b, 100000);

        cout<<"Nurjol 12190180"<<endl;
    

    return 0;
}
