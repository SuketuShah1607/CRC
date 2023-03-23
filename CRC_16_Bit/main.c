#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define GENERATOR_POLYNOMIAL    (0xA001U)//(0x8005U)
#define CRC_INITIAL_VALUE       (0x0000U)//(0xFFFFU)

uint8_t message[5] = { 0x11 , 0x30, 0x01, 0x01, 0x12 } ;
uint8_t size = 5 ;

uint16_t crc_16_generator( uint8_t *msg , uint8_t size ) ;

int main()
{
    uint16_t crc = 0 ;
    crc = crc_16_generator(message,size) ;
    printf( "%x" , crc ) ;
    return 0;
}

uint16_t crc_16_generator( uint8_t *msg , uint8_t len )
{
    uint16_t crcReg = CRC_INITIAL_VALUE ;
    uint8_t tempBuff = 0 ;
    uint8_t count = 0 ;
    uint8_t count2 = 0 ;

    for( count2 = 0 ; count2 < len ; count2++ )
    {

        crcReg ^=  msg[count2] ;

        for( count = 0 ; count < 8 ; count++ )
        {

            tempBuff = ( crcReg & 0x1 ) ;

            crcReg = crcReg >> 1 ;

            if( tempBuff == 1 )
            {
                crcReg ^=  GENERATOR_POLYNOMIAL ;
            }
        }
    }

    return crcReg ;

}
