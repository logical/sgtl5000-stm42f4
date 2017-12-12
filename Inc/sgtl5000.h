#ifndef SGTL5000_H
#define SGTL5000_H

#include "stm32f4xx_hal.h"

#define WRITE_ADDRESS 0b00010100
#define READ_ADDRESS 0b00010101


#define CHIP_DIG_POWER_ADD 0x0002
#define CHIP_I2S_CTRL_ADD 0x0006
#define CHIP_SSS_CTRL_ADD 0x000A
#define CHIP_ADCDAC_CTRL_ADD 0x000E
#define CHIP_DAC_VOL_ADD 0x0010
#define CHIP_PAD_STRENGTH_ADD 0x0014
#define CHIP_ANA_ADC_CTRL_ADD 0x0020
#define CHIP_ANA_HP_CTRL_ADD 0x0022
#define CHIP_ANA_CTRL_ADD 0x0024
#define CHIP_LINE_OUT_VOL_ADD 0x002E
#define CHIP_PLL_CTRL_ADD 0x0032
#define CHIP_CLK_TOP_CTRL_ADD 0x0034
#define CHIP_ANA_STATUS_ADD 0x0036
#define CHIP_ANA_TEST1_ADD 0x0038
#define CHIP_ANA_TEST2_ADD 0x003A
#define CHIP_SHORT_CTRL_ADD 0x003C
#define DAP_CONTROL_ADD 0x0100
#define DAP_PEQ_ADD 0x0102
#define DAP_BASS_ENHANCE_ADD 0x0104
#define DAP_BASS_ENHANCE_CTRL_ADD 0x0106
#define DAP_AUDIO_EQ_ADD 0x0108
#define DAP_SGTL_SURROUND_ADD 0x010A
#define DAP_FILTER_COEF_ACCESS_ADD 0x010C
#define DAP_COEF_WR_B0_MSB_ADD 0x010E
#define DAP_COEF_WR_B0_LSB_ADD 0x0110
#define DAP_AUDIO_EQ_BASS_BAND0_ADD 0x0116 //115 Hz
#define DAP_AUDIO_EQ_BAND1_ADD 0x0118 //330 Hz
#define DAP_AUDIO_EQ_BAND2_ADD 0x011A //990 Hz
#define DAP_AUDIO_EQ_BAND3_ADD 0x011C //3000 Hz
#define DAP_AUDIO_EQ_TREBLE_BAND4_ADD 0x011E //9900 Hz
#define DAP_MAIN_CHAN_ADD 0x0120
#define DAP_MIX_CHAN_ADD 0x0122
#define DAP_AVC_CTRL_ADD 0x0124
#define DAP_AVC_THRESHOLD_ADD 0x0126
#define DAP_AVC_ATTACK_ADD 0x0128
#define DAP_AVC_DECAY_ADD 0x012A
#define DAP_COEF_WR_B1_MSB_ADD 0x012C
#define DAP_COEF_WR_B1_LSB_ADD 0x012E
#define DAP_COEF_WR_B2_MSB_ADD 0x0130
#define DAP_COEF_WR_B2_LSB_ADD 0x0132
#define DAP_COEF_WR_A1_MSB_ADD 0x0134
#define DAP_COEF_WR_A1_LSB_ADD 0x0136
#define DAP_COEF_WR_A2_MSB_ADD 0x0138
#define DAP_COEF_WR_A2_LSB_ADD 0x013A





#define CHIP_LINREG_CTRL_ADD 0x0026
#define CHIP_ANA_POWER_ADD 0x0030
#define CHIP_REF_CTRL_ADD 0x0028
#define CHIP_LINE_OUT_CTRL_ADD 0x002C
#define CHIP_CLK_CTRL_ADD 0x0004
#define CHIP_MIC_CTRL_ADD 0x002A


//ALL bitfields are lsb to msb

union{
	uint16_t data;
	struct{
		uint16_t REVID :8; 
		uint16_t PARTID :8;
	};
}CHIP_ID ;

union{
	uint16_t data;
	struct{
		uint16_t I2S_IN_POWERUP :1;
		uint16_t I2S_OUT_POWERUP :1;
		uint16_t RSVD1 :2;
		uint16_t DAP_POWERUP :1;
		uint16_t DAC_POWERUP :1;
		uint16_t ADC_POWERUP :1; 
		uint16_t RSVD0 :9;
	};
}CHIP_DIG_POWER ;

union{
	uint16_t data;
	struct{
		uint16_t DAC_VOL_LEFT :8; 
		uint16_t DAC_VOL_RIGHT :8;
	};
}CHIP_DAC_VOL ;

