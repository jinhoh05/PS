#include <iostream>

using namespace std;

int N, A[200];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)cin >> A[i];

	for (int i = N - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			int M = (A[j] > A[j + 1]) ? A[j] : A[j + 1];
			int m = (A[j] > A[j + 1]) ? A[j + 1] : A[j];

			A[j] = m; A[j + 1] = M;
		}
		for (int k = 0; k < N; k++) {
			cout << A[k] << " ";
		}cout << "\n";
	}
}