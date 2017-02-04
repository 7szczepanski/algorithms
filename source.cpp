#include <iostream>
#include <stdlib.h>  // not relevant right now
#include <random>
#include <time.h>
#include <string>

using namespace std;

/////////////////////////
const int rows = 10;  //size Y of our array
const int cols = 10;  //size X of our array
int tab[cols][rows];  
int tab1d[cols];      //any variable here will do
int minval = 50;      
int maxval = 99-minval;     //not very elegant solution, but it works
string zdanie= ("Alfred told me");   // any sentence will do



/////////////////////////

int generateTab();  
int generate1dTab();
int findMin();
int findMax();
void printTab();
void print1dTab();
void quicksort(int *vtab, int l, int r);  // we can use function from algorithm library but it's not about using this here :)
void reverse();
void reverseString(string& s);
void printString();

int main() {
	int wyb;

	srand(time(NULL));
	generateTab();
	printTab();
	cout << endl;
	generate2dTab();
	print1dTab();
	cout << endl;
	/* MENU */
	for (;;) {

		cout << "-------------------- MENU -----------------" << endl;
		cout << "|Chose what do you want to do..|" << endl;
		cout << "|1. Minimal value                         |" << endl;
		cout << "|2. Maximal value                         |" << endl;
		cout << "|3. Generate onedimensional array         |" << endl;
		cout << "|4. Quicksort oneD array                  |" << endl;
		cout << "|5. Reverse oneD array                    |" << endl;
		cout << "|6. Reverse string i.e "Alfred told me"   |" << endl;
		cout << "-------------------------------------------" << endl;
		cin >> wyb;
		if (wyb == 1) { cout << findMin()<< endl; }
		if (wyb == 2) { cout << findMax()<< endl; }
		if (wyb == 3) { generate1dTab(); print1dTab(); cout << endl; }
		if (wyb == 4) { quicksort(tab1d, 0, cols - 1); print1dTab(); cout << endl; }
		if (wyb == 5) {	reverse(); print1dTab();  cout << endl;	}
		if (wyb == 6) { cout << "Sentence before reversing: " << zdanie << endl; reverseString(zdanie); cout <<"and after: "; cout << zdanie << endl; }
	  if else{cout<<"Sorry wrong nubmer"<<endl;}

		}
		return 0;
	}





void reverse() {
	int temp;
	for (int i=0; i <cols/2; i++) {
		temp = tab1d[cols-i-1];             // We are asigning variable from the table to temporary variable
		tab1d[cols - i - 1]= tab1d[i];      // swaping places (Swap function will be great here)
		tab1d[i] = temp;                    // For best visual representation we are using third cup to switch fluids betwen two cups

	}
	
}
int generate1dTab() {
	for (int i = 0; i < cols; i++) {
		tab1d[i] = rand() % maxval + minval;       // filing tab with random numbers
	}
	return tab1d[cols];                          // return because we want to work with this later
}
void print1dTab() {                            // this function prints our table (useful when we want to show changes being done with tab)
	for (int i = 0; i < cols; i++) {
		cout<<tab1d[i]<<" ";
	}
}
void quicksort(int *vtab, int l, int r){       // tab - table, l - start point of our table (most of the times its 0), r - size of our table (i.e cols-1)

	int v = vtab[(l + r) / 2];                   // Quicksort works this way, we are chosing one point in our array and divide acording to this point whole array
	int i, j, x;                                 // then we are sorting in two separate steps first and second half of our array
	i = l;                                       
	j = r;
	do
	{
		while (vtab[i]<v) i++;
		while (vtab[j]>v) j--;
		if (i <= j)
		{
			x = vtab[i];
			vtab[i] = vtab[j];
			vtab[j] = x;
			i++;
			j--;
		}
	} while (i <= j);
	if (j>l) quicksort(vtab, l, j);            // and we can do this recursively :) so it is done imidiately (try it out for larger array)
	if (i<r) quicksort(vtab, i, r);
}


void printTab() {
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			cout << tab[i][j] << " ";
		}
		cout << endl;
	}
}
int generateTab() {


	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			tab[i][j] = rand() % maxval + minval;
		}

	}
	return tab[cols][rows];
}
int findMax() {
	int max=0;
	
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			if (max < tab[i][j])
			{
				max = tab[i][j];                      // if the max value is lower than array element then this is maximal value
			}
		}
	}

	return max;
}
int findMin() {
	int min = 100;
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {          // if the min value is greater than array element then this is minimal value
			if (min > tab[i][j])
			{
				min = tab[i][j];	
			}
		}
	}

}

void reverseString(string& str) {
	
		for (int i = 0, j = s.length() - 1; i<j; i++, j--) {
			
				char ch = str[i];
			
				str[i] = str[j];                        // mostly the same code like with reversing array
			
				str[j] = ch;
			
		}
	
}