union{
	uint16_t data;
	struct{
		uint16_t LRPOL :1;
		uint16_t LRALIGN :1;
		uint16_t I2S_MODE :2;
		uint16_t DLEN :2;
		uint16_t SCLK_INV :1;
		uint16_t MS :1;
		uint16_t SCLKFREQ :1; 
		uint16_t RSVD0 :7;

	};
}CHIP_I2S_CTRL ;

union{
	uint16_t data;
	struct{
		uint16_t CTRL_CLK :2;
		uint16_t CTRL_DATA :2;
		uint16_t I2S_DOUT :2;
		uint16_t I2S_SCLK :2;
		uint16_t I2S_LRCLK :2; 
		uint16_t RSVD0 :6;
	};
}CHIP_PAD_STRENGTH ;

union{
	uint16_t data;
	struct{
		uint16_t ADC_VOL_LEFT :4;
		uint16_t ADC_VOL_RIGHT :4;
		uint16_t ADC_VOL_M6DB :1; 
		uint16_t RSVD0 :7;
	};
}CHIP_ANA_ADC_CTRL ;

union{
	uint16_t data;
	struct{
		uint16_t D_PROGRAMMING :4;
		uint16_t RSVD1 :1;
		uint16_t VDDC_ASSN_OVRD :1;
		uint16_t VDDC_MAN_ASSN :1; 
		uint16_t RSVD0 :9;
	};
}CHIP_LINREG_CTRL ;

union{
	uint16_t data;
	struct{
		uint16_t HP_VOL_LEFT :7;
		uint16_t RSVD1 :1;
		uint16_t HP_VOL_RIGHT :7; 
		uint16_t RSVD0 :1;
	};
}CHIP_ANA_HP_CTRL ;

union{
	uint16_t data;
	struct{
		uint16_t SMALL_POP :1;
		uint16_t BIAS_CTRL :3;
		uint16_t VAG_VAL :5; 
		uint16_t RSVD0 :7;
	};
}CHIP_REF_CTRL ;

union{
	uint16_t data;
	struct{
		uint16_t LO_VAGCNTRL :6;
		uint16_t RSVD1 :2;
		uint16_t OUT_CURRENT :4; 
		uint16_t RSVD0 :4;
	};
}CHIP_LINE_OUT_CTRL ;

union{
	uint16_t data;
	struct{
		uint16_t LINEOUT_POWERUP :1;
		uint16_t ADC_POWERUP :1;
		uint16_t CAPLESS_HEADPHONE_POWERUP :1;
		uint16_t DAC_POWERUP :1;
		uint16_t HEADPHONE_POWERUP :1;
		uint16_t REFTOP_POWERUP :1;
		uint16_t ADC_MONO :1;
		uint16_t VAG_POWERUP :1;
		uint16_t VCOAMP_POWERUP :1;
		uint16_t LINREG_D_POWERUP :1;
		uint16_t PLL_POWERUP :1;
		uint16_t VDDC_CHRGPMP_POWERUP :1;
		uint16_t STARTUP_POWERUP :1;
		uint16_t LINREG_SIMPLE_POWERUP :1;
		uint16_t DAC_MONO :1; 
		uint16_t RSVD0 :1;
	};
}CHIP_ANA_POWER ;

union{
	uint16_t data;
	struct{
		uint16_t LO_VOL_LEFT :5;
		uint16_t RSVD1 :3;
		uint16_t LO_VOL_RIGHT :5; 
		uint16_t RSVD0 :3;
	};
}CHIP_LINE_OUT_VOL ;

union{
	uint16_t data;
	struct{
		uint16_t RSVD2 :3;
		uint16_t INPUT_FREQ_DIV2 :1;
		uint16_t RSVD1 :7;
		uint16_t ENABLE_INT_OSC :1; 
		uint16_t RSVD0 :4;
};
}CHIP_CLK_TOP_CTRL ;

