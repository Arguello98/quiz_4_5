#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/* 
	siendo  n el largo del arreglo y m el largo de los numeros
	f(n,m) = 2 + 1+ (3+3+2+1+(3+1+2+4)*(n+1) + 1 + 1+ (3+ (2+6+5+2)*(n+1) )*10)*m
	f(n,m) = 3+(11+10n+11+2+(3+15n+15)*10)*m
	f(n,m) = 3+(24+10n+150n+180)*m
	f(n,m) =160mn+214m+3
	
	Big O
		0(mn)
		
	loop invariant 
		siendo n el largo del arreglo y los elementos A[i,....,n]
		siendo max el largo del numero mas grande y j un contador
			A[i]%10**j,..,A[n]%10**j siempre estara ordenado
		Caso inicial
			entonces para j=0 cualquier numero division entera entre 1 es 0
		Caso medio
			para todo j<max A[i]%10**j hasta A[n]%10**j estara ordenado
			entonces para j=1 estara ordenado por unidades,
			j=2 por decenas y asi sucesivamente
		Caso final
			j=max A[i]%10**j hasta A[n]**j estara ordenado
*/

void radixSort(int *arr, int n, int max) {
   int i, j, m, p = 1, index, temp, count = 0; //2
   vector<int> pocket[10];      //radix of decimal number is 10
   for(i = 0; i< max; i++) {	//1+(3+
      m = pow(10, i+1);	//3
      p = pow(10, i);	//2
      for(j = 0; j<n; j++) {	//1+(3+
         temp = arr[j]%m;	//1
         index = temp/p;      //2
         pocket[index].push_back(arr[j]);	//4
      }
      count = 0;	//1
      for(j = 0; j<10; j++) {	// 1 +(3+
         //delete from linked lists and store to array
         while(!pocket[j].empty()) {	//(2
            arr[count] = *(pocket[j].begin());	//6
            pocket[j].erase(pocket[j].begin());	//5
            count++;	//2
         }
      }
   }
}

int main(int argc, char** argv) {
	
	return 0;
}
