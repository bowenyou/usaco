/*
ID: bowen.y1
LANG: C++
TASK: ariprog
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

bool arr[125002] = {false};
int N, M;

int main(){
    ifstream fin("ariprog.in");
    ofstream fout("ariprog.out");

    fin >> N >> M;

    for (int i=0; i<=M; i++){
        for (int j=i; j<=M; j++){
            arr[i*i + j*j] = true;
        }
    }

    bool exists = false;

    for (int d=1; d<=M*M*2/(N-1); d++){
        for (int a=0; a<=M*M; a++){
            bool prog = true;
            for (int n=0; n<N; n++){
                if (arr[a + n*d] == false){
                    prog = false;
                    break;
                }
            }
            if (prog == true){
                exists = true;
                fout << a << " " << d << "\n";
            }
        }
    }

    if (exists == false){
        fout << "NONE\n";
    }

    fin.close();
    fout.close();

    return 0;
}