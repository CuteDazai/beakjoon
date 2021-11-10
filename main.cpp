




/*
// 1157
//이 문제를 풀면서 약간의 시행착오가 있었다. 밑의 코드를 보면 ar_2 배열이 char형으로 선언되어 있는데 테스트 케이스들을 입력했을때 이상없이 작동되었지만, 백준에서는 계속 틀렸다. 이유를 생각해보니 for 문을 한번 돌 때마다 ar_2 배열의 인덱스가 1씩 증가하므로, 이를 int형으로 선언해야 되었던 것 같다. 실제로 ar_2를 int로 선언하니 백준에서도 바로 로 성공으로 처리했다.

//출처: https://amanteattirance.tistory.com/62 [Anything]
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
    int alpha[26]={0,};
    
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




// 2908
#include <stdio.h>

// 숫자를 뒤집줌
int reverseNum(int num)
{
    int revNum=0, hund=100;
    while(num>0)
    {
        revNum += num%10*hund;
        hund/=10;
        num/=10;
    }
    return revNum;
}
int main()
{
    int a=0, b=0;
    
    scanf("%d %d", &a, &b);
    a=reverseNum(a);
    b=reverseNum(b);
    printf("%d %d", a, b);
    
}



// 1152
#include <stdio.h>

int main()
{
    int cnt=0;
    char sent[1000001];
    
    scanf("%[^\n]", sent);
    
    if(sent[0]!=' ') cnt++;

    for(int i=0; sent[i+1]!='\0'; ++i)
    {
        if(sent[i]==' '&&sent[i+1]!=' ')
            cnt++;
    }
    
    printf("%d", cnt);
}


// 2475
#include <stdio.h>

int main()
{
    int num=0, sum=0;
    for(int i=0; i<5; ++i)
    {
        scanf("%d", &num);
        num*=num;
        sum+=num;
    }
    printf("%d", sum%10);
}


// 2675
#include <stdio.h>

int main()
{
    int testCase=0, R=0;
    char str[21]={0,};
    
    scanf("%d", &testCase);
    for(int i=0; i<testCase; ++i)
    {
        scanf("%d %s", &R, str);
        for(int j=0; str[j]!='\0'; ++j)
            for(int k=0; k<R; ++k) printf("%c", str[j]);
        printf("\n");
    }
}


// 10809
#include <stdio.h>

int main()
{
    int alpha[26]={0,}, len=0;
    char a[101]={0,};
    
    scanf("%s", a);
    while(a[len]) len++;  //문자열의 길이 구하기

    for(int i=len; i>=0; --i)
    {
        alpha[a[i]-97]=i+1;
    }
    
    for(int i=0; i<26; ++i)
    {
        if(alpha[i]==0) printf("%d ", -1);
        else printf("%d ", alpha[i]-1);
    }
}

// 11720
#include <stdio.h>

int main()
{
    int n=0, sum=0;
    char num[101];
    scanf("%d %s", &n, num);
    
  for(int i=0; num[i]!='\0'; ++i)
    sum += num[i]-48;

  printf("%d", sum);
}


// 1065
#include <stdio.h>

int checkhonshu(int num)
{
    int front=0, back=0, gap=0;
    
    back = num%10;
    num /= 10;
    front = num%10;
    gap = front-back;
    
    while(num>0)
    {
        back = num%10;
        num /= 10;
        if(num==0)  break;
        front = num%10;
        if(gap != front-back)
            return 0;
        gap = front-back;
    }
    return 1;
}

int main()
{
    int num=0, cnt=99;
    
    scanf("%d", &num);
    
    if(num<100) printf("%d", num);
    else
    {
      for(int i=100; i<num+1; ++i)
        if(checkhonshu(i)) cnt++;
      printf("%d", cnt);
    }
}




// 4673
#include <stdio.h>
void makeSelfNumber(int num, int* arr)
{
    int selfnumber=num;
    while(num>0)
    {
        selfnumber += num%10;
        num /= 10;
    }

    if(selfnumber<10001)
      *(arr+selfnumber) = 1;
}

int main()
{
    int arr[10000]={0,};
    
    for(int i=1; i<10001; ++i)
        makeSelfNumber(i, arr);
    
    for(int i=1; i<10001; ++i)
        if(!arr[i]) printf("%d\n", i);
}


// 4344
#include <stdio.h>

int main()
{
    int c=0, n=0, pass=0;
    int student[1000]={0,};
    double sum_score=0;
    
    scanf("%d", &c);


    for(int i=0; i<c; ++i)
    {
        scanf("%d", &n);

      for(int i=0; i<n; ++i)
      {
        scanf("%d", &student[i]);
        sum_score+=student[i];
      }
      
      for(int i=0; i<n; ++i)
        if(sum_score/n<student[i]) pass++;

      printf("%.3lf%%\n", (double)pass/n*100.0);

      pass = 0;
      sum_score = 0;
    }
}


// 8958
#include <stdio.h>

int main()
{
    int n=0, score=0, point=1;
    char testcase[80]={0,};
    
    scanf("%d", &n);
    
    for(int i=0; i<n; ++i)
    {
        scanf("%s", testcase);
        for(int j=0; testcase[j]!='\0'; ++j)
        {
            if(testcase[j]=='O')
            {
              score += point;
              point ++;
          }else if(testcase[j]=='X')
            point = 1;
        }
        printf("%d\n", score);
        point = 1;
        score = 0;
    }
}



// 1546
#include <stdio.h>

int main()
{
  int n=0, max=0;
  double sum=0;

  double score[1000] = {0,};

  scanf("%d", &n);
  for(int i=0; i<n; ++i)
  {
    scanf("%lf", &score[i]);
    if(max<score[i]) max = score[i];
  }

  for(int i=0; i<n; ++i)
  {
    score[i] = score[i]/max*100.0f;
    sum +=  score[i];
  }

  printf("%lf", sum/n);
}


// 3052
#include <stdio.h>

int main()
{
    int num[10]={};
    int cnt=10;
    
    for(int i=0; i<10; ++i)
    {
      scanf("%d", &num[i]);
      num[i] %=42;
      //printf("%d\n", num[i]);
    }
    
    for(int i=0; i<9; ++i)
    {
      for(int j=i+1; j<10; ++j)
      {
        if(num[i]==-1) break;

        if(num[i]==num[j])
        {
          cnt--;
          num[j] = -1;
        }
      }
    }
    
    printf("%d", cnt);
}




#include <stdio.h>

int main()
{
    int a=0, b=0, c=0, num=0;
    int str[10]={};
    
    scanf("%d %d %d", &a, &b, &c);
    num = a*b*c;
    
    if(num==0) str[0]++;
    
    while(num!=0)
    {
        str[num%10]++;
        num/=10;
    }
    
    for(int i=0; i<10; ++i)
        printf("%d\n", str[i]);
}


#include <stdio.h>

int main()
{
    int num=0, max=0, cnt=1;
    
    scanf("%d", &max);
    
    for(int i=1; i<9; ++i)
    {
        scanf("%d", &num);
        if(num>max)
        {
            max = num;
            cnt = i+1;
        }
    }
    
    printf("%d\n%d", max, cnt);
}




// 10818
#include <stdio.h>

int main()
{
    int len=0, max=0, min=0;
    scanf("%d", &len);
    int num[len];
    printf("%d", len);

    for(int i=0; i<len; ++i)
    {
        scanf("%d", &num[i]);
        printf("%d", num[i]);
    }
    
    max = num[0];
    min = num[0];
    
    for(int i=1; i<len; ++i)
    {
        max = (max>num[i]) ? max : num[i];
        min = (min<num[i]) ? min : num[i];
    }

    printf("%d %d", min, max);
}
#include <stdio.h>

int main()
{
    int n=0, max=0, min=0, input=0;
    
    scanf("%d", &n);
    
    scanf("%d", &input);
    
    max = input;
    min = input;
    
    for(int i=0; i<n-1; ++i)
    {
        scanf("%d", &input);
        if(max<n) max = input;
        if(min>n) min = input;
    }
    printf("%d %d", min, max);
}


// 1110
#include <stdio.h>

int main()
{
    int cnt=0, num=0, num2=0;
    
    scanf("%d", &num);
    num2 = num;

    do{
      num2 = num2%10*10+(num2/10+num2%10)%10;
      cnt++;
    }while(num!=num2);

    printf("%d", cnt);
}


// 10951
#include <stdio.h>

int main()
{
    int a=0, b=0;
    
    while(scanf("%d %d", &a, &b)!=EOF)
        printf("%d\n", a+b);
}


// 10952
#include <stdio.h>

int main()
{
  int a=0, b=0;
    
  scanf("%d %d", &a, &b);

  while(a!=0||b!=0)
  {
    printf("%d\n", a+b);
    scanf("%d %d", &a, &b);
  }
}


#include <bits/stdc++.h>

int main()
{
    int t=0, a=0, b=0;
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin>>t;
    
    for(int i=0; i<t; ++i)
    {
        std::cin>>a>>b;
        std::cout<<a+b<<'\n';
    }
}
*/