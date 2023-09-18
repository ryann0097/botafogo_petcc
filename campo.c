#include <stdio.h>

int main() {
    // declaração de variaveis
    int linhas, colunas, entrada;
    scanf("%d %d",&linhas, &colunas);
    
    //criação da porcaria da matriz
    int campo[linhas][colunas];
    
    for(int i = 0; i<linhas; i++){
        for(int j = 0; j<colunas; j++){
            scanf("%d", &campo[i][j]);
        }
    }
    //esse foi o preenchimento de vetor. não há como verificar durante o código
    //seria inteiramente bizarro.
    int irrigado = 0, n_irrigado = 0;
    for(int i = 0; i<linhas; i++){
        for(int j = 0; j<colunas; j++){
            if(campo[i][j] == 2 || campo[i][j] == 0){continue;}
    //se esse lote do kct do campo for infertil ou um irrigador, continua
            else if(campo[i][j]== 1){
    //ahhhh meu little friend. se for um lote fértil, bora verificar né
                if(campo[i-1][j] == 2 || campo[i+1][j]==2 || campo[i][j-1]==2 || campo[i][j+1]==2){irrigado++;}
    //ficou uma condicional ridícula, mas se qualquer um das 4 direções for um irrigador, podemos dizer que esse é um lote irrigado. do contrario
    //temos o outro contador que será incrementado.
                else{n_irrigado++;}
            }
        }
    }
    printf("%d %d",irrigado, n_irrigado);
    return 0;
}