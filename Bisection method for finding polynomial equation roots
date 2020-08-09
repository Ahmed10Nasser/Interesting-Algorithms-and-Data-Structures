/// Ahmed Nasser Mohamed
/// 08/06/2020

/*
--Problem description : find the roots of a given polynomial equation in a given domain
--Solution : use bisection method implemented with float binary search
--Time complexity : O((DomainLength^2) * log(n))
*/

#include<bits/stdc++.h>
using namespace std;

//Constants
int const N=5e5+5, M=26+5, oo=0x3f3f3f3f, MOD=1e8, maxit=100;
double const tol=1e-20,OO=0x3f3f3f3f3f3f3f3f;

// Global variables
int dom1,dom2,Dom1,Dom2,cnt;
bool notValid;
string eq;
vector <pair<double,int>> arr;
map <double,double> mem;
map <double, bool> sol;

/// Functions prototypes
string trim(string s);
void findCoff(string eq);
void check(string stemp);
double bisection(double a, double b);
double fun(double x);

int main()
{

    while(true)
    {
        notValid=0;
        arr.clear();
        cout<<"         F(x) = ax^b + cx^d + ex^f +....+gx+h       Where a,b,c,d,e,f,g and h are constants.\n";
        cout<<"\nEnter an equation following the format of F(x): ";
        getline(cin,eq);
        findCoff(trim(eq));
        if(notValid)
            cout<<"\nThe input is NOT CORRECT, please try again!\n\n";
        else
            break;
    }

    cout<<"\nEnter the integer start of the domain: ";
    cin>>dom1;
    cout<<"\nEnter the integer end of the domain: ";
    cin>>dom2;
    cout<<"\n";
    Dom1=min(dom1,dom2);
    Dom2=max(dom1,dom2);
    cout<<setprecision(16);
    for(int i=Dom1; i<=Dom2; i++)
    {
        for(int j=i+1; j<=Dom2; j++)
        {
            if(fun((double)(i))*fun((double)(j))>0)
                continue;
            double ans=bisection((double)(i),(double)(j));
            if(sol[ans]==0)
            {
                sol[ans]=1;
                cout<<"Root "<<++cnt<<" = "<<ans<<"\n";
            }
        }
    }
    if(sol.size()==0)
        cout<<"There are no roots in the given domain\n";




}




double fun(double x)
{
    if(mem.find(x)!=mem.end())
        return mem[x];
    double ret=0;
    for(pair<double,int> p : arr)
        ret+=p.first*pow(x,p.second);
    return mem[x]=ret;
}



double bisection(double a, double b)
{
    double c;
    double fa=fun(a);
    if(abs(fa)<tol)
        return a;
    double fb= fun(b);
    if(abs(fb)<tol)
        return b;
    for(int i=0; i<maxit; i++)
    {

        c=(a+b)/2.0;
        double fc=fun(c);
        if(abs(b-a)<tol)
            break;
        if(abs(fc)<tol)
            break;
        if(fa*fc>0)
        {
            a=c;
            fa=fc;
        }
        if(fb*fc>0)
        {
            b=c;
            fb=fc;
        }
    }
    return c;
}


string trim(string s)
{
    string str=s;
   str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
   return str;
}


void check(string stemp)
{
    double coff=OO;
    char a;
    int ord=oo;
    string ts="NONE",stest="NONE";
    stringstream ss1;
    ss1<<stemp;
    ss1>>coff;
    if(coff!=OO && coff!=0)
    {
        ss1>>ts;
        if(ts=="x")
            arr.push_back({coff,1});
        else if(ts.substr(0,2)=="x^" && ts.size()>2)
        {
            stringstream ss2;
            ss2<<ts;
            ss2>>a>>a>>ord>>stest;
            if(ord!=oo && ord!=0 && stest=="NONE")
                arr.push_back({coff,ord});
            else
                notValid=1;
        }
        else if (ts=="NONE")
            arr.push_back({coff,0});
        else
            notValid=1;
    }
    else
        notValid=1;

}


void findCoff(string eq)
{
    if(eq[0]!='-')
        eq='+'+eq;
    int sz=eq.size();
    string stemp="";
    bool taken=0;
    for(int i=0; i<sz && !notValid; i++)
    {
        if(eq[i]=='+' || eq[i]=='-')
        {
            if(taken)
            {
                if(stemp.size()>1 && !(stemp[1]-'0'>=0 && stemp[1]-'0'<=9))
                    stemp.insert(1,"1");
                check(stemp);
                taken=0;
                i--;
                continue;
            }
            else
            {
                taken=1;
            }
            stemp=eq[i];
        }
        else
            stemp+=eq[i];
    }
    check(stemp);
}
