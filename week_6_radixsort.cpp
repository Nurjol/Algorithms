//
//  week6.cpp
//  exercise
//
//  Created by Nurjol Badyelkhan on 2021/04/07.
//
//assistant email: mskim@inha.edu
//prof email : wichoi@inha.ac.kr
#include <stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;
void rxSort(int *data,int size,int p,int k){
    int *counts, *temp;
    int index,pval,i,j,n;
    if((counts = (int*)malloc(k* sizeof(int)))==NULL) return;
    if((temp = (int*)malloc(size* sizeof(int)))==NULL) return;
    for(n = 0;n<p;n++){
        for(i = 0;i<k;i++){
            counts[i] = 0;
        }
        pval = (int)pow((double)k,(double)n);
        for(j=0;j<size;j++){
            index = (int)(data[j]/pval)%k;
    
            counts[index] = counts[index] + 1;
        }
        for(i = 1;i<k;i++){
            counts[i] = counts[i]+counts[i-1];
            cout<<counts[i]<<endl;
        }
        for(j = size-1;j>=0;j--){
            index = (int)(data[j]/pval)%k;
            temp[counts[index]-1] = data[j];
            counts[index] = counts[index]-1;
        }
        memcpy(data,temp,size * sizeof(int));
    }
    
}


int main(){
    int Array[8] = {170,45,75,90,2,24,802,66};
    int *p= Array;
    cout<<"before sorting: "<<endl;
    for(int i=0;i<8;i++){
        cout<<Array[i]<<" ";
    }
    cout<<endl;
    rxSort(p,8,3,10);
    cout<<"after sorting"<<endl;
    for(int i=0;i<8;i++){
        cout<<Array[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}
