/*#include <iostream>
#include <vector>
using namespace std;

int main()
{  	float encomendasAentrar[256];//encomendas que vao para o camiao
	float totalEncomendas[256][2];//todas as encomendas ([numeroencomenda][peso])
	float pesoMaxCamiao;
	float encomendasExcluidas[256];//encomendas que nao vao no camiao
	int numEncomendas;//numero de encomendas
	int j=0;
	int i=0;
	int printfinal=0;
	float peso=0;
	float max=0;
	int auxEntrada=0;
	int auxNegados=0;
	int maisnada=1;
	
		cout<<"introduza o numero de encomendas"<<endl;
		cin>>numEncomendas;
		cout<<"introduza peso das encomendas"<<endl;
		while(numEncomendas>0){
			cin>>peso;
			totalEncomendas[i][0]=peso;
			i++;
			numEncomendas--;
		}

	while(pesoMaxCamiao>0 && maisnada!=1){
		//procura o peso maximo
		for(j=0;j<i;j++){
			if(totalEncomendas[j][0]>totalEncomendas[j+1][0]){
			max=totalEncomendas[j][0];
			if(pesoMaxCamiao<max && pesoMaxCamiao!=0){ //Se for max >peso max vai para os negados
			encomendasExcluidas[auxNegados]=max;
			auxNegados++;
			}
			totalEncomendas[j][0]=0;
		}
			else{	
			max=totalEncomendas[j+1][0];
			if(pesoMaxCamiao<max && pesoMaxCamiao!=0){
			encomendasExcluidas[auxNegados]=max;
			auxNegados++;
			}

			totalEncomendas[j+1][0]=0;}

		if(pesoMaxCamiao<max && pesoMaxCamiao!=0){
			encomendasExcluidas[auxNegados]=max;
			auxNegados++;
			totalEncomendas[j][0]=0;
			}
		}
		if(pesoMaxCamiao>max){
			encomendasAentrar[auxEntrada]=max;
			auxEntrada++;
			pesoMaxCamiao-=max;
		}
		if((auxNegados+1)+(auxEntrada+1)==numEncomendas) //Se ja tiver passado todas as encomendas
			maisnada=1;
		
		maisnada=0;
		j=0;
		max=0;
	}

		for(printfinal=0;printfinal<=auxEntrada;printfinal++)
		cout<<"encomendas que entram" << encomendasAentrar[printfinal] <<endl;

}*/
