/*
ID: bowen.y1
LANG: C++
TASK: combo
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int N;

int check_close(int a, int b){
      if (abs(a-b) <= 2){
            return 1;
      }
      if (abs(a-b) >= N-2){
            return 1;
      }
      return 0;
}


int is_valid(int n1, int n2, int n3, int c1, int c2, int c3){
      return check_close(n1, c1) && check_close(n2, c2) && check_close(n3, c3);
}

int main(){
      ifstream fin("combo.in");
      ofstream fout("combo.out");

      int f1, f2, f3, m1, m2, m3;
      int count = 0;

      fin >> N;
      fin >> f1 >> f2 >> f3;
      fin >> m1 >> m2 >> m3;

      for (int i=1; i<=N; i++){
            for (int j=1; j<=N; j++){
                  for (int k=1; k<=N; k++){
                        count += is_valid(i, j, k, f1, f2, f3) || is_valid(i, j, k, m1, m2, m3);
                  }
            }
      }

      fout << count << "\n";
      fin.close();
      fout.close();

      return 0;
}


