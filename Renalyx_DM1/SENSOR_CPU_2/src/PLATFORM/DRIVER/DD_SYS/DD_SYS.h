/*
 * DD_SYS.h
 *
 * Created: 3/8/2017 3:18:28 PM
 *  Author: Electrical
 */ 


#ifndef DD_SYS_H_
#define DD_SYS_H_

#include "asf.h"

#include "Platform/Driver/DRIVER_CALLS.h"
#include "Platform/Service/SENSOR_SV_INTERFACE.h"



/* ALL FEEDBACK PINS ARE DECLARED HERE*/

#define   PS1_DRDY_N_status  ( ( (PIOD->PIO_PDSR) >> 2 ) & 1 )
#define   PS2_DRDY_N_status  ( ( (PIOD->PIO_PDSR) >> 1 ) & 1 )
#define   PS3_DRDY_N_status  ( ( (PIOD->PIO_PDSR) >> 0 ) & 1 )

#define   DRDY_TS1_status     ( ( (PIOA->PIO_PDSR) >> 15 ) & 1 )
#define   DRDY_TS2_status  ( ( (PIOA->PIO_PDSR) >> 16 ) & 1 )
#define   DRDY_TS3_status  ( ( (PIOA->PIO_PDSR) >> 20 ) & 1 )

#define   DRDY_CS1_TS_status     ( ( (PIOA->PIO_PDSR) >> 17 ) & 1 )
#define   DRDY_CS2_TS_status  ( ( (PIOA->PIO_PDSR) >> 18 ) & 1 )
#define   DRDY_CS3_TS_status  ( ( (PIOA->PIO_PDSR) >> 19 ) & 1 )

#define   THERMOCOUPLE_DRDY_status  ( ( (PIOA->PIO_PDSR) >> 14 ) & 1 )

typedef union  {
	uint8_t bytearray[2] ;
	uint16_t Twobyte  ;
}dd_data_size;



/************************************************************************/
/* ADS1120 commands                                                                   */
/************************************************************************/

#define ADS1120_RESET         0b00000110
#define ADS1120_START_OR_SYNC 0b00001000
#define ADS1120_POWERDOWN     0b00000010
#define ADS1120_RDATA         0b00010000

#define  ADS1120_RREG_START_REG_ADR_Pos 2 
#define  ADS1120_RREG_START_REG_ADR_MSK (0x3u << ADS1120_RREG_START_REG_ADR_Pos)
#define  ADS1120_RREG_START_REG_ADR(value) ((ADS1120_RREG_START_REG_ADR_MSK & ((value) << ADS1120_RREG_START_REG_ADR_Pos)))
#define  ADS1120_RREG_NO_OF_BYTES_Pos 0
#define  ADS1120_RREG_NO_OF_BYTES_MSK (0x3u << ADS1120_RREG_NO_OF_BYTES_Pos)
#define  ADS1120_RREG_NO_OF_BYTES(value) ((ADS1120_RREG_NO_OF_BYTES_MSK & ((value) << ADS1120_RREG_NO_OF_BYTES_Pos)))
#define  ADS1120_RREG_COMMAND  0b00100000

#define  ADS1120_WREG_START_REG_ADR_Pos 2
#define  ADS1120_WREG_START_REG_ADR_MSK (0x3u << ADS1120_RREG_START_REG_ADR_Pos)
#define  ADS1120_WREG_START_REG_ADR(value) ((ADS1120_RREG_START_REG_ADR_MSK & ((value) << ADS1120_RREG_START_REG_ADR_Pos)))
#define  ADS1120_WREG_NO_OF_BYTES_Pos 0
#define  ADS1120_WREG_NO_OF_BYTES_MSK (0x3u << ADS1120_WREG_NO_OF_BYTES_Pos)
#define  ADS1120_WREG_NO_OF_BYTES(value) ((ADS1120_WREG_NO_OF_BYTES_MSK & ((value) << ADS1120_WREG_NO_OF_BYTES_Pos)))
#define  ADS1120_WREG_COMMAND  0b01000000

/****CONFIG_REG0 STARTS HERE*/
#define   ADS1120_CONFIG_REG0_PGA_BYPASS  (0x1u << 0)


#define   ADS1120_CONFIG_REG0_GAIN_POS 1
#define   ADS1120_CONFIG_REG0_GAIN_MSK (0X7u << ADS1120_CONFIG_REG0_GAIN_POS )
#define   ADS1120_CONFIG_REG0_GAIN(value)  ((ADS1120_CONFIG_REG0_GAIN_MSK & ((value) << ADS1120_CONFIG_REG0_GAIN_POS)))

