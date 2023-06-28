#ifndef SPI_H_
#define SPI_H_
void SPI_MASTER_INIT(void);
void SPI_SLAVE_INIT(void);
void MASTER_SEND(unsigned char Data);
unsigned char SLAVE_RESIVE(void);

#endif /* SPI_H_ */
