#include <iostream>
#include <typeinfo>
#include <vector>
#include <set>
#include <iterator>
using namespace std;

class MASINA
{
protected:
float dimensiune;
string nume;
bool nou = true;
public:
    MASINA(){
    dimensiune = 0;
    nume  = " ";
    }

    MASINA (float d) : dimensiune(d) {}

   virtual void afisare() const = 0;

   friend istream &operator >> (istream &in, MASINA &ob)
    {
         in >> ob.dimensiune;
         return in;
    }
/*
    friend ostream &operator << (ostream &out, MASINA &ob)
    {
         out <<"Dimensiunea masinii este = ";
         out << ob.dimensiune;
    }
*/
  MASINA &operator = (const MASINA &ob)
  {
      if(this != &ob)
      {
          dimensiune = ob.dimensiune;
      }
      return *this;
  }

  ~MASINA()
  {
   dimensiune = 0;
   nume = " ";
  }

};

class MINI : public MASINA
{
  protected:
      string descriere;
  public:
    MINI():MASINA()
    {
     descriere = "Masina de oras de mic litraj";
     nume = "MINI";
    }

    void afisare () const
    {
        cout << nume <<" -> "<< descriere<<" cu dimensiuna de "<<dimensiune<<"m"<<endl;
    }

    MINI &operator = (const MINI &ob)
    {
        if(this != &ob)
        {
        MASINA :: operator = (ob);
        }
        return *this;

    }

    ~MINI()
    {
        descriere = " ";
    }

    friend istream &operator >> (istream &, MINI &);
};

istream &operator >> (istream &in, MINI &ob)
{
     cout <<"Dimensiunea masinii ";
         in >> (MASINA&) ob;

          try{
                if(ob.dimensiune > 4)
                {
                    cout <<"EROARE! Masinile mini au dimensiunea maxima de 4 m." << endl;
                    throw (ob.dimensiune);
                }

              }
              catch(float)
              {
                  cout << "Dimensiunea masinii va fi setata la dimensiunea maxima"<< endl;
                  ob.dimensiune = 4;
              }

           try{
                if(ob.dimensiune < 2)
                {
                    cout <<"EROARE! Masinile mini au dimensiunea minima de 2 m." << endl;
                    throw (ob.dimensiune);
                }

              }
              catch(float)
              {
                  cout << "Dimensiunea masinii va fi setata la dimensiunea minima" << endl;
                  ob.dimensiune = 2;
              }

         return in;

    }

class MICA : public MASINA
{
  protected:
      string descriere;
  public:
    MICA():MASINA()
    {
        descriere = "Masina de oras mai mare decat MINI";
        nume = "MICA";
    }

    void afisare()const
    {
        cout << nume <<" -> "<<descriere<<" cu dimensiuna de "<<dimensiune<<"m"<<endl;
    }

    friend istream &operator >> (istream &in, MICA &ob)
    {   cout <<"Dimensiunea masinii ";
         in >> (MASINA&) ob;

         try{
                if(ob.dimensiune > 4.1)
                {
                    cout <<"EROARE! Masinile MICI au dimensiunea maxima de 4.1 m." << endl;
                    throw (ob.dimensiune);
                }

              }
              catch(float)
              {
                  cout << "Dimensiunea masinii va fi setata la dimensiunea maxima"<< endl;
                  ob.dimensiune = 4.1;
              }

           try{
                if(ob.dimensiune < 3.85)
                {
                    cout <<"EROARE! Masinile MICI au dimensiunea minima de 3.85 m." << endl;
                    throw (ob.dimensiune);
                }

              }
              catch(float)
              {
                  cout << "Dimensiunea masinii va fi setata la dimensiunea minima" << endl;
                  ob.dimensiune = 3.85;
              }

         return in;

    }

    MICA &operator = (const MICA &ob)
    {
        if(this != &ob)
        {
            MASINA :: operator = (ob);
        }
        return *this;
    }

    ~MICA()
    {
        descriere = " ";
    }

};

class COMPACTA : public MASINA
{
private:
    string model;
    string descriere;
public:
    COMPACTA() : MASINA() {
        descriere = "Masina usoara de folosit atat in oras cat si la drum lung";
        nume = "COMPACTA";
    }
  void afisare () const
  {
     cout << nume<<":Model "<<model<<" -> "<<descriere<<" cu dimensiuna de "<<dimensiune<<"m"<<endl;
  }

