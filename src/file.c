#include "file.h"
#include "data.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* extern file */
/* global variable */
int nmb_hiden_file = 0;
int nmb_hiden_directory = 0;
int nmb_file = 0;
int nmb_directory = 0;
int nmb_python_file = 0;
int nmb_php_file = 0;
int nmb_c_file = 0;
int nmb_cpp_file = 0 ;
int nmb_javascript_file = 0;
int nmb_text_file = 0;
int nmb_html_file = 0;
int nmb_java_file = 0;
int nmb_pdf_file = 0;
int nmb_assembleur_file = 0;
int nmb_ruby_file = 0;
int nmb_perl_file = 0;
int nmb_go_file = 0 ;
int new_file = 0;


/* Music and video */
int nmb_music = 0;
int nmb_video = 0;

char *extention[SIZE_EXTENTION] = {".pdf",".py",".c",".c++",".cpp",".txt",".js",".html",".php",".java",".asm",
".rb",".pl",".go"}; 
char *music[SIZE_EXTENTION] = {".mp3",".m4a"};
char *video[SIZE_EXTENTION] = {".mp4",".avi"};




//scan file
static bool is_last_char(char the_[],char tab[]){
    int verify = 1;
    if(strlen(the_)  < strlen(tab))return false;
    for(int j = 0,i = strlen(the_) -strlen(tab);i<strlen(the_);j++,i++){
       if(the_[i] == tab[j]){continue;}
       verify = 0;
       break;
       } 
       
    return verify == 1 ?true:false;

}


static void scan_file(char *name_file_to_scan){ 
    //pour verifie si li antre lan boucle lan
    int nmb=0;
    //is_inode_bin(name_file_to_scan);
    //verify the extention
    for(int i=0;i<SIZE_EXTENTION;i++){
        if(is_last_char(name_file_to_scan,extention[i]) == true){
            nmb++;
            switch(i){
                    case 0:
                    nmb_pdf_file++;
                        break;
                    case 1:
                        nmb_python_file++;
                        break;
                    case 2:
                        nmb_c_file++;
                        break;
                    case 3:
                    case 4:
                        nmb_cpp_file++;
                        break;
                    case 5:
                        nmb_text_file++;
                        break;
                    case 6:
                        nmb_javascript_file++;
                        break;
                    case 7:
                        nmb_html_file++;
                        break;
                    case 8:
                        nmb_php_file++;
                        break;
                    case 9:
                        nmb_java_file++;
                        break;
                    case 10:
                        nmb_assembleur_file++;
                        break;   
                    case 11:
                            nmb_ruby_file++;
                            break;
                    case 12:
                        nmb_perl_file++;
                        break;
                    default:
                        nmb_go_file++;
                        }
            break;
        }
    
    }
        if(nmb == 1)return;
        
        for(int i = 0;i<2;i++){
            if(is_last_char(name_file_to_scan,music[i]) == true ){nmb_music++;break;}   
            else if(is_last_char(name_file_to_scan,video[i]) == true){nmb_video++;break;}
           
    }
}   


char tampon[_SC_UCHAR_MAX];
const char *c = ".";
int scan_dir(char *name_directory,struct dirent  **name_list){
    struct dirent **new_name_list;
    int n = scandir(name_directory,&name_list,NULL,alphasort);
    //printf("Scaning %s\n",name_directory);
    sleep(0.5);
     if(n == -1){
         puts("error scandir");
         return  -1;
     }
       else if(n == 2){
         //not scan
        chdir("../");
        return 0;
     }
     //printf("nombre de fichier -> %d pour scanner dans %s\n",n-2,name_directory);
    while(n--){
        if(name_list[n]->d_type == DT_DIR){
            nmb_directory++;
            if (strcmp(name_list[n]->d_name,c) == 0 || strcmp(name_list[n]->d_name,"..") == 0){
                if(chdir("../") == -1){exit(-1);}
                break;
            }
            if(name_list[n]->d_name[0]  == 46)nmb_hiden_directory++;
            getcwd(tampon,_SC_UCHAR_MAX);
            strcat(tampon,"/");
            strcat(tampon,name_list[n]->d_name);
            if(chdir(tampon) == -1){
                //don't make something
            }
            else scan_dir(tampon,new_name_list);
        }
        else if(name_list[n]->d_type == DT_REG ){
            nmb_file++;    
            if(name_list[n]->d_name[0] == 46 )nmb_hiden_file++;
            scan_file(name_list[n]->d_name);
        }
    }
}