typedef enum {
	ADS1120_DEVICE_GAIN_1,
	ADS1120_DEVICE_GAIN_2,
	ADS1120_DEVICE_GAIN_4,
	ADS1120_DEVICE_GAIN_8,
	ADS1120_DEVICE_GAIN_16,
	ADS1120_DEVICE_GAIN_32,
	ADS1120_DEVICE_GAIN_64,
	ADS1120_DEVICE_GAIN_128	
}ADS1120__GAIN_TYPE;

#define   ADS1120_CONFIG_REG0_MUX_POS 4
#define   ADS1120_CONFIG_REG0_MUX_MSK (0Xfu << ADS1120_CONFIG_REG0_MUX_POS )
#define   ADS1120_CONFIG_REG0_MUX(value)  ((ADS1120_CONFIG_REG0_MUX_MSK & ((value) << ADS1120_CONFIG_REG0_MUX_POS)))

typedef enum {
	 ADS1120_MUX_AIN0_AIN1,
	 ADS1120_MUX_AIN0_AIN2,
	 ADS1120_MUX_AIN0_AIN3,
	 ADS1120_MUX_AIN1_AIN2,
	 ADS1120_MUX_AIN1_AIN3,
	 ADS1120_MUX_AIN2_AIN3,
	 ADS1120_MUX_AIN1_AIN0,
	 ADS1120_MUX_AIN3_AIN2,
	 ADS1120_MUX_AIN0_AVSS,
	 ADS1120_MUX_AIN1_AVSS,
	 ADS1120_MUX_AIN2_AVSS,
	 ADS1120_MUX_AIN3_AVSS,
	 ADS1120_MUX_V_REFPx_M_V_REFNx_D_4,
	 ADS1120_MUX_AVDD_M_AVSS_D_4,
	 ADS1120_MUX_AINP_AND_AINN_shorted_AVDD_A_AVSS
	 }ADS1120_MUX_TYPE;



/****CONFIG_REG0 ENDS HERE*/


/****CONFIG_REG1 STARTS HERE*/
#define   ADS1120_CONFIG_REG1_BCS  (0x1u << 0)
#define   ADS1120_CONFIG_REG1_TS   (0x1u << 1)
#define   ADS1120_CONFIG_REG1_CM   (0X1u << 2)

typedef enum  {
	ADS1120_MODE_MORMAL,
	ADS1120_MODE_DUTY_CYCLE,
	ADS1120_MODE_TURBO,
	ADS1120_MODE_Reserved,
	
}ADS1120_MODE_TYPE;


#define   ADS1120_CONFIG_REG1_MODE_Pos 3
#define   ADS1120_CONFIG_REG1_MODE_MSK (0X3u << ADS1120_CONFIG_REG1_MODE_Pos )
#define   ADS1120_CONFIG_REG1_MODE(value)  ((ADS1120_CONFIG_REG1_MODE_MSK & ((value) << ADS1120_CONFIG_REG1_MODE_Pos)))

typedef enum  {
	ADS1120_DR_20_SPS,
	ADS1120_DR_45_SPS,
	ADS1120_DR_90_SPS,
	ADS1120_DR_170_SPS,
	ADS1120_DR_330_SPS,
	ADS1120_DR_600_SPS,
	ADS1120_DR_1000_SPS,	
}ADS1120_DR_TYPE;
#define   ADS1120_CONFIG_REG1_DR_Pos 5
#define   ADS1120_CONFIG_REG1_DR_MSK (0X7u << ADS1120_CONFIG_REG1_DR_Pos )
#define   ADS1120_CONFIG_REG1_DR(value)  ((ADS1120_CONFIG_REG1_DR_MSK & ((value) << ADS1120_CONFIG_REG1_DR_Pos)))
/****CONFIG_REG1 ENDS HERE*/

/****CONFIG_REG2 STARTS HERE*/
typedef enum  {
	ADS1120_IDAC_OFF,
	ADS1120_ICAD_RESERVED,
	ADS1120_IDAC_50UA,
	ADS1120_IDAC_100UA,
	ADS1120_IDAC_250UA,
	ADS1120_IDAC_500UA,
	ADS1120_IDAC_1000UA,
	ADS1120_IDAC_1500UA,
}ADS1120_IDAC_CURRENT_SETTING_TYPE;
#define   ADS1120_CONFIG_REG2_IDAC_Pos  0
#define   ADS1120_CONFIG_REG2_IDAC_MSK  (0X7u << ADS1120_CONFIG_REG2_IDAC_Pos )
#define   ADS1120_CONFIG_REG2_IDAC(value)   ((ADS1120_CONFIG_REG2_IDAC_MSK & ((value) << ADS1120_CONFIG_REG2_IDAC_Pos)))

