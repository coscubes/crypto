#include<fstream>
#include<iostream>
#include<ostream>
#include<stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>

using namespace std;

   class Vigenere
   {
       public:
            string key;
            Vigenere(string key)
            {
                for (int i = 0; i < key.size(); ++i)
                {
                    if (key[i] >= 'A' && key[i] <= 'Z')
                        this->key += key[i];
                    else if (key[i] >= 'a' && key[i] <= 'z')
                        this->key += key[i] + 'A' - 'a';
                }
            }

            string encrypt(string text)
            {
                string out;
                for (int i = 0, j = 0; i < text.length(); ++i)
                {
                    char c = text[i];
                    if (c >= 'a' && c <= 'z')
                        c += 'A' - 'a';
                    else if (c < 'A' || c > 'Z')
                        continue;
                    out += (c + key[j] - 2 * 'A') % 26 + 'A';
                    j = (j + 1) % key.length();
                }
                return out;
            }

            string decrypt(string text)
            {
                string out;
                for (int i = 0, j = 0; i < text.length(); ++i)
                {
                    char c = text[i];
                    if (c >= 'a' && c <= 'z')
                        c += 'A' - 'a';
                    else if (c < 'A' || c > 'Z')
                        continue;
                    out += (c - key[j] + 26) % 26 + 'A';
                    j = (j + 1) % key.length();
                }
                return out;
            }
    };

int en_de_wca(char [],int);
int en_wca();  
char* en_str(char [],int);
int de_wca();
char* de_str(char [], int);
int en_de_xora(char [],int);
int en_xora();
void en_xtr(char [],int);
int de_xora();
void de_xtr(char [],int);
int en_vca();
int de_vca();
int en_de_vca();

string xstr="";
string xxtr="";

main()
{
 int goon=1,i,count;
 int ch=0, s1ch,s2ch,s3ch, ekey=0;
 char str[50];
 while(goon) 
  {
    int s1goon=1,s2goon=1,s3goon=1;
    system("cls");   
    cout<<"           Main Menu               "<<endl;
    cout<<"==================================="<<endl;
    cout<<"1. Encode/Decode a String on screen"<<endl;
    cout<<"2. Encode data from a File         "<<endl;
    cout<<"3. Decode data from a File         "<<endl;
    cout<<"4. Exit this Menu			      "<<endl;
    cout<<"==================================="<<endl;
    cout<<"Your Choice : ";
    cin>>ch;
    switch (ch){
	  case 1:
	       {
	        while(s1goon)
	        {
	        system("cls");
	        cout<<"       Sub Menu (Choice 1)     "<<endl;
		    cout<<"==============================="<<endl;
		    cout<<"1. Use Wheel Cipher Algo       "<<endl;
		    cout<<"2. Use Vignere Cipher Algo     "<<endl;
		    cout<<"3. Use XOR Algo                "<<endl;
		    cout<<"4. Exit this Menu			  "<<endl;
		    cout<<"==============================="<<endl;
	        cout<<"Your Choice : ";
		    cin>>s1ch;
		    switch(s1ch){
		    case 1:
		          int x;
		          system("cls");
		          cout<<"Enter String to Encode : ";
		          fflush(stdin);
   	              gets(str);
		          cout<<"Enter Key              : ";
		          cin>>ekey;
		          x=en_de_wca(str, ekey);
		          break;
		    case 2:
		          x=en_de_vca();
		          break;
		    case 3:
		          ekey=0;
		          system("cls");
		          cout<<"Enter String to Encode : ";
		          fflush(stdin);
		          gets(str);
		          cout<<"Enter Key              : ";
		          cin>>ekey;
		          x=en_de_xora(str, ekey);
		          break;
		    
		    case 4:
		          s1goon=0;
		    }
	       
 		    break;
 		    }
 	  case 2:
 	        {
 	        while(s2goon)
	        {
	        system("cls");
	        cout<<"       Sub Menu (Choice 2)     "<<endl;
		    cout<<"==============================="<<endl;
		    cout<<"1. Use Wheel Cipher Algo       "<<endl;
		    cout<<"2. Use Vignere Cipher Algo     "<<endl;
		    cout<<"3. Use XOR Algo                "<<endl;
		    cout<<"4. Exit this Menu			  "<<endl;
		    cout<<"==============================="<<endl;
		    cout<<"Your Choice : ";
		    cin>>s2ch;
		    switch(s2ch){
		    case 1:
		          int x;	          
		          x=en_wca();
		          break;
		    case 2:
		          en_vca();
		          break;
		    case 3:
		          x=en_xora();
		          break;
		    case 4:
		          s2goon=0;
		    }
	       
 		    break;
 		    }
 	         system("cls");
 	         
             break;
            }
 	  case 3:
 	        {
 	         system("cls");
 	         while(s3goon)
	        {
	        system("cls");
	        cout<<"       Sub Menu (Choice 3)     "<<endl;
		    cout<<"==============================="<<endl;
		    cout<<"1. Use Wheel Cipher Algo       "<<endl;
		    cout<<"2. Use Vignere Cipher Algo     "<<endl;
		    cout<<"3. Use XOR Algo                "<<endl;
		    cout<<"4. Exit this Menu			  "<<endl;
		    cout<<"==============================="<<endl;
		    cout<<"Your Choice : ";
		    cin>>s3ch;
		    switch(s3ch){
		    case 1:
		          int x;	          
		          x=de_wca();
		          break;
		    case 2:
		          de_vca();
		          break;
		    case 3:
		          x=de_xora();
		          break;
		    case 4:
		          s3goon=0;
		    }
	       
 		    break;
 		    }
 	        
 	         break;
 	        }
	  case 4:
	      goon=0; 
	      exit(0);
	  default:            
    	  cout<<"Error!! Bad choice";
    	  getch();
    	  break;
      }
  }

}
}

