   #include"machine.h"
   #include<stdio.h>
        #include<stdio.h>
 
      
       void ecrire_dir(FILE *f,buff *buff1,int i)
       {
       	
       	if(f)
       	{
       		int n;
       		fseek(f,sizeof(buff)*i,SEEK_SET);
			  n =fwrite(buff1,sizeof(buff),1,f);
       		
		   }
	   }
	   void lire_dir(FILE *f,buff *buff1,int i)
	   {
	   	if(f)
	   	{
	   		fseek(f,sizeof(buff)*i,SEEK_SET);
	   		int n=fread(buff1,sizeof(buff),1,f);
		   }
	   }
	   
	   int entete(FILE *f,int n)//n c'est le num du caracteristique du fichier
	   {
	   	if(f)
	   	{
		   lire_dir(f,&buff1,0);		   
	      switch(n)
	      {
	     case 1:return buff1.tab[0].i;//numéro du dernier bloc;
	     break;
	    case 2: return buff1.tab[0].j; //nombre d'enge inserée dans tout le fichier 
	    break;
	   		
	   	
	   		
	      }
        }
	   	
	   	
	   	
	   }
	   void aff_entete(FILE *f,int n,int v)
	   
{
	
	  if(f)
	  {
	
	   
	  	switch(n)
	  	{
	  		case 1:
	  			buff1.tab[0].i=v;//num du dernier bloc
	  			break;
	  			case 2:
	  				buff1.tab[0].j=v;//nbr des eng inseree 
	  				break;
	  				
		  }
		  ecrire_dir(f,&buff1,0);
	  	
	  }
	
}

void rech(FILE *f,int *i,int *j,int *trouv,int  cle)//rechercher dans tnof
{

	if(f)
	{
		*trouv=0;
		
		int n=entete(f,1);// on recupere le numéro du dernier bloc
		int a=1,k;
		while(a<=n && *trouv==0)//on parcour le fichier bloc par bloc 
		{
			
		
			k=0;
			lire_dir(f,&buff1,a);
		  while(k<buff1.nb && *trouv==0)
		  {
		  	if(buff1.tab[k].cle==cle && buff1.tab[k].eff==0)//e existe 
		  	{
		  		*i=a;
		  	     *j=k;
		  	     *trouv=1;
		  	     
			  }
			  else k++;
		  	
		  }
		
			a++;
		
			
		}
		
	}
	
}
	
	
	void insert(FILE *f,index element)//insert dans tof
	{
		if(f)
		{
			
			int i,j,trouv;
			trouv=0;
			rech(f,&i,&j,&trouv,element.cle);
		 
			if(!trouv)
			{
				i=entete(f,1);
				 
			    j=entete(f,2);
			  
			   
				
			
				lire_dir(f,&buff1,i);
				
				if(buff1.nb<40)
				{
					
					buff1.tab[buff1.nb++]=element;
	
			  
		      	}
				
					
				else
				{
					
					i++;
				
					buff1.tab[0]=element;
					buff1.nb=1;
				
						
					
					
				}
				ecrire_dir(f,&buff1,i);
				 //on a cree un nouveau bloc
				   aff_entete(f,1,i);// nbr du dernier bloc
			j++;//nbr eng
		
				
				aff_entete(f,2,j);
				
			}
		}
		
	}
	
	
	

  void  ini_tof(FILE *f) //inialiser l'entete du fichier tof
   {
   	if(f)
   	{
   		aff_entete(f,1,1);
   		aff_entete(f,2,0);
   		buff1.nb=0;
   		ecrire_dir(f,&buff1,1);
	   }
   }


  void afficher(FILE *f)//afficher fichier tof
  {
  
    int i=1,n=entete(f,1),j=0;
    int cpt=0;
    lire_dir(f,&buff1,1);
    
    while(i<=n  )
    {
    	
    	if(j<buff1.nb)
    	{
    			cpt++;
    		printf("***** engestrement  %d\n\n",cpt);
    	
    	printf("**** cle :%d \n **** i:%d\n**** j:%d\n**** eff:%d\n\n\n",buff1.tab[j].cle,buff1.tab[j].i,buff1.tab[j].j,buff1.tab[j].eff);
    	j++;
		}
		else
		{
			i++;
			if(i<=n){
		
		  lire_dir(f,&buff1,i);
		  j=0;
		  	cpt++;
    		printf("***** eng %d\n\n",cpt);
		  	printf("**** cle :%d \n **** i:%d\n**** j:%d\n**** eff:%d\n",buff1.tab[j].cle,buff1.tab[j].i,buff1.tab[j].j,buff1.tab[j].eff);
		  	j++;
		  }
	
		}
    	
	}
    
  }
  
  

	
	
	
	
	
	// T/OVC 
	 
	
void 	lire_dir_tvc(FILE *f,int i,char **buff) //work 
	{
		if(f)
		{
			int n;
			fseek(f,sizeof(char)*255*i,SEEK_SET);
		    n=fread(*buff,sizeof(char)*255,1,f);
		
		    
			
		}
		
	}
void 	ecrire_dir_tvc(FILE *f,int i,char **buff)//work
	{
		
		if(f)
		{
			int n;
				fseek(f,sizeof(char)*255*i,SEEK_SET);
		    n=fwrite(*buff,sizeof(char)*255,1,f);
		}
	}
	
	
void 	extraire_chaine(FILE *f,int *i,int *j,int n,char **ch)//extriare chaine dans le fichier tnovc
	{
		if(f)
		{
			
			
			lire_dir_tvc(f,*i,&buff2);
		
			*ch=(char*)malloc(sizeof(char)*n);
				*ch=(char*)malloc(sizeof(char)*n);
		    int k= *j,z=0;
		    for(;z<n;z++)
		    {
		    if(k<255)
		    {
		    	(*ch)[z]=buff2[k++];
			}
			else
			{
			
				*i+=1;
				lire_dir_tvc(f,*i,&buff2);
				(*ch)[z]=buff2[0];
				k=1;
				
				
			}
		    	
		    	
			}
			*j=k;
			(*ch)[z]='\0';
			
		}
		
		
	}
	