#define  ADS1120_CONFIG_REG2_PSW (0x1u << 3)

typedef enum  {
	ADS1120_FIR_OFF=0,
	ADS1120_FIR_50_60_REJECTION,
	ADS1120_50_REJECTION,
	ADS1120_60_REJECTION,

}ADS1120_FIR_FILTER_CONFIGURATION_TYPE;
#define  ADS1120_CONFIG_REG2_50_60_Pos  4
#define  ADS1120_CONFIG_REG2_50_60_MSK  (0X3u << ADS1120_CONFIG_REG2_50_60_Pos )
#define  ADS1120_CONFIG_REG2_50_60(value)  ((ADS1120_CONFIG_REG2_50_60_MSK & ((value) << ADS1120_CONFIG_REG2_50_60_Pos)))


typedef enum  {
	ADS1120_VREF_INTERNAL_2P048,
	ADS1120_EXTERNAL_REF_REFP0_REFN0,
	ADS1120_EXTERNAL_REF_REFP1_REFN1,
	ADS1120_AVDD_AVSS,

}ADS1120_VREF_SEL_TYPE;
#define  ADS1120_CONFIG_REG2_VREF_Pos  6
#define  ADS1120_CONFIG_REG2_VREF_MSK  (0X3u << ADS1120_CONFIG_REG2_VREF_Pos )
#define  ADS1120_CONFIG_REG2_VREF(value) ((ADS1120_CONFIG_REG2_VREF_MSK & ((value) << ADS1120_CONFIG_REG2_VREF_Pos)))    

/****CONFIG_REG3 STARTS HERE*/
#define   ADS1120_CONFIG_REG3_DRDYM  (0x1u << 1)


typedef enum  {
	ADS1120_IDAC2_DISABLED,
	ADS1120_IDAC2_AIN0_OR_REFP1,
	ADS1120_IDAC2_AIN1,
	ADS1120_IDAC2_AIN2,
    ADS1120_IDAC2_AIN3_OR_REFN1,
    ADS1120_IDAC2_REFP0,
    ADS1120_IDAC2_REFN0,
}ADS1120_IDAC2_ROUTING_TYPE;
#define   ADS1120_CONFIG_REG3_I2MUX_Pos  2
#define   ADS1120_CONFIG_REG3_I2MUX_MSK  (0X7u << ADS1120_CONFIG_REG3_I2MUX_Pos)
#define   ADS1120_CONFIG_REG3_I2MUX(value)  ((ADS1120_CONFIG_REG3_I2MUX_MSK & ((value) << ADS1120_CONFIG_REG3_I2MUX_Pos)))


typedef enum  {
	ADS1120_IDAC1_DISABLED,
	ADS1120_IDAC1_AIN0_OR_REFP1,
	ADS1120_IDAC1_AIN1,
	ADS1120_IDAC1_AIN2,
	ADS1120_IDAC1_AIN3_OR_REFN1,
	ADS1120_IDAC1_REFP0,
	ADS1120_IDAC1_REFN0,
}ADS1120_IDAC1_ROUTING_TYPE;

#define   ADS1120_CONFIG_REG3_I1MUX_Pos  5
#define   ADS1120_CONFIG_REG3_I1MUX_MSK  (0X7u << ADS1120_CONFIG_REG3_I1MUX_Pos)
#define   ADS1120_CONFIG_REG3_I1MUX(value)  ((ADS1120_CONFIG_REG3_I1MUX_MSK & ((value) << ADS1120_CONFIG_REG3_I1MUX_Pos)))
/****CONFIG_REG3 ENDS HERE*/




/************************************************************************/
/* ADS1248 COMMANDS                                                                     */
/************************************************************************/
#define  ADS1248_WAKEUP 0b00000000
#define  ADS1248_SLEEP  0b00000010
#define  ADS1248_SYNC1  0b00000100  
#define  ADS1248_RESET  0b00000110
#define  ADS1248_NOP    0b11111111
#define  ADS1248_RDATA  0b00010010
#define  ADS1248_RDATAC 0b00010100
#define  ADS1248_SDATAC 0b00010110