int en_de_wca(char mstr[],int mkey)
{
int len,i,j, up_low, xkey=0;
len=strlen(mstr);
for(i=0;i<len;i++)
 {
  if(!isdigit(mstr[i])) 
   {

   if ((isalpha(mstr[i]))&& (!isspace(mstr[i])))
   {
    if(isupper(mstr[i])==0)
         up_low=1;
    else
	     up_low=0;
    for(j=0;j<mkey;j++){
     if(up_low==0){
       
       if (mstr[i]=='Z'){
        mstr[i]='A';
        }
        else {
         mstr[i]++;
        }
     }
     else {
     
      if (mstr[i]=='z'){
        mstr[i]='a';
        }
        else {
         mstr[i]++;
        }
     }
   }

 }
}
else{
  mstr[i]=mstr[i]-'1';
  }
  
}
cout<<"encoded string is : "<<mstr<<endl;
 getch();
 
 cout<<"Enter Key to Decode : ";
 cin>>xkey;
 
 if (mkey!=xkey){
   cout<<"Authorisation Invalid !!....";
   getch();
   return 0;
 }
 
 for (i=0;i<len;i++)
 {
  if((!isdigit(mstr[i]))&& (!isspace(mstr[i])))
  {

  if (isalpha(mstr[i]))
   {
    if(isupper(mstr[i])==0)
         up_low=1;
    else
	     up_low=0;
    for(j=0;j<xkey;j++){
     if(up_low==0){
     
      if (mstr[i]=='A'){
        mstr[i]='Z';
      }
      else {
        mstr[i]--;
      }
     }
     else {
      if (mstr[i]=='a'){
        mstr[i]='z';
      }
      else {
        mstr[i]--;
      }
     }
   }
 }
 
 else{
  mstr[i]=mstr[i]+'1';
  }
}

}
cout<<"decoded string is : "<<mstr;
 getch(); 
}
   
int en_wca()
{
int mkey;
char tstr[50], estr[50];
fstream fi,fo;
    	   fi.open("sdata.txt",ios::in);
    	   fo.open("cedata.txt",ios::out|ios::app);
   				
    		if(!fi){
       			 cerr<<"Cannot open file to read !";
       			 getch();
       	    return 1;} 
       	    
       	    cout<<"Enter Key to Encode : ";
       	    cin>>mkey;
       	    fo<<mkey;
       	    fo<<'\n';
       	    
       	    while (!fi.eof()){

       	    	fi.getline(tstr,50,'\n');
       	    	strcpy(estr,en_str(tstr,mkey));
       	    	fo<<estr;
       	    	fo<<'\n';
 
        	}
        	fi.close();
        	fo.close();
}

