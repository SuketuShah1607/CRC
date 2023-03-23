#include <stdio.h>
#include <stdlib.h>

#define CRC_LENGTH  4
#define POLYNOMIAL  0xd

int message = 0;
int crcComputationBuff = 0;

int main()
{

    int i=0;

    message = 0x24;
    message = 0x24 << (CRC_LENGTH - 1) ;        //Padding 0 to form divdend

    crcComputationBuff = message;

    for(i=16;i>0;i--)
    {
        if( (( crcComputationBuff >> i ) & 0x01) == 1 )
        {
            printf(" %x %d\n",crcComputationBuff,i);
            if( i > (CRC_LENGTH - 1) )
                crcComputationBuff ^= ( POLYNOMIAL << (i-(CRC_LENGTH - 1)) ) ;
            else
                crcComputationBuff ^= ( POLYNOMIAL ) ;
        }
    }
    printf(" %x %d\n",crcComputationBuff,i);

    return 0;
}
