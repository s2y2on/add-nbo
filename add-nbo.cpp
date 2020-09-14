#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>
 
void add(uint32_t n1, uint32_t n2) {
	n1 = ntohl(n1);
	n2 = ntohl(n2);
    	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",n1, n1, n2, n2, n1+n2, n1+n2);
}

int main(int argc, char *argv[]) {
    uint32_t bin1, bin2; 
    FILE *f1, *f2;
    f1 = fopen(argv[1], "r");
    f2 = fopen(argv[2], "r");
    
    fread(&bin1, 1, 32, f1); 
    fread(&bin2, 1, 32, f2);
    
    add(bin1, bin2);
    
    fclose(f1); 
    fclose(f2);
}

