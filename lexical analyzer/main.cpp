#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int id=1;
string keyWords[7] = {"for","int","float","double","if","while","else"};

int esPerline[10],line = 0, charPerline[10];

void counts(string a,int length)
{
    for(int i = 0;i<length;i++){
        if(a[i]=='\t' || a[i] == ' ')
        {
            esPerline[line] +=1;
        }
        else if(a[i]=='\n'){
            line++;
        }
        else{
            charPerline[line] +=1;
        }
    }
}

bool isKeyWords(string temp)
{
    for(int i=0;i<7;i++)
    {
        if(keyWords[i] == temp)
        {
            return true;
        }
    }
    return false;
}

bool isOperator(char a)
{
    if(a== '+' || a == '-' || a == '*' || a == '/' || a == '=' ||  a == '^'|| a == '>'|| a == '<')
    {
        return true;
    }

    return false;
}

bool isVariable(string str){
    bool flag = true;

    if(isdigit(str[0])){
        for(int i = 0;i<str.length();i++){
            if(isdigit(str[i])){
                flag = true;
            }
            else{
                if(flag){
                    flag = false;
                    break;
                }
            }
        }
    }
    return flag;
}

bool isValid(string str, int n)
{
	char temp[100];
	int k = 0;
	if (!((str[0] >= 'a' && str[0] <= 'z')
		|| (str[0] >= 'A' && str[0] <= 'Z')
		|| str[0] == '_')
        )
		return false;

	for (int i = 0; i<n; i++) {
		if(isOperator(str[i])){
            temp[k] = NULL;
            k=0;
            if(!isVariable(temp)){
                return false;
            }
		}
		else{
            if(str[i]!=' '){
                temp[k] = str[i];
                k++;
            }
		}

	}
	return true;
}

void check(string a, int length)
{
    string temp="";
    int j;
    if(isValid(a,length)){
        for(int i=0;i<length;i++)
        {
            temp = "";
            while(a[i] !=' ')
            {
                temp +=a[i];
                i++;
            }
            if(isKeyWords(temp))
            {
                cout<<"< "<<temp<<" >";
            }
        }
    }
    else{

    }
}

int main()
{

    string a = "int x = y + z - 30 ";

    int length = a.size();
    counts(a,length);
    cout<<"Total Number Of Line Is : "<<line+1<<endl;
    for(int i = 0;i<=line;i++)
    {
        cout<<"Number Of White Space In Line "<<i+1<<" is : "<<esPerline[i]<<endl;
        cout<<"Number Of Char In Line "<<i+1<<" is : " <<charPerline[i]<<endl<<endl;
    }

    check(a,length);

    int k = 1;
    bool digitStart = true;
    bool variableStart = true;
    if(isValid(a,length)){
        for(int i=0;i<length;i++){
            if(isOperator(a[i])){
                cout<<")"<<"("<<a[i]<<")";
                digitStart = true;
                variableStart = true;
            }
            else if(isdigit(a[i])){
                if(digitStart){
                    cout<<"(";
                    digitStart = false;
                }
                cout<<a[i];
            }
            else{
                if(a[i]!=' ' && a[i]!=';'){
                    if(variableStart){
                        cout<<"(id, "<<k;
                        k++;
                        variableStart = false;
                    }
                }
            }
        }
        cout<<")";
    }
    else{
        cout<<"The Statement Is Not Valid!!!";
    }
    return 0;
}

