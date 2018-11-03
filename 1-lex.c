#include<stdio.h>
#include<string.h>

int keyw(char inp[])
{
	char keywords[32][10]={"auto","break","case","char","const","continue","default",
	"do","double","else","enum","extern","float","for",
	"goto","if","int","long","register","return","short",
	"signed","sizeof","static","struct","switch","typedef",
	"union","unsigned","void","volatile","while"};
 	int i,f1=0;
    
	for(i=0;i<32;i++)
 	{
   		if(strcmp(keywords[i], inp) == 0)
   		{
     		f1 = 1;
     		break;
   		}
 	}
 	return f1;
}

void main(){
 	char ch, inp[15], operators[] = "+-*/%=><", symb[]= "~!#$^&*()_|\'{}[]:?,./";
 	FILE *fp;
 	int i,j=0;
    
 	fp = fopen("lex.c","r");
    
 	if(fp == NULL){
   		printf("error while opening the file\n");
   		exit(0);
    }
    
 	while((ch = fgetc(fp)) != EOF){

  		for(i = 0; i < sizeof(operators)-1; ++i)
  		{
    		if(ch == operators[i]){
      
				if(j>0){
					inp[j] = '\0';
					j = 0;
				                              
					if(keyw(inp) == 1)
			  			printf("<keyword,%s>\n", inp);
					else
			  			printf("<id,%s>\n", inp);
				}
				printf("<op,%c> \n", ch);
	  		}
  		}
  
	  	for(i = 0; i < sizeof(symb)-1; ++i)
	  	{
	  		if(ch == symb[i]){
		  
				if(j>0){
					inp[j] = '\0';
					j = 0;
				                              
					if(keyw(inp) == 1)
			  			printf("<keyword,%s>\n", inp);
					else
			  			printf("<id,%s>\n", inp);
				}
				printf("<symbol,%c> \n", ch);
	  		}
		}
		       
	  	if(isalnum(ch)){
		 	inp[j++] = ch;
	  	}
	  	else if((ch == ' ' || ch == '\n') && (j != 0)){
			inp[j] = '\0';
			j = 0;
		                                  
			if(keyw(inp) == 1)
		 		printf("<keyword,%s>\n", inp);
			else
		 		printf("<id,%s>\n", inp);
	  	}		    

	}   

 	fclose(fp);

}