// le premier bloc est comme suit  XXXX|XXX|XXX|
//                                 1    2    3
// 1 le dernier bloc
// 2 la premier position libre dans le dernier bloc
// 3 le nombre d'engestrement
	
	int entete_tvc(FILE *f,int n)//work 
	{
		if(f)
		{
			
				int j;
			lire_dir_tvc(f,0,&buff2);
			  char *ch;
		int i=0;
			switch(n)
			{
				
			case 1:    //le dernier bloc 	
		  
			j=0;
			extraire_chaine(f,&i,&j,4,&ch);
			j=atoi(ch);
		
		  
		     	return j;
			
			
			case 2 :  //  la dernier position libre
		
			j=5;
			extraire_chaine(f,&i,&j,3,&ch);
			j=atoi(ch);
			return j;
		   
		   case 3 :
		   	
			j=9;
			extraire_chaine(f,&i,&j,3,&ch);
			j=atoi(ch);
		 
				return j;
		  
				
				
			}
			
		}
		
		
	} 
	
	
	void aff_entete_tvc(FILE *f,int i,int n)//work 
	{
		if(f)
		{
		
			int j,k,num_chiffre;
			char ch[4];
			lire_dir_tvc(f,0,&buff2);
			switch(i)
			{  
			
			case 1:
			
				j=0;
				  num_chiffre = snprintf(NULL, 0, "%d", n);
				  if(num_chiffre==1) sprintf(ch,"000%d",n);
				  if(num_chiffre==2) sprintf(ch,"00%d",n);
				  if(num_chiffre==3) sprintf(ch,"0%d",n);
				  if(num_chiffre==4) sprintf(ch,"%d",n);
			
				for(k=0;k<4;k++)
				buff2[k]=ch[k];
				buff2[k]='|';
				ecrire_dir_tvc(f,0,&buff2);
				break;
				
				
			case 2:
					
			   j=0;
			   num_chiffre = snprintf(NULL, 0, "%d", n);
				  if(num_chiffre==1) sprintf(ch,"00%d",n);
				  if(num_chiffre==2) sprintf(ch,"0%d",n);
				 if(num_chiffre==3) sprintf(ch,"%d",n);
			    
			   	for(k=5;k<8;k++) 
				buff2[k]=ch[j++];
				buff2[k]='|';
			
				ecrire_dir_tvc(f,0,&buff2);
		    break;
			case 3:	
			 j=0;
			  num_chiffre = snprintf(NULL, 0, "%d", n);
			if(num_chiffre==1) sprintf(ch,"00%d",n);
			 if(num_chiffre==2) sprintf(ch,"0%d",n);
		    if(num_chiffre==3) sprintf(ch,"%d",n);
		    
			    	for(k=9;k<12;k++) 
				buff2[k]=ch[j++];
				buff2[k]='|';
			
				ecrire_dir_tvc(f,0,&buff2);
			 
		}
	}
}

 void ecrire_chaine(FILE *f,int *i,int *j,int n,char *ch)//ecrire chaine pour fichier tnovc
 {
 int bloc =*i;
 	lire_dir_tvc(f,*i,&buff2);
 	
 	int k=0;
	 
 
	 
	 //on souvegarde le numdu dernier bloc
	 
 	for(;k<n;k++)
 	{
 		if(*j<255)
 		{
 			
 			buff2[*j]=ch[k];
 			*j+=1;
		 }
		else
		{
			ecrire_dir_tvc(f,*i,&buff2);
			*i+=1;
			buff2[0]=ch[k];
			*j=1;
			
		}
	
 	
 		
 		
	 }
	 	ecrire_dir_tvc(f,*i,&buff2);
	 if(bloc==entete_tvc(f,1))
	 {
	 	aff_entete_tvc(f,1,*i);
	 	aff_entete_tvc(f,2,*j);
	 }
	
	 
}


 	
 	
 
	void ini(FILE *f)//inialiser le fichier tovc
	{
		int i=0;
		for(;i<15;i++)buff2[i]='0';
		
		ecrire_dir_tvc(f,0,&buff2);
		aff_entete_tvc(f,1,1);
		
		
		
	}
void 	lire_bloc(FILE *f,int i,char **buff)
	{
		lire_dir_tvc(f,i,buff);
		if(entete_tvc(f,1)==i) (*buff)[entete_tvc(f,2)]='\0';
	
		else (*buff)[255]='\0';
		
	}
