/*
ID: bowen.y1
LANG: C++
TASK: numtri
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

#define MAX_R 1000
#define MAX(a,b) (a > b) ? a : b 

int tri[MAX_R + 3][MAX_R + 3];
int n;

int main(){
    ifstream fin("numtri.in");
    ofstream fout("numtri.out");

    fin >> n;
    for (int i=0; i<n; i++){
        for (int j=0; j<=i; j++){
            fin >> tri[i][j];
        }
    }

    for (int i=n-1; i>=1; i--){
        for (int j=0; j<i; j++){
            tri[i-1][j] += MAX(tri[i][j], tri[i][j+1]);
        }
    }
    fout << tri[0][0] << "\n";

    fin.close();
    fout.close();

    return 0;
}