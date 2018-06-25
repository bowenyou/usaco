/*
ID: bowen.y1
LANG: C++
TASK: wormhole
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

#define MAX_N 12

int n;
int x[MAX_N+1], y[MAX_N+1];
int partner[MAX_N+1];
int beside[MAX_N+1];

bool cycle(void){

    for (int i=1; i<=n; i++){
        int pos = i;
        for (int count=0; count<n; count++){
            pos = beside[partner[pos]];
        }
        if (pos != 0){
            return true;
        }
    }
    return false;
}

int ans(void){

    int i, total=0;
    for (i=1; i<=n; i++){
        if (partner[i] == 0){
            break;
        }
    }

    if (i > n){
        if (cycle()){
            return 1;
        }
        return 0;
    }

    for (int j=i+1; j<=n; j++){
        if (partner[j] == 0){
            partner[i] = j;
            partner[j] = i;
            total += ans();
            partner[i] = partner[j] = 0;
        }
    }

    return total;

}

int main(){
    ifstream fin("wormhole.in");
    ofstream fout("wormhole.out");

    fin >> n;
    for (int i=1; i<=n; i++){
          fin >> x[i] >> y[i];
    }
    
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (x[j] > x[i] && y[i] == y[j]){
                if (beside[i] == 0 || x[j] - x[i] < x[beside[i]] - x[i]){
                    beside[i] = j;
                }
            }
        }
    }

    fout << ans() << "\n";

    fin.close();
    fout.close();

    return 0;
}


