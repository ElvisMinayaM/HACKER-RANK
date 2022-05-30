#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'funWithAnagrams' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY text as parameter.
 */
bool areAnagram(string str1, string str2){
    int n1=str1.length();
    int n2=str2.length();
    if(n1!=n2) return false;
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    for(int i=0;i<n1;i++) if(str1[i]!=str2[i]) return false;
    return true;
}

vector<string> funWithAnagrams(vector<string> text){
    for(int i=0;i<text.size();i++){
        for(int j=i+1;j<text.size();j++){        
            if(areAnagram(text[i],text[j])){
                text.erase(text.begin()+j);  
                j-=1;   
            }
        }
    }
    sort(text.begin(),text.end());
    return text;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string text_count_temp;
    getline(cin, text_count_temp);

    int text_count = stoi(ltrim(rtrim(text_count_temp)));

    vector<string> text(text_count);

    for (int i = 0; i < text_count; i++) {
        string text_item;
        getline(cin, text_item);

        text[i] = text_item;
    }

    vector<string> result = funWithAnagrams(text);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