char* en_str(char mstr[], int xkey){

int len,i,j, up_low;
len=strlen(mstr);
for(i=0;i<len;i++)
 {
  if(!isdigit(mstr[i])) 
   {

   if ((isalpha(mstr[i]))&& (!isspace(mstr[i])))
   {
    if(isupper(mstr[i])==0)
         up_low=1;
    else
	     up_low=0;
    for(j=0;j<xkey;j++){
     if(up_low==0){
       
       if (mstr[i]=='Z'){
        mstr[i]='A';
        }
        else {
         mstr[i]++;
        }
     }
     else {
     
      if (mstr[i]=='z'){
        mstr[i]='a';
        }
        else {
         mstr[i]++;
        }
     }
   }

 }
}
else{
  mstr[i]=mstr[i]-'1';
  }
}
return mstr;
}

int de_wca()
{
char tstr[50], mstr[50];
int zkey, count, keymatched=0;
fstream fi,fo;
    	   fi.open("cedata.txt",ios::in);
    	   fo.open("cddata.txt",ios::out|ios::app);
   				
    		if(!fi){
       			 cerr<<"Cannot open file to read !";
       			 getch();
       	    return 1;}
       	    
       	    cout<<"Enter Key to Decode : ";
       	    cin>>zkey;
       	    count=1;
       	    while (!fi.eof()){
       	    
       	    	fi.getline(tstr,50,'\n');
       	    	if (count==1){
					
       	    	  if(atoi(tstr)==zkey)
         	    	   keymatched=1;
                 }
                 
                 if (keymatched==0)
                  {
                   cout<<"Authorisation Invalid!!...";
       	           getch();
       	           return 0;
                  }
       	    	 if (count>1 && keymatched==1)
			     {
       	    		strcpy(mstr,de_str(tstr,zkey));
       	    		fo<<mstr;
       	    		fo<<'\n';
       	         }
              count=count+1;
        	}
        	
        	fi.close();
        	fo.close();

}

char* de_str(char dstr[],int qkey) {

int len,i,j, up_low;
len=strlen(dstr);
for (i=0;i<len;i++)
 {
  if((!isdigit(dstr[i]))&& (!isspace(dstr[i])))
  {

  if (isalpha(dstr[i]))
   {
    if(isupper(dstr[i])==0)
         up_low=1;
    else
	     up_low=0;
    for(j=0;j<qkey;j++){
     if(up_low==0){
     
      if (dstr[i]=='A'){
        dstr[i]='Z';
      }
      else {
        dstr[i]--;
      }
     }
     else {
      if (dstr[i]=='a'){
        dstr[i]='z';
      }
      else {
        dstr[i]--;
      }
     }
   }
 }
 
 else{
  dstr[i]=dstr[i]+'1';
  }
 
}

}
return dstr;
}

int en_de_xora(char mstr[],int mkey)
{

 int i,len,xkey;
 len=strlen(mstr);
 string xstr="";
 string dxtr="";
 for(i=0;i< len;i++){
    xstr+= mstr[i]^char(((mkey+i)% 255));
 }
 cout<<"Encoded string is : "<<xstr<<endl;
 getch();
 
 cout<<"Enter Key to Decode String : ";
 cin>>xkey;
 
 if (xkey==mkey)
   {
 	for(i=0;i< len;i++){
    dxtr+= xstr[i]^char(((mkey+i)% 255));
   }
 	cout<<"Decoded string is : "<<dxtr;
   }
   else
    {
     cout<<"Authorisation Invalid !!...";
     getch();
     return 0;
    }
 getch();
 return 1;
}

int en_xora()
{
const char* c_str();
int mkey;
char tstr[50];
string estr="";
fstream fi,fo;
    	   fi.open("sdata.txt",ios::in);
    	   fo.open("xedata.txt",ios::out|ios::app);
   				
    		if(!fi){
       			 cerr<<"Cannot open file to read !";
       			 getch();
       	    return 1;} 
       	    
       	    cout<<"Enter Key to Encode : ";
       	    cin>>mkey;
       	    fo<<mkey;
       	    fo<<'\n';
       	   
       	    while (!fi.eof()){
                estr="";
       	    	fi.getline(tstr,50,'\n');
       	    	en_xtr(tstr,mkey);
       	    	estr=xstr;
       	    	fo<<estr;
       	    	fo<<'\n';
 
        	}
        	fi.close();
        	fo.close();
}


