#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Vector
{
private:
  int *arr;
  int lungime;

public:
    Vector (int numar, int dimensiune)
  {
    arr = (int *) malloc (sizeof (int) * dimensiune);
      lungime = dimensiune;
    for (int i = 0; i < dimensiune; i++)
      {
	    arr[i] = numar;
      }
  }
  Vector (const Vector &v)
  {
    arr = (int *) malloc (sizeof (int) * v.lungime);
    lungime = v.lungime;
    for (int i = 0; i < lungime; i++)
      {
	arr[i] = v.arr[i];
      }
  }
  
  ~Vector ()
  {
    free (arr);
  }

  void reallocate (int numar, int dimensiune)
  {
    free (arr);
    arr = (int *) malloc (sizeof (int) * dimensiune);
    lungime = dimensiune;
    for (int i = 0; i < dimensiune; i++)
      {
	arr[i] = numar;
      }
  }
  int sum ()
  {
    int sum = 0;
    for (int i = 0; i < lungime; i++)
      {
	sum += arr[i];
      }
  }
  int maxPozitie (int *max)
  {
    int mx = arr[0];
    int poz = 0;
    for (int i = 0; i < lungime; i++)
      {
	if (arr[i] > mx)
	  {
	    poz = i;
	    mx = arr[i];
	  }
      }
    *max = mx;
    return poz;
  }

  void sort ()
  {
    std::sort (arr, arr + lungime);
  }

  void operator= (const Vector & vect)
  {
    for (int i = 0; i < lungime; i++)
      {
	arr[i] = vect.arr[i];
      }
  }

  friend std::ostream & operator<< (std::ostream & os, const Vector & vect)
  {
    for (int i = 0; i < vect.lungime; i++)
      {
	os << vect.arr[i] << " ";
      }
    return os;
  }
  friend std::istream & operator>> (std::istream & in, Vector & vect)
  {

    for (int i = 0; i < vect.lungime; i++)
      {
	in >> vect.arr[i];
      }
    return in;
  }

  Vector operator* (const Vector & v)
  {
    Vector vect (v);

    for (int i = 0; i < lungime; i++)
      {
	vect.arr[i] = arr[i] * v.arr[i];
      }
    return vect;
  }
};

void citire_afisare(){
    int n;
    cout<<"numar vectori"<<'\n';
    cin >> n;
    for(int i=0;i<n;i++){
        int length;
        cout<<"dimensiune vector"<<'\n';
        cin>>length;
        Vector v1(1,length);
        cout<<"elementele vectorului"<<'\n';
        cin>>v1;
         cout<<"elementele sunt"<<'\n';
        cout<<v1;
    }
  
}

main ()
{   
    Vector v(2,10);
    Vector v1(v);
    
    v=v1*v;
    v1=v;
    cout<<v1;

  citire_afisare();
  return 0;
}
