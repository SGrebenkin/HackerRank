// https://www.hackerrank.com/challenges/botcleanlarge

#include<iostream>
#include<vector>
using namespace std;

void next_move(int posr, int posc, vector <string> board) {
    string& s = board[posr];
    
    if (board[posr][posc] == 'd')
    {
        cout << "CLEAN" << endl;
        return;
    }
    
    int ig = -1, jg = -1, curMin = -1;
    for (int i = 0; i < board.size(); ++i)
        for (int j = 0; j < board[i].size(); ++j)
            if (board[i][j] == 'd')
                if (curMin == -1 || curMin > (abs(i-posr) + abs(j-posc))) {
                    curMin = abs(i-posr) + abs(j-posc);
                    ig = i;
                    jg = j;
                }

    if (ig - posr > 0)
        cout << "DOWN" << endl;
    else if (ig - posr < 0)
        cout << "UP" << endl;
    else if (jg - posc > 0)
        cout << "RIGHT" << endl;
    else if (jg - posc < 0)
        cout << "LEFT" << endl;
}

int main(void) {
    int pos[2];
    vector <string> board;
    cin>>pos[0]>>pos[1];

    int height, width;
    cin >> height >> width;
    for(int i=0; i < height; i++) {
        string s;
        cin >> s;
        board.push_back(s);
    }

    next_move(pos[0], pos[1], board);

    return 0;
}

