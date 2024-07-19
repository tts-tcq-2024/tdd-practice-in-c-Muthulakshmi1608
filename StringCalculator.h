#include <stdio.h>
#include<string.h>
#include<stdbool.h>

int is_delimiter(char c, const char *delims) {
  while (*delims != '\0') {
    if (c == *delims) {
      return 1;
    }
    delims++;
  }
  return 0;
}

int split_string(char *str, const char *delims, int visit_token(char*,int,int,int)) {
  char *start = str;
  int result;
  int flg;
  int count=0;
  //static int sum=0;
  int set=0;
  while (*str != '\0') {
    flg=is_delimiter(*str, delims);
    if (flg) {
      // Found a delimiter, terminate the current substring
      set++;
      *str = '\0';
      result=visit_token(start,flg,count,set); 
      printf("%sAAA\n",start);// Call a function to process the token (substring)
      start = str + 1;  // Update start pointer to next character after delimiter
    }
    str++;
    count++;
  }
  // Handle the last token (if any)
  if (*start != '\0') {
    result=visit_token(start,flg,count,set);
    printf("%dSSS\n",result);
  }
  return result;
}

int condition(int num)
{
  if(num>=0 && num<=1000)  
  {
      return num;
  }
  return 0;
}


int print_token(char *token,int flg,int count,int set) {
 
  static int sum=0;
  int prev=atoi(token);
  
  if(flg || (set>0))
  {
      //prev=atoi(token);
      printf("%dPrev\n",prev);
      sum=sum+prev;
      printf("%dSUM\n",sum);
      return sum;
  }
  
  if(!flg && (count>0) && set==0 )
  {
      int result=condition((atoi(token)));
      return (result);
  }
  
  return atoi(token);
  
}
