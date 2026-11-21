#include <bits/stdc++.h>

using namespace std;

constexpr int group_count = 6;
constexpr int student_count = 12;
constexpr int max_ttl = group_count - 1;

array<bool, group_count> group_visit;
int transfer_time[student_count][student_count];
int best_acc_time = 0x7fffffff;

void dfs(int student_id, int ttl, int acc_time) {
  if (ttl == 0)
  {
    if (acc_time < best_acc_time)
      best_acc_time = acc_time;
    return;
  }

  for (int i = 0; i < group_count; i++)
  {
    if (group_visit[i])
      continue;

    const int next_student_id = i * 2;
    const int next_acc_time_1 = acc_time + transfer_time[student_id][next_student_id];        // 다른 그룹으로의 전달
    const int next_acc_time_2 = acc_time + transfer_time[student_id][next_student_id + 1];
    const int between_transfer_time = transfer_time[next_student_id][next_student_id + 1];    // 같은 그룹내에서 전달
    const int next_ttl = ttl - 1;

    group_visit[i] = true;
    dfs(next_student_id + 1, next_ttl, next_acc_time_1 + between_transfer_time);
    dfs(next_student_id, next_ttl, next_acc_time_2 + between_transfer_time);
    group_visit[i] = false;
  }
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for (int i = 0; i < student_count; i++) {
    for (int j = 0; j < student_count; j++) {
      cin >> transfer_time[i][j];
    }
  }

  for (int i = 0; i < group_count; i++) {
    const int group_id = i;
    const int student_id = i * 2;
    const int between_transfer_time = transfer_time[student_id][student_id + 1];    // 같은 그룹내 전달

    group_visit[group_id] = true;
    dfs(student_id, max_ttl, between_transfer_time);
    dfs(student_id + 1, max_ttl, between_transfer_time);
    group_visit[group_id] = false;
  }

  cout << best_acc_time << "\n";

  return 0;
}