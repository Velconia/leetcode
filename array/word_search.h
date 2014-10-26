#include <vector>
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;
using std::string;

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (board.empty() || board[0].empty()) return false;
        if (word.empty()) return true;
        
        // Use visited to record which places have been visted.
        vector<vector<bool> > visited;
        
        // Initialization of visited array.
        for (vector<vector<char> >::iterator iter = board.begin(); iter != board.end(); ++iter) {
            vector<bool> tmp;
            for (vector<char>::iterator row_iter = iter->begin(); row_iter != iter->end(); ++row_iter) {
                tmp.push_back(false);
            }
            visited.push_back(tmp);
        }

        // Go through all nodes
        for (vector<vector<char> >::iterator iter = board.begin(); iter != board.end(); ++iter) {
            for (vector<char>::iterator row_iter = iter->begin(); row_iter != iter->end(); ++row_iter) {
                // Take x as the height of this pos
                // y as the width of this pos
                int x = iter - board.begin();
                int y = row_iter - iter->begin();
                if (find(x, y, word, word.cbegin(), board, visited)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
private:
    bool find(int x, int y, const string& word, const string::const_iterator word_iter, 
              vector<vector<char> >& board, vector<vector<bool> >& visited) {
        // Return when we reach the last pos of the word.
        if (word_iter == word.cend()) return true;
        
        // Set this place to be visited
        if (board[x][y] == *word_iter) {
            visited[x][y] = true;
            // Avoid we meet the last one
            if (word_iter + 1 == word.cend()) return true;
        } else {
            return false;
        }

        if (x != 0) {
            if (!visited[x - 1][y]) {
                if (find(x - 1, y, word, word_iter + 1, board, visited)) {
                    return true;
                }
            }
        }
        
        if (y != 0) {
            if (!visited[x][y - 1]) {
                if (find(x, y - 1, word, word_iter + 1, board, visited)) {
                    return true;
                }
            }
        }
        
        if (x != board.size() - 1) {
            if (!visited[x + 1][y]) {
                if (find(x + 1, y, word, word_iter + 1, board, visited)) {
                    return true;
                }
            }
        }
        
        if (y != board[0].size() - 1) {
            if (!visited[x][y + 1]) {
                if (find(x, y + 1, word, word_iter + 1, board, visited)) {
                    return true;
                }
            }
        }
        
        visited[x][y] = false;
        return false;
    }
};