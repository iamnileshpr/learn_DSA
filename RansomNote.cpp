#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:

    bool fun(unordered_map<char,int> have, unordered_map<char,int> need){
        for(auto i : need){
            char c = i.first;
            int fneed = i.second;
            int fhave = have[c];

            if(fhave < fneed){
                return false;
            }
        }
        return true;
    }

    bool canConstruct(string ransomNote, string magazine) {

        unordered_map<char,int> have;
        unordered_map<char,int> need;

        int n = ransomNote.size();
        int m = magazine.size();

        for(int i = 0; i < n; i++){
            need[ransomNote[i]]++;
        }

        for(int i = 0; i < m; i++){
            have[magazine[i]]++;
        }

        return fun(have, need);
    }
};

int main(){
    Solution obj;

    string ransomNote = "aa";
    string magazine = "aab";

    if(obj.canConstruct(ransomNote, magazine)){
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}