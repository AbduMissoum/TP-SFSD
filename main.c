  #include<stdio.h>
    #include"machine.h"
     #include<ctype.h>
    
    
  int main()
  {
      FILE *f3;
  	f=fopen("lovc.txt","wb+");
  		f1=fopen("tovc.txt","wb+");	
  		f2=fopen("tof.txt","wb+");
  			f3=fopen("lovc_organizer.txt","wb+");
   
 buff_l=(buff_lvc*)malloc(sizeof(buff_lvc));
    buff3=(buff_lvc*)malloc(sizeof(buff_lvc));

      buff2=(char*)malloc(sizeof(char)*255);
  
    
      MENU(f,f2,f1,f3);
    
    fclose(f);
    fclose(f1);
    fclose(f2);
    fclose(f3);
}
    
     


