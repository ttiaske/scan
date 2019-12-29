#include "file.h"
#include "data.h" // get_error()
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //strcmp



/* extern file  */
extern int nmb_hiden_file;
extern int nmb_hiden_directory;
extern int nmb_file;
extern int nmb_directory;
extern int nmb_python_file;
extern int nmb_php_file;
extern int nmb_c_file;
extern int nmb_cpp_file;
extern int nmb_javascript_file;
extern int nmb_text_file;
extern int nmb_html_file;
extern int nmb_java_file;
extern int nmb_pdf_file;
extern int nmb_assembleur_file;
extern int nmb_ruby_file;
extern int nmb_perl_file;
extern int nmb_go_file;

extern int new_file;

/*  */
extern int nmb_music;
extern int nmb_video;

/* color  */
void msg(int number, char *type_file){
    char  *msg;
    if (strcmp(type_file,"Hidden File\t") == 0 || strcmp(type_file,"Hidden Directory") == 0){
        sprintf(msg,"%s\tFound[%s%d%s]\n",type_file,CYAN,number,RESET);
    }
    else if(strcmp(type_file,"File\t\t") == 0)sprintf(msg,"File\t \t\tFound[%s%d%s]\n",CYAN,number,RESET);   
    else sprintf(msg,"%s File \t\tFound[%s%d%s]\n",type_file,CYAN,number,RESET);
    printf(msg);
}
//for display number extention find
void display(void){
    puts(" ");
    if(nmb_hiden_directory != 0)msg(nmb_hiden_directory,"Hidden Directory");
    if(nmb_hiden_file != 0)msg(nmb_hiden_file,"Hidden File\t");    
    if(nmb_directory != 0 )msg(nmb_directory,"Directory");
    if(nmb_file !=0)msg(nmb_file,"File\t\t");
    {
        if(nmb_c_file !=0)msg(nmb_c_file,"C ");
        if(nmb_python_file !=0)msg(nmb_python_file,"Python");
        if(nmb_cpp_file !=0)msg(nmb_cpp_file,"C++");
        if(nmb_javascript_file !=0)msg(nmb_javascript_file,"JS");
        if(nmb_html_file != 0)msg(nmb_html_file,"HTML");
        if(nmb_pdf_file !=0)msg(nmb_pdf_file,"pdf");
        if(nmb_text_file !=0)msg(nmb_text_file,"Text");
        if(nmb_music !=0)msg(nmb_music,"Music");    
        if(nmb_video !=0)msg(nmb_video,"Video");
        if(nmb_assembleur_file != 0)msg(nmb_assembleur_file,"Asm");
        if(nmb_ruby_file !=0)msg(nmb_ruby_file,"Ruby");
        if(nmb_perl_file != 0)msg(nmb_perl_file,"Perl");
        if(nmb_go_file != 0)msg(nmb_go_file,"Go");
        if(nmb_java_file != 0)msg(nmb_java_file,"Java");
    }
}

int main(void){

    struct dirent **namelist;
    char *name = getenv("HOME");
    chdir(name);
    puts("Scannig.....");
    sleep(2);
    scan_dir(name,namelist);
    display();
    return EXIT_SUCCESS;
}
