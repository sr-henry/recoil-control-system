#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct PERFUME {  
    struct PERFUME *esq, *dir;   
    int cod;   
    char nome[30];  
    float preco;   
    }  *raiz = NULL,*aux = NULL;   
      
typedef struct PERFUME *arvore_ptr;   
  
//prototipos para passar para o outro arquivo  
void Inserir (arvore_ptr*, int, char[], float);   
void Pesquisar (arvore_ptr, int);   
  
  
/*int c = codigo char n[] = nome[30] float preco = p*/  
void Inserir (arvore_ptr *pai, int c, char n[], float p) {  
    if ((*pai)) {   
        if (c &lt; (*pai) -&gt; cod)  
           Inserir(&((*pai) -&gt; esq), c, n, p);   
        else  
           Inserir(&((*pai) -&gt; dir), c, n, p);  
    }  
    else {   
        (*pai) = (arvore_ptr) malloc (sizeof (struct PERFUME));   
            if (*pai) {   
                  (*pai) -&gt; cod = c;   
                   strcpy((*pai) -&gt; nome, n);  
                  (*pai) -&gt; preco = p;  
                  (*pai) -&gt; esq = NULL;   
                  (*pai) -&gt; dir = NULL;  
            }  
        }  
}  
  
void Pesquisar (arvore_ptr raiz, int c) {  
    if (raiz) {  
        if (c == raiz-&gt; cod) {   
            printf(&quot;codigo = %d\n&quot;, raiz -&gt; cod);  
            printf(&quot;nome = %s\n&quot;, raiz -&gt; nome);  
            printf(&quot;preco %d = %.2f\n&quot;, raiz -&gt; preco);  
      
            aux = raiz;   
            return;  
        }   
        else {  
            if (c &lt; raiz -&gt; cod)  
                Pesquisar(raiz -&gt; esq, c);   
            else  
                Pesquisar(raiz -&gt; dir, c);  
             }  
    }  
}  
  
void sbinario () {  
   FILE *fp;  
   fp = fopen (&quot;Binario.dat&quot;, &quot;ab&quot;); //wb para escrita //rb para leitura  
   if (fp == NULL) {  
      printf (&quot;Erro ao abrir o arquivo.\n&quot;);  
      exit(1);  
   }  
   else {  
   //if (fp != NULL) {}  
   printf (&quot;Arquivo Binario criado com sucesso.\n&quot;);   
   fwrite(&raiz, sizeof(raiz), 1, fp);  
   fclose (fp);  
   }     
}

/*Função reponsavel por exibir o conteudo do arquivo .dat*/

void imprime(){
     FILE * fp;
     fp = fopen (&quot;Binario.dat&quot;, &quot;rb&quot;); 
      if (fp == NULL) {  
      printf (&quot;Erro ao abrir o arquivo.\n&quot;);  
      exit(1);  
}
        while(fread(&raiz,sizeof(raiz),1,fp)){
                 
                 printf(&quot;%d, %s, %.2f\n&quot;,raiz-&gt;cod,raiz-&gt;nome,raiz-&gt;preco);
                 
                }
                  fclose(fp);
         
}  
      
void stexto () {  
   FILE * arquivo_texto; 
   arquivo_texto = fopen (&quot;arquivo_texto.txt&quot;, &quot;a&quot;); //duvida aqui se é r ou a  
   if (arquivo_texto == NULL) {  
         printf(&quot;Erro ao abrir o arquivo.\n&quot;);  
         exit(1);             
   }    
   //%s string //%d integer  
   fprintf(arquivo_texto, &quot;%d %s %2f\n&quot;, raiz-&gt;cod, raiz-&gt;nome, raiz-&gt;preco);
   printf(&quot;%d %s %2f\n&quot;,raiz-&gt;cod, raiz-&gt;nome, raiz-&gt;preco);   
   fclose(arquivo_texto);  
}  
            
int main() {  
    int opcao =1;   
    int entrada;  
    char nome1[30];  
    float p;  
    char temp[30];  
      
        while(opcao!=0) {     
                
              printf(&quot;|________________________|\n\n\n\n&quot;);  
              printf(&quot;=====&gt;Menu&lt;=====\n&quot;);  
              printf(&quot;________________\n&quot;);  
              printf(&quot;1--&gt;Inserir\n&quot;);  
              printf(&quot;2--&gt;Pesquisar\n&quot;);  
                          printf(&quot;3--&gt;Salvar Binario\n&quot;);  
                          printf(&quot;4--&gt;Salvar Texto\n&quot;); 
                          printf(&quot;5--&gt;Imprimir Texto\n&quot;);  
              printf(&quot;0--&gt;Sair        \n&quot;);  
              printf(&quot;________________\n&quot;);     
              printf(&quot;Opcao:&quot;);  
               scanf(&quot;%d%*c&quot;, &opcao);  
                       
    switch(opcao)  
      {  
          case 1:{  
                   printf(&quot;\nDigite o codigo: &quot;);   
                   gets(temp);  
                               entrada = atoi(temp);  
      
                   printf(&quot;digite o nome: &quot;);  
                   gets(nome1);  
      
                   printf(&quot;digite o preco: &quot;);  
                   gets(temp);  
                   p = atof(temp); //string para float  
                   Inserir(&raiz,entrada, nome1, p);  
                   break;  
                   }  
                 
          case 2:{  
                   printf(&quot;\nDigite o codigo: &quot;);   
                   gets(temp);  
                   entrada = atoi(temp); //string para int  
                   Pesquisar(raiz,entrada);   
      
                     if (aux) {  
                        printf(&quot;\n %d Existe na arvore\n&quot;,entrada);   
                     }  
                     else  
                        printf(&quot;\n %d Nao existe na arvore&quot;,entrada);   
                   break;  
                   }  
            
          case 3:{  
               sbinario();  
               break;  
               }  
                 
          case 4: {stexto();
          break;
          }
          case 5:{
               imprime();
               break;
               }       
      }   
   }  
} 