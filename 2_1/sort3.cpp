/*
ID: bowen.y1
LANG: C++
TASK: sort3
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

#define MAX_N 1000
#define MAX_KEY 3

int N;
int arr[MAX_N];

int main(){
    ifstream fin("sort3.in");
    ofstream fout("sort3.out");

    int key[MAX_KEY + 1] = {0};
    int s12 = 0;
    int s13 = 0;
    int s21 = 0;
    int s23 = 0;
    int s31 = 0;
    int s32 = 0;

    fin >> N;
    for (int i=0; i<N; i++){
      fin >> arr[i];
      key[arr[i]]++;
    }

    for (int i=0; i<key[1]; i++){
      if (arr[i] == 3) s13++;
      if (arr[i] == 2) s12++;
    }

    for (int i=key[1]; i<key[1]+key[2]; i++){
      if (arr[i] == 3) s23++;
      if (arr[i] == 1) s21++;
    }

    for (int i=key[1]+key[2]; i<key[1]+key[2]+key[3]; i++){
      if (arr[i] == 1) s31++;
      if (arr[i] == 2) s32++;
    }

    fout << min(s12, s21) + min(s13, s31) + min(s23, s32) + 2 * (max(s12, s21) - min(s12, s21)) << endl;

    fin.close();
    fout.close();
    return 0;
}
