#include <stdio.h>
#define TRUE 1
    int main(){
        int n1, n2, op, usar, troca, mask = 0b10000000;
    
    n1 = 0b00000000;
    n2 = 0b00000000;
    
        while(TRUE){    
            puts("Qual ação você deseja fazer?");
            puts("1. Usar");
            puts("2. Trocar o conteúdo");
            puts("3. Encerrar");
            scanf("%d",&op);
            
            switch(op){
                case 1:
                    puts("Qual gaveta você deseja usar?");
                    scanf("%d",&usar);
                    
                    switch(usar){
                        case 1:
                            if(n1 == 0b00000000){
                                n1 = n1 | mask;
                                n2 = n2 >> 1;
                            }else{
                                n1 = n1 >> 1;
                                n2 = n2 >> 1;
                                n1 = n1 | mask;
                            }
                        break;    
                        case 2:
                            if(n2 == 0b00000000){
                                n2 = n2 | mask;
                                n1 = n1 >> 1;
                            }else{
                                n2 = n2 >> 1;
                                n1 = n1 >> 1;
                                n2 = n2 | mask;    
                            }
                        break;
                        default:
                            puts("Gaveta inexistente");
                    }
                break;
                case 2:
                    if (n1 > n2){
                        troca = n2;
                        n2 = n1;
                        n1 = troca;
                    }else{
                        troca = n1;
                        n1 = n2;
                        n2 = troca;
                    }
                break;
                case 3:
                    puts("Você encerrou a operação");
                    printf("Gaveta 1: %d; Gaveta 2: %d", n1, n2);
                    return 1;
                break;
                default:
                    puts("Ação inválida");    
            }
        }
        
        
return 0;    
}