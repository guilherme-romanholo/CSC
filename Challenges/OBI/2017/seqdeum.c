#include <stdio.h>

int main (int argc, char *argv[])
{
  int num, v[10] = {1,11,111,1111,11111,111111,1111111,11111111,111111111}, i = 0, j;
  scanf("%d",&num);
  while (num >= v[i]) {
      j = v[i]/num;
      if (j*num == v[i]) {
        break;
      }
      i++;
  }
  printf("%d\n",j);
  return 0;
}
