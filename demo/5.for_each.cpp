#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
    
    vector vv{1,2,3,4,5,6};
    for_each(vv.begin(), vv.end(), [](auto item){
        printf("%d\n",item);
    });

    return 0;
}


/*
reference: https://zhuanlan.zhihu.com/p/597223487
*/