#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#include <cmath>
#include <unistd.h>
#include <chrono>
#include <thread>



using namespace std;



class ProgressBar
{
    public:
        ProgressBar(std::ostream &os, int const& length=30);
        void init();
        void update(int const& i, int const& n);

    private:
        int m_length;
        int m_mark;
        int m_progress;
        std::ostream &m_os;
};

inline void ProgressBar::update(int const& i, int const& n)
{
    int p(((float) i/(n-1))*m_length);
    m_progress=p;
    if (m_progress>m_mark)
    {
        m_mark=m_progress;
        m_os << "*";
    }
    m_os.flush();
}



ProgressBar::ProgressBar(std::ostream &os, int const& length):
    m_length(length), m_mark(0), m_progress(0),
    m_os(os)
{}

void ProgressBar::init()
{
    m_os << "\t[";
    for (int i=0; i<m_length; ++i)
        m_os << " ";
    m_os << "\t ]";
    for (int i=0; i<=m_length; ++i)
        m_os << "\b";
    m_os.flush();
}






class terminal
{

    public:

    int id;
    string adresse_mac;

    int getId()
    {
        return id;
    }

    void setId(int new_id)
    {
        id = new_id;
    }

    void setMac(string mac)
    {
        adresse_mac = mac;
    }

    string getAdressemac()
    {
        return adresse_mac;
    }
};

class routeur
{
public:

    string table[100];

    void saveMac(string mac, int indice)
    {
        table[indice] = mac;
    }

     string getEltTable(int indice)
    {
        return table[indice];
    }

    void getTable()
    {
        int taille,i;
        taille = sizeof(table);
        for(i=0;i<taille;i++)
        {
            cout << " adresse MAC du terminal   " << i+1 << " : "<< table[i]<<endl;
        }
    }
};

void loading()
{
    int i;
           for(i=0; i<=100; i++)
    {
        system("cls");
        cout << "\n\tLoading: " << i << " %  \t";
       // ProgressBar bar(std::cout);
        //bar.init();
        //int n(100), m(100000);
        //for (int i=0; i<n; ++i)
        //{
    //      calculs longs, par exemple :
          //  for (int j=0; j<m; ++j);
           // bar.update(i, n);
        //}
        //std::cout << std::endl;
        Sleep(50);
        if(i==100)
        {

        }
    }
}

class messageTerminal
{
public:
    string message;
    string terminal;
};

void consulterMessages(string terminal)
{
    cout << "\t                          ***************************                            \t" << endl;
    cout << "\t                           MESSAGES  "<< terminal <<"                            \t" << endl;
    cout << "\t                          ***************************                            \t" << endl;



}

