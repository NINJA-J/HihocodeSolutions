//
//  Solution1331.cpp
//  HihocodeSolutions
//
//  Created by Jonathan闫 on 2017/9/22.
//  Copyright © 2017年 Jonathan闫. All rights reserved.
//

/*
 时间限制:10000ms
 单点时限:1000ms
 内存限制:256MB
 描述
 我们都知道二进制数的每一位可以是0或1。有一天小Hi突发奇想：如果允许使用数字2会发生什么事情？小Hi称其为扩展二进制数，例如(21)ii = 2 * 21 + 1 = 5, (112)ii = 1 * 22 + 1 * 21 + 2 = 8。
 
 很快小Hi意识到在扩展二进制中，每个数的表示方法不是唯一的。例如8还可以有(1000)ii, (200)ii, (120)ii 三种表示方法。
 
 对于一个给定的十进制数 N ，小Hi希望知道它的扩展二进制表示有几种方法？
 
 输入
 一个十进制整数 N。(0 ≤ N ≤ 1000000000)
 
 输出
 N的扩展二进制表示数目。

 a[0] 无前导零情况个数
 a[1] 有前导零情况个数
 a[2] 前导零个数
 
 if(p[i+1]=1)
 a[0][i+1] = a[0][i] + a[1][i]
 a[1][i+1] = a[0][i] * a[2][i] + a[1][i] * ( a[2][i+1] + 1)
 a[2][i]   = 0
 if(p[i+1]=0)
 a[0][i+1] = a[0][i]
 a[1][i+1] = a[1][i]
 a[2][i]   = a[2][i] + 1
 
 if(p[0]=1)
 a[0][0] = 1
 a[1][0] = 0
 a[2][0] = 0
 if(p[0]=0)
 a[0][0] = 0
 a[1][0] = 1
 a[2][0] = 0
 */

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include "Solutions.hpp"

using namespace std;

ifstream fin("data.txt");

void solution1331(){
    int a0,a1,a2;
    long n;
    int bits = 0;
    long t;
    
    fin >> n;
    
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
