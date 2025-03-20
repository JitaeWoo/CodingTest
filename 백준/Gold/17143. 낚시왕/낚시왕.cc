#include <iostream>
#include <vector>

class shark {
  int speed;
  int direction;
  int dr[4] = {-1, 1, 0, 0};
  int dc[4] = {0, 0, 1, -1};
  int change[4] = {1, 0, 3, 2};

public:
  int r;
  int c;
  int size;
  shark() {
    std::cin >> r >> c >> speed >> direction >> size;
    r--;
    c--;
    direction--;
  }

  void direction_change() { direction = change[direction]; }

  void move(int R, int C) {
    int temp = 0;
    if (direction < 2) {
      temp = speed % (R * 2 - 2);
    } else {
      temp = speed % (C * 2 - 2);
    }
    for (int i = 0; i < temp; i++) {
      int cr = r + dr[direction];
      int cc = c + dc[direction];
      if (cr < 0 || cr >= R || cc < 0 || cc >= C) {
        direction_change();
        i--;
        continue;
      }
      r = cr;
      c = cc;
    }
  }
};

class fishing_game {
  int R;
  int C;
  std::vector<std::vector<std::vector<shark>>> board;
  std::vector<shark> sharks;
  int result;

public:
  fishing_game() {
    int M = 0;
    std::cin >> R >> C >> M;
    board.resize(R);
    for (int i = 0; i < R; i++) {
      board[i].resize(C);
    }

    for (int i = 0; i < M; i++) {
      shark sha = shark();
      board[sha.r][sha.c].push_back(sha);
    }
    result = 0;
  }

  int play() {
    for (int i = 0; i < C; i++) {
      // 물고기 한 마리 잡기
      for (int j = 0; j < R; j++) {
        if (!board[j][i].empty()) {
          result += board[j][i][0].size;
          board[j][i].clear();
          break;
        }
      }

      // 물고기 이동
      for (int j = 0; j < R; j++) {
        for (int k = 0; k < C; k++) {
          if (!board[j][k].empty()) {
            board[j][k][0].move(R, C);
            sharks.push_back(board[j][k][0]);
            board[j][k].clear();
          }
        }
      }
      for (shark sha : sharks) {
        board[sha.r][sha.c].push_back(sha);
      }
      sharks.clear();

      // 서로 잡아먹기
      for (int j = 0; j < R; j++) {
        for (int k = 0; k < C; k++) {
          if (board[j][k].size() > 1) {
            shark max_sha = board[j][k][0];
            for (int l = 1; l < board[j][k].size(); l++) {
              if (max_sha.size < board[j][k][l].size) {
                max_sha = board[j][k][l];
              }
            }
            board[j][k].clear();
            board[j][k].push_back(max_sha);
          }
        }
      }
    }

    return result;
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  fishing_game fish = fishing_game();

  std::cout << fish.play() << "\n";

  return 0;
}
