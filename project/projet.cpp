#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;



struct information{
	string nom,password;
};


struct profile{
	string nom1,pass1,pays;
	float nbc,nbd,nbrd,pr;
};


struct creers{
	string nom2,pass2;
};

void decroissantnbc(profile tab[],int n){
	profile temp;
for(int i=0; i < n-1; i++)
    for(int j=0; j < n-i-1; j++)
      if(tab[j].nbc < tab[j+1].nbc){
        temp = tab[j];
        tab[j] = tab[j+1];
        tab[j+1] = temp;
        }
        
       cout<<"\nAffichemet des pays par ordre croissant par nombre de cas confirmes :\n\n";
   cout<<"\n| Pays \t|  nombre total de cas confirmés \t| nombre total des décès \t| nombre de retours à domicile |";
   	for(int i=0;i<n;i++){
   	cout<<"\n| "<<tab[i].pays<<"\t\t|"<<tab[i].nbc<<"\t\t|"<<tab[i].nbd<<"\t\t|"<<tab[i].nbrd<<" |\n";
	   
	}
}
    


void croissantnbrd(profile tab[],int n){
	profile tmp;
	int j;
for(int i=1; i<n ; i++){
    tmp=tab[i];
    for(j=i; j>0 && tab[j-1].nbrd>tmp.nbrd; j--){
        tab[j]=tab[j-1]; 
   }
   tab[j]=tmp; 
}
   cout<<"\n\nAffichemet des pays par ordre croissant par nombre de retroure a domicile :\n\n";
   	for(int i=0;i<n;i++){
   	 cout<<"\n| Pays : "<<tab[i] .pays<<" nombre total de cas confirmés : "<<tab[i].nbc<<" nombre total des décès : "<<tab[i].nbd<<" nombre de retours à domicile : "<<tab[i].nbrd<<endl;
	cout<<"\n";    
	}
}


void afficher (profile tab[],int n){
		cout<<"|------------------------------|\n";
		cout<<"| Pays\t| pourcentage des deces\t|\n";
		cout<<"|------------------------------|\n";
		for(int i=0;i<n;i++){
		cout<<"| "<<tab[i].pays<<" \t| "<<tab[i].pr<<"\t\t|\n";
	}
	cout<<"|------------------------------|\n";
}

void nbtotal(profile tab[],int n){
	cout<<"\n nombre totale des deces : ";
	int s=0;
	for(int i=0;i<n ;i++){
		s=tab[i].nbd+s;
	}
	cout<<s;
	cout<<"\n nombre total des cas confirme : ";
	int a=0;
	for(int i=0;i<n;i++){
		a=tab[i].nbc+a;
	}
	cout<<a;
	cout<<"\n nombre totale de retoure a domiciles : ";
	int b=0;
	for(int i=0;i<n;i++){
		b=tab[i].nbrd+b;
	}
	cout<<b;
}

void nbtotalpays(profile tab[],int n){
	cout<<"donner le nom du pays :\n";
	string name;
	for(int i=0;i<n;i++){
	do{
		cin>>name;
		if(name!=tab[i].pays)
		cout<<"***Pays non trouver.Redonner un nom de pays .***";
	}while(name!=tab[i].pays);
    }
    for(int i=0;i<n;i++){
	if(name==tab[i].nom1){
		cout<<"\n nombre tottale des deces : "<<tab[i].nbd;
		cout<<"\n nombre total des cas confirme : "<<tab[i].nbc;
		cout<<"\n nombre totale de retoure a domiciles : "<<tab[i].nbrd;
	}
}
}

void supprimer(profile tab[],int n){
    
    int index,maxsize=n; 
	string nom ;
    
    cout<<"Donner le pays que vous voulez supprimer :\n";  
    cin>>nom;
   for(int i=0;i<n;i++){
    if(nom==tab[i].nom1){
    	index=i;
    }
        for(int i=index;i<=maxsize-1;i++)
        {
            tab[i]=tab[i+1];
        }
        tab[maxsize-1]={};
}
	    cout<<"\nPays supprimer.";

}

