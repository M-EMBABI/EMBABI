/*
 * STD_MACROS.h
 *
 * Created: 2/11/2023 5:26:08 AM
 *  Author: MOHAMMED
 */ 


#define register_size 8
#define SET_BET(reg,bit) reg|=(1<<bit)
#define CLR_BIT(reg,bit) reg&=~(1<<bit)
#define TOG_BIT(reg,bit) reg^=(1<<bit)
#define READ_BIT(reg,bit) ((reg&(1<<bit))>>bit)
#define IS_BIT_SET(reg,bit) ((reg&(1<<bit))>>bit)
#define IS_BIT_CLR(reg,bit) !((reg&(1<<bit))>>bit)
#define ROL(reg,num) reg=(reg<<(num))|(reg>>(register_size-num))
#define ROR(reg,num) reg=(reg>>(num))|(reg<<(register_size-num))
