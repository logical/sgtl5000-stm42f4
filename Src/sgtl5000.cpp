#include "sgtl5000.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"

extern I2C_HandleTypeDef hi2c1;


uint16_t sgtl5000::read(uint16_t reg){
	uint8_t buff[2];

	buff[1]=0xff & reg;
	buff[0]=0xff & reg>>8;

	HAL_I2C_Master_Transmit(&hi2c1,WRITE_ADDRESS,buff,2,0xFF);
	HAL_Delay(1);
	HAL_I2C_Master_Receive(&hi2c1, READ_ADDRESS, buff, 2, 0xFF);
	HAL_Delay(1);
	return (uint16_t)buff[0]<<8 | buff[1];

}

void sgtl5000::write(uint16_t reg,uint16_t data){

uint8_t buff[4];

	buff[3]=0xff & data;
	buff[2]=0xff & data>>8;
	buff[1]=0xff & reg;
	buff[0]=0xff & reg>>8;


	HAL_I2C_Master_Transmit(&hi2c1,WRITE_ADDRESS,buff,4,0xFF);

	HAL_Delay(1);
}
 


void sgtl5000::set_volume(uint8_t vol){

	write(CHIP_ANA_HP_CTRL_ADD, (uint16_t)vol<<8 | vol );
}

void sgtl5000::start_play(void){
	CHIP_ANA_CTRL.data = read(CHIP_ANA_CTRL_ADD);
	CHIP_ANA_CTRL.MUTE_HP = 0x0000; //unmute amp
	CHIP_ANA_CTRL.MUTE_LO = 0x0000; //unmute headphone
	CHIP_ANA_CTRL.MUTE_ADC = 0x0001; //mute microphone
	write (CHIP_ANA_CTRL_ADD, CHIP_ANA_CTRL.data);
}

void sgtl5000::start_receive(void){

	CHIP_ANA_CTRL.data = read(CHIP_ANA_CTRL_ADD);
	CHIP_ANA_CTRL.MUTE_HP = 0x0001; //mute amp
	//CHIP_ANA_CTRL.MUTE_LO = 0x0001; //mute headphone
	CHIP_ANA_CTRL.MUTE_ADC = 0x0000; //unmute microphone

	write (CHIP_ANA_CTRL_ADD, CHIP_ANA_CTRL.data);

}
void sgtl5000::init(void){

	write(CHIP_ANA_POWER_ADD, 0x4060);  // VDDD is externally driven with 1.8V
	write(CHIP_LINREG_CTRL_ADD, 0x006C);  // VDDA & VDDIO both over 3.1V
	write(CHIP_REF_CTRL_ADD, 0x01F2); // VAG=1.575, normal ramp, +12.5% bias current
	write(CHIP_LINE_OUT_CTRL_ADD, 0x0F22); // LO_VAGCNTRL=1.65V, OUT_CURRENT=0.54mA
	write(CHIP_SHORT_CTRL_ADD, 0x4446);  // allow up to 125mA
	write(CHIP_ANA_CTRL_ADD, 0x0137);  // enable zero cross detectors
	write(CHIP_ANA_POWER_ADD, 0x40FF); // power up: lineout, hp, adc, dac
	write(CHIP_DIG_POWER_ADD, 0x0073); // power up all digital stuff
	HAL_Delay(400);

	write(CHIP_LINE_OUT_VOL_ADD, 0x1D1D); // default approx 1.3 volts peak-to-peak
	write(CHIP_CLK_CTRL_ADD, 0x0000);  // 32k kHz, 256*Fs
	write(CHIP_I2S_CTRL_ADD, 0x0130); // SCLK=32*Fs, 16bit, I2S format



	// Example 1: I2S_IN -> DAP -> DAC -> LINEOUT, HP_OUT
	CHIP_SSS_CTRL.data=read(CHIP_SSS_CTRL_ADD);
	//CHIP_SSS_CTRL.DAP_MIX_SELECT=0x0001; // bits 7:6
	// Route I2S_IN to DAP
	CHIP_SSS_CTRL.DAP_SELECT=0x0001; // bits 7:6
	// Route DAP to DAC
	CHIP_SSS_CTRL.DAC_SELECT=0x0003; // bits 5:4
	//CHIP_SSS_CTRL.I2S_SELECT=0x0001; // bits 5:4
	CHIP_SSS_CTRL.I2S_SELECT=0x0000; // bits 1:0

	write(CHIP_SSS_CTRL_ADD,CHIP_SSS_CTRL.data);
	// Select DAC as the input to HP_OUT
	CHIP_ANA_CTRL.data=read(CHIP_ANA_CTRL_ADD);
	//CHIP_ANA_CTRL.SELECT_ADC = 0x0001; // bit 2

	CHIP_ANA_CTRL.SELECT_HP = 0x0000; // bit 6
	write(CHIP_ANA_CTRL_ADD,CHIP_ANA_CTRL.data);




	// Enable DAP block
	// NOTE: DAP will be in a pass-through mode if none of DAP
	// sub-blocks are enabled.
	DAP_CONTROL.data= read(DAP_CONTROL_ADD);
	DAP_CONTROL.DAP_EN=1;
	//DAP_CONTROL.MIX_EN=1;
	write(DAP_CONTROL_ADD,DAP_CONTROL.data); // bit 0

	write(DAP_MAIN_CHAN_ADD,0xFFFF); // bit 0
	write(DAP_MIX_CHAN_ADD,0xFFFF); // bit 0

	DAP_AVC_CTRL.data = read(DAP_AVC_CTRL_ADD);
	DAP_AVC_CTRL.EN=1;
	write(DAP_AVC_CTRL_ADD,DAP_AVC_CTRL.data);
	//---------------- Input Volume Control---------------------
	// Configure ADC left and right analog volume to desired default. 
	// Example shows volume of 0dB
	write( CHIP_ANA_ADC_CTRL_ADD, 0x0000);
	// Configure MIC gain if needed. Example shows gain of 20dB
	CHIP_MIC_CTRL.data = read(CHIP_MIC_CTRL_ADD);
	CHIP_MIC_CTRL.GAIN = 0x0001;
	write(CHIP_MIC_CTRL_ADD, CHIP_MIC_CTRL.data); 
	// LINEOUT and DAC volume control

	CHIP_ANA_CTRL.data = read(CHIP_ANA_CTRL_ADD);

	CHIP_ANA_CTRL.MUTE_LO = 0x0000;
	CHIP_ANA_CTRL.MUTE_HP = 0x0000; //unmute amp
	write (CHIP_ANA_CTRL_ADD, CHIP_ANA_CTRL.data);
	// bit 8
	// Configure DAC left and right digital volume. Example shows 
	// volume of 0dB
	write(CHIP_DAC_VOL_ADD, 0x3C3C);

	CHIP_ADCDAC_CTRL.data = read(CHIP_ADCDAC_CTRL_ADD);
	CHIP_ADCDAC_CTRL.DAC_MUTE_LEFT=0x0000;// bit 2
	CHIP_ADCDAC_CTRL.DAC_MUTE_RIGHT=0x0000;// bit 3
	write(CHIP_ADCDAC_CTRL_ADD,CHIP_ADCDAC_CTRL.data);


	// Unmute ADC
	//CHIP_ANA_CTRL.data = read(CHIP_ANA_CTRL_ADD);
	//CHIP_ANA_CTRL.MUTE_ADC= 0x0000; 

	//write(CHIP_ANA_CTRL_ADD,CHIP_ANA_CTRL.data);





}























