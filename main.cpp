#include <iostream>
#include <cstdlib>
#include "pin.h"
#include "RandMT.h"
#include <ctime>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <functional>

using namespace std;

int main(int argc, char** argv) 
{
	int i,meg,y;
	double sec1,sec2,sec3,sec4;
	clock_t ct0,ct1;
	
	ofstream  fout("XRONOI.TXT");
	
	cout << "STUDENT" << endl;
	cout << "========" << endl;
    cout << "NAME: Konstantinos Makridis" << endl;
    cout << "AEM: 4645" << endl;
	cout << endl;
		
	cout << "Computer characteristics" << endl;
	cout << "========================" << endl;
	cout << "CPU: AMD Ryzen 5 - 3500U 2.10 GHz" << endl;
	cout << "RAM: 8GB" << endl;
	cout << "========="<< endl;
	cout << endl;
	
	cout << "Array size: ";
	cin >> meg;
	
	pin.setArraySize(meg);
	pin.createArray();
	
	cout << endl;
	cout << "Array Types" <<endl;
	cout << "============" << endl;
	cout <<"1.100% Random" << endl;
	cout <<"2.50% Sorted,50% Random" << endl;
	cout <<"3.Sorted Ascending" << endl;
	cout <<"4.Sorted Descending" << endl;
	cout <<"Choose: ";
	cin >> y;
	
	switch(y)
	{
		case(1):
			pin.fillArray100();
	    	break;
	    case(2):
	    	pin.fillArray50();   	
			break;
	    case(3):
	    	pin.fillArrayASC();
	    	break;
	    case(4):
	    	pin.sortDESC();
	    	
	    	break;
		 default:
		 cout << "ok";	
	}
	
	cout << "Now Sorting.." << endl;
	
	//BUBBLE
	ct0=clock();
	pin.bubbleSort();
	ct1=clock();
	sec1=(double)(ct1-ct0)/CLOCKS_PER_SEC;	

	//SELECTION
	ct0=clock();
	pin.selectSort();
	ct1=clock();
	sec2=(double)(ct1-ct0)/CLOCKS_PER_SEC;
	
	//INSERT
	ct0=clock();
	pin.insertSort();
	ct1=clock();
	sec3=(double)(ct1-ct0)/CLOCKS_PER_SEC;
	
	//QUICK
	ct0=clock();
	pin.quickSort(0,meg);
	ct1=clock();
	sec4=(double)(ct1-ct0)/CLOCKS_PER_SEC;
	
    cout << "DONE." << endl;
    fout << "ARRAY SIZE =" << meg;
    if(y == 1)
    {
    	fout <<"ARRAY TYPE =Random 100%" << endl;
	}
	else if(y==2)
	{
		fout <<"ARRAY TYPE =50% Sorted,50% Random" << endl;
	}
	else if(y==3)
	{
		fout <<"ARRAY TYPE =Sorted Ascending" << endl;
	}
	else if(y==4)
	{
		fout <<"Sorted Descending" << endl;
	}
	
	fout << endl;
	fout << "EXECUTION TIMES(in seconds)" << endl;
	fout << "============================" << endl;
	fout << "Bubble Time ="<<sec1 << endl << endl;	
	fout << "Selection Time ="<<sec2 << endl << endl;
	fout << "Insert Time ="<<sec3 << endl << endl;
	fout << "Quick Time ="<<sec4 << endl << endl;
	fout.close();
	
	return 0;
}

