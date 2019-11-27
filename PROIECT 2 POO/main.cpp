#include <iostream>

using namespace std;

class Numar_Natural_Mare;
class Numar_intreg_mare;
class Management;

class Vector
{
private:
    int *a;
    friend class Numar_Natural_Mare;
    friend istream &operator >> (istream& in,Numar_Natural_Mare& ob1);
    friend ostream& operator << (ostream& out,Numar_Natural_Mare& ob1);
    friend class Numar_intreg_mare;

};
///----------------------------------------------CLASA NUMAR NATURAL MARE-------------------------------////////////////
class Numar_Natural_Mare
{
protected:
    int nrcif;
    Vector V;


public:
    Numar_Natural_Mare ()
    {
        nrcif = 0;
        V.a = 0;
    }

    Numar_Natural_Mare(int n,int *b) : nrcif(n)
    {
        V.a = new int[n];
        for (int i = 0; i < n; i++)
            V.a[i] = b[i];
    }

    Numar_Natural_Mare & operator = (const Numar_Natural_Mare &ob)
    {
        if(this != &ob)
        {
            nrcif = ob.nrcif;
            V.a = new int[nrcif];
            for(int i = 0; i < nrcif; i++)
                V.a[i] = ob.V.a[i];
        }

        return *this;
    }

    Numar_Natural_Mare (const Numar_Natural_Mare &ob)
    {
        if(this != &ob)
        {
            nrcif = ob.nrcif;
            V.a = new int[nrcif];
            for(int i = 0; i < nrcif; i++)
                V.a[i] = ob.V.a[i];
        }
    }

    Numar_Natural_Mare operator + (Numar_Natural_Mare const obiect);
    Numar_Natural_Mare operator - (Numar_Natural_Mare const obicet);



    friend istream& operator >> (istream& in,Numar_Natural_Mare& ob1);
    friend ostream& operator << (ostream& out,Numar_Natural_Mare& ob1);
    friend class Management;
    friend maxim(int,int);

    ~Numar_Natural_Mare()
    {
        nrcif = 0;
    };


};

