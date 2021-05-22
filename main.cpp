#include <bits/stdc++.h>
using namespace std;
string LCSubStr(string X, string Y)
{
    int m = X.length();
    int n = Y.length();
    int result = 0;
    int end;

    int len[2][n];


    int currRow = 0;


    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                len[currRow][j] = 0;
            }
            else if (X[i - 1] == Y[j - 1]) {
                len[currRow][j] = len[1 - currRow][j - 1] + 1;
                if (len[currRow][j] > result) {
                    result = len[currRow][j];
                    end = i - 1;
                }
            }
            else {
                len[currRow][j] = 0;
            }
        }

        currRow = 1 - currRow;
    }

    if (result == 0) {
        return "nothing common";
    }


    return X.substr(end - result + 1, result);
}

int main()
{  int a,b;
    cout<<"Enter the length of the first array:";
    cin>>a;
    cout<<"Enter the length of the second array;";
    cin>>b;

    int arr[a];
    int arr1[b];
    cout<<"Enter the first array:";
    for(int i=0;i<a;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the second array:";
    for(int i=0;i<b;i++)
    {
        cin>>arr1[i];
    }
    string X;
    for (int k: arr) {
        X.push_back(k + '0');
    }
    string Y;

    for (int i: arr1) {
        Y.push_back(i + '0');
    }
    cout <<"longest common substring;"<<LCSubStr(X, Y);
    return 0;
}
