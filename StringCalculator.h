#include<stdio.h>
#include<string.h>
#include<stdbool.h>

/*To find out the delimiter in the input string*/
int is_delimiter(char c, const char *delims) {
  while (*delims != '\0') {
    if (c == *delims) {
      return 1;
    }
    delims++;
  }
  return 0;
}

bool conditioncheck_for_number(int num)
{
  return (num>=0 && num<=1000);
}

/* Condition check for a number */
int condition(int num)
{
  bool conditioncheck = conditioncheck_for_number(num);
  if(conditioncheck)
  {
      return num;
  }
  else if(num<0)
  {
    printf("Negatives %d not allowed",num);
    return -1;
  }
  return 0;
}

/* positive single digit logic inorder to reduce the complexity logic for the positive_single_number function*/
bool positive_single_digit(int count,int set,char *token)
{
    return ((count>0) && set==0 && (!isalpha(*token)));
}

bool positive_single_number(int flg,int count,int set,char *token)
{
    bool is_singledigit=positive_single_digit(count,set,token);
    return (!flg  && is_singledigit);
}

/* positive multiple digits logic inorder to reduce the complexity logic for the positive_multiple_numbers function*/
bool positive_multiple_digits(int flg,int count,int set,char *token)
{
    return ((flg || (set>0)));
}

bool positive_multiple_numbers(int flg,int set,char *token,int count)
{
    bool is_multipledigits=positive_multiple_digits(flg,count,set,token);
    return (is_multipledigits);
}

int stringcalculation(char *token,int flg,int count,int set) {
 
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

int last_character(int flg,int set,char *strptr,int count,int result)
{
  if (*strptr != '\0') {
    result=stringcalculation(strptr,flg,count,set);
    return result;
  }
  return result;
}

/* Splitting the strings into substring logic for calculation */
int split_string(const char *str, const char *delims) {
  char *copyptr;
  copyptr = (char *)malloc(strlen(str) + 1);
  strcpy(copyptr,str);//Copying the input string into copyptr inorder to form substring from the input
  char *strptr = copyptr;
  int flg,result=0;
  int count=0;
  int set=0;
  while (*copyptr != '\0') {
    flg=is_delimiter(*copyptr, delims);
    if (flg) {
      set++;
      // Found a delimiter, terminate the current substring
      *copyptr='\0';
      result=stringcalculation(strptr,flg,count,set);
      strptr = copyptr + 1;  // Update start pointer to next character after delimiter
    }
    copyptr++;
    count++;
  }
  // Handle the last character (if any)
  result=last_character(flg,set,strptr,count,result);
  return result;
}


int add(const char* input)
{
  const char delims[] = ",;\n[]*//";
  int result=0;
  result=split_string(input, delims);  
  return result;
}
