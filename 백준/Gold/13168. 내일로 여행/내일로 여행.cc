#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
#define INF 100000001
unordered_map<string, int> maps;
vector<string> destination;
double ticket[101][101], noticket[101][101];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,r;
	cin >> n >> r;

	int idx = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (maps.find(s) == maps.end()) maps[s] = idx++;
	}
	
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		destination.push_back(s);
	}
	fill(&ticket[0][0], &ticket[100][101], INF);
	fill(&noticket[0][0], &noticket[100][101], INF);

	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		string trans_s, from_s, to_s;
		double cost;
		cin >> trans_s >> from_s >> to_s >> cost;
		
		int from = maps[from_s];
		int to = maps[to_s];

		if (trans_s == "ITX-Saemaeul" || trans_s == "ITX-Cheongchun" || trans_s == "Mugunghwa") {
			ticket[from][to] = 0;
			ticket[to][from] = 0;
		}
		else if (trans_s == "S-Train" || trans_s == "V-Train") {
			ticket[from][to] = min(ticket[from][to],cost / 2);
			ticket[to][from] = min(ticket[to][from],cost / 2);
		}
		else {
			ticket[from][to] = min(ticket[from][to], cost);
			ticket[to][from] = min(ticket[to][from], cost);
		}
		noticket[from][to] = min(noticket[from][to], cost);
		noticket[to][from] = min(noticket[to][from], cost);
	}



	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ticket[i][j] = min(ticket[i][j],ticket[i][k] + ticket[k][j]);
				noticket[i][j] = min(noticket[i][j], noticket[i][k] + noticket[k][j]);
			}
		}
	}

	double sum_ticket = 0;
	double sum_noticket = 0;
	for (int i = 0; i < destination.size()-1; i++) {
		int from = maps[destination[i]];
		int to = maps[destination[i + 1]];

		sum_ticket += ticket[from][to];
		sum_noticket += noticket[from][to];
	}

	if (sum_ticket + r < sum_noticket) cout << "Yes";
	else cout << "No";



}