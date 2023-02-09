#include<stdio.h>
#include <stdbool.h>
#include <string.h>

// IGNORAR OUTROS DÍGITOS ALÉM DE NÚMERO
void entrada(int CNPJ[])
{
    char entrada[30];
    int i, j=0, tam;
    printf("Entre com o CNPJ: ");
    fgets(entrada, 30, stdin);
    tam = strlen(entrada);
    
    for(i=0; i<tam; i++)
    {
        if(entrada[i]>=48 && entrada[i]<=57)
        {  
            CNPJ[j] = entrada[i]-48;
            
            j++;
        }
    }
}
// FIM IGNORAR OUTROS DÍGITOS ALÉM DE NÚMERO


// FUNÇÃO CALCULAR CNPJ
int calculoDigitoVerificador(int CNPJ[], int m[], int N)
{
    int soma = 0;
    int i;
    
    for(i=0; i<N; i++)
	{	
	    soma = soma + CNPJ[i] * m[i];
	}
	
	return ((soma*10) % 11)%10;
}
// FIM FUNÇÃO CALCULAR CNPJ


int main()
{
	int CNPJ[13];
	int m1[11]={1,1,2,2,2,3,3,3,0,0,0,1};
	int m2[12]={5,4,3,2,9,8,7,6,5,4,3,2};
	int i;
	
	entrada(CNPJ);
  	
  	// MANEIRA REDUZIDA
	if(calculoDigitoVerificador(CNPJ, m1, 9) == CNPJ[9] && calculoDigitoVerificador(CNPJ, m2, 10) == CNPJ[10])
	{
	    printf("\nCNPJ VÁLIDO!");
		//printf("\nPrimeiro verificador valitrue;
	}
	// FIM MANEIRA REDUZIDA
	
	
	else
	{
	    printf("\nCNPJ INVÁLIDO!");
		//printf("\nErro no primeiro verificador.");
	}
	
	return 0;
}



