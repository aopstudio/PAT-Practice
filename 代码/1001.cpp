#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a,b,c,n;
    cin>>a>>b;
    c=a+b;
    string str=to_string(c);
    n=str.size();
    for(int i=0;i<n;i++){
        cout<<str[i];
        if(c<0&&i!=n-1&&(n-i-1)%3==0&&i!=0) {
            cout<<',';
        }
        if(c>0&&(n-i-1)%3==0&&i!=n-1) {
            cout<<',';
        }

    }
    return 0;
}
