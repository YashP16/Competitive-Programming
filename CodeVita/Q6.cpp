#include <iostream>
#include <limits.h>
#include <string.h>
long long sum,N;
#define MAXN 200
int M[MAXN][MAXN];

int count = 1;
int a,b,c,d,e,f,g,h;
void Top(){
  sum += M[a][b];
  b++;
  //return;
}
void Right(){
  sum+= M[c][d];
  c++;
  //return;
}
void Bottom  (){
  sum+= M[e][f];
  f--;
  //return;
  }
void Left(){
    sum+= M[g][h];
  if(g == count ){
    a = count;
    b = count;
    c = count;
    d = (N-1) - count;
    e = (N-1) - count;
    f = (N-1) - count;
    g = (N-1) - count;
    h = count;
    count ++;
  }
  else g--;
  //return;
}
int main(){
  int T;
  std :: cin >> T;
  while(T--){
    int E;sum =0;count = 1;

    memset(M,0,sizeof(M));
    std :: cin >> N;
    std :: cin >> E;

    a=0;b=0;c=0;d=N-1;e=N-1;f=N-1;g=N-1;h=0;

    if(E > N*N || E < 0){
      std:: cout << "Invalid Input\n";
    }
    else{
      int counter = 1;
      //int M[N][N];
      for(int i =0; i<N; i++){ // creating matrix
        for(int j =0; j<N; j++){
          M[i][j] = counter;
          counter++;
        }
      }
      int t = 0;

      while (E >0){
        if((t%4)==0) Top();
        else if((t%4)==1) Right();
        else if((t%4)==2) Bottom();
        else if((t%4)==3) Left();
        t++;
        E--;
      }
      std::cout << sum << std::endl;
      }
  }
  return 0;
}
