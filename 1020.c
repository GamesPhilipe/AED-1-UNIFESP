#include <stdio.h>
 
int main() {
    int a, m, d, i, r;
    
    scanf("%d", &i);
    a = i / 365;
    r = i % 365;
    m = r / 30;
    d = r % 30;
    
    printf("%d ano(s)\n", a);
    printf("%d mes(es)\n", m);
    printf("%d dia(s)\n", d);
    
    return 0;
}
