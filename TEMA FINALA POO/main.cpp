
#include <iostream>

using namespace std;
class lista;

class nod
{
    int val;
    nod* next;

    friend class lista; /// toate functiile membre din clasa lista au acces la datele private din nod

    friend ostream& operator<<(ostream&, lista&);
    friend istream& operator >>(ostream& ,lista &);

};

class lista
{
private:
    int numar;
    nod* prim, *ultim;
public:

    lista()
    {
        /// CONSTRUCTOR DE INITIALIZARE
        prim = NULL;
        ultim= NULL;
        numar=0;

    }
    lista( const lista &bobi); /// CONSTRUCTOR DE COPIERE
    void citire(int *,int ); /// ADAUGAREA ELEMENTELOR IN LISTA
    void deletedup(); /// STERGEREA ELEM DUPLICATE
    lista operator +( lista const &multime );
    lista operator *( lista const &multime );
    lista operator -( lista const &multime );
    lista & operator =(lista const &multime);

    friend ostream& operator<<(ostream&, lista&);
    friend istream& operator >> (istream&, lista&);

    ~lista();


};

lista lista :: operator *(lista const &multime)///SUPRAINCARCAREA OPERATORULUI * (INTERSECTIA A 2 MULTIMI) scriem 2 de lista pentru ca primul este
///de la tipul returnat de date , in cazul nostru o lista, iar al doilea pentru ca apartine de clasa lista
{
    lista auxx;
    nod* col=multime.prim;
    nod* box;

    while(col!= NULL)
    {
        nod *ox = prim;
        while(ox != NULL )
        {
            if(col->val == ox->val)
            {
                if(auxx.prim == NULL)
                {
                    auxx.ultim=new nod;
                    auxx.prim=auxx.ultim;
                    box=auxx.ultim;
                    auxx.ultim->val=col->val;
                    auxx.ultim->next=NULL;
                    auxx.numar++;
                }
                else
                {
                    auxx.ultim=new nod;
                    auxx.ultim->val=col->val;
                    auxx.ultim->next=NULL;
                    box->next=auxx.ultim;
                    box=auxx.ultim;
                    auxx.numar++;
                }
            }
            ox=ox->next;
        }
        col=col->next;
    }
    if(auxx.prim==NULL)
            cout <<"Nu exista elemente comune " <<endl<< endl;
        else
            cout <<"Intersectia lui A cu B este  = "<< auxx <<endl;

    return auxx;


}
lista lista :: operator -(lista const &multime)///SUPRAINCARCAREA OPERATORULUI - (DIFERENTA A 2 MULTIMI)
{
    int ok;
    lista auxy;
    nod* col=multime.prim;
    nod* box;

    while(col!= NULL)
    {
        ok=0;
        nod *ox = prim;
        while(ox != NULL )
        {
            if(col->val == ox->val)
            {
                ok=1;
            }
            ox=ox->next;
        }
        if(ok == 0)
        {
            if(auxy.prim == NULL)
            {
                auxy.ultim=new nod;
                auxy.prim=auxy.ultim;
                box=auxy.ultim;
                auxy.ultim->val=col->val;
                auxy.ultim->next=NULL;
                auxy.numar++;
            }
            else
            {
                auxy.ultim=new nod;
                auxy.ultim->val=col->val;
                auxy.ultim->next=NULL;
                box->next=auxy.ultim;
                box=auxy.ultim;
                auxy.numar++;
            }

        }
        col=col->next;

    }
    if(auxy.prim ==  NULL)
        cout <<"Cele 2 liste sunt identice ";
    else
    cout <<"Diferenta dintre A/B este = " << auxy;
    return auxy;
}
lista lista :: operator +(lista const &multime)///SUPRAINCARCAREA OPERATORULUI + ( REUNIUNEA A 2 MULTIMI)
{
    lista aux;
    nod *ox,*leg;
    nod *col=prim;
    aux.numar=numar+multime.numar;

    ox=multime.prim;
    aux.ultim=new nod;
    aux.ultim->val=col->val;
    aux.ultim->next=NULL;
    aux.prim=aux.ultim;
    leg=aux.prim;
    col=col->next;

    while(col!=NULL)
    {
        aux.ultim=new nod;
        aux.ultim->val=col->val;
        aux.ultim->next=NULL;
        leg->next=aux.ultim;
        leg=leg->next;
        col=col->next;
    }
    while(ox!=NULL)
    {
        aux.ultim=new nod;
        aux.ultim->val=ox->val;
        aux.ultim->next=NULL;
        leg->next=aux.ultim;
        leg=leg->next;
        ox=ox->next;
    }

    return aux;

}
lista & lista :: operator =(lista const &bobi)
{
    if(bobi.prim == NULL)
     return *this;

    if(this != &bobi)
    {
    this->~lista();
    numar=bobi.numar;
    nod* aux2;
    aux2=bobi.prim;
    nod* aux1;

    nod* neew=new nod;
    neew->val=aux2->val;
    neew->next=NULL;
    prim=neew;
    aux1=neew;
    aux2=aux2->next;

    while (aux2!=NULL)
    {
        nod* neew=new nod;
        neew->val=aux2->val;
        neew->next=NULL;
        aux1->next=neew;
        aux1=aux1->next;
        aux2=aux2->next;
    }
    }
    return *this;
}

