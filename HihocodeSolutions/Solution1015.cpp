//
//  Solution1015.cpp
//  HihocodeSolutions
//
//  Created by Jonathan闫 on 2017/9/23.
//  Copyright © 2017年 Jonathan闫. All rights reserved.
//

/*
 时间限制:1000ms
 单点时限:1000ms
 内存限制:256MB
 描述
 小Hi和小Ho是一对好朋友，出生在信息化社会的他们对编程产生了莫大的兴趣，他们约定好互相帮助，在编程的学习道路上一同前进。
 
 这一天，他们遇到了一只河蟹，于是河蟹就向小Hi和小Ho提出了那个经典的问题：“小Hi和小Ho，你们能不能够判断一段文字（原串）里面是不是存在那么一些……特殊……的文字（模式串）？”
 
 小Hi和小Ho仔细思考了一下，觉得只能想到很简单的做法，但是又觉得既然河蟹先生这么说了，就肯定不会这么容易的让他们回答了，于是他们只能说道：“抱歉，河蟹先生，我们只能想到时间复杂度为（文本长度 * 特殊文字总长度）的方法，即对于每个模式串分开判断，然后依次枚举起始位置并检查是否能够匹配，但是这不是您想要的方法是吧？”
 
 河蟹点了点头，说道：”看来你们的水平还有待提高，这样吧，如果我说只有一个特殊文字，你能不能做到呢？“
 
 小Ho这时候还有点晕晕乎乎的，但是小Hi很快开口道：”我知道！这就是一个很经典的模式匹配问题！可以使用KMP算法进行求解！“
 
 河蟹满意的点了点头，对小Hi说道：”既然你知道就好办了，你去把小Ho教会，下周我有重要的任务交给你们！“
 
 ”保证完成任务！”小Hi点头道。
 
 提示一：KMP的思路
 
 提示二：NEXT数组的使用
 
 提示三：如何求解NEXT数组
 
 输入
 第一行一个整数N，表示测试数据组数。
 
 接下来的N*2行，每两行表示一个测试数据。在每一个测试数据中，第一行为模式串，由不超过10^4个大写字母组成，第二行为原串，由不超过10^6个大写字母组成。
 
 其中N<=20
 
 输出
 对于每一个测试数据，按照它们在输入中出现的顺序输出一行Ans，表示模式串在原串中出现的次数。
 */

#include <stdio.h>
#include "Solutions.hpp"
#include <fstream>
#include <iostream>
#include <unordered_map>

using namespace std;

ifstream fin("data.txt");

int indexOfMult( string &str, string &pattern ){
    unordered_map<int, int> l;
    int i = 0, p = 0, cnt = 0;
    int pLen = pattern.length();
    
    for ( i = 0; i < pLen+1; i++)
        l.insert( pair<int, int>(i,0) );
    l[0] = -1;
    
    for ( i = 0, p = 0; i < pLen; i++ ) {
        if( pattern[i] != pattern[p] )
            p = 0;
        else if( i > 0 )
            p++;
        else
            p = 0;
        
        l[i+1] = p;
    }
    
    for ( i = 0, p = 0;; ) {
        
//        cout<<str<<endl;
//        for (int k = 0; k < i; k++)
//            cout<<" ";
//        cout<<pattern<<endl;
//        for (int k = 0; k < i + p; k++)
//            cout<<" ";
//        cout<<'^'<<endl<<endl;
        
        if( str[i+p] != pattern[p] ){
            i += p - l[p];
            p = l[p] > 0 ? l[p] : 0;
        } else
            p++;
        
        if ( p == pLen ){
            i += pLen - l[pLen];
            p = l[pLen];
            cnt++;
        }
        
        if( i + p >= str.length() )
            break;
    }
    return cnt;
}

void solution1015(){
    int n;
    fin>>n;//cout<<n<<endl;
    while (n--) {
        string a,b;
        fin>>a>>b;//cout<<a<<endl<<b<<endl;
        cout<<indexOfMult(b, a)<<endl;
    }
}