  friend istream &operator >> (istream &in, COMPACTA &ob)
    {
        cout <<"Dimensiunea masinii ";
         in >> (MASINA&) ob;
         try{
                if(ob.dimensiune > 4.5)
                {
                    cout <<"EROARE! Masinile COMPACT au dimensiunea maxima de 4.5 m." << endl;
                    throw (ob.dimensiune);
                }

              }
              catch(float)
              {
                  cout << "Dimensiunea masinii va fi setata la dimensiunea maxima"<< endl;
                  ob.dimensiune = 4.5;
              }

           try{
                if(ob.dimensiune < 4.1)
                {
                    cout <<"EROARE! Masinile COMPACT au dimensiunea minima de 4.2 m." << endl;
                    throw (ob.dimensiune);
                }

              }
              catch(float)
              {
                  cout << "Dimensiunea masinii va fi setata la dimensiunea minima" << endl;
                  ob.dimensiune = 4.2;
              }

         cout << "Modelul masinii este hatchback, combi sau sedan:";
         in >> ob.model;
         try{
             if(ob.model != "sedan" && ob.model != "combi" && ob.model != "hatchback")
             {
                 cout <<"EROARE! Ati introdus un model gresit.";
                 throw(ob.model);
             }
         }
         catch(string)
         {
             cout <<"Modelul va fi setat automat pe Sedan "<<endl;
             ob.model = "Sedan";
         }

         return in;
    }

   COMPACTA &operator = (const COMPACTA &ob)
   {
       if(this != &ob)
       {
           MASINA :: operator = (ob);
           model = ob.model;
       }
       return *this;
   }
    ~COMPACTA()
    {
        model = " ";
        descriere = " ";
    }

};

class MONOVOLUME : public MASINA
{
private:
    string descriere;
public:
    MONOVOLUME() : MASINA() {
        descriere = "Masina sub forma de van ce poate transporta 5-7 persoane";
        nume = "MONOVOLUME";
    }

  void afisare () const
  {
     cout << nume<<" -> "<<descriere<<" cu dimensiuna de "<<dimensiune<<"m"<<endl;
  }

  friend istream &operator >> (istream &in, MONOVOLUME &ob)
    {    cout <<"Dimensiunea masinii ";
         in >> (MASINA&) ob;
         return in;
    }

    MONOVOLUME &operator = (const  MONOVOLUME &ob)
   {
       if(this != &ob)
       {
           MASINA :: operator = (ob);
       }
   }

    ~MONOVOLUME()
    {
     descriere = " ";
    }

};

template <class T>
class Vanzare{

private:

 int nrTotalMasini;
 int nrMasiniVandute;
 vector <T*> masiniStoc;
 vector <T*> masiniVandute;

public:
 Vanzare () {
  nrTotalMasini = 0;
  nrMasiniVandute = 0;
 }

 Vanzare operator -= (int index)
 {
     vinde(index);
     return (*this);
 }

 void vinde(int index)
 {
           if(nrTotalMasini == 0)
            {
                cout <<"Stocul de masini este gol"<< endl;
                return;
            }
            if(index > nrTotalMasini){
                cout <<"Nu exista pe stoc masina cu indexul"<< index << endl;
            return;
            }

            masiniVandute.push_back(masiniStoc[index-1]);
            cout <<"Masina "; masiniStoc[index-1]->afisare();
            cout <<" A FOST VANDUTA" << endl;

            masiniStoc.erase(masiniStoc.begin()+(index-1));
            nrMasiniVandute++;
            nrTotalMasini--;
 }

 void afisareStoc()
 {
            cout <<"Numarul total de masini din stoc este: "<< nrTotalMasini << endl;
           for(int i = 0;i < nrTotalMasini; i++){
            cout <<"("<<i+1<<")";
            masiniStoc[i]->afisare();
           }

            cout <<"Numarul total de masini vandute este: "<< nrMasiniVandute << endl;
            for(int k = 0;k < nrMasiniVandute; k++)
            masiniVandute[k]->afisare();
 }
 void setup()
 {
     cout << "Alegeti o masina de bagat pe stoc "<<endl;
     cout << "1. Pentru masina MINI" << endl;
     cout << "2. Pentru masina MICA"<< endl;
     cout << "3. Pentru masina COMPACTA"<<endl;
       int x;
       cout << "Introduceti optiunea: ";
       cin >> x;
       T* ob;
       T* aux;
       T* aux2;

        switch (x)
       {

       case 1:
           ob = dynamic_cast <MINI*>(aux2);
           ob = new MINI;
           cin >> (MINI&)(*ob);
           nrTotalMasini++;
           masiniStoc.push_back(ob);
        break;

       case 2:
           ob = dynamic_cast <MICA*>(aux2);
           ob = new MICA;
           cin >> (MINI&)(*ob);
           nrTotalMasini++;
           masiniStoc.push_back(ob);
        break;

       case 3:
           ob = dynamic_cast <COMPACTA*>(aux2);
           ob = new COMPACTA;
           cin >> (COMPACTA&)(*ob);
           nrTotalMasini++;
           masiniStoc.push_back(ob);
        break;
       default:
        break;
       }


 }

