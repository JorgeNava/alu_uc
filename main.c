#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALU.h"
#include "UC.h"
/*        Dec Hex Binary C1    C2
          0	   0  0000  0000  0000
          1	   1  0001  0001  0001
          2	   2  0010  0010  0010
          3	   3  0011  0011  0011
          4	   4  0100  0100  0100
          5	   5  0101  0101  0101
          6	   6  0110  0110  0110
          7	   7  0111  0111  0111
          8	   8  1000  1000  1000
          9	   9  1001  1001  1001
          10	 a  1010  1010  1010
          11	 b  1011  1011  1011
          12	 c  1100  1100  1100
          13	 d  1101  1101  1101
          14	 e  1110  1110  1110
          15	 f  1111  1111  1111
*/
// * alu(iA, iB, opCode, showBits)

void use_alu(short op, unsigned iA, unsigned iB, int opCode, unsigned *rslt, unsigned *status, int showBits){
  short i;
  printf("OP-%d: \n",op);
  alu(iA, iB, opCode, rslt, status, showBits);
  printf("R: %u - %u\n",*rslt,toBits(*rslt));
/*   printf("R: %u - ",*rslt);
  show_bits(*rslt); */
  printf("Status: "); 
  for (i = 0; i < 5; ++i)
      printf("%d", status[i]) ;
}

int main(){
  printf("=== CONTROL UNIT ===\n");  
  unsigned r, i;
  unsigned *rslt = &r, status[5];

  /* use_alu() 
    short op, unsigned iA, unsigned iB, int opCode, 
    unsigned *rslt, unsigned *status, int showBits
  */
  use_alu(1, -1, 1, 0, rslt, status, 1);
}
