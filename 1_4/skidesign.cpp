/*
ID: bowen.y1
LANG: C++
TASK: skidesign
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <math.h>

using namespace std;

int main(){
    
    ifstream fin("skidesign.in");
    ofstream fout("skidesign.out");

    int N, adj;
    fin >> N;

    int h[N];
    int cost = INT_MAX;

    for (int i=0; i<N; i++){
        fin >> h[i];
    }

    for (int i=0; i<84; i++){
        adj = 0;
        for (int j=0; j<N; j++){
            if (h[j] < i){
                adj += pow(i-h[j], 2);
            } else if (h[j] > i+17){
                adj += pow(h[j]-(i+17), 2);
            }
        }
        if (cost > adj){
            cost = adj;
        }
    }

    fout << cost << "\n";

    fin.close();
    fout.close();

    return 0;
}