void en_xtr(char dstr[],int qkey)
{

int i,len,xkey;
 len=strlen(dstr);
 for(i=0;i< len;i++){
    xstr+= dstr[i]^char(((qkey+i)% 255));
    }
}


int de_xora()
{
char tstr[50];
string mstr="";
int zkey, count, keymatched=0;
fstream fi,fo;
    	   fi.open("xedata.txt",ios::in);
    	   fo.open("xddata.txt",ios::out|ios::app);
   				
    		if(!fi){
       			 cerr<<"Cannot open file to read !";
       			 getch();
       	    return 1;}
       	    
       	    cout<<"Enter Key to Decode : ";
       	    cin>>zkey;
       	    count=1;
       	    while (!fi.eof()){
       	        mstr="";
       	    	fi.getline(tstr,50,'\n');
       	    	if (count==1){
			
       	    	  if(atoi(tstr)==zkey)
         	    	   keymatched=1;
         	       }
                 
                 if (count ==1 && keymatched==0)
                  {
                   cout<<"Authorisation Invalid!!...";
       	           getch();
       	           return 0;
                  }
       	    	 if (count>1 && keymatched==1)
			     {
			     	de_xtr(tstr,zkey);
       	    		mstr=xxtr;
       	    		fo<<mstr;
       	    		fo<<'\n';
       	         }
  
              count=count+1;
        	}
        	
        	fi.close();
        	fo.close();

}

void de_xtr(char cxtr [],int ckey)
{
 int i,len;
 len=strlen(cxtr);
  xxtr="";
  	for(i=0;i< len;i++){
    xxtr+= cxtr[i]^char(((ckey+i)% 255));
   }

}

int en_vca()
{
string mkey="", estr="", tstr="";
fstream fi,fo;
    	   fi.open("sdata.txt",ios::in);
    	   fo.open("vedata.txt",ios::out|ios::app);
   				
    		if(!fi){
       			 cerr<<"Cannot open file to read !";
       			 getch();
       	    return 1;} 
       	    
       	    cout<<"Enter Key to Encode : ";
       	    cin>>mkey;
       	    fo<<mkey;
       	    fo<<'\n';
       	    xstr="";
       	    Vigenere cipher(mkey);
       	    while (!fi.eof()){
             	getline(fi,tstr,'\n');
       	    	fo<<cipher.encrypt(tstr);
       	    	fo<<'\n';
        	}
        	fi.close();
        	fo.close();
}


int de_vca()
{
char mstr[50];
string zkey="", tstr="";
int count, keymatched=0;
fstream fi,fo;
    	   fi.open("vedata.txt",ios::in);
    	   fo.open("vddata.txt",ios::out|ios::app);
   				
    		if(!fi){
       			 cerr<<"Cannot open file to read !";
       			 getch();
       	    return 1;}
       	    
       	    cout<<"Enter Key to Decode : ";
       	    cin>>zkey;
       	    count=1;
       	    Vigenere cipher(zkey);
       	    while (!fi.eof()){
       	    
       	    	getline(fi,tstr,'\n');
       	    	if (count==1){
					
       	    	  if(tstr==zkey)
         	    	   keymatched=1;
                 }
                 
                 if (keymatched==0)
                  {
                   cout<<"Authorisation Invalid!!...";
       	           getch();
       	           return 0;
                  }
       	    	 if (count>1 && keymatched==1)
			     {
       	    		
       	    		fo<<cipher.decrypt(tstr);
       	    		fo<<'\n';
       	         }

              count=count+1;
        	}
        	
        	fi.close();
        	fo.close();
}

int en_de_vca()
{
string mstr="", mkey="", zkey="",encoded="";
cout<<"Enter String to Encode : ";
fflush(stdin);
cin>>mstr;
cout<<"Enter Key :";
fflush(stdin);
cin>>mkey;

 Vigenere cipher(mkey);
 encoded=cipher.encrypt(mstr);
 cout<<"Encoded String is :"<<encoded<<endl;
 getch();
        
 cout<<"Enter Key to Decode : ";
 fflush(stdin);
 cin>>zkey;
 cout<<"Decoded String is : "<<cipher.decrypt(encoded);
 getch();
}
