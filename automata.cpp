#include <bits/stdc++.h>

using namespace std;

class Automata{
public:
    explicit Automata(char symb) {
        avt.push_back({});
        avt[0].push_back({symb, 1});
        avt.push_back({});
        term.push_back(1);
    }
    vector<vector<pair<char, int> > > avt;  // автомат
    vector<int> term; // терминальные вершины
};

void star(Automata &A) {
    bool isRoot = false;  // встречался ли корень в терминальных вершинах
    for(int i = 0;i < (int)A.term.size();++i) {
        if(A.term[i] == 0) isRoot = true;
        A.avt[A.term[i]].push_back({' ', 0});  // добавляем ребро от каждой терминальной вершины в корень
    }
    if(!isRoot) {
        A.term.push_back(0);
    }
}
Automata point(Automata &first, Automata &second) {
    Automata result = first;
    result.term.clear();
    int size = 0;
    for(int i = 0;i < (int)first.term.size();++i) {
        size = (int)result.avt.size();
        --size;
        for(int j = 0;j < (int)second.avt[0].size();++j) {
            result.avt[first.term[i]].push_back({second.avt[0][j].first, second.avt[0][j].second + size}); // подвешиваем к каждой вершине
            // детей корня второго
        }
        for(int j = 1;j < (int)second.avt.size();++j) {  // добавляем все остальные вершины в автомат, при этом у каждой обновляем индекс
            vector<pair<char, int> > cur;
            for(int q = 0;q < (int)second.avt[j].size();++q) {
                cur.emplace_back(second.avt[j][q].first, second.avt[j][q].second + size);
            }
            result.avt.push_back(cur);
        }
        for(int j = 0;j < (int)second.term.size();++j) {  // обновляем терминальные вершины
            result.term.push_back(second.term[j] + size);
        }
    }
    return result;
}
Automata pluss(Automata &first, Automata &second) {
    auto result = first;
    int size = (int)first.avt.size();
    --size;
    for(int i = 0;i < (int)second.avt[0].size();++i) {  // к корню первого автомата подвешиваем детей корня второго автомата
        result.avt[0].push_back({second.avt[0][i].first, second.avt[0][i].second + size});
    }
    for(int i = 1;i < (int)second.avt.size();++i) { // добавляем все остальные вершины, при этом у каждой обновляем индекс
        vector<pair<char, int> > cur;
        for(int j = 0;j < (int)second.avt[i].size();++j) {
            cur.emplace_back(second.avt[i][j].first, second.avt[i][j].second + size);
        }
        result.avt.push_back(cur);
    }
    for(int i = 0;i < (int)second.term.size();++i) { // добавляем терминальные вершины второго автомата
        result.term.push_back(second.term[i] + size);
    }
    return result;
}
int main() {
    string expression;
    cin >> expression;
    stack <Automata> S;  // стек разбора
    for(int i = 0;i < expression.length();++i) {
        if(expression[i] == '+') {
            auto second = S.top();
            S.pop();
            auto first = S.top();
            S.pop();
            auto result = pluss(first, second);
            S.push(result);
        }
        else if(expression[i] == '.') {
            auto second = S.top();
            S.pop();
            auto first = S.top();
            S.pop();
            auto result = point(first, second);
            S.push(result);
        }
        else if(expression[i] == '*') {
            auto first = S.top();
            S.pop();
            star(first);
            S.push(first);
        }
        else {
            Automata next(expression[i]);
            S.push(next);
        }
    }
    auto res = S.top();
    for(int i = 0;i < (int)res.avt.size();++i) {
        for(int j = 0;j < (int)res.avt[i].size();++j) {
            cout << res.avt[i][j].first << ' ' << i << ' ' << res.avt[i][j].second << endl;
        }
    }
    cout << "Terminal\n";
    for(int i = 0;i < (int)res.term.size();++i) {
        cout << res.term[i] << ' ';
    }
    return 0;
}