union{
	uint16_t data;
	struct{
		uint16_t RSVD2 :4;
		uint16_t PLL_IS_LOCKED :1;
		uint16_t RSVD1 :3;
		uint16_t CSHORT_STS :1;
		uint16_t LRSHORT_STS :1; 
		uint16_t RSVD0 :6;

	};
}CHIP_ANA_STATUS ;
union{
	uint16_t data;
	struct{
		uint16_t TESTMODE :1;
		uint16_t TM_SELECT_MIC :1;
		uint16_t TM_HPCOMMON :1;
		uint16_t TM_ADCIN_TOHP :1;
		uint16_t VAG_CLASSA :1;
		uint16_t VAG_DOUB_CURRENT :1;
		uint16_t HP_HOLD_GND :1;
		uint16_t HP_HOLD_GND_CENTER :1;
		uint16_t HP_CLASSAB :1;
		uint16_t HP_ANTIPOP :3;
		uint16_t HP_I1_ADJ :2; 
		uint16_t HP_IALL_ADJ :2;

	};
}CHIP_ANA_TEST1 ;
union{
	uint16_t data;
	struct{
		uint16_t ADC_DITHEROFF :1;
		uint16_t ADC_LESSI :1;
		uint16_t INVERT_ADC_DATA_TIMING :1;
		uint16_t INVERT_ADC_SAMPLE_CLOCK :1;
		uint16_t DAC_CLASSA :1;
		uint16_t DAC_DIS_RTZ :1;
		uint16_t DAC_DOUBLE_I :1;
		uint16_t DAC_EXTEND_RTZ :1;
		uint16_t INVERT_DAC_DATA_TIMING :1;
		uint16_t INVERT_DAC_SAMPLE_CLOCK :1;
		uint16_t LO_PASS_MASTERVAG :1;
		uint16_t VCO_TUNE_AGAIN :1;
		uint16_t MONOMODE_DAC :1;
		uint16_t SPARE :1;
		uint16_t LINEOUT_TO_VDDA :1; 
		uint16_t RSVD0 :1;
	};
}CHIP_ANA_TEST2 ;union{
	uint16_t data;
	struct{
		uint16_t MODE_CM :2;
		uint16_t MODE_LR :2;
		uint16_t LVLADJC :3;
		uint16_t RSVD2 :1;
		uint16_t LVLADJL :3;
		uint16_t RSVD1 :1;
		uint16_t LVLADJR :3; 
		uint16_t RSVD0 :1;
	};
}CHIP_SHORT_CTRL ;

union{
	uint16_t data;
	struct{
		uint16_t DAP_EN :1;
		uint16_t RSVD1 :3;
		uint16_t MIX_EN :1;
		uint16_t RSVD0 :11;
	};
}DAP_CONTROL ;
union{
	uint16_t data;
	struct{

		uint16_t EN :3; 
		uint16_t RSVD0 :13;

	};
}DAP_PEQ ;
union{
	uint16_t data;
	struct{
		uint16_t EN :1;
		uint16_t RSVD2 :3;
		uint16_t CUTOFF :3;
		uint16_t RSVD1 :1;
		uint16_t BYPASS_HPF :1; 
		uint16_t RSVD0 :7;
	};
}DAP_BASS_ENHANCE ;
union{
	uint16_t data;
	struct{
		uint16_t BASS_LEVEL :7;
		uint16_t RSVD1 :1;
		uint16_t LR_LEVEL :6; 
		uint16_t RSVD0 :2;

	};
}DAP_BASS_ENHANCE_CTRL ;
union{
	uint16_t data;
	struct{
		uint16_t EN :2; 
		uint16_t RSVD0 :14;

	};
}DAP_AUDIO_EQ ;

union{
	uint16_t data;
	struct{
		uint16_t INDEX :8;
		uint16_t WR :1; 
		uint16_t RSVD0 :7;

	};
} DAP_FILTER_COEF_ACCESS;

union{
	uint16_t data;
	struct{
		uint16_t SELECT :2;
		uint16_t RSVD1 :2;
		uint16_t WIDTH_CONTROL :3; 
		uint16_t RSVD0 :9;
	};
}DAP_SGTL_SURROUND ;
union{
	uint16_t data;
	struct{

		uint16_t BIT_4 :1; 
		uint16_t BIT_5 :1;
		uint16_t BIT_6 :1; 
		uint16_t BIT_7 :1;
		uint16_t BIT_8 :1; 
		uint16_t BIT_9 :1;
		uint16_t BIT_10 :1; 
		uint16_t BIT_11 :1;
		uint16_t BIT_12 :1; 
		uint16_t BIT_13 :1;
		uint16_t BIT_14 :1; 
		uint16_t BIT_15 :1;
		uint16_t BIT_16 :1; 
		uint16_t BIT_17 :1;
		uint16_t BIT_18 :1; 
		uint16_t BIT_19 :1;
	};
}DAP_COEF_WR_B0_MSB ;
union{
	uint16_t data;
	struct{
		uint16_t BIT_0 :1; 
		uint16_t BIT_1 :1;
		uint16_t BIT_2 :1; 
		uint16_t BIT_3 :1;
		uint16_t RSVD0 :12;
	};
}DAP_COEF_WR_B0_LSB ;
union{
	uint16_t data;
	struct{
		uint16_t VOLUME :7; 
		uint16_t RSVD0 :9;

	};
}DAP_AUDIO_EQ_BASS_BAND0 ;
union{
	uint16_t data;
	struct{
		uint16_t VOLUME :7; 
		uint16_t RSVD0 :9;

	};
}DAP_AUDIO_EQ_BAND1 ;
union{
	uint16_t data;
	struct{
		uint16_t VOLUME :7; 
		uint16_t RSVD0 :9;

	};
}DAP_AUDIO_EQ_BAND2 ;
union{
	uint16_t data;
	struct{
		uint16_t VOLUME :7; 
		uint16_t RSVD0 :9;

	};
}DAP_AUDIO_EQ_BAND3 ;
union{
	uint16_t data;
	struct{
		uint16_t VOLUME :7; 
		uint16_t RSVD0 :9;

	};
}DAP_AUDIO_EQ_TREBLE_BAND4 ;