#define ADS1248_RREG_FIRST_REG_Pos 0
#define ADS1248_RREG_FIRST_REG_MSK (0xfu << ADS1248_RREG_FIRST_REG_Pos)
#define ADS1248_RREG_FIRST_REG(value) ((ADS1248_RREG_FIRST_REG_MSK & ((value) << ADS1248_RREG_FIRST_REG_Pos)))
#define ADS1248_RREG_COMMAND  0b00100000

#define ADS1248_RREG_2_NUM_OF_BYTES_Pos 0
#define ADS1248_RREG_2_NUM_OF_BYTES_MSK (0xfu << ADS1248_RREG_2_NUM_OF_BYTES_Pos)
#define ADS1248_RREG_2_NUM_OF_BYTES(value) ((ADS1248_RREG_2_NUM_OF_BYTES_MSK & ((value) << ADS1248_RREG_2_NUM_OF_BYTES_Pos)))
#define ADS1248_RREG_2_COMMAND  0b00000000

#define  ADS1248_WREG_FIRST_REG_Pos 0
#define  ADS1248_WREG_FIRST_REG_MSK (0xfu << ADS1248_WREG_FIRST_REG_Pos)
#define  ADS1248_WREG_FIRST_REG(value) ((ADS1248_WREG_FIRST_REG_MSK & ((value) << ADS1248_WREG_FIRST_REG_Pos)))
#define  ADS1248_WREG_COMMAND  0b01000000

#define ADS1248_WREG_2_NUM_OF_BYTES_Pos 0
#define ADS1248_WREG_2_NUM_OF_BYTES_MSK (0xfu << ADS1248_WREG_2_NUM_OF_BYTES_Pos)
#define ADS1248_WREG_2_NUM_OF_BYTES(value) ((ADS1248_WREG_2_NUM_OF_BYTES_MSK & ((value) << ADS1248_WREG_2_NUM_OF_BYTES_Pos)))
#define ADS1248_WREG_2_COMMAND  0b00000000

#define  ADS1248_SYSOCAL  0b01100000
#define  ADS1248_SYSGCAL  0b01100001
#define  ADS1248_SELFOCAL 0b01100010

/****CONFIG_of_REG STARTS HERE_ MUX0*/

#define   ADS1248_MUX0_SN_AIN0 0
#define   ADS1248_MUX0_SN_AIN1 1
#define   ADS1248_MUX0_SN_AIN2 2
#define   ADS1248_MUX0_SN_AIN3 3
#define   ADS1248_MUX0_SN_AIN4 4
#define   ADS1248_MUX0_SN_AIN5 5
#define   ADS1248_MUX0_SN_AIN6 6
#define   ADS1248_MUX0_SN_AIN7 7
#define   ADS1248_MUX0_MUX_SN_Pos 0
#define   ADS1248_MUX0_MUX_SN_Msk (0x7u << ADS1248_MUX0_MUX_SN_Pos)
#define   ADS1248_MUX0_MUX_SN(value)  ((ADS1248_MUX0_MUX_SN_Msk & ((value) << ADS1248_MUX0_MUX_SN_Pos)))


#define  ADS1248_MUX0_SP_AIN0 0
#define  ADS1248_MUX0_SP_AIN1 1
#define  ADS1248_MUX0_SP_AIN2 2
#define  ADS1248_MUX0_SP_AIN3 3
#define  ADS1248_MUX0_SP_AIN4 4
#define  ADS1248_MUX0_SP_AIN5 5
#define  ADS1248_MUX0_SP_AIN6 6
#define  ADS1248_MUX0_SP_AIN7 7
#define   ADS1248_MUX0_MUX_SP_Pos 3
#define   ADS1248_MUX0_MUX_SP_Msk (0x7u << ADS1248_MUX0_MUX_SP_Pos)
#define   ADS1248_MUX0_MUX_SP(value)  ((ADS1248_MUX0_MUX_SP_Msk & ((value) << ADS1248_MUX0_MUX_SP_Pos)))

#define   ADS1248_MUX0_MUX_BCS_Pos 6
#define   ADS1248_MUX0_MUX_BCS_Msk (0x3u << ADS1248_MUX0_MUX_BCS_Pos)
#define   ADS1248_MUX0_MUX_BCS(value)  ((ADS1248_MUX0_MUX_BCS_Msk & ((value) << ADS1248_MUX0_MUX_BCS_Pos)))

typedef enum {
	ADS1248_BURN_OUT_CURRENT_SOURCE_OFF=0,
	ADS1248_BURN_OUT_CURRENT_SOURCE_ON_0P5UA,
	ADS1248_BURN_OUT_CURRENT_SOURCE_ON_2UA,
	ADS1248_BURN_OUT_CURRENT_SOURCE_ON_10UA	
} ADS1248_MUX0_MUX_BCS_FIELD_TYPE;


