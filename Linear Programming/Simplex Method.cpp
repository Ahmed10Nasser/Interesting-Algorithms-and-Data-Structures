#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

int const N=100+5, M=300+5, MOD=1e9+7, OO=0x3f3f3f3f;
long double const tolerance=1e-11;

int eqN,varN,n,m,art;
int basis[N];
long double arr[N][M],cj[M],z[M],ans[M], opt;
bool isleft[M];

void printTable()
{
    cout<<0<<"   |   ";
    for(int j=0; j<m; j++)
        cout<<cj[j]<<"  ";
    cout<<"\n";
    for(int i=0; i<n; i++)
    {
        cout<<basis[i]<<"   |   ";
        for(int j=0; j<m; j++)
            cout<<arr[i][j]<<"  ";
        cout<<"\n";
    }
    cout<<"======================================\n";
}

bool solve()
{
    while(true)
    {
//        printTable();
        /// Determining key column
        long double mn=0,d;
        int ki=-1, kj=-1;
        for(int j=1; j<m; j++)
        {
            if(isleft[j])
                continue;
            if(arr[n-1][j]+tolerance<0)
            {
                if(arr[n-1][j]+tolerance<mn)
                {
                    mn=arr[n-1][j];
                    kj=j;
                }
            }
        }
        /// We done if there is no negative numbers in Z-Cj row
        if(kj==-1)
            break;
        /// Determining key row
        int tBasis=-1;
        mn=DBL_MAX;
        for(int i=0; i<n-2; i++)
        {
            if(arr[i][kj]>0)
            {
                d=arr[i][0]/arr[i][kj];
                if(d+tolerance<mn)
                {
                    mn=d;
                    ki=i;
                    tBasis=basis[i];
                }
                else if(fabs(d-mn)<tolerance)
                {
                    if(tBasis<=eqN+varN && basis[i]>eqN+varN)
                    {
                        ki=i;
                        tBasis=basis[i];
                    }
                }
            }
        }
        /// Unbounded case if there is no positive numbers in key column
        if(ki==-1)
            return 0;
        /// Updating the basis variables (Entering and Leaving)
        if(basis[ki]>varN+eqN)
            isleft[basis[ki]]=1;
        basis[ki]=kj;
        /// Gauss-Jordan for the key element
        d=arr[ki][kj];
        for(int j=0; j<m; j++)
        {
            if(isleft[j])
                continue;
            arr[ki][j]/=d;
        }
        for(int i=0; i<n-2; i++)
        {
            if(i==ki)
                continue;
            d=arr[i][kj];
            for(int j=0; j<m; j++)
            {
                if(isleft[j])
                    continue;
                arr[i][j]-=(d*arr[ki][j]);
            }
        }
        /// Updating Z and Z-Cj rows
        for(int j=0; j<m; j++)
        {
            if(isleft[j])
                continue;
            arr[n-1][j]=arr[n-2][j]=0;
        }
        for(int j=0; j<m; j++)
        {
            if(isleft[j])
                continue;
            for(int i=0; i<n-2; i++)
                arr[n-2][j]+=(arr[i][j]*cj[basis[i]]);
            arr[n-1][j]=arr[n-2][j]-cj[j];
        }
    }
    return 1;
}

int main()
{
    FIO
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);
/// TAKING THE INPUT AND INSERT IT INTO SIMPLEX TABLE
    cin>>eqN>>varN;
    for(int i=0; i<eqN; i++)
    {
        arr[i][i+varN+1]=1;
        basis[i]=i+varN+1;
        for(int j=1; j<=varN; j++)
            cin>>arr[i][j];
    }
    for(int i=0; i<eqN; i++)
    {
        cin>>arr[i][0];
        if(arr[i][0]<0)
        {
            arr[i][i+varN+1]=-1;
            for(int j=0; j<=varN; j++)
                arr[i][j]*=-1;
            art++;
            arr[i][varN+eqN+art]=1;
            cj[varN+eqN+art]=-1;
            basis[i]=varN+eqN+art;
        }
    }
    n=eqN+2;
    m=1+varN+eqN+art;
    for(int j=1; j<=varN; j++)
        cin>>z[j];
    for(int j=0; j<m; j++)
    {
        for(int i=0; i<n-2; i++)
            arr[n-2][j]+=(arr[i][j]*cj[basis[i]]);
        arr[n-1][j]=arr[n-2][j]-cj[j];
    }
/// PHASE I : ELIMINATING ARTIFICIAL VARIABLES
    bool isBounded=solve();
    if(!isBounded)
    {
        cout<<"Infinity\n";
        return 0;
    }
    bool isFeasible=1;
    for(int i=0; i<n-2 && isFeasible; i++)
        if(basis[i]>varN+eqN)
            isFeasible=0;
    if(!isFeasible)
    {
        cout<<"No solution\n";
        return 0;
    }
    m-=art;
    for(int j=1; j<m; j++)
        cj[j]=z[j];
    for(int j=0; j<m; j++)
        arr[n-1][j]=arr[n-2][j]=0;
    for(int j=0; j<m; j++)
    {
        for(int i=0; i<n-2; i++)
            arr[n-2][j]+=(arr[i][j]*cj[basis[i]]);
        arr[n-1][j]=arr[n-2][j]-cj[j];
    }
//    cout<<"****************************************************\n";
/// PHASE II : GET OPTIMAL
    isBounded=solve();
    if(!isBounded)
    {
        cout<<"Infinity\n";
        return 0;
    }
    for(int i=0; i<n-1; i++)
        ans[basis[i]]=arr[i][0];
    /// check if the solution fit with the constrains or not
    cout<<"Bounded solution\n"<<setprecision(18)<<fixed;
    for(int i=1; i<=varN; i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
    return 0;
}

