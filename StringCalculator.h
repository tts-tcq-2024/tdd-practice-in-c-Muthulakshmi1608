int stringcount(const char* input)
{
  int count;
  int i=0;
while(input[i++]!='\0')
   {
     count++;
   }
  return count;
}

bool positiveno(int a,const char* input)
{
  return (a==1 && (input<=1000) && (input>=0));
}

char string_nodelimiter(const char* input)
{
  int a;
  a=stringcount(input);
  if(positiveno(a,input))
  {
    return input;
  }
}

int add(const char* input)
{
  if (input == NULL || input[0] == '\0') {
        return 0; // The string is empty
    }
  return -1;
}