/******************************VBIAS_REGISTOR*************************************************************************/

#define   ADS1248_VBIAS_AIN0  (0x1u << 0)
#define   ADS1248_VBIAS_AIN1  (0x1u << 1)
#define   ADS1248_VBIAS_AIN2  (0x1u << 2)
#define   ADS1248_VBIAS_AIN3  (0x1u << 3)
#define   ADS1248_VBIAS_AIN4  (0x1u << 4)
#define   ADS1248_VBIAS_AIN5  (0x1u << 5)
#define   ADS1248_VBIAS_AIN6  (0x1u << 6)
#define   ADS1248_VBIAS_AIN7  (0x1u << 7)
/***********************************MUX1*******************/

typedef enum {
	ADS1248_NORMAL_OPERARION=0,
	ADS1248_OFFSET_CALIBRATION,
	ADS1248_GAIN_CALIBRATION,
	ADS1248_TEMPERATURE_MEASUREMENT,
	ADS1248_REF1_MONITOR,
	ADS1248_REF0_MONITOR,
	ADS1248_ANALOG_SUPPLY_MONITOR,
	ADS1248_DIGITAL_SUPPLY_MONITOR
} SYSTEM_MONITORS_CONTROL_MUXCAL_FIELD_TYPE;
#define  ADS1248_MUX1_MUXCAL_Pos 0
#define  ADS1248_MUX1_MUXCAL_Msk (0x7u << ADS1248_MUX1_MUXCAL_Pos)
#define  ADS1248_MUX1_MUXCAL(value)  ((ADS1248_MUX1_MUXCAL_Msk & (value << ADS1248_MUX1_MUXCAL_Pos))

typedef enum {
	ADS1248_REFP0_REFN0_REF_IP=0,
	ADS1248_REFP1_REFN1_REF_IP,
	ADS1248_INTERNAL_REF,
	ADS1248_INTERNAL_REF_CONN_TO_REFP0_REFNO
}ADS1248_REF_SEL_CONTROL_TYPES;
#define  ADS1248_MUX1_REFSELT_Pos 3
#define  ADS1248_MUX1_REFSELT_Msk (0x3u << ADS1248_MUX1_REFSELT_Pos)
#define  ADS1248_MUX1_REFSELT(value)  ((ADS1248_MUX1_REFSELT_Msk & ((value) << ADS1248_MUX1_REFSELT_Pos)))

typedef enum {
	ADS1248_INTERNAL_REF_ALWAYS_OFF=0,
	ADS1248_INTERNAL_REF_ALWAYS_ON,
	ADS1248_INTERNAL_REF_ON_WHEN_CONVERTION_STARTS_1,
	ADS1248_INTERNAL_REF_ON_WHEN_CONVERTION_STARTS_2
}ADS1248_VREFCONTOL_TYPES;
#define  ADS1248_MUX1_VREFCON_Pos 5
#define  ADS1248_MUX1_VREFCON_Msk (0x3u << ADS1248_MUX1_VREFCON_Pos)
#define  ADS1248_MUX1_VREFCON(value)  ((ADS1248_MUX1_VREFCON_Msk & ((value) << ADS1248_MUX1_VREFCON_Pos)))

#define  ADS1248_CLKSTAT (0x1u << 7)
/****************************SYS0_REG***********************************/


typedef enum{
	ADS1248_DR_SPS_5 = 0,
	ADS1248_DR_SPS_10,
	ADS1248_DR_SPS_20,
	ADS1248_DR_SPS_40,
	ADS1248_DR_SPS_80,
	ADS1248_DR_SPS_160,
	ADS1248_DR_SPS_320,
	ADS1248_DR_SPS_640,
	ADS1248_DR_SPS_1000,
	ADS1248_DR_SPS_2000
}ADS1248_DR_TYPES;
#define ADS1248_SYS0_DR_Pos 0
#define  ADS1248_SYS0_DR_Msk (0xfu << ADS1248_SYS0_DR_Pos)
#define  ADS1248_SYS0_DR(value)  ((ADS1248_SYS0_DR_Msk & ((value) << ADS1248_SYS0_DR_Pos)))


