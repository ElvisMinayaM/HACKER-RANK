#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'shortestSubstring' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING givenString as parameter.
 */

int shortestSubstring(string givenString){
    string res;
    int n=givenString.length();
    int dist_count=0;
    unordered_map<int,int> hash_map;
    for(int i=0;i<n;i++) hash_map[givenString[i]]++;
    dist_count = hash_map.size();
    int size = INT_MAX;
    for(int i=0;i<n;i++) {
        int count=0;
        int visited[256]={0};
        string sub_str="";
        for(int j=i;j<n;j++) {
            if(visited[givenString[j]]==0){
                count+a+;
                visited[givenString[j]]=1;
            }
            sub_str+=givenString[j];
            if(count==dist_count) break;
        }
        if(sub_str.length()<size && count==dist_count){
            res=sub_str;
            size=res.length();
        }
    }
    return res.size();
}

int main(){
    ofstream fout(getenv("OUTPUT_PATH"));

    string givenString;
    getline(cin, givenString);

    int result = shortestSubstring(givenString);

    fout << result << "\n";

    fout.close();

    return 0;
}

