#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int last_char(char the_[],char tab[],int len_exten);

void main(void){

   char *text = "text.js";
   char *text_2 = ".js";
   char *end;
   end = strstr(text,text_2);
   int x = last_char(text,text_2,strlen(text_2));
   
  printf("the code -> %d\n",x);

}



int last_char(char the_[],char tab[],int len_exten){
    for(int j = 0,i = strlen(the_) -len_exten;i<strlen(the_);j++,i++){
       printf("%c == %c\n",the_[i],tab[j]);
       if(the_[i] == tab[j]) continue;
       return -1; 
       }     

return 0;
}
