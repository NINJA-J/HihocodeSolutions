//
//  Solution2017ACM-I.cpp
//  HihocodeSolutions
//
//  Created by Jonathan闫 on 2017/9/23.
//  Copyright © 2017年 Jonathan闫. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <iostream>
#include "Solutions.hpp"

using namespace std;

#define N 200000

long num[N];
long maxList[N];
long minList[N];

void buildMap( int powLen ){
    int len = pow( 2, powLen );
    memcpy(maxList, num, len * sizeof(long));
    memcpy(minList, num, len * sizeof(long));
    
    for ( int i = 0; i < len; i+=2 ){
        maxList[i] = max( num[i], num[i+1] );// ? i : i+1;
        minList[i] = min( num[i], num[i+1] );// ? i : i+1;
    }
    
    for (long step = 4; step<=len*2; step<<=1) {
        for (int i = step/2-1; i < len; i+=step) {
            maxList[i] = max( maxList[i-step/4], maxList[i+step/4] );// ? i-step/4 : i+step/4;
            minList[i] = min( minList[i-step/4], minList[i+step/4] );// ? i-step/4 : i+step/4;
        }
    }
}

void dispInfos( long len ){
    for (int i = 0; i < len; i++) {
        cout<<i<<" ";
    }; cout<<endl;
    
    for (int i = 0; i < len; i++) {
        cout<<num[i]<<" ";
    }; cout<<endl;
    
    for (int i = 0; i < len; i++) {
        cout<<minList[i]<<" ";
    }; cout<<endl;
    
    for (int i = 0; i < len; i++) {
        cout<<maxList[i]<<" ";
    }; cout<<endl;
}

long getMax( long l, long r, long splict = -1 ){
//    cout<<"Get max in "<<l<<","<<r;
//    splict == -1 ? cout<<" origin" : cout<<" by "<<splict;
//    cout<<endl;
    
    long len = r - l + 1;
    long properLen = splict == -1 ? pow( 2, (int)log2(len) + 1 ) : splict;
    
    if( splict != -1 && r - l + 1 == splict * 2 && l % splict == 0 )
        return maxList[l+splict-1];
    if( l == r )
        return num[l];
    
    long pLenIndexL = ( l / properLen + 1 ) * properLen;
    long pLenIndexR = ( r / properLen + 1 ) * properLen;
    
    if(pLenIndexL==pLenIndexR)
        return getMax(l, r, properLen>>1);
    
    return max(getMax(l, pLenIndexL-1,properLen>>1), getMax(pLenIndexL, r, properLen>>1));
}

long getMin( long l, long r, long splict = -1 ){
    long properLen = splict == -1 ? pow( 2, (int)log2(r-l+1) + 1 ) : splict;
    
    if( splict != -1 && r-l+1 == splict * 2 && l % splict == 0 )
        return minList[l+splict-1];
    if( l == r )
        return num[l];
    
    long pLenIndexL = ( l / properLen + 1 ) * properLen;
    long pLenIndexR = ( r / properLen + 1 ) * properLen;
    
    if(pLenIndexL==pLenIndexR)
        return getMin(l, r, properLen>>1);
    
    return min(getMin(l, pLenIndexL-1,properLen>>1), getMin(pLenIndexL, r, properLen>>1));
}

void setVal( long p, long val, long powLen ){
    long indexG = (p>>1)<<1;
    long mIndex;
    long tempMax, tempMin;
    long stepBB;
    
    num[p] = val;
    maxList[indexG] = max(num[indexG], num[indexG+1]);
    minList[indexG] = min(num[indexG], num[indexG+1]);
    
    for ( int lStep = 2; lStep<=powLen; lStep++ ) {
        stepBB = 1<<lStep>>2;
        mIndex = ((p>>lStep)<<lStep) + (1<<lStep>>1) - 1;
        tempMax = max( maxList[mIndex-stepBB], maxList[mIndex+stepBB] );
        tempMin = min( minList[mIndex-stepBB], minList[mIndex+stepBB] );
        
        if( maxList[mIndex] == tempMax && minList[mIndex] == tempMin ) break;
        
        if( maxList[mIndex] != tempMax ) maxList[mIndex] =  tempMax;
        if( minList[mIndex] != tempMin ) minList[mIndex] =  tempMin;
    }
}

void solution2017ACM_I(){
    int n;
    fin>>n;
    while(n--){
        int k; fin>>k;
        long len = pow(2, k);
        for (long i = 0; i < k; i++)
            fin>>num[i];
        
        long q; fin>>q;
        for (long i = 0; i < q; i++) {
            int cmd;
            long a,b;
            if(cmd==1){
                long gMax, gMin;
                gMax = getMax(a, b);
                gMin = getMin(a, b);
                cout<<min(getMax(a, b)*getMin(a, b), min(pow(get, <#double#>), <#const _Tp &__b#>))
            }
        }
    }
    long nump[]={9,8,1,4,3,2,5,7};
    memcpy(num, nump, sizeof(nump));
    buildMap(3);
    cout<<"min[0,7] = "<<getMin(0, 7)<<endl;
    setVal(5, 0, 3);
    dispInfos(8);
    cout<<"min[0,7] = "<<getMin(0, 7)<<endl;
}
