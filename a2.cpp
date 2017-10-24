#include<iostream>
#include<omp.h>
using namespace std;
int k=0;
class strat
{
	public:
		
		int party(int arr[],int low,int high)
		{
			int temp,i,j,key;
			key=arr[low];
			i=low+1;
			j=high;
			while(1)
			{
				while(i<high && key>=arr[i])
				{
					i++;
				}
				while(key<arr[j])
				{
					j--;
				}
				if(i<j)
				{
					temp=arr[i];
					arr[i]=arr[j];
					arr[j]=temp;
				}
				else
				{
					temp=arr[low];
					arr[low]=arr[j];
					arr[j]=temp;
					return j;
				}
			}
		}
		
		void quicky(int arr[],int low,int high)
		{
			int j;
			if(low<high)
			{
				j=party(arr,low,high);
				cout<<"Pivot Element with "<<j<<"th index was found by thread->"<<k<<"\n";
				#pragma omp parallel sections
				{
				
					#pragma omp section
					{
						k=k+1;
						quicky(arr,low,j-1);
					}
					#pragma omp section
					{
						k=k+1;
						quicky(arr,j+1,high);
					}
				}
			}
		}
};

int main()
{
    strat a;

    int arr[100];
    int n,i;

    cout<<"Enter the value of n\n";
    cin>>n;
    cout<<"Enter the "<<n<<" number of elements \n";

    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    a.quicky(arr, 0, n - 1);

    cout<<"Elements of array after sorting \n";
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }

    cout<<"\n";
}
