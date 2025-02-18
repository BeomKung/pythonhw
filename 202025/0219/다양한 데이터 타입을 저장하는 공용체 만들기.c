#include <stdio.h>

void main()
{  

        union num {
                int intVal;
                float floatVal;
                char charVal;
            };
            
            union num n;
            n.floatVal = 3.14;
            n.intVal = 100;
            n.charVal = 'C';
            
            printf("%f %d\n", n.floatVal, &n.floatVal);
            printf("%d %d\n", n.intVal, &n.intVal);
            printf("%c %d\n", n.charVal, &n.charVal);
}
