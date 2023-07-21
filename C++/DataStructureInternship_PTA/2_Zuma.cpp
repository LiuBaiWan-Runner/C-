/*
 * @file    :2_Zuma.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-07-21
 * @brief   :Zuma
 *          :线性结构
 *          :
 */
#include <iostream>
#include<cstring>
using namespace std;

const int N = 1e4+7;
char s[N], tmp[N];

void insert(int k, char A);
bool remove();

int main()
{
    int n, k;
    char A;
    cin >> s;
    cin >> n;
    for(int i = 1; i <=n; i++){
        cin >> k >> A;
        insert(k, A); //在k处插入A
        while(remove()); //连续三个以上相同字母进行合并删除
        if(strlen(s) == 0){
            cout << "-" << endl;
        }
        else{
            cout << s << endl;
        }
    }
    return 0;
}

//在指定位置k插入指定字母A
void insert(int k, char A){
    strcpy(tmp, s + k); //strcpy(dest,src)将src所指字符串赋给tmp
    s[k] = A;
    strcpy(s + k + 1, tmp);
}

//将相邻的连续三个或四个字母不断消除
bool remove(){
    int len = strlen(s);
    int i = 0;
    while(i < len){
        char t = s[i];
        int start = i;
        int count = 0;
        while(i < len && t == s[i]){ //从头向后查找连续相同字母个数
            count++;
            i++;
        }
        if(count >= 3){ //不相同后根据个数决定是否删除
            strcpy(tmp, s+i); //覆盖删除指定位置字符串
            strcpy(s + start, tmp);
            return true; //通过循环可实现所有结果都删除
        }
    }
    return false;
}