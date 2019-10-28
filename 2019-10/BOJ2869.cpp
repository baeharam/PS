#include <cstdio>

int a,b,v;

int main(void)
{
  scanf("%d%d%d",&a,&b,&v);
  int r = (v-a)%(a-b);
  printf("%d\n",(r?(v-a)/(a-b)+1:(v-a)/(a-b))+1);
  return 0;
}