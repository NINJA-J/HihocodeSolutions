//
//  Solution1331.cpp
//  HihocodeSolutions
//
//  Created by Jonathan闫 on 2017/9/22.
//  Copyright © 2017年 Jonathan闫. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

void solution1331(){
    int a0,a1,a2;
    long n;
    int bits = 0;
    long t;
    
    cin >> n;
    
    t = n;
    while( t ){
        bits++;
        t /= 2;
    }
    
    t = 2; bits--;
    if( n & 1 ){
        a0 = 1; a1 = a2 = 0;
    } else {
        a0 = 0; a1 = 1; a2 = 0;
    }
    
    while(bits--){
        int b0 = a0, b1 = a1, b2 = a2 + 1;
        if( n & t ){
            b0 = a0 + a1;
            b1 = a1 * ( a2 + 1 ) + a0 * a2;
            b2 = 0;
        }
        a0 = b0; a1 = b1; a2 = b2;
        t <<= 1;
    }
    cout<< a0 + a1 <<endl;
    
}