Numar_Natural_Mare  Numar_Natural_Mare  :: operator - (Numar_Natural_Mare const obiect)
{
    Numar_Natural_Mare rez;
    Numar_Natural_Mare aux1;
    Numar_Natural_Mare aux2;
    int k;
    int t = 0;
    int i,j;
    if(obiect.nrcif > nrcif)
    {
        rez.nrcif = obiect.nrcif;
        aux2.V.a = obiect.V.a;
        i = obiect.nrcif - 1;

        aux1.V.a = V.a;
        j = nrcif - 1;

    }
    else if(obiect.nrcif < nrcif)
    {
        rez.nrcif = nrcif;
        aux2.V.a = V.a;
        i = nrcif - 1;

        aux1.V.a = obiect.V.a;
        j = obiect.nrcif - 1;
    }

    else if(obiect.nrcif ==  nrcif)
    {

        for(k = 0; k < obiect.nrcif; k ++)
            if(V.a[k] > obiect.V.a[k])
            {
                rez.nrcif = nrcif;
                aux2.V.a = V.a;
                i = nrcif - 1;

                aux1.V.a = obiect.V.a;
                j = obiect.nrcif - 1;
                break;
            }
            else if(V.a[k] < obiect.V.a[k])
            {
                rez.nrcif = obiect.nrcif;
                aux2.V.a = obiect.V.a;
                i = obiect.nrcif - 1;

                aux1.V.a = V.a;
                j = nrcif - 1;
                break;
            }
            else if (V.a[k] == obiect.V.a[k])
            {
                rez.nrcif = nrcif;
                aux2.V.a = V.a;
                i = nrcif - 1;

                aux1.V.a = obiect.V.a;
                j = obiect.nrcif - 1;

            }

    }

    rez.V.a = new int[rez.nrcif];

    int countRez = rez.nrcif - 1;

    while(i >= 0 && j >= 0)
    {

        rez.V.a[countRez] = aux2.V.a[i] - aux1.V.a[j] + t;

        if(rez.V.a[countRez] < 0)
        {
            rez.V.a[countRez] = rez.V.a[countRez] + 10;

            t = -1;

        }
        else
            t = 0;

        i--;
        j--;
        countRez--;
    }

    while(i >= 0)
    {
        rez.V.a[countRez] = aux2.V.a[i] + t;
        if(rez.V.a[countRez] < 0)
        {
            rez.V.a[countRez] = rez.V.a[countRez] + 10;

            t = -1;
        }
        else
            t = 0;

        i--;
        countRez--;
    }
    int ok = 0; /// Daca ok ramane 0 inseamna ca toate cifrele din rezultat au fost 0 si nu s-a intrat in for
    for(i = 0; i < rez.nrcif ; i++)
        if(rez.V.a[i] != 0)
        {
            rez.V.a = &rez.V.a[i];
            rez.nrcif = rez.nrcif - i;
            ok = 1;
            break;
        }
    ///Scoatem toate cifrele de 0 care sunt in plus daca rez = 0 0 0 0..
    for(i = 0; i < rez.nrcif ; i++)
        if(ok == 0)
        {
            rez.nrcif--;
            rez.V.a = &rez.V.a[i];
        }



    return rez;
}
Numar_Natural_Mare Numar_Natural_Mare :: operator + (Numar_Natural_Mare const obiect)
{
    Numar_Natural_Mare rez;

    if(obiect.nrcif - nrcif <= 1 && obiect.nrcif - nrcif >= 0)
        rez.nrcif = obiect.nrcif + 1;
    else if(nrcif - obiect.nrcif <= 1 && nrcif - obiect.nrcif >= 0)
        rez.nrcif = nrcif + 1;
    else if(obiect.nrcif - nrcif > 1)
        rez.nrcif = obiect.nrcif;
    else
        rez.nrcif = nrcif;



    rez.V.a = new int[rez.nrcif];

    int i = nrcif - 1;
    int j = obiect.nrcif - 1;
    int countRez = rez.nrcif - 1;
    int k = 0;

    while(i >= 0 && j >= 0)
    {
        if(V.a[i] + obiect.V.a[j] >= 10 && k == 0)
        {
            rez.V.a[countRez] = (V.a[i] + obiect.V.a[j] + k) % 10;
            k = 1;
        }
        else if(V.a[i] + obiect.V.a[j] < 10 && k == 0)
        {
            rez.V.a[countRez] = V.a[i] + obiect.V.a[j] + k;
            k = 0;
        }
        else if(V.a[i] + obiect.V.a[j] >= 10 && k == 1)
        {
            rez.V.a[countRez] = (V.a[i] + obiect.V.a[j] + k) % 10;
            k = 1;
        }

        else if(V.a[i] + obiect.V.a[j] < 10 && k == 1)
        {
            rez.V.a[countRez] = (V.a[i] + obiect.V.a[j] + k) % 10;

            if((V.a[i] + obiect.V.a[j] + k) >= 10)
                k = 1;
            else
                k = 0;
        }
        i--;
        j--;
        countRez--;
    }

    while(i >= 0)
    {
        if(k == 1 && V.a[i] + k >= 10)
        {
            rez.V.a[countRez] = (V.a[i] + k) % 10;
            k = 1;
        }
        else if( k == 1 && V.a[i] + k < 10)
        {
            rez.V.a[countRez] = (V.a[i] + k) % 10;
            k = 0;
        }
        else if( k == 0 )
            rez.V.a[countRez] =V.a[i];

        i--;
        countRez--;
    }
    while(j >= 0)
    {
        if(k == 1 && obiect.V.a[j] + k >= 10)
        {
            rez.V.a[countRez] = (obiect.V.a[j] + k) % 10;
            k = 1;
        }
        else if( k == 1 && obiect.V.a[j] + k < 10)
        {
            rez.V.a[countRez] = (obiect.V.a[j] + k) % 10;
            k = 0;
        }
        else if( k == 0 )
            rez.V.a[countRez] =obiect.V.a[j];
        j--;
        countRez--;
    }

    if(k == 1 && countRez >= 0)
    {
        rez.V.a[countRez] = k;
        k = 0;
        countRez--;
    }
    else if(k == 0 && countRez >= 0)
    {
        rez.V.a = &rez.V.a[1];
        rez.nrcif--;
    }

    return rez;
}
istream& operator >> (istream& in,Numar_Natural_Mare& ob1 )
{
    cout <<"Introduceti numarul de cifre :";
    in >> ob1.nrcif;
    ob1.V.a = new int[ob1.nrcif];
    cout <<"Introduceti cifrele :";
    for (int i = 0; i < ob1.nrcif ; i++)
    {
        in >> ob1.V.a[i];
        try
        {
            if(ob1.V.a[i] > 10)
                throw(ob1.V.a[i]);
        }
        catch(int)
        {
            cout <<"Nu a fost introdusa o cifra.Se va introduce in vector valoarea numarului introdus % 10 : " << ob1.V.a[i] % 10 << endl;
            ob1.V.a[i] = ob1.V.a[i] % 10;
        }
    }

    return in;
}
ostream& operator << (ostream& out,Numar_Natural_Mare& ob1)
{
    for (int i = 0; i < ob1.nrcif; i++)
        out << ob1.V.a[i] << " ";

    return out;
}


///-------------------------------------------------------------CLASA NUMAR INTREG MARE--------------------/////////
class Numar_intreg_mare : public Numar_Natural_Mare
{
    string semn;

public:
    Numar_intreg_mare () { };

    Numar_intreg_mare( string s,int n, int* b ):Numar_Natural_Mare(n,b),semn(s) {}

    Numar_intreg_mare (const Numar_Natural_Mare &ob): Numar_Natural_Mare (ob)
    {
        semn = "+";
    }

    friend istream& operator >>(istream& in,Numar_intreg_mare& ob)
    {
        cout <<"Introduceti semnul numarului: ";
        in >> ob.semn;
        try
        {
            if(ob.semn != "+" && ob.semn != "-")
                throw(ob.semn);
        }
        catch(string)
        {
            cout << "S-a introdus o valoare gresita iar semnul numarul va fi initializat cu +" << endl;
            ob.semn = "+";
        }

        in >> (Numar_Natural_Mare&) ob;

        return in;
    }

