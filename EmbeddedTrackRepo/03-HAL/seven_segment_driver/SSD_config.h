
#ifndef _SSD_CONFIG_H_
#define _SSD_CONFIG_H_

/*Comment!: Number of displays */
/*Range!  : 0 ~ 6 */
#define SSD_u8DISPCOUNT 		2

/***********************************************************************/
/****************************DISPLAY1***********************************/
/***********************************************************************/
/*Range!  : SSD_u8COMMCATH - SSD_u8COMMAND*/
#define SSD_u8DISP1TYPE 	     SSD_u8COMMCATH
/*Range!  : SSD_u8NUM0 ~ SSD_u8NUM9 */
#define SSD_u8DISP1_INITVAL		 SSD_u8NUM0
/*Range!  : SSD_u8ONSTATE - SSD_u8OFFSTATE */
#define SSD_u8DISP1_INITSTATE    SSD_u8ONSTATE
/*Range!  : DIO_u8PIN0 - DIO_u8PIN31 */
#define SSD_u8DISP1_INITCOM		 DIO_u8PIN0
#define SSD_u8DISP1_SEGA	     DIO_u8PIN1
#define SSD_u8DISP1_SEGB         DIO_u8PIN2
#define SSD_u8DISP1_SEGC         DIO_u8PIN3
#define SSD_u8DISP1_SEGD         DIO_u8PIN4
#define SSD_u8DISP1_SEGE         DIO_u8PIN5
#define SSD_u8DISP1_SEGF         DIO_u8PIN6
#define SSD_u8DISP1_SEGG         DIO_u8PIN7

/***********************************************************************/
/****************************DISPLAY2***********************************/
/***********************************************************************/
/*Range!  : SSD_u8COMMCATH - SSD_u8COMMAND*/
#define SSD_u8DISP2TYPE 		  SSD_u8COMMCATH
/*Range!  : SSD_u8NUM0 ~ SSD_u8NUM9 */
#define SSD_u8DISP2_INITVAL		  SSD_u8NUM1
/*Range!  : SSD_u8ONSTATE - SSD_u8OFFSTATE */
#define SSD_u8DISP2_INITSTATE     SSD_u8ONSTATE
/*Range!  : DIO_u8PIN0 - DIO_u8PIN31 */
#define SSD_u8DISP2_INITCOM       DIO_u8PIN8
#define SSD_u8DISP2_SEGA          DIO_u8PIN1
#define SSD_u8DISP2_SEGB          DIO_u8PIN2
#define SSD_u8DISP2_SEGC          DIO_u8PIN3
#define SSD_u8DISP2_SEGD          DIO_u8PIN4
#define SSD_u8DISP2_SEGE          DIO_u8PIN5
#define SSD_u8DISP2_SEGF          DIO_u8PIN6
#define SSD_u8DISP2_SEGG          DIO_u8PIN7

/***********************************************************************/
/****************************DISPLAY3***********************************/
/***********************************************************************/
/*Range!  : SSD_u8COMMCATH - SSD_u8COMMAND*/
#define SSD_u8DISP3TYPE 		 SSD_u8COMMCATH
/*Range!  : SSD_u8NUM0 ~ SSD_u8NUM9 */
#define SSD_u8DISP3_INITVAL      SSD_u8NUM2
/*Range!  : SSD_u8ONSTATE - SSD_u8OFFSTATE */
#define SSD_u8DISP3_INITSTATE    SSD_u8ONSTATE
/*Range!  : DIO_u8PIN0 - DIO_u8PIN31 */
#define SSD_u8DISP3_INITCOM      DIO_u8PIN16
#define SSD_u8DISP3_SEGA         DIO_u8PIN17
#define SSD_u8DISP3_SEGB         DIO_u8PIN18
#define SSD_u8DISP3_SEGC         DIO_u8PIN19
#define SSD_u8DISP3_SEGD         DIO_u8PIN20
#define SSD_u8DISP3_SEGE         DIO_u8PIN21
#define SSD_u8DISP3_SEGF         DIO_u8PIN22
#define SSD_u8DISP3_SEGG         DIO_u8PIN23

