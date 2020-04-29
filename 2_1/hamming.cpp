/*
ID: bowen.y1
LANG: C++
TASK: hamming
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <bitset>

using namespace std;

int hamming_distance(int x, int y) {

  bitset<8> b (x^y);
  return b.count();

}

int main(){
    ifstream fin("hamming.in");
    ofstream fout("hamming.out");

    int N, B, D;

    fin >> N >> B >> D;

    vector<int> ans;
    ans.push_back(0);

    for (int i=0; i!=1<<B; i++) {
        bool y=true;
        for (int x:ans){
          y = y && (hamming_distance(i,x)>=D);
        }

        if(y) ans.push_back(i);
        
        if(ans.size() == N) break;
    }

    for (int i=0; i<ans.size(); i++) {
      if ((i >= 1) && (i % 10 == 0)) {
        fout << "\n";
      } else if (i != 0) {
        fout << " ";
      }
      fout << ans[i];
    }

    fout << "\n";

    fin.close();
    fout.close();

    return 0;
}
