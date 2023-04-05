#include <iostream>
#include <cstdlib>
#include <utility>
#include <algorithm>
#include <functional>  
#include "RandMT.h"
#include "pin.h"
#include <ctime>

using namespace std;

void pin::setArraySize(int n1)
{
	n= n1;
}

void pin::createArray()
{
	p= new int[n];
}

void pin::fillArray100()
{
	int i;
	unsigned int x;
	RandMT myrand;
	RandMT(time(NULL));
	for(i=0;i<n;i++)
	{
		p[i]=myrand();
	}
}
 
void pin::fillArray50()
{
	int i,x=n/2;
	RandMT myrand;
	RandMT(time(NULL));
	for(i=0;i<x;i++)
	{
		p[i]=myrand();
	}
	sort(p,p+x);
	RandMT(time(NULL));
	for(i=x;i<n;i++)
	{
		p[i]=myrand();
	}
}

void pin::fillArrayASC()
{
	int i;
	RandMT myrand;
	RandMT(time(NULL));
	for(i=0;i<n;i++)
	{
		p[i]=myrand();
	}
	sort(p,p+n);
}

void pin::sortDESC()
{
	int i,j,temp;
	RandMT myrand;
	RandMT(time(NULL));
	for(i=0;i<n;i++)
	{
		p[i]=myrand();
	}
	sort(p,p+n,greater<int>());
}

void pin::printAray()
{
	int i;
	for(i=0; i<n; i++)
	{
	 cout << p[i] << endl;
	}
}

void pin::bubbleSort()
{
	int i,j,temp;
	for(i=1; i<n; i++)
	{
		for(j=n-1;j>=1;j--)
		{
			if(p[j-1]>p[j])
			{
				temp = p[j-1];
				p[j-1]=p[j];
				p[j]=temp;
			}
		}
	
	}
	
}	    

void pin::selectSort()
{
	int i,k,j,min;
	 for(i=0; i<n-1; i++)     
	    {      
	      k = i;       
	      min = p[i];        
	 for(j=i+1; j<n; j++)          
	    {             
	     if(p[j] < min)            
	     {               
	     k = j;                  
	     min = p[j];               
	     }      
	    }        
	     p[k] = p[i];        
	     p[i] = min;       
		}
}	    

void pin::insertSort()
{
	int i,key,x,j;
	for(i=1;i<n;i++)
	{
		x = p[i];
		j=i-1;
		while(j>=0 && p[j]>x)
		{
			p[j+1] = p[j];
			j=j-1;
		}
		p[j+1]=x;
	}	
}

void pin::quickSort(int left,int right)
{
	int i,j,x,mid;
	if(left < right)
	{
		i = left;
		j = right;
		mid =(left+right)/2;
		x=p[mid];
		while(i<j)
		 {
		 	while(p[i]<x)
		 	    i++;
		 	while(p[j]>x)
		 	    j--;
		 	if(i<j)
		 	  {
		 	  	 if(p[i] == p[j])
		 	  	   {
		 	  	      if(i<mid)
		 	  	      {
						i++;
					  }
					  if(j>mid)
					  {
					    j--;
					  }
				   }
				 else
				 {
					swap(p[i],p[j]);
				 }
			  }
		 }
		 quickSort(left,j-1);
		 quickSort(j+1,right);
	}
}

