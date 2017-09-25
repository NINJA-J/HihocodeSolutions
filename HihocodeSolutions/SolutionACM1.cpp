//
//  SolutionACM1.cpp
//  HihocodeSolutions
//
//  Created by Jonathan闫 on 2017/9/23.
//  Copyright © 2017年 Jonathan闫. All rights reserved.
//

#include "Solutions.hpp"
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

void solution2017ACM_A(){
    vector<int> p;
    vector<int> q;
    unordered_map<int, int> minMap;
    
    int n,m,qn;
    
    cin>>n>>m;
    for (int i = 0; i < n; i++) {
        int t;
        cin>>t;
        p.push_back(t);
    }
    
    cin>>qn;
    for (int i = 0; i < qn; i++) {
        int t;
        cin>>t;
        q.push_back(t);
    }
    
    for (int i = q.size()-1; i >= 0; i--) {
        p.erase(p.begin()+q[i]);
    }
    
//    for (int i = 1; i < p.size(); i*=2) {
//        for (int j = 0; j + i < p.size(); j++) {
//            if(i==1)
//        }
//    }
}
