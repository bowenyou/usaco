/*
ID: bowen.y1
LANG: C++
TASK: castle
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

const int MAX_N = 50;

bool walls[MAX_N][MAX_N][4];
int visited[MAX_N][MAX_N];
int largest_room[MAX_N * MAX_N] = {0};

int room = 0;
int room_size = 0;
int max_size = 0;

void dfs(int n, int m) {
  if (visited[n][m] != -1) return;

  visited[n][m] = room;
  room_size++;
  if (walls[n][m][0]) dfs(n, m - 1);
  if (walls[n][m][1]) dfs(n - 1, m);
  if (walls[n][m][2]) dfs(n, m + 1);
  if (walls[n][m][3]) dfs(n + 1, m);

}

int main(){
  ifstream fin("castle.in");
  ofstream fout("castle.out");

  int M, N;

  fin >> M >> N;

  int wall;

  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      fin >> wall;

      if (!(wall & 1)) walls[i][j][0] = 1;
      if (!(wall & 2)) walls[i][j][1] = 1;
      if (!(wall & 4)) walls[i][j][2] = 1;
      if (!(wall & 8)) walls[i][j][3] = 1;

      visited[i][j] = -1;
    }
  }

  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      dfs(i, j);
      if (room_size > 0) {
        largest_room[room] = room_size;
        room++;
        if (room_size > max_size) max_size = room_size;
        room_size = 0;
      }
    }
  }

  fout << room << "\n";
  fout << max_size << "\n";

  int wall_row = -1;
  int wall_col = -1;
  char direction = ' ';

  int temp;

  for (int j=0; j<M; j++) {
    for (int i=N-1; i>=0; i--) {
      if (i > 0 && !walls[i][j][1] && visited[i][j] != visited[i-1][j]) {
        temp = largest_room[visited[i][j]] + largest_room[visited[i-1][j]];
        if (temp > max_size) {
          max_size = temp;
          wall_row = i;
          wall_col = j;
          direction = 'N';
        }
      }

      if ((j < M - 1) && (!(walls[i][j][2])) && (visited[i][j] != visited[i][j+1])) {
        temp = largest_room[visited[i][j]] + largest_room[visited[i][j+1]];
        if (temp > max_size) {
          max_size = temp;
          wall_row = i;
          wall_col = j;
          direction = 'E';
        }
      }
    }
  }

  fout << max_size << "\n" << wall_row + 1 << " " << wall_col + 1 << " " << direction << "\n";

  fin.close();
  fout.close();

  return 0;
}
