 
   #include<stdio.h>
   #include<stdlib.h>
   #include<string.h>
  
 
  
      //TOVC
    typedef  struct eng
	 {
	     int eff ; //soit 0 ou 1
	     int cle;
	     char nom[30]; 
	     char prenom[30];
	     
	  }eng;
	  
	  
	   //T/OF
	  typedef struct index
	  {
	  	int i;
	  	int j;
	  	int cle;
	  	int eff;
	  }index;
	  typedef struct buff
	  {
	  int nb;
	  
	  index tab[40];  
	  
	  }buff;
	  
	   FILE *f;
       buff buff1;//utilisé comme buffer du fichier tof
    
    
    
    
	 
	 FILE *f2;
	 char  *buff2;//utilisé comme buffer du fichier tovc
	 
	//L/OVC
	 typedef struct buff_lvc//structure du bloc dans lovc
	 {
	 	char tab[255];
	 	int suiv;
	 }buff_lvc;
	 
	  FILE *f1;
	  buff_lvc *buff_l,*buff3;
	 
	 
	 
      //table d'index primaire 	 
	   typedef struct table
	   {
	 index *tab;
	    
	   }table;
	     table *t;
	     
	     
	     
	     
	     
	     
	     
	     
	     
	     
	     
	     typedef struct couple//pour servir dans les tables d'index secondaires
	     {
	     	int i;
           struct couple *suiv;
		 }couple;
		 
	     
	     
	     typedef struct table_secondaire
	     {
	     	char full[30];
	     	couple *suiv;
		 }table_secondaire;
		 
		     table_secondaire nom[29];//les table d'index secondaires
    table_secondaire  prenom[32];
	     
	     
	     
	     
	     
	

	 
	 
