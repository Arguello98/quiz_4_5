#include <iostream>
#include <vector>
using namespace std;

/*Insertion sort utilizado para crear un vector con los ordenes de los indices de mas bajo a mas alto */
void insertion_sort(vector<int>& v, int arr[], int tamano){
	v.push_back(0);
	for(int i=1; i<tamano; i++)   
    {  
    	v.push_back(i);
        int temp = arr[i];  
        int j= i-1;  
        while(j>=0 && temp <= arr[v[j]])  
        {  
        	swap(v[j+1],v[j]); 
            j = j-1;  
        }  
    } 	
}	

/*
	f(n)
		siendo n,m los largos de los arreglos x y y
		f(m,n) = 3+9+(3+3+2+6+2+2)*(m+n+1) +1
		f(m,n)=12+(18)*(m+n+1)+1
		f(m,n) = 12 + 18m + 18n + 18+1
		f(m,n) = 18m+18n+31

	Big O
		O(m+n)

	loop invariant 
		por cada iteracion 
			if(valor_X > valor_Y)
				costo_mixto+= valor_X
			else
				costo_mixto += valor_Y
		siendo valor_X el valor mas alto x de por la cantidad de piezas para cortar
			valor_X  = x * piezas_H
		siuendo valor_Y el valor mas alto de y por la cantidad de piezas por cortar
	
*/
int costo(int N, int M, int x[], int y[]){
	int piezas_H  = 1; //1
	int piezas_V = 1;	//1
	int costo_mixto = 0;	//1
	vector<int> x_ord;
	vector<int> y_ord;
	
	int valor_X, valor_Y;
	insertion_sort(x_ord,x,N-1);	
	insertion_sort(y_ord,y,M-1);	
	
	if(N> 1 && M>1){	//3
		valor_X = x[x_ord[N-2]];	//3
		valor_Y = y[y_ord[M-2]];	//3
	}
	else{
		if(N<=1){	//1
			valor_X = -1;	//1
		}
		if(M<=1){	//1
			valor_Y= -1;	//1
		}
	}

	
	while(piezas_H < N || piezas_V < M){	//(3	+
		if(piezas_H < N && piezas_V < M){	//3
			if(valor_Y > valor_X){	//2
				valor_Y = y[y_ord[M-piezas_V-1]] * piezas_H;	//6
				costo_mixto += valor_Y;	//2
				piezas_V ++;	//2
			}
			else{
				valor_X = x[x_ord[N-piezas_H-1]] * piezas_V;	//6
				costo_mixto += valor_X;	//2
				piezas_H ++;	//2
			}
		}
		else{
			if(piezas_V < M){	//1
				valor_Y = y[y_ord[M-piezas_V-1]] * piezas_H;	//6
				costo_mixto += valor_Y;	//2
				piezas_V ++;		//2
			}
			else{
				valor_X = x[x_ord[N-piezas_H-1]] * piezas_V;	//2
				costo_mixto += valor_X;	//2
				piezas_H ++;	//2
			}
		}
		
	}	
	return costo_mixto;	//1
}


int main(int argc, char** argv) {
	int x[] = {1,2,3};
	int y[] = {};
	int r = costo(4,1,x,y);
	cout <<r<<endl;
	return 0;
}
