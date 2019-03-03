#include <iostream>
using namespace std;

int main() {
    int t,i;
    cin>>t;
    int input[t];
    for(i=0;i<t;i++)
    {
        cin>>input[i];
    }
    for(i=0;i<t;i++)
    {
        int n=input[i];
        //float s;
        int j;
        int left=0,right=n;
        while(left<right)
        {
            int mid=(left+right)/2;
            int square1=mid*mid;
            int square2=(mid+1)*(mid+1);
            if(square1<=n&&n<=square2)
            {
                if(n==square1)
                {
                    j=mid-1;
                }
                else
                {
                    j=mid;
                }
                break;
            }
            else if(n>square1)
            {
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
        cout<<j<<"\n";

    }
	//code
	return 0;
}