void 	ecrire_bloc(FILE *f,int i,char **buff)//commer lire_dir mais avec des exeptions
	{
		
		if(entete_tvc(f,1)==i)
		{
		aff_entete_tvc(f,2,strlen(*buff));
		}
		ecrire_dir_tvc(f,i,buff);
	}
	// la machine abstract pour L/OVC 
	//lire_dir_tvc ,ecrire_dir_tvc, aff_entete_lvc,entete_lvc,ecrire_chaine_lvc,extraire_chaine_lvc,chargement_ini
	
	void ecrire_dir_lvc(FILE *f,int i,buff_lvc **buff)//work
	{
		if(f)
		{
			int n;
		fseek(f,sizeof(buff_lvc)*i,SEEK_SET);
		n=fwrite(*buff,sizeof(buff_lvc),1,f);
		}	
	}
	
	
	void lire_dir_lvc(FILE *f,int i,buff_lvc **buff)//work
	{
		if(f)
		{
			int n;
		fseek(f,sizeof(buff_lvc)*i,SEEK_SET);
		n=fread(*buff,sizeof(buff_lvc),1,f);
		}
	}

		////


   void  extraire_chaine_lvc(FILE *f,int *i,int *j,int n,char **ch)//work as expected 
    {
    if(f)
	{
		
  		lire_dir_lvc(f,*i,&buff_l);
  
			
	
			*ch=(char*)malloc(sizeof(char)*n);
			
  		*ch=(char*)malloc(sizeof(char)*n);
  	
  		
  			//	*ch=(char*)malloc(sizeof(char)*n);
  			
		    int k=*j,z=0;
  		    for(z=0;z<n;z++)
		    {
		    
		    if(k<255)
 		    {
 		    
		    	(*ch)[z]=buff_l->tab[k++];
		    
		    
  			}
			else
  			{
			
				*i=buff_l->suiv;
				lire_dir_lvc(f,*i,&buff_l);
				(*ch)[z]=buff_l->tab[0];
			     k=1;
				
				
			}
		    	
		    	
			}
			*j=k;
			(*ch)[z]='\0';
		
			
			
    	}
	  }
	  

	
	  
	  	// entete dans le bloc 0  organizé comme suit xxxx|xxx|xxx|xxx
	 //                                                1   2   3   4
	 //1: le num du la tete de la liste
	 //2:le dernier position libre 
	 //3:le num du dernier bloc
	int entete_lvc(FILE *f,int n)
	{
		if(f)
		{
			lire_dir_lvc(f,0,&buff_l);
			  char *ch;
			  int j;
			  int i=0;
			switch(n)
			{
				case 1:
					j=0;
					extraire_chaine_lvc(f,&i,&j,4,&ch);
				
				j=atoi(ch);
				return j;						
					
			    case 2:
			    	j=5;
			extraire_chaine_lvc(f,&i,&j,3,&ch);
			
			j=atoi(ch);
			return j;
	
			case 3:
				j=9;
				extraire_chaine_lvc(f,&i,&j,4,&ch);
				
				j=atoi(ch);
				return j;
				
			
				
			    	
			    	
						
			}
		}
	}
	
	
	
			void aff_entete_lvc(FILE *f,int i,int n)//work
		{
			if(f)
			 {
			 	int j,k,num_chiffre;
			char ch[4];
			lire_dir_lvc(f,0,&buff_l);
			
			 	switch(i)
			 	 {
			 	 case 1:
			 	 		j=0;
				  num_chiffre = snprintf(NULL, 0, "%d", n);
				
				  if(num_chiffre==1) sprintf(ch,"000%d",n);
				  if(num_chiffre==2) sprintf(ch,"00%d",n);
				  if(num_chiffre==3) sprintf(ch,"0%d",n);
				  if(num_chiffre==4) sprintf(ch,"%d",n);
	
				for(k=0;k<4;k++)
			buff_l->tab[k]=ch[k];
				buff_l->tab[k]='|';
				ecrire_dir_lvc(f,0,&buff_l);
				break;
			
			
			case 2:
				j=0;
			 num_chiffre = snprintf(NULL, 0, "%d", n);
				
				  if(num_chiffre==1) sprintf(ch,"00%d",n);
				  if(num_chiffre==2) sprintf(ch,"0%d",n);
				  if(num_chiffre==3) sprintf(ch,"%d",n);
				  
	
				for(k=5;k<8;k++)
			buff_l->tab[k]=ch[j++];
				buff_l->tab[k]='|';
				ecrire_dir_lvc(f,0,&buff_l);
				break;
			
			case 3:
					j=0;
				  num_chiffre = snprintf(NULL, 0, "%d", n);
				
				  if(num_chiffre==1) sprintf(ch,"000%d",n);
				  if(num_chiffre==2) sprintf(ch,"00%d",n);
				  if(num_chiffre==3) sprintf(ch,"0%d",n);
				  if(num_chiffre==4) sprintf(ch,"%d",n);
	
				for(k=9;k<13;k++)
			buff_l->tab[k]=ch[j++];
				buff_l->tab[k]='|';
				ecrire_dir_lvc(f,0,&buff_l);
				break;
					
				
			 	    	
			 	 
			 	 	
			 	 	
				  }
			 }
			
			
			}	
	
	
	
	
	
	
	
	
	  void ecrire_chaine_lvc(FILE *f,int *i,int *j,int n,char *ch)//nriglouha 
	  {
	  	int bloc =*i;
	  	int i1;
	  	int dernier_bloc=entete_lvc(f,3);
	  	if(dernier_bloc==*i) i1=alloc_bloc(f);
	  
	  	lire_dir_lvc(f,*i,&buff_l);
	  	int k=0;
	  	for(;k<n;k++)
	  	{
	  			  
	  		if(*j<255)
	  		{
		
	  		buff_l->tab[*j]= ch[k];
	  	
	  		*j+=1;
	  	}
	  		 else
	  		 {
	  		 
	  		    if(buff_l->suiv==-1)
	  		 	{
	  		 		
	  		 	buff_l->suiv=i1;
	  		 		
				   }
	  		 	
	  		 	buff_l->tab[*j]='\0';
	  		 	ecrire_dir_lvc(f,*i,&buff_l);
	  		 	
	  		   *i=buff_l->suiv;
	  		 	buff_l->tab[0]=ch[k];
	  		 	*j=1;
			   }
		  }
		  
		  
		  if(dernier_bloc== bloc)// on a allouer un nouveau bloc
		  {
		  	buff_l->suiv=-1;
		  	
		  		  ecrire_dir_lvc(f,*i,&buff_l);
		  		  if(dernier_bloc!=*i)
		        	aff_entete_lvc(f,3,*i);
	
		  	aff_entete_lvc(f,2,*j);
		  	
		  }
		  else
		  {
		  	
		  	ecrire_dir_lvc(f,*i,&buff_l);
		  	
			  	
		  }
		  
		  
		
	  	
	  	
	  	
	  	
	  }
	


	
	void ini_lvc(FILE *f)//inialiser le fichier lovc
	{
		if(f)
		 {

		int i=0;
		for(;i<15;i++)buff_l->tab[i]='0';

		 	aff_entete_lvc(f,1,1);
		 	aff_entete_lvc(f,2,0);
		 	aff_entete_lvc(f,3,1);
		 	ecrire_dir_lvc(f,0,&buff_l);
		 }
	}
	int alloc_bloc(FILE *f)
	{
		if(f)
		{
			return entete_lvc(f,3)+1;
			
		}
		
		}
		

		

   
     void insert_lvc(FILE *f,eng e)
     {
     	int i;
     	int j;
    char full_name[70];//nom prenom
     	if(e.cle>=0){
		 	sprintf(full_name,"%s %s",e.nom,e.prenom);
		 
     	char ch[4],eff[1]="|",taille[3];
     	int num_chiffre1,num_chiffre2,n;
     	n=strlen(full_name);
     		 num_chiffre2 = snprintf(NULL, 0, "%d", n);
				 if(num_chiffre2==1) sprintf(taille,"00%d",n);
				  if(num_chiffre2==2) sprintf(taille,"0%d",n);
				 if(num_chiffre2==3) sprintf(taille,"%d",n);
			
     	 num_chiffre1 = snprintf(NULL, 0, "%d", e.cle);
				 if(num_chiffre1==1) sprintf(ch,"000%d",e.cle);
				  if(num_chiffre1==2) sprintf(ch,"00%d",e.cle);
				 if(num_chiffre1==3) sprintf(ch,"0%d",e.cle);
				 if(num_chiffre1==4) sprintf(ch,"%d",e.cle);
			i=entete_lvc(f,3);
			j=entete_lvc(f,2);
				ecrire_chaine_lvc(f,&i,&j,3,taille);
			
					ecrire_chaine_lvc(f,&i,&j,1,eff);
		ecrire_chaine_lvc(f,&i,&j,4,ch);
	
		ecrire_chaine_lvc(f,&i,&j,1,eff);
	     eff[0]=e.eff+48;
		ecrire_chaine_lvc(f,&i,&j,1,eff);
		eff[0]='|';

		ecrire_chaine_lvc(f,&i,&j,1,eff);

		ecrire_chaine_lvc(f,&i,&j,strlen(full_name),full_name);
			eff[0]='#';	
				ecrire_chaine_lvc(f,&i,&j,1,eff);
		 
     	
     	
     }
	 }
	 
	  void lire_bloc_lvc(FILE *f,int i,buff_lvc **buff)
	 {
	 	if(f)
	 	{
	 		int n;
	 		fseek(f,sizeof(buff_lvc)*i,SEEK_SET);
	 		n= fread(*buff,sizeof(buff_lvc),1,f);
	 		if(i==entete_lvc(f,3)) (*buff)->tab[entete_lvc(f,2)]='\0';
	 		
		 }
	 }
	
	//remplir le fichier f (l/ovc) avec n donne genere aletoirement a partir d'une liste predefini 
	void chargement_iniale(FILE *f, int n)
	{
     ini_lvc(f);
     //list of names
        char names[32][30]={"ABDALLAH","RAYHANE","KADER","AHMED","BASSEM","ISAM","KAMAL","MAYSA","ZINEB",
		"MUSTAPHA","MOHAMED","NADIA","SAMIR","SAMI","HOUDAIFA","MALIK","MONCIF","AMAR","OMAR","IKRAM",
		"BASMALA","DJINANE","INES","LINA","KARIMA","KHALIL","OUSSAMA MOHAMED","IMAN","ANFAL","NADIR","KHALED","MAHMOUD"};
		//list of fimilly names
		 char familly_names[29][30] = {
        "BENALI", "BOUDIAF", "BOUZID", "CHAOUCH", "DJELLOUL", "FERHAT", "GANA", "HADDAD", "BENZAMA", "KHODJA",
        "MOKRANE", "OUYAHIA", "REZKI", "MENDAS", "TAIBI", "YAHIAOUI", "ZIDANE",
        "AMROUCHE", "BELKACEM", "DJANADI", "BENSALAM", "BOUTEFLIKA", "CHAREF", "ELALIA",
        "MISSOUM", "GOURARI", "HAMOUM",
        "TOUMI", "MAZIZ"};

  int i=1;
  int p=0;
  eng e;
     for(;i<=n;i++){
    int cle=p*10+rand()%10;
    p++;
   int eff=rand()%2;
   int prenom=rand()%32;
  
 int nom=rand()%29;
 
   
   sprintf(e.prenom ,"%s",names[prenom]);
  
     sprintf(e.nom,"%s",familly_names[nom]);
     
    e.cle=cle;
    e.eff=eff;
    insert_lvc(f,e);

     
     
     
	}
    }
    
    
    
      	void extraire(FILE *f,int *i,int *j,char *ch)//extraire eng a partir du fichier lnovc et gere le  cheveuchement 
	 	{
	 	int k=0;
		 lire_dir_lvc(f,*i,&buff_l);	
	 	if(*j==255)
	 	{
	 		*j=0;
	 		*i=buff_l->suiv;
		 }
		 if(*j==0)
		 lire_dir_lvc(f,*i,&buff_l);
		 while(buff_l->tab[*j]!='#')
		 {
		 	ch[k++]=buff_l->tab[*j];
		 	*j+=1;
		 	if(*j>=255)
		 	{
		 		*j=0;
		 		*i=buff_l->suiv;
		 		lire_dir_lvc(f,*i,&buff_l);
			 }
		 	
		 	
		 }
		 ch[k]=buff_l->tab[*j];
		 *j+=1;
		 	if(*j>=255)
		 	{
		 		*j=0;
		 		*i=buff_l->suiv;
		 	
			 }
			 ch[k+1]='\0';
		 	
		 
	 		
	 		
	 		
	 		
	 		
	 		
		 }
		 
	void extraire_tvc(FILE *f,int *i,int *j,char *ch)//extraire eng et gere le cheveuchement 
	 	{
	 	int k=0;	
	 	if(*j==255)
	 	{
	 		*j=0;
	 		*i+=1;
		 }
		 
		 lire_dir_tvc(f,*i,&buff2);
		 while(buff2[*j]!='#')
		 {
		 	ch[k++]=buff2[*j];
		 	*j+=1;
		 	if(*j>=255)
		 	{
		 		*j=0;
		 		*i+=1;
		 		lire_dir_tvc(f,*i,&buff2);
			 }
		 	
		 	
		 }
		 ch[k]=buff2[*j];
		 *j+=1;
		 	if(*j>=255)
		 	{
		 		*j=0;
		 		*i+=1;
		 	
			 }
			 ch[k+1]='\0';
		 	
		 
	 		
	 		
	 		
	 		
	 		
	 		
		 }
	 	
	 	

		
	//creer un fichier t/ovc a partir du fichier 
	void LNOVC_TO_TNOVC(FILE *f1,FILE *f2)
	{
		ini(f2);
		int i,i1,j,j1,n,k,taille;
		int a1,b1;
		a1=1;
		b1=0;
		int cpt=0;
		i=entete_lvc(f1,1);
		n=entete_lvc(f1,3);
		k=entete_lvc(f1,2);
		
	
		j=j1=0;
		char ch[255];
		while(i!=n || (i==n && j<k))
		{
		
		extraire(f1,&i,&j,ch);
	
		if(ch[9]=='0')
		{
			
		ecrire_chaine(f2,&a1,&b1,strlen(ch),ch);
			
		}

     	}
	 	
		
			
			
			
		}


	//l/ovc to t/of
	void LNOVC_TO_TNOF(FILE *f,FILE *f1)
	{
		
		if(f && f1 )
		{
			ini_tof(f1);
			
			int i,i1,j,j1,n,k,taille,a;
			index element;
			i=entete_lvc(f,1);
			n=entete_lvc(f,3);
			k=entete_lvc(f,2);
	   char cle[4];
			
		
			j=0;
		char ch[255];
			while(i!=n || (i==n && j<k) )
			{
			
				i1=i;
				j1=j;
				extraire(f,&i,&j,ch);
			
	
				//on convertit la cle en entier 
				for(a=4;a<8;a++)cle[a-4]=ch[a];
				element.cle=atoi(cle);
				
				// on recupere j et i 
				element.i=i1;
				element.j=j1;
				// on recupere le  champ effacé
				element.eff=ch[9]-48;
			
				insert(f1,element);				
				
				
			
	
				
			}
			
			
			
			
			
			
		}
		
	}


    void cree_table_index(FILE *f, table **t )
    {
    	int k=entete(f,2);
    	int n=entete(f,1);
    	int i=1;
    	int j1=0,j2=0;
        *t=(table*)malloc(sizeof(table));
    
     ( **t).tab=(index*)malloc(sizeof(index)*k);
     
        lire_dir(f,&buff1,1);
        while(i<=n)
        {
        	if(j1<buff1.nb)
        	{
        	 (**t).tab[j2]=buff1.tab[j1];
       
        		j2++,j1++;
			}
			else
			{
				j1=0;
				i++;
				if(i<=n){
				
				lire_dir(f,&buff1,i);
				(**t).tab[j2]=buff1.tab[j1];
				j2++,j1++;
			}
				
				
			}
        	
        	
        	
		}
        
        
    
    	
    	
	}
	
	//la reorganization ****
	
	int nbr_eng_non_supp(table *t)//apres le tri du champ eff on appelle cette fonction et on tri la table selon i
	{
		int i=0;
		while(t->tab[i].eff==0) i++;
		return i;
		
	}
	