union{
	uint16_t data;
	struct{
		uint16_t EN :1;
		uint16_t RSVD3 :4;
		uint16_t HARD_LIMIT_EN :1;
		uint16_t RSVD2 :2;
		uint16_t LBI_RESPONSE :2;
		uint16_t RSVD1 :2;
		uint16_t MAX_GAIN :2;
		uint16_t RSVD0 :2;
	};
}DAP_AVC_CTRL ;
union{
	uint16_t data;
	struct{
		uint16_t RATE :12; 
		uint16_t RSVD0 :4;
	};
}DAP_AVC_ATTACK ;
union{
	uint16_t data;
	struct{
		uint16_t RATE :12; 
		uint16_t RSVD0 :4;
	};
}DAP_AVC_DECAY ;



union{
	uint16_t data;
	struct{
		uint16_t I2S_SELECT :2;
		uint16_t RSVD2 :2;
		uint16_t DAC_SELECT :2;
		uint16_t DAP_SELECT :2;
		uint16_t DAP_MIX_SELECT :2;
		uint16_t I2S_LRSWAP :1;
		uint16_t RSVD1 :1;
		uint16_t DAC_LRSWAP :1;
		uint16_t DAP_LRSWAP :1;
		uint16_t DAP_MIX_LRSWAP :1; 
		uint16_t RSVD0 :1;
	};
}DAP_COEF_WR_B2_LSB ;





union{
	uint16_t data;
	struct{
	uint16_t FRAC_DIVISOR :11;
	uint16_t INT_DIVISOR :5;

	};
}CHIP_PLL_CTRL;

union {
	uint16_t data;	
	struct{
		uint16_t MCLK_FREQ :2;
		uint16_t SYS_FS :2;
		uint16_t RATE_MODE :2;
		uint16_t RSVD0 :10;
	};
}CHIP_CLK_CTRL;

union {
	uint16_t data;
	struct{
		uint16_t ADC_HPF_BYPASS :1;
		uint16_t ADC_HPF_FREEZE :1;
		uint16_t DAC_MUTE_LEFT :1;
		uint16_t DAC_MUTE_RIGHT :1;
		uint16_t RSVD2 :4;
		uint16_t VOL_EXPO_RAMP :1;
		uint16_t VOL_RAMP_EN :1;
		uint16_t RSVD1 :2;
		uint16_t VOL_BUSY_DAC_LEFT :1;
		uint16_t VOL_BUSY_DAC_RIGHT :1;
		uint16_t RSVD0 :2;
	};
}CHIP_ADCDAC_CTRL;

union {
	uint16_t data;
	struct{
		uint16_t MUTE_ADC :1;
		uint16_t EN_ZCD_ADC :1;
		uint16_t SELECT_ADC :1;
		uint16_t RSVD2 :1;
		uint16_t MUTE_HP :1;
		uint16_t EN_ZCD_HP :1;
		uint16_t SELECT_HP :1; 
		uint16_t RSVD1 :1;
		uint16_t MUTE_LO :1;
		uint16_t RSVD0 :7;
	};
}CHIP_ANA_CTRL;



union{
	uint16_t data;
	struct{
		uint16_t GAIN :2;
		uint16_t RSVD2 :2;
		uint16_t BIAS_VOLT :3;
		uint16_t RSVD1 :1;
		uint16_t BIAS_RESISTOR :2; 
		uint16_t RSVD0 :6;
	};
}CHIP_MIC_CTRL ;

union{
	uint16_t data;
	struct{
		uint16_t I2S_SELECT :2;
		uint16_t RSVD2 :2;
		uint16_t DAC_SELECT :2;
		uint16_t DAP_SELECT :2;
		uint16_t DAP_MIX_SELECT :2;
		uint16_t I2S_LRSWAP :1;
		uint16_t RSVD1 :1;
		uint16_t DAC_LRSWAP :1;
		uint16_t DAP_LRSWAP :1;
		uint16_t DAP_MIX_LRSWAP :1; 
		uint16_t RSVD0 :1;
	};
}CHIP_SSS_CTRL ;

class sgtl5000{
public:
	void init(void);
	void set_volume(uint8_t vol);
	void start_play(void);
	void start_receive(void);

protected:
	void write(uint16_t reg,uint16_t data);
	uint16_t read(uint16_t reg);





};








#endif
