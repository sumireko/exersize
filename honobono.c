#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

int a = 10000;
int f = 440;
int n = 16460;

void sound(int);
int main(){
  int onpu[]={-2,-2,-2,-2,-2,-4,-4,0, -2,-2,-2,-9,-4,-5,-7,-5,-9,-9,-9,-2,-2,-4,2,3,-2,-2,-2,-2,-2,-2,-2,-2, -2,-2,-2,-2,-2,-4,-4,0,-2,-2,-2,3,3,3,5,7,3,3,3,10,10,8,5,2,3,3,3,3,3,3,3,3};
  int length;
  length=64;

  int i;

  for(i=0;i<length-1;i++){
    sound(onpu[i]);
  } 
  return 0;
}

void sound(int m){
   short data[n];
   int i;
  for(i=0;i<n;i++){
    data[i]=a*sin(2*M_PI*f*pow(2,m/12.0)*i/44100);
  }
  write(1,data,n*2);
}