// Comparison function for qsort by 'i' field
int compareByI(const void *a, const void *b) {
    return ((index*)a)->i - ((index*)b)->i;
}

// Comparison function for qsort by 'eff' field
int compareByEff(const void *a, const void *b) {
    return ((index*)a)->eff - ((index*)b)->eff;
   }    
	
	
	  void tri(table *t,int n,int end)//tri la table si end=1 tri selon i
	                                    //end=0 tri selon eff
	  
	  {
	  	  
	  	 
    if(n==1)
    // Sort the array by 'i'
    qsort(t->tab, end, sizeof(t->tab[0]), compareByI);

   else     
   qsort(t->tab, end, sizeof(t->tab[0]), compareByEff);
	  	
	  	
	  	
	  }

	







	  void reorganization(FILE *f,FILE *f3,table *t,int taille_t)
	  {
	  	ini_lvc(f3);
	  	tri(t,2,taille_t);
	  	
	  	int n=nbr_eng_non_supp(t);
	  	tri(t,1,n);
	
         int i,i1,j1,j,bloc=t->tab[0].i,
         taille;
         int ins1,ins2;
         lire_dir_lvc(f,bloc,&buff_l);
         ins1=1;
         ins2=0;
         i=0;
         char ch[255];
        while(i<n)
         {
         	   
         	if(bloc==t->tab[i].i)
         	{
         		i1=bloc;
         		j1=t->tab[i].j;
			 extraire(f,&i1,&j1,ch);//on extraire un eng 
			 
			  ecrire_chaine_lvc(f3,&ins1,&ins2,strlen(ch),ch);
				i++;
			 }
			 
			 else
			 {
			 
			 bloc=t->tab[i].i;
			 lire_dir_lvc(f,bloc,&buff_l);
			 
		}
         	
         	
		 }
	  	
	  	
	  }
	 
	 
	 
	 
	 
	 
	 
	 void afficher_table_index(table *t,FILE *f1)
	 {
	 	int i=0;
	   int n=entete(f1,2);
	 	printf("\nl'affichage de la table d'index\n");
	 	printf("cle  |eff|i |  j | \n");
	 	for(;i<n;i++)
	 	{
	 	
	 	printf("%d  | %d | %d | %d |\n",t->tab[i].cle,t->tab[i].eff,t->tab[i].i,t->tab[i].j);
		 printf("----------------------------\n");	
	 		
	 		
	 		
		 }
	 	
	 	
	 	
	 	
	 	
	 }
	 
	 void	afficher_fichier(FILE *f)//l'affichage du fichier l/ovc
	{
		
		printf("\n\n\n*****l'affichage du fichier L/OVC *************\n\n\n");
			int i,i1,j,j1,n,taille,cpt,k;
			cpt=0;
		
			i=entete_lvc(f,1);
			n=entete_lvc(f,3);
			k=entete_lvc(f,2);
			char cle[4];
			
			char ch[255];
			j=0;
			while(i!=n || (i==n && j<k) )
			{
			
				extraire(f,&i,&j,ch);
			printf("l'engestrement num %d  :  %s\n",++cpt,ch);
	}
		
	
		
		
		
	}
	 
	 
	 void afficher_fichier_tovc(FILE *f)
	 {
	 	int i=1,k=entete_tvc(f,1);
		 int n=entete_tvc(f,2),
		 j=0;
	 	int i1,j1,taille;
	 	
	 		int cpt=0;
	 	
	 		printf("\n\n\n********l'affichage du fichier T/OVC \n\n");
	 		char ch[255];
	 	while(i<k || (i==k && j<n))
	 	{
	 		
	 	
				extraire_tvc(f,&i,&j,ch);
			printf("l'engestrement num %d  :  %s\n",++cpt,ch);

	 		
	 		
		 }
	 	
	 }
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 void MENU(FILE *f,FILE *f2, FILE *f1, FILE *f3)
	 {
	 	int choix,n,choix2,choix3,commance;
	 	int i,j;
		 
	 	printf("**************TP DU MODULE SFSD*************\n\n\n");
	 	
	 	printf("********************MISSOUM ABDALLAH G02*******************\n\n");
	 printf("************USER GUIDE**********\n\n\n\n");
    printf(" **1 CLE <=9999 CAR   LENGTH(CLE)=4  DONC LE NOMBRE DES DONNES DOIT ÊTRE INFERIEUR OU EGAL À 1000\n\n");
    printf("\n **2 LA CLE, LE CHAMP EFFACE, LE NOM, LE PRENOM SONT GÉNÉRÉS ALÉATOIREMENT D'APRES UNE LISTE BIEN DÉFINIE (VOIR CHARGEMENT_INITIALE POUR PLUS DE DETAIL)\n\n");
    printf("\n **3 CHAQUE ENREGISTREMENT DANS L/OVC EST CONSTITUE COMME SUIT XXX|XXXX|X|NOM PRENOM#....\n");
    printf("LE PREMIER CHAMP EST RESERVE POUR LA TAILLE DU NOM+PRENOM AUTREMENT DIT TAILLE=STRLEN(NOM+" "+PRENOM)\n");
    printf("LE DEUXIEME CHAMP EST POUR LA CLE\n");
    printf("LE TROISIEME CHAMP EST LE CHAMP EFFACE  EFF=0 DONNE NON SUPPRIMÉE  ,EFF=1 ON A SUPPRIMÉ LA DONNÉE\n\n");
 do{
 
	   	 printf("\n\n****LANCER LE PROGRAM\n 1/OUI\n2/NON \n");
	   scanf("%d",&commance);
	   
      }while(commance==2);
      system("cls");
	    
	        do
	        {
	        
	        			printf("\n--------------------------------\n");
	        		printf("1/TESTER LE TP1\n");
	        			printf("2/TESTER LE TP2\n");
	        				printf("3/QUIT\n\n "); 
	        				printf("***DONNER VOTRE CHOIX  ::");
	        				scanf("%d",&choix);
	        	switch(choix)
	        	{
	              case 1:
	              		printf("\n--------------------------------\n");
	        		printf("CHARGEMENT DU FICHIER L/OVC AVEC N DONNE GENERE ALETIOREMENT \n");
	        		printf("\nDONNER LE NOMBRE DES DONNES :");
	        		scanf("%d",&n);
	        		chargement_iniale(f,n);
	        		do{
					
	        				printf("\n--------------------------------\n");
	        		printf("1/FRACTIONNER LE FICHIER L/OVC A T/OF\n\n");
	        		printf("2/FRACTIONNER LE FICHIER L/OVC A T/OVC\n\n");
	        			printf("3/AFFICHER  LE FICHIER L/OVC\n\n");
	        				printf("4/RECONSTRUIRE LE FICHIER L/OVC AVEC N DONNE ALETOIRE \n\n");
	        					printf("5/RETOUR \n\n");
	        				printf("***DONNER VOTRE CHOIX  ::");
	        				scanf("%d",&choix2);
	        				printf("\n");
	        				switch(choix2)
	        				{
	        					case 1 :
	        						LNOVC_TO_TNOF(f,f2);
	        						afficher(f2);
	        						break;
	        					case 2:
	        						LNOVC_TO_TNOVC(f,f1);
	        						afficher_fichier_tovc(f1);
	        					break;
	        					case 3:
	        						afficher_fichier(f);
	        						break;
	        					case 4 :
	        						printf("\nDONNER LE NOMBRE DES DONNES :");
	        		                 scanf("%d",&n);
	        		                chargement_iniale(f,n);
	        						break;
	        				
							}
							
							
				}while(choix2!=5);
	        		break;
					
					
				case 2:
							printf("\n--------------------------------\n");
	        		printf("CHARGEMENT DU FICHIER L/OVC AVEC N DONNE GENERE ALETIOREMENT \n");
	        		printf("\nDONNER LE NOMBRE DES DONNES :");
	        		scanf("%d",&n);
	        		chargement_iniale(f,n);
					LNOVC_TO_TNOF(f,f2);
					do
					{
					
								printf("\n--------------------------------\n");
	        		printf("1/CHARGER LE FICHIER F1 DANS UNE TABLE DANS LA MEMOIRE CENTRALE AVEC L'AFFICHAGE DE LA TABLE \n\n");
	        		printf("2/FAIRE LA REORGANIZATON DU FICHIER F L/OVC ET SON AFFICAHGE \n\n");
	        				printf("3/AFFICHAGE LA TABLE D'INDEX APRES LA REORGANIZATION \n\n");
	        			printf("4/RECHARCHER UNE PERSONNE PAR NOM ET PRENOM  \n\n");
	        			printf("5/RECHERCHER PAR PRENOM \n\n");
	        			printf("6/RECHERCHER PAR NOM \n");
	        			printf("7/RECONSTRUIRE LE FICHIER L/OVC AVEC N DONNE ALETOIRE \n\n");
	        			printf("8/AFFICHER LE FICHIER L/OVC\n");
	        			printf("9/FRACTIONNER LE FICHIER L/OVC TO T/OVC ET SON AFFICHAGE \n\n");
					    printf("10/RETOUR \n");
				
			     	       printf("***DONNER VOTRE CHOIX  ::");
	        				scanf("%d",&choix2);
	        		switch(choix2)
	        		{
	        			case 1:
	        				cree_table_index(f2,&t);
	        				afficher_table_index(t,f2);
	        				break;
	        			case 2:
	        				cree_table_index(f2,&t);
	        				 i=entete(f2,2);
	        				reorganization(f,f3,t,i);
	        				printf("\n*****L'AFFICHAGE DU FICHIER ORGANISE \n\n");
	        				afficher_fichier(f3);
	        				break;
	        			case 3:
	        				cree_table_index(f2,&t);
	        				 i=entete(f2,2);
	        				reorganization(f,f3,t,i);
	        				afficher_table_index(t,f2);
	        				break;
	        			case 4:
	        				
	        				  inialiser(nom,29);
                              inialiser(prenom,32);
                              cree_table_index(f2,&t);
                               i=entete(f2,2);
                               remplir_table_secondaire(f,nom,prenom,t,i);
	        				rechercher_nom_prenom(f,nom,prenom,t);
	        				break;
	        				case 5:
	        				inialiser(nom,29);
                            inialiser(prenom,32);
                            cree_table_index(f2,&t);
                            i=entete(f2,2);
                            remplir_table_secondaire(f,nom,prenom,t,i);
                            rech_selon_prenom(f,prenom,t);
	        			   break;
	        			   case 6:
	        			   	inialiser(nom,29);
                            inialiser(prenom,32);
                            cree_table_index(f2,&t);
                            i=entete(f2,2);
                            remplir_table_secondaire(f,nom,prenom,t,i);
                            rech_selon_nom(f,nom,t);
	        			   	
	        					break;
	        		    case 7:
	        		    	
	        		    	printf("CHARGEMENT DU FICHIER L/OVC AVEC N DONNE GENERE ALETIOREMENT \n");
	        		       printf("\nDONNER LE NOMBRE DES DONNES :");
	        		        scanf("%d",&n);
	        		      chargement_iniale(f,n);
					         LNOVC_TO_TNOF(f,f2);
	        		    	break;
	        		    case 8:
	        		    	afficher_fichier(f);
	        		    	break;
	        		    case 9:
	        		    	LNOVC_TO_TNOVC(f,f1);
	        		    	afficher_fichier_tovc(f1);
	        		    
	        				
	        			 		
	        				
	        			
					}
	              	
	              	
	              	
	              }while(choix2!=10);
	              	break;
	            case 3:
				system("cls");
				printf("\n\n*************J'ESPERE MADAME QUE VOUS AVEZ AMIEZ LE TP MES SALUTATION MISSOUM ABDALLAH G02*******");
				break;
	              	
	              	
	              	
	       			
	        	
	        
				}
				
			
				
			
	        	
			}while(choix!=3); 		
	 		
		 }
	 	
	 	
	
	 	
	 	


 
   void extraire_nom_ou_prenom(char *ch,char *result,int n)//extriare  ( nom si n=0
                                                                //     (prenom si n=1
   {
   	char c;
   	int i,j,k=0;
   	
   	
   	j=11;
   	while(ch[j]!=' ')
   	{
   		if(n==0)
   		result[k++]=ch[j];
   	j++;
	   }
	   j++;
	if(n==1)
	{
		while(ch[j]!='#')
	
		result[k++]=ch[j++];
	

	}
	result[k]='\0';
   		
	  
	  
   	
   }

	 void inialiser(table_secondaire *t,int n)//iniliser la table d'index secondaires (n=32 la taille du list des prenom 
	                                                                                //(n=29 la taille du list des noms 
	 {
	 	int i=0;
	 	for(;i<n;i++)
	 	{
	 		strcpy(t[i].full,"");
	 		t[i].suiv=NULL;
	 		
	 		
	 		
		 }
	 	
	 	
	 }
	 void remplir_table_secondaire(FILE *f,table_secondaire *t1,table_secondaire *t2,table *t ,int n)//n=taille(t)
	 {
	 	int i=0,i1,j1,i2=0,i3=0;
	 	int j2,k;
	 	couple *p,*q,*l;
	 	char ch[255],result[30];
	 	for(;i<n;i++)
	 	{
	 		i1=t->tab[i].i;
	 		j1=t->tab[i].j;
	 		extraire(f,&i1,&j1,ch);
	 	
	 	
	 		 extraire_nom_ou_prenom(ch,result,0);
	 		 j2=0;
	 		 while(j2<29)
	 		 {
	 		 	
	 		 	if(strcmp(t1[j2].full,"")==0 || strcmp(t1[j2].full,result)==0)
				   break;
	 		 	j2++;
	 		 	
			  }
			  if(strcmp(t1[j2].full,"")==0)
			  {
			  	strcpy(t1[j2].full,result);
			  
			  }
			  
			p=(couple*)malloc(sizeof(couple));
			p->i=i;
			l=t1[j2].suiv;
			p->suiv=l;
			t1[j2].suiv=p;
		
			
			 
			  	 extraire_nom_ou_prenom(ch,result,1);
	 		 j2=0;
	 		 while(j2<32)
	 		 {
	 		 	if(strcmp(t2[j2].full,"")==0 || strcmp(t2[j2].full,result)==0)
				   break;
	 		 	j2++;
	 		 	
			  }
			  if(strcmp(t2[j2].full,"")==0)
			  {
			  	strcpy(t2[j2].full,result);
			  }
			  
			p=(couple*)malloc(sizeof(couple));
			p->i=i;
			l=t2[j2].suiv;
			p->suiv=l;
			t2[j2].suiv=p;
			 
			  
	 		 
	 		 
	 		 
	   
	 		
	
	 		
		 }
	 	
	 	
	 	
	 	
	 	
	 }
    couple *rechercher_nom(table_secondaire *t,char *nom1)//rechercher nom et retourne la tete de la list
    
    {
      int i=0;
	  while(i<29)
	  {
	  	if(strcmp(t[i].full,nom1)==0) return t[i].suiv;
	  	i++;
	  	
	  	
		  }	
		  if(i==29) return NULL;
    	
    	
	}
	
	    couple *rechercher_prenom(table_secondaire *t,char *prenom1)//rechercher le prenom et retourne la tete de la list
    
    {
      int i=0;
	  while(i<32)
	  {
	  	if(strcmp(t[i].full,prenom1)==0) return t[i].suiv;
	  	i++;
	  	
	  	
		  }	
		  if(i==32) return NULL;
    	
    	
	}
	 
	 
	 void rechercher_nom_prenom(FILE *f,table_secondaire *t1,table_secondaire *t2,table *t)
	 
	 {
	 	int i,j;
	 	char nom1[30],prenom1[30],ch[255];
	 	couple  *p,*q,*l;
	 	printf("\nDONNER LE NOM DE FAMILLE RECHERCHE :");
	 	scanf("%s",nom1);
	 	printf("\nDONNER LE PRENOM DE LA PERSONNE RECHERCHE :");
	 	scanf("%s",prenom1);
	 	printf("\n\n");
	 	convert_to_upper(prenom1);
	 	convert_to_upper(nom1);
	 	p=rechercher_nom(t1,nom1);
	 	q=rechercher_prenom(t2,prenom1);
	 	if(!p || !q ) printf("IL YA PAS DES PERSONNES AVEC CE NOM  %s  ET PRENOM  %s",nom1,prenom1);
	 	else
	 	{
	 		l=q;
	 		while(p)
	 		{
	 			q=l;
	 			while(q)
	 			{
	 			  	if(p->i==q->i)
	 			  	{
	 			  		i=p->i;
	 			  		j=t->tab[i].j;
	 			  		i=t->tab[i].i;
	 			  		extraire(f,&i,&j,ch);
	 			  		puts(ch);
	 			  	
	 			  		
	 			  		
				}
				q=q->suiv;
	 				
	 				
				 }
				 p=p->suiv;
	 			
	 			
			 }
	 		
		 }
	 	
	 	
	 	
	 	
	 	
	 	
	 	
	 	
	 }
	 
	void rech_selon_prenom(FILE *f,table_secondaire *t1,table *t)//rechercher un prenom et afficher la list
	{
		couple *p;
		int i,j;
		int cpt=0;
		char prenom0[30];
		char ch[255];
		printf("\n DONNER LE PRENOM ::");
		scanf("%s",prenom0);
		convert_to_upper(prenom0);
		p=rechercher_prenom(t1,prenom0);
		if(!p) printf("DANS LE FICHIER CE PRENOM N'EXISTENT PAS");
		else
		{
			printf("\n\nLES ENGESTREMENT QUI ONT LE PRENOM %s SONT ::\n",prenom0);
		while(p){
		
		i=t->tab[p->i].i;
		j=t->tab[p->i].j;
		extraire(f,&i,&j,ch);
		puts(ch);
		p=p->suiv;
	
			
			
		}
		}
		
		
	}
		void rech_selon_nom(FILE *f,table_secondaire *t1,table *t)//rechercher un nom et afficher la list
	{
		couple *p;
		int i,j;
		int cpt=0;
		char nom0[30];
		char ch[255];
		printf("\n DONNER LE NOM ::");
		scanf("%s",nom0);
		convert_to_upper(nom0);
		p=rechercher_nom(t1,nom0);
		if(!p) printf("DANS LE FICHIER CE NOM N'EXISTENT PAS");
		else
		{
			printf("\n\nLES ENGESTREMENT QUI ONT LE NOM %s SONT ::\n",nom0);
		while(p){
		
		i=t->tab[p->i].i;
		j=t->tab[p->i].j;
		extraire(f,&i,&j,ch);
		puts(ch);
		p=p->suiv;
	
			
			
		}
		}
		
		
	}
	
	
	
	void convert_to_upper(char *inputString) //quand user recherche son nom ou prenom on le convertit to uppercase 
	{
    while (*inputString) {
        *inputString = toupper((unsigned char)*inputString);
        inputString++;
    }
}
	 /*
	 C'EST TOUT MERCI DE VOTRE ATTENTION
	 */
	 
	 
	 
	 
	   