-----------------------------------------------------------------------
#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;

int const N=100+5, M=300+5, MOD=1e9+7, OO=0x3f3f3f3f;
long double const tolerance=1e-11;

int eqN,varN,n,m,art;
int basis[N];
long double arr[N][M],cj[M],z[M],ans[M], opt;
bool isleft[M];

void printTable()
{
    cout<<0<<"   |   ";
    for(int j=0; j<m; j++)
        cout<<cj[j]<<"  ";
    cout<<"\n";
    for(int i=0; i<n; i++)
    {
        cout<<basis[i]<<"   |   ";
        for(int j=0; j<m; j++)
            cout<<arr[i][j]<<"  ";
        cout<<"\n";
    }
    cout<<"======================================\n";
}

bool solve()
{
    while(true)
    {
//        printTable();
        /// Determining key column
        long double mn=0,d;
        int ki=-1, kj=-1;
        for(int j=1; j<m; j++)
        {
            if(isleft[j])
                continue;
            if(arr[n-1][j]+tolerance<0)
            {
                if(arr[n-1][j]+tolerance<mn)
                {
                    mn=arr[n-1][j];
                    kj=j;
                }
            }
        }
        /// We done if there is no negative numbers in Z-Cj row
        if(kj==-1)
            break;
        /// Determining key row
        int tBasis=-1;
        mn=DBL_MAX;
        for(int i=0; i<n-2; i++)
        {
            if(arr[i][kj]>0)
            {
                d=arr[i][0]/arr[i][kj];
                if(d+tolerance<mn)
                {
                    mn=d;
                    ki=i;
                    tBasis=basis[i];
                }
                else if(fabs(d-mn)<tolerance)
                {
                    if(tBasis<=eqN+varN && basis[i]>eqN+varN)
                    {
                        ki=i;
                        tBasis=basis[i];
                    }
                }
            }
        }
        /// Unbounded case if there is no positive numbers in key column
        if(ki==-1)
            return 0;
        /// Updating the basis variables (Entering and Leaving)
        if(basis[ki]>varN+eqN)
            isleft[basis[ki]]=1;
        basis[ki]=kj;
        /// Gauss-Jordan for the key element
        d=arr[ki][kj];
        for(int j=0; j<m; j++)
        {
            if(isleft[j])
                continue;
            arr[ki][j]/=d;
        }
        for(int i=0; i<n-2; i++)
        {
            if(i==ki)
                continue;
            d=arr[i][kj];
            for(int j=0; j<m; j++)
            {
                if(isleft[j])
                    continue;
                arr[i][j]-=(d*arr[ki][j]);
            }
        }
        /// Updating Z and Z-Cj rows
        for(int j=0; j<m; j++)
        {
            if(isleft[j])
                continue;
            arr[n-1][j]=arr[n-2][j]=0;
        }
        for(int j=0; j<m; j++)
        {
            if(isleft[j])
                continue;
            for(int i=0; i<n-2; i++)
                arr[n-2][j]+=(arr[i][j]*cj[basis[i]]);
            arr[n-1][j]=arr[n-2][j]-cj[j];
        }
    }
    return 1;
}

int main()
{
    FIO
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);
/// TAKING THE INPUT AND INSERT IT INTO SIMPLEX TABLE
    cin>>eqN>>varN;
    for(int i=0; i<eqN; i++)
    {
        arr[i][i+varN+1]=1;
        basis[i]=i+varN+1;
        for(int j=1; j<=varN; j++)
            cin>>arr[i][j];
    }
    for(int i=0; i<eqN; i++)
    {
        cin>>arr[i][0];
        if(arr[i][0]<0)
        {
            arr[i][i+varN+1]=-1;
            for(int j=0; j<=varN; j++)
                arr[i][j]*=-1;
            art++;
            arr[i][varN+eqN+art]=1;
            cj[varN+eqN+art]=-1;
            basis[i]=varN+eqN+art;
        }
    }
    n=eqN+2;
    m=1+varN+eqN+art;
    for(int j=1; j<=varN; j++)
        cin>>z[j];
    for(int j=0; j<m; j++)
    {
        for(int i=0; i<n-2; i++)
            arr[n-2][j]+=(arr[i][j]*cj[basis[i]]);
        arr[n-1][j]=arr[n-2][j]-cj[j];
    }
/// PHASE I : ELIMINATING ARTIFICIAL VARIABLES
    bool isBounded=solve();
    if(!isBounded)
    {
        cout<<"Infinity\n";
        return 0;
    }
    bool isFeasible=1;
    for(int i=0; i<n-2 && isFeasible; i++)
        if(basis[i]>varN+eqN)
            isFeasible=0;
    if(!isFeasible)
    {
        cout<<"No solution\n";
        return 0;
    }
    m-=art;
    for(int j=1; j<m; j++)
        cj[j]=z[j];
    for(int j=0; j<m; j++)
        arr[n-1][j]=arr[n-2][j]=0;
    for(int j=0; j<m; j++)
    {
        for(int i=0; i<n-2; i++)
            arr[n-2][j]+=(arr[i][j]*cj[basis[i]]);
        arr[n-1][j]=arr[n-2][j]-cj[j];
    }
//    cout<<"****************************************************\n";
/// PHASE II : GET OPTIMAL
    isBounded=solve();
    if(!isBounded)
    {
        cout<<"Infinity\n";
        return 0;
    }
    for(int i=0; i<n-1; i++)
        ans[basis[i]]=arr[i][0];
    /// check if the solution fit with the constrains or not
    cout<<"Bounded solution\n"<<setprecision(18)<<fixed;
    for(int i=1; i<=varN; i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
    return 0;
}
