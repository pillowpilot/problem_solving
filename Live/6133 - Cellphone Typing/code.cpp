#include <bits/stdc++.h>

using namespace std;

#define MAXNODE 1000000
int gc[MAXNODE];
vector<int> g[MAXNODE];
int newNodeCounter;	

int addSon(int i, char c){
//printf("%d -> %c\n", i, c);
	g[i].push_back(newNodeCounter);
	gc[newNodeCounter] = c;
	newNodeCounter++;
	return newNodeCounter - 1;
}

void init(){
	newNodeCounter = 1;
	for(int i = 0; i < MAXNODE; i++){
		g[i].clear();
		gc[i]=0;
	}
}

int dfs(int node, int branch, bool afterBranch){
	if(g[node].size() == 0){
		return branch + (afterBranch ? -1 : 0);
	}else if(g[node].size() == 1){
		return dfs(g[node][0], branch, false);
	}else{
		int sum = 0;
		for(int i = 0; i < g[node].size(); i++){
			int u = g[node][i];
			sum += dfs(u, branch + 1, true);
		}
		return sum;
	}
}

void insert(char str[81], int node){
	char c = str[0];
	if(c == '\0'){
		addSon(node, c);
	}else{
		for(int i = 0; i < g[node].size(); i++){
			if(gc[g[node][i]] == c){
				insert(str + 1, g[node][i]);
				return;
			}
		}
		int newNode = addSon(node, c);
		insert(str + 1, newNode);
	}
}

int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		init();
		for(int i = 0; i < n; i++){
			char str[81];
			scanf("%s", str);
			insert(str, 0);
		}

		if(n != 0){
			addSon(0, 0);
			printf("%.2f\n", (dfs(0, 0, false) ) * 1.0 / n);
		}else{
			printf("1.00\n");
		}
	 
	}
	return 0;
}
