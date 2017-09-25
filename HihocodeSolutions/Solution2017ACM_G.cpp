//
//  Solution2017ACM_G.cpp
//  HihocodeSolutions
//
//  Created by Jonathan闫 on 2017/9/23.
//  Copyright © 2017年 Jonathan闫. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Solutions.hpp"

using namespace std;

void solution2017ACM_G(){
    unsigned long long m,n;
    while(cin>>m>>n){
        if(m<n){
            unsigned long long temp = m;
            m = n;
            n = temp;
        }
        unsigned long long a = m - 1, b = n - 1, c = a%b;
        while(c){
            a=b;b=c;c=a%b;
        }
        cout<<(m-1)/b*(n-1)/b*(b-1) + (m-1)/b + (n-1)/b<<endl;
    }
}