void profilepays(profile tab[],int n){
	cout<<"donner le nombre de pays que vous voulez enregistrer :\n";
	do{
		cin>>n;
		if(n<=0)
		cout<<"\n***Erreure!Redonner un choix.***\n";
	}while(n<=0);
	ofstream paysprofile;
	cout<<"remplir les information suivante du pays :\n";
	paysprofile.open("Pays_login.txt",ios::app);
	for(int i=0;i<n;i++){
    cout<<" nom d'utilisateure : ";
    cin>>tab[i].nom1;
	paysprofile<<tab[i].nom1[n]<<" ";
	cout<<"\n password : ";
	cin>>tab[i].pass1;
	paysprofile<<tab[i].pass1<<" ";
	cout<<"\n nom du pays : ";
	cin>>tab[i].pays;

	paysprofile<<tab[i].pays<<" ";
	cout<<"\n le nombre total des cas confirme : ";
	do{
	cin>>tab[i].nbc;
	if(tab[i].nbc<0)
	cout<<"\n***Erreure!!Redonner le nombre total des cas confirme ***\n";
    }while(tab[i].nbc<0);
    paysprofile<<tab[i].nbc<<" ";
    cout<<"\n nombre total des deces : ";
    do{
    	cin>>tab[i].nbd;
    	if(tab[i].nbd<0)
    	cout<<"\n***Erreur!!Redonner le nombre total des deces ***\n";
	}while(tab[i].nbd<0);
	paysprofile<<tab[i].nbd<<" ";
	cout<<"\n nombre de retrours a domicile : ";
	do{
		cin>>tab[i].nbrd;
		if(tab[i].nbrd<0)
		cout<<"\n***Erreure!!Redonner le nombre de retrours a domicile ***\n";
	}while(tab[i].nbrd<0);
	paysprofile<<tab[i].nbrd<<" ";
	tab[i].pr=(tab[i].nbd/tab[i].nbc)*100;
}
decroissantnbc(tab,n);
croissantnbrd(tab,n);
afficher(tab,n);
nbtotal(tab,n);
nbtotalpays(tab,n);
supprimer(tab,n);

}

void who(){
	
		string line = " ";
fstream readFile("Who_login.txt");
information info;

string _nom;
string _password;

cout << "Donnez votre nom: \n";
cin >> info.nom;

cout << "Donnez votre Password: \n";
cin >> info.password;

while (getline(readFile,line)) {

    stringstream iss(line);
    iss >> _nom >> _password;

    if (info.nom == _nom && info.password == _password) {
        cout << "vous etes connecter !"<< endl;
    }

    else {
        cout << "vous n'etes pas connecter ."<< endl;
    }

}
	
	
		cout<<"creer le profil du pays :\n";
		cout<<"\ndonneer le nombre de pays que vous voulez enregistrer :\n";
		int n;
		do{
		cin>>n;
		if(n<=0)
		cout<<"\n***Erreure!!redonner le nombre de pays .***\n";
	    }while(n<=0);
	    const int nc=n;
	    profile tab[n];
		profilepays(tab,n);		
}



void pays(profile tab[],int n){
	

}




int main (){
	char choix,choix1;
	cout<<"Antonio Rizk\nJeanpierre Ayoub\nPetrer Sankari\n\n\n";

	cout<<"****choisir entre l'un des mode suivants mode :\n\tWHO  ou  PAYS \t\n(si vous voulez acceder le mode WHO taper 'w',si vous voulez acceder le mode PAYS taper 'p'****\n\n";
	do{
		cin>>choix;
		if(choix!='w' && choix!='p')
		cout<<"\n***Erreure!!Redonner un choix ***\n";
	}while(choix!='w' && choix!='p');
	if(choix=='w'){

	who();
}
}
