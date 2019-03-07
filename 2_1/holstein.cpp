/*
ID: bowen.y1
LANG: C++
TASK: holstein
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

#define MAX_V 25
#define MAX_G 15

int V;
int cow[MAX_V];
int G;
int feeds[MAX_G][MAX_V];

int best;
int best_combo[MAX_G];

int curr[MAX_G];

void solve(int count, int idx){

    int i;
    for (i=0; i<V; i++){
        if (cow[i] > 0){
          break;
        }
    }

    if (i >= V){
      best = count;
      for (i=0; i<best; i++){
        best_combo[i] = curr[i];
      }
      return;
    }

    while (count + 1 < best && idx < G){
      for (i=0; i<V; i++){
        cow[i] -= feeds[idx][i];
      }

      curr[count] = idx;

      solve(count + 1, idx + 1);

      for (i=0; i<V; i++){
        cow[i] += feeds[idx][i];
      }
      idx++;
    }
    return;
}

int main(){
    ifstream fin("holstein.in");
    ofstream fout("holstein.out");

    fin >> V;
    for (int i=0; i<V; i++){
      fin >> cow[i];
    }

    fin >> G;

    best = G + 1;

    for (int i=0; i<G; i++){
      for (int j=0; j<V; j++){
        fin >> feeds[i][j];
      }
    }

    solve(0, 0);

    fout << best;
    for (int i=0; i<best; i++){
        fout << " " << best_combo[i] + 1;
    }

    fout << endl;

    fin.close();
    fout.close();

    return 0;
}