 ~Vanzare(){
  nrTotalMasini = 0;
  nrMasiniVandute = 0;
  masiniStoc.clear();
  masiniVandute.clear();
 }
};

template <>
class Vanzare <MONOVOLUME>
{
 private:

 int nrTotalMonov;
 int nrMonovVandute;
 bool nou ;
 vector <MONOVOLUME*> monovStoc;
 vector < pair<MONOVOLUME*,bool> > monovVandute;
 set < pair <MONOVOLUME*,bool> > s;
 pair < MONOVOLUME*, bool > p;
 set<pair < MONOVOLUME*, bool > > :: iterator j;

 public:

        Vanzare()
        {
            nrTotalMonov = 0;
            nrMonovVandute = 0;
        }

        void afisareStoc()
        {
            cout <<"Numarul total de MONOVOLUME din stoc este: "<< nrTotalMonov << endl;
           for(int i = 0;i < nrTotalMonov; i++)
            monovStoc[i]->afisare();

            cout <<"Numarul total de MONOVOLUME vandute este: "<< nrMonovVandute << endl;

            for(j = s.begin(); j != s.end(); ++j)
            {
               j->first->afisare();

               if(j->second == true)
               cout <<"Masina este NOUA" << endl;
               else
                cout <<"Masina este SH" << endl;
            }
        }

         Vanzare operator -= (int index)
        {
            vinde(index);
            return (*this);
        }

        void vinde(int index)
        {

            p = make_pair(monovStoc[index-1],nou);
            s.insert(p);
            monovStoc.erase(monovStoc.begin()+(index-1));
            nrMonovVandute++;
            nrTotalMonov--;
            cout <<"MASINA A FOST VANDUTA" << endl;
        }

        void setup()
        {
           MONOVOLUME* ob;
           int aux;
           ob = new MONOVOLUME;
           cin >> (MONOVOLUME&)(*ob);
           cout <<"Alegeti 1 pentru masina NOUA "<< endl;
           cout <<"Alegeti 2 pentru masina SH "<< endl;
           cout <<"Alegeti tipul masinii: ";
           cin >> aux;

           if(aux == 1)
            nou = true;
           else if(aux == 2)
            nou = false;
           nrTotalMonov++;
           monovStoc.push_back(ob);
        }

        ~Vanzare()
        {
            nrTotalMonov = 0;
            nrMonovVandute = 0;
            monovStoc.clear();
            monovVandute.clear();
        }
};

int main()
{
    Vanzare <MASINA> v;
    Vanzare <MONOVOLUME> mon;
     cout << "(1) Pentru a introduce o masina in stoc"<<endl;
     cout << "(2) Pentru a vizualiza stocul si masinile vandute"<< endl;
     cout << "(3) Pentru a vinde o masina "<< endl;
     cout << "(4) Pentru a introduce un MONOVOLUM" << endl;
     cout << "(5) Pentru a afisa MONOVOLUMELE din stoc si cele vandute"<< endl;
     cout << "(6) Pentru a vinde un MONOVOLUM"<<endl;
     cout << "(0) Pentru a inchide programul" << endl;
       int x,index;
       cout << "Introduceti optiunea: ";
       cin >> x;

    while(x)
    {
        switch(x){
    case 1:
        v.setup();
        break;
    case 2:
        v.afisareStoc();
        break;
    case 3:
        cout <<"Introduceti indexul masinii dorite: ";
        cin >> index;
        v-= index;
        break;
    case 4:
        mon.setup();
        break;
    case 5:
        mon.afisareStoc();
        break;

    case 6:
        cout <<"Introduceti indexul masinii dorite: ";
        cin >> index;
        mon-= index;
        break;

        default:
        break;
        }
        cout <<"Introduceti optiunea: ";
        cin >> x;
    }

    return 0;
}
