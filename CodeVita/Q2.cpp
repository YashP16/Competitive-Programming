
#include<iostream>
#include<math.h>
bool isprime(int n){
  for(int i = 2; i<= sqrt(n); i++){
    if(n%i == 0){
      return false;
    }
  }
    return true;
}


int main (){
  long int N;
  int i;
  std::cin >> N;
  std::cin >> i;
  int counter=0;
  for(long int j =2; j <=N; j++){
    int flag =0;
    if(isprime(j)){
      int temp=j;
      for(int a =0; a < i; a++){
        temp = temp*2 +1;
        if(isprime(temp)){
          flag = 1;
        }
        else{
          flag = 0;
          break;
        }
      }
    }
    if (flag == 1){
      std:: cout << j << " ";
    }
  }
  return 0;
}