lista :: lista (const lista &bobi)/// CONSTRUCTOR DE COPIERE
{
    numar=bobi.numar;
    nod* aux2;
    aux2=bobi.prim;
    nod* aux1;
     if(bobi.prim == NULL)
        cout << "Nu s-a copiat nimic"<< endl;
     else
     {
    nod* neew=new nod;
    neew->val=aux2->val;
    neew->next=NULL;
    prim=neew;
    aux1=neew;
    aux2=aux2->next;

    while (aux2!=NULL)
    {
        nod* neew=new nod;
        neew->val=aux2->val;
        neew->next=NULL;
        aux1->next=neew;
        aux1=aux1->next;
        aux2=aux2->next;
    }
     }


}

lista :: ~lista() /// DESTRUCTORUL
{
        if(prim == NULL){
           ///cout<<"lista a fost deja distrusa"<<endl;
            return;
        }else{
            nod *aux;
            while (prim!=NULL)
            {
                aux=prim;
                prim=prim->next;
                delete(aux);
            }

            ///cout << "S a apelat destructorul" <<endl;
            prim = NULL;
        }
    }

void lista::citire(int *x,int n) /// ADAUGAREA ELEMENTELOR IN LISTA
{
    numar=n;
    for (int i=0; i<n; i++)
    {
        nod *neew;
        nod *aux;
        neew=new nod;
        neew->val=x[i];
        neew->next=NULL;

        if(prim == NULL)
        {
            prim=neew;
        }
        else
        {
            aux=prim;
            while(aux->next != NULL)
                aux=aux->next;
            aux->next=neew;
        }
    }
}

void lista :: deletedup() ///STERGEREA ELEMENTELOR DUPLICATE
{
    nod *ptr1,*ptr2,*dup;

    ptr1=prim;

    while(ptr1 != NULL && ptr1->next != NULL)
    {

        ptr2=ptr1;
        while(ptr2->next != NULL)
        {
            if(ptr1->val == ptr2->next->val)
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete(dup);
                numar--;
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

ostream& operator << (ostream& out, lista& l) ///OPERATORUL DE AFISARE
{


    nod*p = l.prim;
    if(p==NULL)
    {
        out << " 0 "<<endl;
        return out;
    }
    else
    {
    while(p!=NULL)
    {
        out<<p->val<<" ";
        p = p->next;
    }
    out <<"Nr de elemente "<< l.numar;
    out<<endl;
    }
    return out;
}

istream &operator >> (istream& in,lista &l) ///OPERATOR DE CITIRE
{
    nod *p=l.prim;
    int ok,n;
    cout <<"Introduceti numarul de elemente din lista "<< endl ;
    in >> n;
    if(n!=0){
    int *aux=new int[n];
    cout <<"Inserati elementele "<< endl;
    for(int i=0;i<n;i++)
        in >> aux[i];
    l.citire(aux,n);
    }
    else
        cout <<"Nu exista elemente in lista " << endl;

    return in;
}

int main()
{
   // int x[]= {1,2,2,2,9,3,4,9};
    //int y[]= {5,4,3,11,1};
   // int *x, *y;

    lista multime1,multime2,multime4,multime5,multime6;
    //multime1.citire(x,8);
   // multime2.citire(y,5);

    cin >> multime1;
    cin >> multime2;
    cout <<"Multimea A este = " <<  multime1<< endl;
    cout <<"Multimea B este = " << multime2<< endl;
    multime1.deletedup();
    cout <<"Multimea A dupa stergerea elementelor duplicate este  = "<< multime1 << endl;
    lista multime3(multime1);
    cout <<"Multimea A copiata in C  = "<<  multime3<< endl;
    multime4=multime1+multime2;
    cout <<"Reuniunea lui A cu B multimi este  = "<< multime4<<endl;
    multime5=multime2*multime1;
    multime6=multime2-multime1;



    return 0;
}
