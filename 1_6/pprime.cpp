/*
ID: bowen.y1
LANG: C++
TASK: pprime
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>

using namespace std;

ifstream fin("pprime.in");
ofstream fout("pprime.out");

long a, b;

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

void gen(int i){
    char buf[30];
    char *p, *q;
    long n;

    sprintf(buf, "%d", i);

    p = buf+strlen(buf);
    q = p-1;

    while (q > buf){
        *p++ = *--q;
    }
    *p = '\0';

    n = atol(buf);
    if(a <= n && n <= b && isprime(n)){
        fout << n << "\n";
    }
	    
}

void generate(void){
    for (int i=1; i<=9; i++){
        gen(i);
    }
    if (a<=11 && 11<=b){
        fout << "11\n";
    }
    for (int i=10; i<=9999; i++){
        gen(i);
    }

}

int main(){
    fin >> a >> b;

    generate();

    fin.close();
    fout.close();

    return 0;
}