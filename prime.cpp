#include <bits/stdc++.h>
using namespace std;
unsigned int primeSum(unsigned int arr[],unsigned int n)
{
    
    unsigned int max_val = *max_element(arr, arr + n);
 
    vector<bool> prime(max_val + 1, true);
 
    prime[0] = false;
    prime[1] = false;
    for (unsigned int p = 2; p * p <= max_val; p++) {
 
        if (prime[p] == true) {
 
            for (unsigned int i = p * 2; i <= max_val; i += p)
                prime[i] = false;
        }
    }
 
   unsigned int sum = 0;
    for (unsigned int i = 0; i < n; i++)
        if (prime[arr[i]])
            sum += arr[i];
 
    return sum;
}
unsigned int removeDuplicates(unsigned int arr[],unsigned int n)
{
    if (n==0 || n==1)
        return n;
    unsigned int j = 0;
    for (int i=0; i < n-1; i++)
        if (arr[i] != arr[i+1])
            arr[j++] = arr[i];

    arr[j++] = arr[n-1];

    return j;
}
unsigned int g(unsigned int n)
{
    unsigned int count=0;

do {
    n /= 10;
    ++count;
  } while (n != 0);

return count;}
int  main()
{
   unsigned int p,N,k,n,j=0,a1,copy,i,t,a[20],prime[20],c;
   cin>>n;
     k=g(n);
    copy=n;
    N=(k*(k+1))/2;
    for( i=0;i<k;i++){
        
         t=k-i;
         
         if((i>0)&&(j>=i)){
             j=j;
         }
         else{
             j=i;
         }
         
       while(t--)
       {
           a1=pow(10,i+1);
           a[j]=copy%a1;
           copy=copy/10;
           
           ++j;
       }
       copy=n;
    }
 
   sort(a,a+N);
   N = removeDuplicates(a, N);
   
   cout <<"sum of all the prime number: " <<primeSum(a, N);
    
}

