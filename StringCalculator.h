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

bool positive_single_digit(int count,int set,char *str)
{
    return ((count>0) && set==0 && (!isalpha(*str)));
}

bool positive_single_number(int flg,int count,int set,char *str)
{
    bool is_singledigit=positive_single_digit(count,set,str);
    return (!flg  && is_singledigit);
}
bool positive_multiple_digits(int flg,int count,int set,char *str)
{
    return ((flg || (set>0)) && (!isalpha(*str)));
}

bool positive_multiple_numbers(int flg,int set,char *str,int count)
{
    bool is_multipledigits=positive_multiple_digits(flg,count,set,str);
    return (is_multipledigits);
}

int visit_token(const char *token,int flg,int count,int set) {
 
  static int sum=0;
  int prev=atoi(token);
  bool pos_mn=positive_multiple_numbers(flg,set,token,count);
  bool pos_sn=positive_single_number(flg,count,set,token);
  
  if(pos_mn)
  {
    prev=condition(prev);
      sum=sum+prev;
      return sum;
  }
  
  if(pos_sn)
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
      *start='\0';
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
  const char delims[] = ",;\n[]*//";
  int result=0;
  result=split_string(input, delims);  
  return result;
}
