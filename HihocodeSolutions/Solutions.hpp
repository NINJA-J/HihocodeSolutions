//
//  Solution1331.h
//  HihocodeSolutions
//
//  Created by Jonathan闫 on 2017/9/22.
//  Copyright © 2017年 Jonathan闫. All rights reserved.
//

#ifndef Solution1331_h
#define Solution1331_h

#include <fstream>

using namespace std;

extern ifstream fin;

//2017 ACM/ICPC A题
void solution2017ACM_A();

//2017 ACM/ICPC G题-Bounce AC
void solution2017ACM_G();


//2017 ACM/ICPC I题-Minimum
void buildMap( int powLen );
long getMax( long l, long r, long splict = -1 );
long getMin( long l, long r, long splict = -1 );
void setVal( long p, long val );
void dispInfos( long len );
void solution2017ACM_I();

//#1015 : KMP算法
int indexOfMult( string &str, string &pattern );
void solution1015();


void solution1331();

#endif /* Solution1331_h */
