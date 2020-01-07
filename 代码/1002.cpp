#include <iostream>
#include <vector>
using namespace std;

struct poly
{
    int exp;
    float coe;
};
int main()
{
    int a,b;
    cin>>a;
    vector<poly> poly1;
    vector<poly> poly2;
    vector<poly> sum;
    for(int i=0;i<a;i++)
    {
        poly p;
        cin>>p.exp>>p.coe;
        poly1.push_back(p);
    }
    cin>>b;
    for(int i=0;i<b;i++)
    {
        poly p;
        cin>>p.exp>>p.coe;
        poly2.push_back(p);
    }
    int i=0,j=0;

    while(i<a&&j<b)
    {
        if(poly1[i].exp>poly2[j].exp)
        {
            sum.push_back(poly1[i]);
            i++;
        }
        else if(poly1[i].exp<poly2[j].exp)
        {
            sum.push_back(poly2[j]);
            j++;
        }
        else
        {
            if((poly1[i].coe+poly2[j].coe)!=0)  //判断系数和是否为0，只有当非零的时候才加入sum，否则直接跳过
            {
                poly add;
                add.exp=poly1[i].exp;
                add.coe=poly1[i].coe+poly2[j].coe;
                sum.push_back(add);
            }
            i++;
            j++;
        }
    }
    while(i<a)
    {
        sum.push_back(poly1[i]);
        i++;
    }
    while(j<b)
    {
        sum.push_back(poly2[j]);
        j++;
    }
    int n=sum.size();
    cout<<n;
    for(int index=0;index<n;index++)
    {
        printf(" %d %.1f",sum[index].exp,sum[index].coe);
    }

}
