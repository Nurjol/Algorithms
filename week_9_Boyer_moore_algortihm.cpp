//
//  week9.cpp
//  exercise
//
//  Created by Nurjol Badyelkhan on 2021/04/28.
//

#include <stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
#define NUM 26 // NUM as 26 for 26 alphabet
int skip[NUM]; // declaring skip array
int index(char p[],int i){ // index function
    if(i>=65) // in ASCII table Letters are bigger than 65
        return i-65;// if its letter we return subtrackting 65
    else
        return 0;//if its not letter we just return 0
    

}
void InitSkip(char *p){//declaration
    int i,M;
    M = strlen(p);//M is length of pattern
    for(i=0;i<NUM;i++){
        skip[i] = M;//initializing all of the letters as M
    }
    
    for(i=0;i<M;i++){
        skip[index(p,i)]=M-i-1; // actally making the skip array
    }
}
void MisChar(char p[],char t[]){ //main algorithm function
    int M = strlen(p);//initializing M as length of pattern
    int N = strlen(t);//initializing M as length of text

    int k,i=M-1,j; // initializing i as M-1
    //we need to find all pattern not one so i thought it will be better if we initialize i outside of loop
    bool match = true; // if its a match
    while(i<N){// we loop until i is bigger than N
    InitSkip(p);//initializing skip array of pattern
    for(j=M-1;j>=0;i--,j--){
        while(t[i]!=p[j]){// we search matching letter
            k = skip[index(t,i)];//
            if (M-j>k){
                i=i+M-j;
            }
            else{
                i=i+k;
            }
            if(i>=N)
                match = false;
            j=M-1;
        }
    }
        if(match){
            cout<<"Pattern match : "<< i+1<<endl;
            i = i + M+ 1;
        }
    }
    if(!match)
        cout<<"match no found"<<endl;
}
int main(){
    char t[] = "VISION QUESTION ONION CAPTION GRADUATION EDUCATION";
    char p[] = "ATION";
    MisChar(p, t);

    cout<<"Nurjol 12190180"<<endl;
    return 0;
}
