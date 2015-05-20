/*
* copyLeft by Mustafa Aldemir
* 18.05.2015
* find the IPs that make too many requests 
*/
#include <stdlib.h>
#include <string>
#include <iostream>
#include <map>
 
using namespace std;
 
int main(int argc, char* argv[])
{
  map<string, int> mymap;
  string s;
  int limit;
  int size;
 
  if(argc==2){
    limit = atoi(argv[1]);
  } else {
    cout << "Usage:" << endl << "tail -f /var/log/apache2/access.log | awk -Winteractive '{print $1}' | findleechers 10" << endl;
    return 0;
  }
 
  cout << "limit: " << limit <<endl;
 
  while (cin >> s)
  {
    if ( mymap.count(s)>0 ){
      mymap[s]++;
      if ( (limit <= mymap[s]) && (0 == (mymap[s]%limit)) ){
        cout << s << " " << mymap[s] << endl;                                                                                            
      }                                                                                                                                  
    } else {
      mymap.insert( pair<string,int>(s,1) );
    }
 
    size = mymap.size();
    if(10000 < size){
      cout << "Exiting: size has grown too big" << endl;
      return 0;
    }
    /*
    if(0 == (size % 100)){
      cout << "map size: " << size << endl;
    }
    */
  }
 
 return 0;
}