typedef enum {
	ADS1248_PGA_1,
	ADS1248_PGA_2,
	ADS1248_PGA_4,
	ADS1248_PGA_8,
	ADS1248_PGA_16,
	ADS1248_PGA_32,
	ADS1248_PGA_64,
	ADS1248_PGA_128
}ADS1248_SYS0_GAIN_TYPE;
#define  ADS1248_SYS0_PGA_Pos 4
#define  ADS1248_SYS0_PGA_Msk (0x7u << ADS1248_SYS0_PGA_Pos)
#define  ADS1248_SYS0_PGA(value)  ((ADS1248_SYS0_PGA_Msk & ((value) << ADS1248_SYS0_PGA_Pos)))

/********************************************************************************/


typedef enum {
	ADS1248_IDAC_EXCITATION_CURRENT_OFF=0,
	ADS1248_IDAC_EXCITATION_CURRENT_50UA,
	ADS1248_IDAC_EXCITATION_CURRENT_100UA,
	ADS1248_IDAC_EXCITATION_CURRENT_250UA,
	ADS1248_IDAC_EXCITATION_CURRENT_500UA,
	ADS1248_IDAC_EXCITATION_CURRENT_750UA,
	ADS1248_IDAC_EXCITATION_CURRENT_1000UA,
	ADS1248_IDAC_EXCITATION_CURRENT_1500UA
}ADS1248_IDAC_EXCITATION_CURRENT_TYPE;
#define  ADS1248_IDAC0_IMAG_Pos 0
#define  ADS1248_IDAC0_IMAG_Msk (0x7u << ADS1248_IDAC0_IMAG_Pos)
#define  ADS1248_IDAC0_IMAG(value)  ((ADS1248_IDAC0_IMAG_Msk & ((value) << ADS1248_IDAC0_IMAG_Pos)))





#define  ADS1248_DOUT_DRDY_MODE (0x1u << 3) 

/**********************IDAC1 REG**********************************/

#define ADS1248_IDAC1_I2DIR_Pos 0
#define ADS1248_IDAC1_I2DIR_Msk (0xf << ADS1248_IDAC1_I2DIR_Pos)
#define ADS1248_IDAC1_I2DIR(value)  ((ADS1248_IDAC1_I2DIR_Msk & ((value) << ADS1248_IDAC1_I2DIR_Pos)))
typedef enum   {
	ADS1248_AIN0 =0,
	ADS1248_AIN1,
	ADS1248_AIN2,
	ADS1248_AIN3,
	ADS1248_AIN4,
	ADS1248_AIN5,
	ADS1248_AIN6,
	ADS1248_AIN7,
	ADS1248_IEXC1,
	ADS1248_IEXC2,
	ADS1248_DISCONNECTED	
	} ADS1248_IDAC_EXCITATION_CURRENT_OUTPUT_TYPE;	
#define ADS1248_IDAC1_I1DIR_Pos 4
#define ADS1248_IDAC1_I1DIR_Msk (0xf << ADS1248_IDAC1_I1DIR_Pos)
#define ADS1248_IDAC1_I1DIR(value)  ((ADS1248_IDAC1_I1DIR_Msk & ((value) << ADS1248_IDAC1_I1DIR_Pos)))



#define ADS1248_GPIO_IOCFG_0 (0x1u <<0)
#define ADS1248_GPIO_IOCFG_1 (0x1u <<1)
#define ADS1248_GPIO_IOCFG_2 (0x1u <<2)
#define ADS1248_GPIO_IOCFG_3 (0x1u <<3)
#define ADS1248_GPIO_IOCFG_4 (0x1u <<4)
#define ADS1248_GPIO_IOCFG_5 (0x1u <<5)
#define ADS1248_GPIO_IOCFG_6 (0x1u <<6)
#define ADS1248_GPIO_IOCFG_7 (0x1u <<7)

#define ADS1248_GPIO_DIR_IP_0 (0x1u <<0)
#define ADS1248_GPIO_DIR_IP_1 (0x1u <<1)
#define ADS1248_GPIO_DIR_IP_2 (0x1u <<2)
#define ADS1248_GPIO_DIR_IP_3 (0x1u <<3)
#define ADS1248_GPIO_DIR_IP_4 (0x1u <<4)
#define ADS1248_GPIO_DIR_IP_5 (0x1u <<5)
#define ADS1248_GPIO_DIR_IP_6 (0x1u <<6)
#define ADS1248_GPIO_DIR_IP_7 (0x1u <<7)


