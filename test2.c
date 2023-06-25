#include <stdio.h> 
#include<stdlib.h>
#include <string.h>
void QuestionsMarks(char str[]) {  
  // code goes here  
  int i,j,t=0;
  for(i=0;str[i];i++)
  {
      if(str[i]>='0' &&  str[i]<='9')
      {
          for(j=i+1;str[j];j++)
          {
          if(str[j]=='?')
                {
                    t++;
                    continue;
                }
            else if(t>=3 && str[j]>='0' && str[j]<='9')
                {
                    printf("true");
                    exit(0);
                }
            else if(t<3 && str[j]>='0' && str[j]<='9')
                break;
          }
          t=0;
      }  
  }
      printf("false");
            
}
int main(void) { 
  
  // keep this function call here
  char a[] = "arrb6???4xxbl5???eee5";
  QuestionsMarks(a);
  return 0;
    
}
