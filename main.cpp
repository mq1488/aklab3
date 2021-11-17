#include <iostream>
#include <getopt.h>
#include <vector>
#include <algorithm>

using namespace std;


int main (int argc, char *argv[]){
  const char* shortOptions = "hvcl:";

  const struct option longOptions[] = {
    {"help", no_argument, NULL, 'h'},
    {"version", no_argument, NULL, 'v'},
    {"test", no_argument, NULL, 't'},
    {"value", required_argument, NULL, 's'},
    {NULL,0,NULL,0}
  };

  int res;
  int optnIndex;

  vector<int> resOfParsingArgs;

  while ((res=getopt_long(argc, argv, shortOptions, longOptions, &optnIndex))!=-1){

    if (binary_search(resOfParsingArgs.begin(), resOfParsingArgs.end(), res)){
      continue;
    }
    else {
      resOfParsingArgs.push_back(res);
    }

    switch (res)
    {
      case 'h':
        cout << "Arg: Help\n";
        break;
      case 'v':
        cout << "Arg: Version\n";
        break;
      case 't':
        cout << "Arg: Test\n";
        break;
      case 's':
        cout << "Arg:Value:  " << optarg << endl;
        break;
      
      default:
        break;
    }
  }
    return 0;
}
