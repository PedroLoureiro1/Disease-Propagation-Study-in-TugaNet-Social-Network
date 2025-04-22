#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

int maxSaltosTugaNet(int n, const vector<pair<int, int>>& relacoes) {
    unordered_map<int, vector<int>> graph;
    for (const auto& relacao : relacoes) {
        int x = relacao.first;
        int y = relacao.second;
        graph[x].push_back(y);
    }

    stack<int> dfsStack;
    unordered_set<int> visited;
    unordered_set<int> inStack;

    // Função DFS modificada para encontrar o caminho mais longo
    auto dfs = [&](int start) {
        dfsStack.push(start);
        visited.insert(start);
        inStack.insert(start);
        int maxComprimento = 0;

        while (!dfsStack.empty()) {
            int node = dfsStack.top();
            bool found = false;

            for (int neighbor : graph[node]) {
                if (visited.find(neighbor) == visited.end()) {
                    dfsStack.push(neighbor);
                    visited.insert(neighbor);
                    inStack.insert(neighbor);
                    found = true;
                    break;
                } else if (inStack.find(neighbor) != inStack.end()) {
                    // Encontrou um Strongly Connected Component (SCC)
                    return 1;  // Conta apenas 1 salto para SCC
                }
            }

            if (!found) {
                dfsStack.pop();
                inStack.erase(node);
                int comprimento = dfsStack.size();
                maxComprimento = max(maxComprimento, comprimento);
            }
        }

        return maxComprimento;
    };

    // Calcular o comprimento máximo do caminho para cada nó
    int maxComprimentoGlobal = 0;
    for (int node = 1; node <= n; ++node) {
        if (visited.find(node) == visited.end()) {
            maxComprimentoGlobal = max(maxComprimentoGlobal, dfs(node));
        }
    }

    return maxComprimentoGlobal;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> relacoes;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        relacoes.push_back({x, y});
    }

    int resultado = maxSaltosTugaNet(n, relacoes);
    cout << resultado << endl;

    return 0;
}
