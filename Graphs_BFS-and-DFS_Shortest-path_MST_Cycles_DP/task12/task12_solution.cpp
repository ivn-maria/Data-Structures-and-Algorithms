#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

unordered_map<char, int> words;

bool isPossible(const unordered_map<char, int> &tempWords) {
    for (const auto &element: tempWords) {
        if (!(element.second & 1)) {
            return false;
        }
    }

    return true;
}

int main() {
    string word;
    cin >> word;

    vector<int> subArrays(word.size() + 1, INT_MAX);
    subArrays[0] = 0;

    for (int i = 0; i < word.size() - 1; ++i) {
        if (subArrays[i] != INT_MAX) {
            words.clear();
            for (int j = i; j < word.size(); ++j) {
                words[word[j]]++;
                if (isPossible(words)) {
                    subArrays[j + 1] = min(subArrays[i] + 1, subArrays[j + 1]);
                }
            }
        }
    }

    cout << subArrays[word.size()];
}