int main()
{
    int nb, choix;
    int nbrpaquet;
    int i;
    const int mtu = 40;
    int tailleMsg;
    char reponse;
    string mac;
    string msg;
    string emetteur;
    string recepteur;
    string emetteurFind;
    string recepteurFind;
    messageTerminal message[100];


  //   std::cout << "Loading Please Wait";
  //  while (true)
  //  {
   //     sleep(1);
   //     std::cout << "." << std::flush;
   //     sleep(1);
   //     std::cout << "." << std::flush;
   //     sleep(1);
   //     std::cout << "." << std::flush;
   //     sleep(1);
   //     std::cout << "\b\b\b   \b\b\b" << std::flush;
   // }

  // for (;;) {

    //    std::cout << "\b\b\b\b\b\b\b\b\b\bLoading   " << std::flush;
      //  Sleep(100);
     //   std::cout << "\b\b\b\b\b\b\b\b\b\bLOading   " << std::flush;
      //  Sleep(100);
       // std::cout << "\b\b\b\b\b\b\b\b\b\bLoAding   " << std::flush;
       // Sleep(100);
       // std::cout << "\b\b\b\b\b\b\b\b\b\bLoaDing   " << std::flush;
       // Sleep(100);
      //  std::cout << "\b\b\b\b\b\b\b\b\b\bLoadIng   " << std::flush;
      //  Sleep(100);
      //  std::cout << "\b\b\b\b\b\b\b\b\b\bLoadiNg   " << std::flush;
     //   Sleep(100);
     //   std::cout << "\b\b\b\b\b\b\b\b\b\bLoadinG   " << std::flush;
     //   Sleep(100);
     //   std::cout << "\b\b\b\b\b\b\b\b\b\bLoading.  " << std::flush;
     //   Sleep(100);
     //   std::cout << "\b\b\b\b\b\b\b\b\b\bLoading.." << std::flush;
     //   Sleep(100);
     //   std::cout << "\b\b\b\b\b\b\b\b\b\bLoading..." << std::flush;
      //  Sleep(100);
   // }






    cout << "\t                          *************************************************                            \t" << endl;
    cout << "\t                          ********** SIMULATION DU SYTEME RESEAU **********                            \t" << endl;
    cout << "\t                          *************************************************                            \t" << endl;

    Sleep(1000);
    system("cls");
    cout << "\n\tPreciser le nombre de terminaux de votre reseau\t : " ;
    cin >> nb;


    //PLUS DE 2 TERMINAUX POUR UN RESEAU
    while(nb < 2){
    cout << "\n\tOperation immpossible Il faut plus d'un terminal pour simuler un systeme de reseau  !!\t" ;
    cout << "\n\tPreciser le nombre de terminaux de votre reseau\t : " ;
        cin >> nb;
    }

    terminal poste[nb];
    routeur myrouteur;
     system("cls");
    for(i=0;i<nb;i++){
        cout << "\n\tDonner l'adresse MAC du terminal: " << i+1 << "\t : ";
        cin >> mac;
        poste[i].setMac(mac);
        myrouteur.saveMac(mac,i);
    }

     system("cls");
    cout << "\n"<<endl ;
     for(i=0;i<nb;i++){
    cout << "\t["<<i+1<<"]\t" ;
     }
     cout << "\n"<<endl ;

     // MESSAGE A ENVOYER
    cout <<"\n\tEntrer le message a envoyer\t : ";
    cin >> msg;
    cout <<"\n\tLe message a envoyer fait "<< sizeof(msg)<<" octets \t";
    if(msg.size() > mtu){
        nbrpaquet = ceil(sizeof(msg) / mtu);
        cout <<"\n\tLe message sera transfere en "<< nbrpaquet+1 <<" paquet(s) \t";
    }


    cout << "\n"<<endl ;
     for(i=0;i<nb;i++){
    cout << "\t["<<poste[i].getAdressemac()<<"]\t" ;
     }
    cout << "\n"<<endl ;


    int existEmetteur(0);
    while(existEmetteur == 0)
    {
        cout <<"\t Preciser l'emetteur\t : ";
        cin >> emetteur;
        for(i=0;i<nb;i++){
            if(poste[i].adresse_mac == emetteur)
            {
                emetteurFind = poste[i].adresse_mac;
                existEmetteur = 1;

            }
        }
    }
    system("cls");

    cout <<"\n\t Message\t : \t"<< msg<<"\t" <<endl;
    cout <<"\n\t Source\t : "<< emetteurFind <<endl;

    int testSendMe(0);
    while(testSendMe == 0)
    {
        cout <<"\n\t Préciser l'adresse MAC du recepteur : \t";
        cin >> recepteur;
         if(emetteur == recepteur){
            cout << "\n\t Choisissez un autre recepteur s'il vous plait !\t";
        }else{
            testSendMe = 1;
        }

    }

    int existRecepteur(0);
    while(existRecepteur == 0)
    {
        cout <<"\t Préciser l'adresse MAC du recepteur : ";
        cin >> recepteur;
        for(i=0;i<nb;i++){
            if(poste[i].adresse_mac == recepteur)
            {
                recepteurFind = poste[i].adresse_mac;
                existRecepteur = 1;

            }
        }
    }
    system("cls");

    cout <<"\n\t Message\t : "<< msg <<endl;
    cout <<"\n\t Source\t : "<< emetteurFind <<endl;
    cout <<"\n\t Recepteur\t : "<< recepteurFind <<endl;

    cout <<"\n\t Voulez-vous envoyer le message ? (o/n) \t : "<< recepteurFind <<endl;
    cin >> reponse;

    switch(reponse)
    {
    case 'o':
        loading();
        cout <<"\n\t Message envoye a\t : "<< recepteurFind <<endl;
        break;

    case 'n':
        cout <<"\n\t Message non envoye \t : "<<endl;
        break;


    }










   // for(i=0;i<nb;i++){
   //     cout << "\n adresse MAC du terminal   " << i+1 << " : "<< poste[i].getAdressemac()<<endl;
   // }


   // cout << "\n\t Table d'adresses du routeur   \t" << endl;
   // cout << "\t+-------------------------------+\t" << endl;
   // for(i=0;i<nb;i++){
   //     cout << "\t+ adresse_mac termimal " << i+1 << " :"<< myrouteur.getEltTable(i) << endl;
   // }
   //  cout << "\t+-------------------------------+\t" << endl;







    return 0;

}
