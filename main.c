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
int main(){
  printf("=== CONTROL UNIT ===\n");  
  printf("OP-1: \n");
  int r;
  r = alu(13, 1, 13, 1);
  printf("R: %u",toBits(r));
  //unsigned int rsltBit = toBits(r[0]);
  //printf("%u - %u\n", r[0],rsltBit);
  //show_bits(rslt);
  //alu(5,2,0,1);
}  