//
//  week7.cpp
//  exercise
//
//  Created by Nurjol Badyelkhan on 2021/04/14.
//

#include <stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;
void InitNext(string p){
    int m = p.length();
    int next[m+1];
    next[0] = -1;
   
    
    for (int i = 0,j=-1;i<m; i++,j++){
//        if (p[i] == p[j]){
//            next[i] = next[j];}
//        else{
//            next[i] = j;}
        next[i] = j;
        
        while((j>=0)&&(p[i]!=p[j])){
            j = next[j];
        }

    }
    for (int i = 0;i<m;i++){
        cout<<next[i]<<" ";
    }
    cout<<endl;
}


int main(){
    string ex1 = "AABAA";
    cout<<"example1 : "<<endl;
    InitNext(ex1);
    string ex2 = "ABAABAB";
    cout<<"example2 : "<<endl;
    InitNext(ex2);
    string ex3 = "ABABABAC";
    cout<<"example1 : "<<endl;
    InitNext(ex3);
    
    cout<<"Nurjol 12190180"<<endl;
    return 0;
}
