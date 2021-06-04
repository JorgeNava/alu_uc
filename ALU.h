void show_bits( unsigned int x ){
    int i=0;
    for (i = (sizeof(int) * 2) - 1; i >= 0; i--){
        putchar(x & (1u << i) ? '1' : '0');
    }
    printf("\n");
}
unsigned toBits(unsigned k) {
    if (k == 0) return 0;
    if (k == 1) return 1;
    return (k % 2) + 10 * toBits(k / 2);
}

void alu(
            unsigned iA, 
            unsigned iB, 
            int opCode,
            unsigned *rslt, 
            unsigned *status, 
            int showBits
            ){
    short i;
    unsigned temp;
    switch(opCode){
        case 0:                 //RESTA
            temp = iA - iB;
            break;
        case 1:                 //AND
            temp = iA & iB;
            break;
        case 2:                 //OR
            temp = iA | iB;
            break;
        case 3:                 //NOT
            temp = ~iA;
            break;
        case 4:                 //XOR
            temp = iA ^ iB;
            break;
        case 5:                 //COMPLEMENTO A 1
            temp = ~iA;
            break;
        case 6:                 //!COMPLEMENTO A 2
            temp = ~iA + 1; // + 4'b0001
            break;
        case 7:                 //!RECORRIMIENTO ARIT IZQ
            temp = iA << iB;
            break;
        case 8:                 //!RECORRIMIENTO ARIT DER
            temp = iA >> iB;
            break;
        case 9:                 //!RECORRIMIENTO LOG IZQ
            temp = iA << iB;
            break;
        case 10:                 //!RECORRIMIENTO LOG DER
            temp = iA >> iB;
            break;
        case 11:                 //!RECORRIMIENTO CIRC IZQ
            temp = iA << iB;
            break;
        case 12:                 //!RECORRIMIENTO CIRC DER
            temp = iA >> iB;
            break;
        case 13:                 //SUMA
            temp = iA + iB;
            break;
    }

    status[0] = (temp == 0);             //ZERO
    status[1] = temp < 0;                //NEGATIVE
    //status[2] = temp[4];               //!CARRY
    //status[1] = (temp[3:0] > 4'd7);    //!OVERFLOW
    //status[0] = ~^temp[3:0]            //!PARITY

    status[2] = 0;
    status[3] = 0;
    status[4] = 0;

    //*rslt = temp[3:0];                  //4-BITS RESULT
    *rslt = temp;

    if(showBits){
        printf("\tiA: %u -",iA); 
        show_bits(iA);
        printf("\tiB: "); 
        show_bits(iB);
        printf("\topCode: "); 
        show_bits(opCode);
        printf("\ttemp: "); 
        show_bits(temp);
        printf("\trslt: "); 
        show_bits(*rslt);
        printf("\tstatus: "); 
        for (i = 0; i < 5; ++i)
            printf( "%d", status[i]);
        printf("\n");
    }
} 