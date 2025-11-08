#include<iostream> 
#include<vector> 
#include<string> 
#include<algorithm> //For reverse 
#include<sstream>

using namespace std; 

string reverseWords(const std::string &input)
{
    stringstream ss(input); 
    vector<string> words; 
    string word; 

    //Extract words using stringstream 
    while(ss>>word)
    {
        words.push_back(word);
    }
    
    //Reverse the words 
    reverse(words.begin(),words.end()); 

    //Reconstruct the string 
    string res; 
    for(auto i : words)
    {
        res+=words; 
        int j = 0; 
        if(j<words.size())
            res += " ";
    }
    return res;
}

int main()
{
    string sentence = "Hello World I am here"; 
    string reversed = reverseWords(sentence); 
    cout<<reversed<<endl;
    return 0;
}