/***********************************************************************/
/****************************DISPLAY4***********************************/
/***********************************************************************/
/*Range!  : SSD_u8COMMCATH - SSD_u8COMMAND*/
#define SSD_u8DISP4TYPE 		 SSD_u8COMMCATH
/*Range!  : SSD_u8NUM0 ~ SSD_u8NUM9 */
#define SSD_u8DISP4_INITVAL      SSD_u8NUM3
/*Range!  : SSD_u8ONSTATE - SSD_u8OFFSTATE */
#define SSD_u8DISP4_INITSTATE    SSD_u8ONSTATE
/*Range!  : DIO_u8PIN0 - DIO_u8PIN31 */
#define SSD_u8DISP4_INITCOM      DIO_u8PIN24
#define SSD_u8DISP4_SEGA         DIO_u8PIN25
#define SSD_u8DISP4_SEGB         DIO_u8PIN26
#define SSD_u8DISP4_SEGC         DIO_u8PIN27
#define SSD_u8DISP4_SEGD         DIO_u8PIN28
#define SSD_u8DISP4_SEGE         DIO_u8PIN29
#define SSD_u8DISP4_SEGF         DIO_u8PIN30
#define SSD_u8DISP4_SEGG         DIO_u8PIN31

/***********************************************************************/
/****************************DISPLAY5***********************************/
/***********************************************************************/
/*Range!  : SSD_u8COMMCATH - SSD_u8COMMAND*/
#define SSD_u8DISP5TYPE		     SSD_u8COMMCATH
/*Range!  : SSD_u8NUM0 ~ SSD_u8NUM9 */
#define SSD_u8DISP5_INITVAL      SSD_u8NUM2
/*Range!  : SSD_u8ONSTATE - SSD_u8OFFSTATE */
#define SSD_u8DISP5_INITSTATE    SSD_u8ONSTATE
/*Range!  : DIO_u8PIN0 - DIO_u8PIN31 */
#define SSD_u8DISP5_INITCOM      DIO_u8PIN8
#define SSD_u8DISP5_SEGA         DIO_u8PIN1
#define SSD_u8DISP5_SEGB         DIO_u8PIN2
#define SSD_u8DISP5_SEGC         DIO_u8PIN3
#define SSD_u8DISP5_SEGD         DIO_u8PIN4
#define SSD_u8DISP5_SEGE         DIO_u8PIN5
#define SSD_u8DISP5_SEGF         DIO_u8PIN6
#define SSD_u8DISP5_SEGG         DIO_u8PIN7

/***********************************************************************/
/****************************DISPLAY6***********************************/
/***********************************************************************/
/*Range!  : SSD_u8COMMCATH - SSD_u8COMMAND*/
#define SSD_u8DISP6TYPE 		  SSD_u8COMMCATH
/*Range!  : SSD_u8NUM0 ~ SSD_u8NUM9 */
#define SSD_u8DISP6_INITVAL       SSD_u8NUM0
/*Range!  : SSD_u8ONSTATE - SSD_u8OFFSTATE */
#define SSD_u8DISP6_INITSTATE     SSD_u8ONSTATE
/*Range!  : DIO_u8PIN0 - DIO_u8PIN31 */
#define SSD_u8DISP6_INITCOM       DIO_u8PIN0
#define SSD_u8DISP6_SEGA          DIO_u8PIN1
#define SSD_u8DISP6_SEGB          DIO_u8PIN2
#define SSD_u8DISP6_SEGC          DIO_u8PIN3
#define SSD_u8DISP6_SEGD          DIO_u8PIN4
#define SSD_u8DISP6_SEGE          DIO_u8PIN5
#define SSD_u8DISP6_SEGF          DIO_u8PIN6
#define SSD_u8DISP6_SEGG          DIO_u8PIN7

#endif /* SSD_CONFIG_H_ */
