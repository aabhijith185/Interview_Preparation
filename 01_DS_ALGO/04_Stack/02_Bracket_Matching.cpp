#include<iostream>
#include<cstring>
#include<stack>
#include<map>

using namespace std; 

int isBalanced(char *exp)
{
    //create map:set key value pair 
    map<char,char> mapping; 
    mapping['{'] = '}'; 
    mapping['('] = ')'; 
    mapping['['] = ']'; 

    //create map iteratior
    map<char,char>::iterator itr; 

    //Create stack 
    stack<char> stk;

    //Initialize stack 
    for(int i=0;i<strlen(exp);i++)
    {
        if(exp[i] == '{' ||exp[i] == '('|| exp[i] == '[')
            stk.push(exp[i]); 
        else if(exp[i] == '}' ||exp[i] == ')'|| exp[i] == ']')
        {
            if(stk.empty())
                return false; 
            else 
            {
                char tmp = stk.top(); 
                itr = mapping.find(tmp);
                if(itr->second == exp[i])
                    stk.pop(); 
                else 
                    return false;
            }
        }
    }
    return stk.empty()?true:false;
}
int main()
{
	char A[]="{([a+b]*[c-d])/e}";
	cout<<isBalanced(A)<<endl;//Matching

	char B[]="{([a+b]}*[c-d])/e}";
	cout<<isBalanced(B)<<endl;//Not matching

	char C[]="{([{a+b]*[c-d])/e}";
	cout<<isBalanced(C)<<endl;//Not matching
	return 0;
}