    friend ostream& operator << (ostream& out,Numar_intreg_mare& ob)
    {
        out <<"(" << ob.semn<< ") ";
        out << (Numar_Natural_Mare&) ob;

        return out;
    }

    Numar_intreg_mare & operator = (const  Numar_intreg_mare &ob)
    {
        if(this != &ob)
        {
            Numar_Natural_Mare :: operator = (ob);
            semn = ob.semn;
        }
        return *this;
    }

    Numar_intreg_mare(const Numar_intreg_mare &ob) : Numar_Natural_Mare (ob)
    {
        semn = ob.semn;
    }

    Numar_intreg_mare operator + ( Numar_intreg_mare const obiect )
    {
        string semn1 = semn;
        string semn2 = obiect.semn;

        Numar_intreg_mare rez;
        if(semn == obiect.semn)
        {

            rez = Numar_Natural_Mare :: operator +(obiect);
            rez.semn = semn1;

        }
        else
        {
            rez = Numar_Natural_Mare :: operator -(obiect);
            if( nrcif > obiect.nrcif)
                rez.semn = semn;
            else if(nrcif < obiect.nrcif)
                rez.semn = obiect.semn;
            else
                for(int i = 0; i < nrcif; i++)
                {
                    if(V.a[i] > obiect.V.a[i])
                        rez.semn = semn;
                    else if(V.a[i] < obiect.V.a[i])
                        rez.semn = obiect.semn;
                }
        }

        return rez;
    }

    Numar_intreg_mare operator - ( Numar_intreg_mare const obiect )
    {
        string semn1 = semn;
        string semn2 = obiect.semn;
        Numar_intreg_mare rez;
        if(semn == obiect.semn)
        {
            rez = Numar_Natural_Mare :: operator -(obiect);
            if( nrcif > obiect.nrcif)
                rez.semn = semn;
            else if(nrcif < obiect.nrcif)
            {
                if(obiect.semn == "-")
                    rez.semn = "+";
                else if(obiect.semn == "+")
                    rez.semn = "-";
            }

            else
                for(int i = 0; i < nrcif; i++)
                {
                    if(V.a[i] > obiect.V.a[i])
                    {
                        rez.semn = semn;
                        break;
                    }

                    else if(V.a[i] < obiect.V.a[i])
                    {
                        if(obiect.semn == "-")
                            rez.semn = "+";
                        else if(obiect.semn == "+")
                            rez.semn = "-";
                        break;
                    }
                }
        }
        else
        {
            rez = Numar_Natural_Mare :: operator +(obiect);
            if(semn == "-")
                rez.semn = "-";
            else
                rez.semn = "+";
        }


        return rez;
    }

    ~Numar_intreg_mare()
    {
        semn ="";    /// ?
        delete[]V.a;
    }
};

class Management
{
    Numar_intreg_mare* v;
    int n;
public:
    friend istream & operator >>(istream&,Management&);
    friend ostream & operator << (ostream&,Management&);
    Numar_intreg_mare & operator [](int i)
    {
        return v[i];
    }
};
istream & operator >>(istream& in, Management& m)
{
    cout << "Introduceti numarul de numere intregi = ";
    in >> m.n;
    m.v = new Numar_intreg_mare[m.n];

    for(int i = 0; i < m.n ; i++)
        in >> m.v[i];
    return in;
}

ostream & operator << (ostream& out, Management& m)
{
    out << "Cele " << m.n << " numere sunt : " <<endl;
    for(int i=0; i < m.n; i++)
        out << m.v[i] << endl;

    return out;
}
int main()
{
    int ok;
    Management man;
    cin >> man;
    cout << "1 : Pentru afisarea numerelor " << endl;
    cout << "2 : Pentru adunarea a 2 numere si afisarea rezultatului "<<endl;
    cout << "3 : Pentru scaderea a 2 numere si afisarea rezultatului "<<endl;
    cout << "0 : Inchiderea programului "<<endl;

    Numar_intreg_mare rezAd;
    Numar_intreg_mare rezScd;
    while(ok)
    {
        cout <<"Alegeti optiunea :"<< endl;
        cin >> ok;
        switch(ok)
        {
        case 1:
            cout << man ;
            break;
        case 2:
            int i,j;
            cout << "Introduceti indicii celor 2 numere " << endl;
            cin >> i >> j;
            rezAd = man[i] + man[j];
            cout << man[i] << "+" << man[j] <<"=" <<rezAd<< endl;
            break;
        case 3:
            cout << "Introduceti indicii celor 2 numere " <<endl;
            cin >> i >> j;
            rezScd = man[i] - man[j];
            cout << man[i] << "-" << man[j] <<"=" <<rezScd<< endl;
            break;
        case 0:
            ok = 0;
            break;
        default:
            cout <<"Introduceti o optiune valida " <<endl;
            break;
        }
    }
    return 0;
}
