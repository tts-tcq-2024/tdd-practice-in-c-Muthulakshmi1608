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

int split_string(const char *str, const char *delims, int visit_token(const char*,int,int,int)) {
  char *start;
  start = (char *)malloc(strlen(str) + 1);
  strcpy(start,str);
  char *strptr = start;
  int result;
  int flg;
  int count=0;
  int set=0;
  while (*start != '\0') {
    flg=is_delimiter(*start, delims);
    if (flg) {
      // Found a delimiter, terminate the current substring
      set++;
     *start='\0';
      result=visit_token(strptr,flg,count,set);
      strptr = start + 1;  // Update start pointer to next character after delimiter
    }
    start++;
    count++;
  }
  // Handle the last token (if any)
  if (*strptr != '\0') {
    result=visit_token(strptr,flg,count,set);
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


int print_token(const char *token,int flg,int count,int set) {
 
  static int sum=0;
  int prev=atoi(token);
  
  if(flg || (set>0))
  {
      //prev=atoi(token);
      sum=sum+prev;
      return sum;
  }
  
  if(!flg && (count>0) && set==0 )
  {
      int result=condition((atoi(token)));
      return (result);
  }
  
  return atoi(token);
  
}

int add(const char* input)
{
  char delims[] = ",;\n[]*//";
  int result=0;
  result=split_string(input, delims, print_token);  
  return result;
}