typedef struct  {
	   uint8_t  ADS1248_MUX0;
	   uint8_t  ADS1248_VBIAS;	
	   uint8_t  ADS1248_MUX1;
	   uint8_t  ADS1248_SYS0;
	   uint8_t  ADS1248_OFC0;
	   uint8_t  ADS1248_OFC1;
	   uint8_t  ADS1248_OFC2;
	   uint8_t  ADS1248_FSC0;
	   uint8_t  ADS1248_FSC1;
	   uint8_t  ADS1248_FSC2;
	   uint8_t  ADS1248_IDAC0;
	   uint8_t  ADS1248_IDAC1;
	   uint8_t  ADS1248_GPIOCFG;
	   uint8_t  ADS1248_GPIODIR;
	   uint8_t  ADS1248_GPIODAT;	
} ADS1248_REGISTOR_MAP_TYPE;






/**********ad5174*********DIGITAL_POT*****************************DEFINED_HERE*/


typedef enum{
	AD5174_DO_NOTHING=0,
	AD5174_WRITE_SERIALREG_TO_RDAC,
	AD5174_READ_RDAC,
	AD5174_STORE_RDAC_TO_50TP,
	AD5174_SOFTWARE_RESET,
	AD5174_READ_50_TP_IN_NEXT_FRAME,
	AD5174_READ_ADRESS_OF_LAST_50TP_MEM_LOC,
	AD5174_WRITE_SERIAL_REG_TO_CONTRL_REG,
	AD5174_READ_CONTROLREG,
	AD5174_SOFTWARE_SHUTDOWN
}   AD5174_COMMAND_TYPE;

#define AD5174_COMMAND_Pos 3
#define AD5174_COMMAND_Msk ((0xfu) << AD5174_COMMAND_Pos)
#define AD5174_COMMAND(value)   ((AD5174_COMMAND_Msk & ((value) << AD5174_COMMAND_Pos)))

#define AD5174_CONT_REG_ENABLE_FOR_50_TP (0x1u << 0)
#define AD5174_CONT_REG_ALLOW_UPDT_DIG_POT_BY_SER_INTERFACE (0x1u << 1)

#define AD5174_CONTROL_REG_FUSE_PROGRAM_SUCCESSFUL (0x1u << 3)


/************************************************************************/
/* ADC128 INIT DONE HERE                                                                     */
/************************************************************************/
 typedef enum  {
	 ADC128S022_CONDUCTIVITY_SENSOR_RMS_VOLTAGE=0,
	 ADC128S022_CS1_SEN_RMS_CURRENT,
	 ADC128S022_CS2_SEN_RMS_CURRENT,
	 ADC128S022_DAA_SEN_RMS_CURRENT,
	 ADC128S022_DAB_SEN_RMS_CURRENT,
	 ADC128S022_DAC1_SEN_RMS_CURRENT,
	 ADC128S022_DAC2_SEN_RMS_CURRENT,
	 ADC128S022_CS3_SEN_RMS_CURRENT,
 } ADC128S022_ADC_IP_TYPE;

#define ADC128S022_ADC_IP_Pos 3
#define ADC128S022_ADC_IP_Msk  ((0x7u) << ADC128S022_ADC_IP_Pos)
#define ADC128S022_ADC_IP(value)   ((ADC128S022_ADC_IP_Msk & ((value) << ADC128S022_ADC_IP_Pos)))

/**********************************************************************************************************/




#define	FORCE_P_TO_CALIBRATION_RES_1  (0x1u << 0)
#define	RTD_P_TO_CALIBRATION_RES_1    (0x1u << 1)   
#define	RTD_M_TO_CALIBRATION_RES_2    (0x1u << 2)
#define	FORCE_M_TO_CALIBRATION_RES_2  (0x1u << 3)
#define	FORCE_P_TO_PT100_1   (0x1u << 4)
#define	RTD_P_TO_PT100_2     (0x1u << 5)
#define	RTD_M_TO_PT100_3     (0x1u << 6)
#define	FORCE_M_TO_PT100_4   (0x1u << 7)

#define  MAXIM_IC_TO_PT100  (FORCE_P_TO_PT100_1 | RTD_P_TO_PT100_2 | RTD_M_TO_PT100_3 | FORCE_M_TO_PT100_4)
#define  MAXIM_IC_TO_CALIBRATION_RES  (FORCE_P_TO_CALIBRATION_RES_1 | RTD_P_TO_CALIBRATION_RES_1 | RTD_M_TO_CALIBRATION_RES_2 | FORCE_M_TO_CALIBRATION_RES_2)


/************************************************************************/
/*     CONDUCTIVITY   mux1                                                             */
/************************************************************************/
#define CS1_GAIN_Pos 0
#define CS1_GAIN_Msk  ((0x7u) << CS1_GAIN_Pos)

