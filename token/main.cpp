#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

bool isKeyword(string token)
{
string keywords[] = {"int", "float", "char", "if", "else", "while", "return"};
for (int i = 0; i < 7; i++)
{
    if (token == keywords[i])
        return true;
}
return false;
}

bool isConstant(string token)
{
    if (token[0] >= 48 && token[0] <= 57)
        return true;

    return false;
}

bool isOperator(string token)
{
if (token == "+" || token == "-" || token == "*" ||
token == "/" || token == "=" || token == ">" || token == "<")
return true;
return false;
}

bool isSeparator(string token)
{
if (token == ";" || token == "," || token == "(" || token == ")")
return true;
return false;
}

void identifyToken(string token)
{
if (isKeyword(token))
cout << token << " - Keyword" << endl;
else if (isConstant(token))
    cout << token << " - Constant" << endl;
else if (isOperator(token))
    cout << token << " - Operator" << endl;
else if (isSeparator(token))
    cout << token << " - Separator" << endl;
else
    cout << token << " - Identifier" << endl;
}

int main()
{
string token;
ifstream file("tokenfile.txt");
while (file >> token)
{
    identifyToken(token);
}
file.close();
return 0;
}


