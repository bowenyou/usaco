/*
ID: bowen.y1
LANG: C++
TASK: sprime
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>

using namespace std;

ifstream fin("sprime.in");
ofstream fout("sprime.out");

int N;

int isprime(long n){

    if (n == 2){
        return 1;
    }
    if (n%2 == 0){
        return 0;
    }

    for (long i=3; i*i<=n; i+=2){
        if (n%i == 0){
            return 0;
        }
    }
    return 1;
}

void sprime(long n, int d){

    if (d == 0){
        fout << n << "\n";
        return;
    }

    n *= 10;
    if (isprime(n+1)){
        sprime(n+1, d-1);
    }
    if (isprime(n+3)){
        sprime(n+3, d-1);
    }
    if (isprime(n+7)){
        sprime(n+7, d-1);
    }
    if (isprime(n+9)){
        sprime(n+9, d-1);
    }

}

int main(){
    fin >> N;

    sprime(2, N-1);
    sprime(3, N-1);
    sprime(5, N-1);
    sprime(7, N-1);

    fin.close();
    fout.close();

    return 0;
}