#define  CS1_GAIN_X100   (0x1u << 0)
#define  CS1_GAIN_X1000  (0x1u << 1)
#define  CS1_GAIN_X10000 (0x1u << 2)


#define CS2_GAIN_Pos 3
#define CS2_GAIN_Msk  ((0x7u) << CS2_GAIN_Pos)

#define  CS2_GAIN_X100   (0x1u << 3)
#define  CS2_GAIN_X1000  (0x1u << 4)
#define  CS2_GAIN_X10000 (0x1u << 5)


#define DAA_GAIN_1_Pos 6
#define DAA_GAIN_1_Msk  ((0x3u) << DAA_GAIN_1_Pos)

#define  DAA_GAIN_X100   (0x1u << 6)
#define  DAA_GAIN_X1000  (0x1u << 7)

/************************************************************************/
/*       CONDUCTIVITY  mux2                                                           */
/************************************************************************/

#define DAA_GAIN_2_Pos 0
#define DAA_GAIN_2_Msk  ((0x1u) << DAA_GAIN_1_Pos)
#define  DAA_GAIN_X10000  (0x1u << 0)

/////////////////////////////////////////////////

#define DAB_GAIN_Pos 1
#define DAB_GAIN_Msk  ((0x7u) << DAB_GAIN_Pos)

#define  DAB_GAIN_X100    (0x1u << 1)
#define  DAB_GAIN_X1000   (0x1u << 2)
#define  DAB_GAIN_X10000  (0x1u << 3)


//////////////////////////////////////////////

#define DAC1_GAIN_Pos 4
#define DAC1_GAIN_Msk  ((0x7u) << DAC1_GAIN_Pos)

#define  DAC1_GAIN_X100   (0x1u << 4)
#define  DAC1_GAIN_X1000  (0x1u << 5)
#define  DAC1_GAIN_X10000 (0x1u << 6) 


/************************************************************************/
/*     CONDUCTIVITY    mux3                                                          */
/************************************************************************/

#define DAC2_GAIN_Pos 0
#define DAC2_GAIN_Msk  ((0xfu) << DAC2_GAIN_Pos)

#define  DAC2_GAIN_X10   (0x1u << 0)
#define  DAC2_GAIN_X100  (0x1u << 1)
#define  DAC2_GAIN_X500  (0x1u << 2)
#define  DAC2_GAIN_X1000 (0x1u << 3)

#define CS3_GAIN_Pos 4
#define CS3_GAIN_Msk  ((0xfu) << CS3_GAIN_Pos)
#define  CS3_GAIN_X10    (0x1u << 4)
#define  CS3_GAIN_X100   (0x1u << 5)
#define  CS3_GAIN_X500   (0x1u << 6)
#define  CS3_GAIN_X1000  (0x1u << 7)

#define SENSOR_TIMEOUT       1000000

typedef enum {
	SENSOR_READ_OK=0,
	SENSOR_NOT_READY,	
}sensor_status_t;


/*ALL FUNCTION PROTOS DECLARED HERE*/
void DD_TS1_CHIP_SELECT(void);
void DD_TS2_CHIP_SELECT(void);
void DD_TS3_CHIP_SELECT(void);
void DD_CS1_TS_CHIP_SELECT(void);
void DD_CS2_TS_CHIP_SELECT(void);
void DD_CS3_TS_CHIP_SELECT(void);
void  DD_TS_MUX_CHIP_SELECT(void);
void DD_SPARE_TS_CHIP_SELECT(void);
void DD_CONDUCTIVITY_DIGITAL_POT_CS(void);
void DD_CON_ADC_CHIP_SELECT(void);
void DD_AN_MUX_CHIPSEL_2(void);
void DD_AN_MUX_CHIPSEL_3(void);
void DD_AN_MUX_CHIPSEL_4(void);
void DD_SPI_PCS_DECODER_ACTIVE(void) ;
void DD_SPI_PCS_DECODER_DEACTIVE(void);
uint16_t DD_INIT_ALL_SENSORS(void);

void DD_DISABLE_ISOLATORS_MISO_PIN();
void DD_ENABLE_ISOLATOR_1(void);
void DD_ENABLE_ISOLATOR_2(void);
void DD_ENABLE_ISOLATOR_3(void);
void DD_ENABLE_ISOLATOR_4(void);

sensor_status_t DD_READ_SENSORS(sv_sensortype ID_SENSOR,uint16_t *sensor_status);
#endif /* DD_SYS_H_ */