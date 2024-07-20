#include<stdio.h>
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



int condition(int num)
{
  if(num>=0 && num<=1000)  
  {
      return num;
  }
  return 0;
}

bool positive_single_number(int flg,int count,int set)
{
    return (!flg  && (count>0) && set==0);
}

bool positive_multiple_numbers(int flg,int set)
{
    return(flg || (set>0));
}

int visit_token(const char *token,int flg,int count,int set) {
 
  static int sum=0;
  int prev=atoi(token);
  
  if(positive_multiple_numbers)
  {
      sum=sum+prev;
      return sum;
  }
  
  if(positive_single_number)
  {
      int result=condition((atoi(token)));
      return (result);
  }
  
  return atoi(token);
  
}

int last_token(int flg,int set,char *strptr,int count,int result)
{
  if (*strptr != '\0') {
    result=visit_token(strptr,flg,count,set);
    return result;
  }
  return result;
}

int split_string(const char *str, const char *delims) {
  char *start;
  start = (char *)malloc(strlen(str) + 1);
  strcpy(start,str);
  char *strptr = start;
  int result=0;
  int flg;
  int count=0;
  int set=0;
  while (*start != '\0') {
    flg=is_delimiter(*start, delims);
    if (flg) {
      // Found a delimiter, terminate the current substring
      set++;
   
      result=visit_token(strptr,flg,count,set);
      strptr = start + 1;  // Update start pointer to next character after delimiter
    }
    start++;
    count++;
  }
  // Handle the last token (if any)
  result=last_token(flg,set,strptr,count,result);
  return result;
}


int add(const char* input)
{
  char delims[] = ",;\n[]*//";
  int result=0;
  result=split_string(input, delims);  
  return result;
}
