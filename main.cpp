
#include <stdio.h>
// 단어 전체를 소문자로 바꿔줌
void changeToLow(char* word)
{
    for(int i=0; word[i]!='\0'; ++i)
      if(word[i]<'a')
        word[i]+='a'-'A';
}
int main()
{
    int max=0;
    char result = 0;
    char word[1000001];
    int alpha[26]={0,}; //char형으로 선언하게 되면 알파벳 하나의
    //중복횟수가 255가 넘는 경우 오버플로가 발생해 오답처리됨
    
    scanf("%s", word);
    
    changeToLow(word);
    //printf("%s", word);
    for(int i=0; word[i]!='\0'; ++i)
      alpha[word[i]-'a']++;    
    
    for(int i=0; i<'z'-'a'+1; ++i)
    {
      if(alpha[i]>max)
      {
        max = alpha[i];
        result = i+'A';
      }else if(alpha[i]==max) result = -1;
    }
    if(result == -1) printf("?");
    else printf("%c", result);
}
