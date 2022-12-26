/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Functions and registers to access AXP20X power management chip.
 *
 * Copyright (C) 2013, Carlo Caione <carlo@caione.org>
 */

#ifndef __LINUX_MFD_AXP20X_H
#define __LINUX_MFD_AXP20X_H

#include <linux/regmap.h>

enum axp20x_variants {
	AXP152_ID = 0,
	AXP202_ID,
	AXP209_ID,
	AXP221_ID,
	AXP223_ID,
	AXP288_ID,
	AXP803_ID,
	AXP806_ID,
	AXP809_ID,
	AXP813_ID,
	AXP858_ID,
	NR_AXP20X_VARIANTS,
};

#define AXP20X_DATACACHE(m)		(0x04 + (m))

/* Power supply */
#define AXP152_PWR_OP_MODE		0x01
#define AXP152_LDO3456_DC1234_CTRL	0x12
#define AXP152_ALDO_OP_MODE		0x13
#define AXP152_LDO0_CTRL		0x15
#define AXP152_DCDC2_V_OUT		0x23
#define AXP152_DCDC2_V_RAMP		0x25
#define AXP152_DCDC1_V_OUT		0x26
#define AXP152_DCDC3_V_OUT		0x27
#define AXP152_ALDO12_V_OUT		0x28
#define AXP152_DLDO1_V_OUT		0x29
#define AXP152_DLDO2_V_OUT		0x2a
#define AXP152_DCDC4_V_OUT		0x2b
#define AXP152_V_OFF			0x31
#define AXP152_OFF_CTRL			0x32
#define AXP152_PEK_KEY			0x36
#define AXP152_DCDC_FREQ		0x37
#define AXP152_DCDC_MODE		0x80

#define AXP20X_PWR_INPUT_STATUS		0x00
#define AXP20X_PWR_OP_MODE		0x01
#define AXP20X_USB_OTG_STATUS		0x02
#define AXP20X_PWR_OUT_CTRL		0x12
#define AXP20X_DCDC2_V_OUT		0x23
#define AXP20X_DCDC2_LDO3_V_RAMP	0x25
#define AXP20X_DCDC3_V_OUT		0x27
#define AXP20X_LDO24_V_OUT		0x28
#define AXP20X_LDO3_V_OUT		0x29
#define AXP20X_VBUS_IPSOUT_MGMT		0x30
#define AXP20X_V_OFF			0x31
#define AXP20X_OFF_CTRL			0x32
#define AXP20X_CHRG_CTRL1		0x33
#define AXP20X_CHRG_CTRL2		0x34
#define AXP20X_CHRG_BAK_CTRL		0x35
#define AXP20X_PEK_KEY			0x36
#define AXP20X_DCDC_FREQ		0x37
#define AXP20X_V_LTF_CHRG		0x38
#define AXP20X_V_HTF_CHRG		0x39
#define AXP20X_APS_WARN_L1		0x3a
#define AXP20X_APS_WARN_L2		0x3b
#define AXP20X_V_LTF_DISCHRG		0x3c
#define AXP20X_V_HTF_DISCHRG		0x3d

#define AXP22X_PWR_OUT_CTRL1		0x10
#define AXP22X_PWR_OUT_CTRL2		0x12
#define AXP22X_PWR_OUT_CTRL3		0x13
#define AXP22X_DLDO1_V_OUT		0x15
#define AXP22X_DLDO2_V_OUT		0x16
#define AXP22X_DLDO3_V_OUT		0x17
#define AXP22X_DLDO4_V_OUT		0x18
#define AXP22X_ELDO1_V_OUT		0x19
#define AXP22X_ELDO2_V_OUT		0x1a
#define AXP22X_ELDO3_V_OUT		0x1b
#define AXP22X_DC5LDO_V_OUT		0x1c
#define AXP22X_DCDC1_V_OUT		0x21
#define AXP22X_DCDC2_V_OUT		0x22
#define AXP22X_DCDC3_V_OUT		0x23
#define AXP22X_DCDC4_V_OUT		0x24
#define AXP22X_DCDC5_V_OUT		0x25
#define AXP22X_DCDC23_V_RAMP_CTRL	0x27
#define AXP22X_ALDO1_V_OUT		0x28
#define AXP22X_ALDO2_V_OUT		0x29
#define AXP22X_ALDO3_V_OUT		0x2a
#define AXP22X_CHRG_CTRL3		0x35

#define AXP806_STARTUP_SRC		0x00
#define AXP806_CHIP_ID			0x03
#define AXP806_PWR_OUT_CTRL1		0x10
#define AXP806_PWR_OUT_CTRL2		0x11
#define AXP806_DCDCA_V_CTRL		0x12
#define AXP806_DCDCB_V_CTRL		0x13
#define AXP806_DCDCC_V_CTRL		0x14
#define AXP806_DCDCD_V_CTRL		0x15
#define AXP806_DCDCE_V_CTRL		0x16
#define AXP806_ALDO1_V_CTRL		0x17
#define AXP806_ALDO2_V_CTRL		0x18
#define AXP806_ALDO3_V_CTRL		0x19
#define AXP806_DCDC_MODE_CTRL1		0x1a
#define AXP806_DCDC_MODE_CTRL2		0x1b
#define AXP806_DCDC_FREQ_CTRL		0x1c
#define AXP806_BLDO1_V_CTRL		0x20
#define AXP806_BLDO2_V_CTRL		0x21
#define AXP806_BLDO3_V_CTRL		0x22
#define AXP806_BLDO4_V_CTRL		0x23
#define AXP806_CLDO1_V_CTRL		0x24
#define AXP806_CLDO2_V_CTRL		0x25
#define AXP806_CLDO3_V_CTRL		0x26
#define AXP806_VREF_TEMP_WARN_L		0xf3
#define AXP806_BUS_ADDR_EXT		0xfe
#define AXP806_REG_ADDR_EXT		0xff

#define AXP803_POLYPHASE_CTRL		0x14
#define AXP803_FLDO1_V_OUT		0x1c
#define AXP803_FLDO2_V_OUT		0x1d
#define AXP803_DCDC1_V_OUT		0x20
#define AXP803_DCDC2_V_OUT		0x21
#define AXP803_DCDC3_V_OUT		0x22
#define AXP803_DCDC4_V_OUT		0x23
#define AXP803_DCDC5_V_OUT		0x24
#define AXP803_DCDC6_V_OUT		0x25
#define AXP803_DCDC_FREQ_CTRL		0x3b

#define AXP858_ON_INDICATE		(0x00)
#define AXP858_OFF_INDICATE		(0x01)
#define AXP858_IC_TYPE			(0x03)
#define AXP858_DATA_BUFFER1		(0x04)
#define AXP858_DATA_BUFFER2		(0x05)
#define AXP858_DATA_BUFFER3		(0x06)
#define AXP858_DATA_BUFFER4		(0x07)
#define AXP858_OUTPUT_CONTROL1	(0x10)
#define AXP858_OUTPUT_CONTROL2	(0x11)
#define AXP858_OUTPUT_CONTROL3	(0x12)
#define AXP858_DCDC1_CONTROL	(0x13)
#define AXP858_DCDC2_CONTROL	(0x14)
#define AXP858_DCDC3_CONTROL	(0x15)
#define AXP858_DCDC4_CONTROL	(0x16)
#define AXP858_DCDC5_CONTROL	(0x17)
#define AXP858_DCDC6_CONTROL	(0x18)
#define AXP858_ALDO1_CONTROL	(0x19)
#define AXP858_DCDC_MODE1		(0x1A)
#define AXP858_DCDC_MODE2		(0x1B)
#define AXP858_DCDC_MODE3		(0x1C)
#define AXP858_DCDC_FREQUENCY	(0x1D)
#define AXP858_OUTPUT_MONITOR	(0x1E)
#define AXP858_IRQ_PWROK_VOFF	(0x1F)
#define AXP858_ALDO2_CTL		(0x20)
#define AXP858_ALDO3_CTL		(0x21)
#define AXP858_ALDO4_CTL		(0x22)
#define AXP858_ALDO5_CTL		(0x23)
#define AXP858_BLDO1_CTL		(0x24)
#define AXP858_BLDO2_CTL		(0x25)
#define AXP858_BLDO3_CTL		(0x26)
#define AXP858_BLDO4_CTL		(0x27)
#define AXP858_BLDO5_CTL		(0x28)
#define AXP858_CLDO1_CTL		(0x29)
#define AXP858_CLDO2_CTL		(0x2A)
#define AXP858_CLDO3_GPIO1_CTL	(0x2B)
#define AXP858_CLDO4_GPIO2_CTL	(0x2C)
#define AXP858_CLDO4_CTL		(0x2D)
#define AXP858_CPUSLDO_CTL		(0x2E)
#define AXP858_WKP_CTL_OC_IRQ	(0x31)
#define AXP858_POWER_DOWN_DIS	(0x32)
#define AXP858_POK_SET			(0x36)
#define AXP858_TWI_OR_RSB		(0x3E)
#define AXP858_IRQ_EN1			(0x40)
#define AXP858_IRQ_EN2			(0x41)
#define AXP858_IRQ_STS1			(0x48)
#define AXP858_IRQ_STS2			(0x49)
#define AXP858_DIGITAL_PAT1		(0xF0)
#define AXP858_DIGITAL_PAT2		(0xF1)
#define AXP858_EPROM_SET		(0xF2)
#define AXP858_VREF_TEM_SET		(0xF3)
#define AXP858_LOCK_F0125		(0xF4)
#define AXP858_EPROM_TUNE		(0xF5)
#define AXP858_ADDR_EXTEN		(0xFF)
#define AXP858_DCDC1_PWRON_DEF	(0x100)
#define AXP858_DCDC2_DEF		(0x101)
#define AXP858_DCDC3_DEF		(0x102)
#define AXP858_DCDC4_DEF		(0x103)
#define AXP858_DCDC5_DEF		(0x104)
#define AXP858_DCDC6_DEF		(0x105)
#define AXP858_ALDO12_DEF		(0x106)
#define AXP858_ALDO23_DEF		(0x107)
#define AXP858_ALDO45_DEF		(0x108)
#define AXP858_ALDO5_BLDO1_DEF	(0x109)
#define AXP858_BLDO12_DEF		(0x10A)
#define AXP858_BLDO23_DEF		(0x10B)
#define AXP858_BLDO45_DEF		(0x10C)
#define AXP858_BLDO5_CLDO1_DEF	(0x10D)
#define AXP858_CLDO23_DEF		(0x10E)
#define AXP858_CLDO34_DEF		(0x10F)
#define AXP858_START_DCDC123	(0x110)
#define AXP858_START_DCDC456	(0x111)
#define AXP858_START_ALDO12		(0x112)
#define AXP858_START_ALDO345	(0x113)
#define AXP858_START_BLDO123	(0x114)
#define AXP858_START_BLDO45		(0x115)
#define AXP858_START_CLDO123	(0x116)
#define AXP858_START_CLDO34_CPUS	(0x117)
#define AXP858_TWI_RSB_SET1		(0x118)
#define AXP858_TWI_RSB_SET2		(0x119)
#define AXP858_TWI_SET			(0x11A)
#define AXP858_VREF_TC_ALDO3	(0x140)
#define AXP858_VREF_VOL			(0x141)
#define AXP858_INTERNAL_ALDO2	(0x142)
#define AXP858_FREQUENCY_ALDO2	(0x143)

/* Other DCDC regulator control registers are the same as AXP803 */
#define AXP813_DCDC7_V_OUT		0x26

/* Interrupt */
#define AXP152_IRQ1_EN			0x40
#define AXP152_IRQ2_EN			0x41
#define AXP152_IRQ3_EN			0x42
#define AXP152_IRQ1_STATE		0x48
#define AXP152_IRQ2_STATE		0x49
#define AXP152_IRQ3_STATE		0x4a

#define AXP20X_IRQ1_EN			0x40
#define AXP20X_IRQ2_EN			0x41
#define AXP20X_IRQ3_EN			0x42
#define AXP20X_IRQ4_EN			0x43
#define AXP20X_IRQ5_EN			0x44
#define AXP20X_IRQ6_EN			0x45
#define AXP20X_IRQ1_STATE		0x48
#define AXP20X_IRQ2_STATE		0x49
#define AXP20X_IRQ3_STATE		0x4a
#define AXP20X_IRQ4_STATE		0x4b
#define AXP20X_IRQ5_STATE		0x4c
#define AXP20X_IRQ6_STATE		0x4d

/* ADC */
#define AXP20X_ACIN_V_ADC_H		0x56
#define AXP20X_ACIN_V_ADC_L		0x57
#define AXP20X_ACIN_I_ADC_H		0x58
#define AXP20X_ACIN_I_ADC_L		0x59
#define AXP20X_VBUS_V_ADC_H		0x5a
#define AXP20X_VBUS_V_ADC_L		0x5b
#define AXP20X_VBUS_I_ADC_H		0x5c
#define AXP20X_VBUS_I_ADC_L		0x5d
#define AXP20X_TEMP_ADC_H		0x5e
#define AXP20X_TEMP_ADC_L		0x5f
#define AXP20X_TS_IN_H			0x62
#define AXP20X_TS_IN_L			0x63
#define AXP20X_GPIO0_V_ADC_H		0x64
#define AXP20X_GPIO0_V_ADC_L		0x65
#define AXP20X_GPIO1_V_ADC_H		0x66
#define AXP20X_GPIO1_V_ADC_L		0x67
#define AXP20X_PWR_BATT_H		0x70
#define AXP20X_PWR_BATT_M		0x71
#define AXP20X_PWR_BATT_L		0x72
#define AXP20X_BATT_V_H			0x78
#define AXP20X_BATT_V_L			0x79
#define AXP20X_BATT_CHRG_I_H		0x7a
#define AXP20X_BATT_CHRG_I_L		0x7b
#define AXP20X_BATT_DISCHRG_I_H		0x7c
#define AXP20X_BATT_DISCHRG_I_L		0x7d
#define AXP20X_IPSOUT_V_HIGH_H		0x7e
#define AXP20X_IPSOUT_V_HIGH_L		0x7f

/* Power supply */
#define AXP20X_DCDC_MODE		0x80
#define AXP20X_ADC_EN1			0x82
#define AXP20X_ADC_EN2			0x83
#define AXP20X_ADC_RATE			0x84
#define AXP20X_GPIO10_IN_RANGE		0x85
#define AXP20X_GPIO1_ADC_IRQ_RIS	0x86
#define AXP20X_GPIO1_ADC_IRQ_FAL	0x87
#define AXP20X_TIMER_CTRL		0x8a
#define AXP20X_VBUS_MON			0x8b
#define AXP20X_OVER_TMP			0x8f

#define AXP22X_PWREN_CTRL1		0x8c
#define AXP22X_PWREN_CTRL2		0x8d

/* GPIO */
#define AXP152_GPIO0_CTRL		0x90
#define AXP152_GPIO1_CTRL		0x91
#define AXP152_GPIO2_CTRL		0x92
#define AXP152_GPIO3_CTRL		0x93
#define AXP152_LDOGPIO2_V_OUT		0x96
#define AXP152_GPIO_INPUT		0x97
#define AXP152_PWM0_FREQ_X		0x98
#define AXP152_PWM0_FREQ_Y		0x99
#define AXP152_PWM0_DUTY_CYCLE		0x9a
#define AXP152_PWM1_FREQ_X		0x9b
#define AXP152_PWM1_FREQ_Y		0x9c
#define AXP152_PWM1_DUTY_CYCLE		0x9d

#define AXP20X_GPIO0_CTRL		0x90
#define AXP20X_LDO5_V_OUT		0x91
#define AXP20X_GPIO1_CTRL		0x92
#define AXP20X_GPIO2_CTRL		0x93
#define AXP20X_GPIO20_SS		0x94
#define AXP20X_GPIO3_CTRL		0x95

#define AXP22X_LDO_IO0_V_OUT		0x91
#define AXP22X_LDO_IO1_V_OUT		0x93
#define AXP22X_GPIO_STATE		0x94
#define AXP22X_GPIO_PULL_DOWN		0x95

/* Battery */
#define AXP20X_CHRG_CC_31_24		0xb0
#define AXP20X_CHRG_CC_23_16		0xb1
#define AXP20X_CHRG_CC_15_8		0xb2
#define AXP20X_CHRG_CC_7_0		0xb3
#define AXP20X_DISCHRG_CC_31_24		0xb4
#define AXP20X_DISCHRG_CC_23_16		0xb5
#define AXP20X_DISCHRG_CC_15_8		0xb6
#define AXP20X_DISCHRG_CC_7_0		0xb7
#define AXP20X_CC_CTRL			0xb8
#define AXP20X_FG_RES			0xb9

/* OCV */
#define AXP20X_RDC_H			0xba
#define AXP20X_RDC_L			0xbb
#define AXP20X_OCV(m)			(0xc0 + (m))
#define AXP20X_OCV_MAX			0xf

/* AXP22X specific registers */
#define AXP22X_PMIC_TEMP_H		0x56
#define AXP22X_PMIC_TEMP_L		0x57
#define AXP22X_TS_ADC_H			0x58
#define AXP22X_TS_ADC_L			0x59
#define AXP22X_BATLOW_THRES1		0xe6

/* AXP288/AXP803 specific registers */
#define AXP288_POWER_REASON		0x02
#define AXP288_BC_GLOBAL		0x2c
#define AXP288_BC_VBUS_CNTL		0x2d
#define AXP288_BC_USB_STAT		0x2e
#define AXP288_BC_DET_STAT		0x2f
#define AXP288_PMIC_ADC_H               0x56
#define AXP288_PMIC_ADC_L               0x57
#define AXP288_TS_ADC_H			0x58
#define AXP288_TS_ADC_L			0x59
#define AXP288_GP_ADC_H			0x5a
#define AXP288_GP_ADC_L			0x5b
#define AXP288_ADC_TS_PIN_CTRL          0x84
#define AXP288_RT_BATT_V_H		0xa0
#define AXP288_RT_BATT_V_L		0xa1

#define AXP813_ACIN_PATH_CTRL		0x3a
#define AXP813_ADC_RATE			0x85

/* Fuel Gauge */
#define AXP288_FG_RDC1_REG          0xba
#define AXP288_FG_RDC0_REG          0xbb
#define AXP288_FG_OCVH_REG          0xbc
#define AXP288_FG_OCVL_REG          0xbd
#define AXP288_FG_OCV_CURVE_REG     0xc0
#define AXP288_FG_DES_CAP1_REG      0xe0
#define AXP288_FG_DES_CAP0_REG      0xe1
#define AXP288_FG_CC_MTR1_REG       0xe2
#define AXP288_FG_CC_MTR0_REG       0xe3
#define AXP288_FG_OCV_CAP_REG       0xe4
#define AXP288_FG_CC_CAP_REG        0xe5
#define AXP288_FG_LOW_CAP_REG       0xe6
#define AXP288_FG_TUNE0             0xe8
#define AXP288_FG_TUNE1             0xe9
#define AXP288_FG_TUNE2             0xea
#define AXP288_FG_TUNE3             0xeb
#define AXP288_FG_TUNE4             0xec
#define AXP288_FG_TUNE5             0xed

/* Regulators IDs */
enum {
	AXP20X_LDO1 = 0,
	AXP20X_LDO2,
	AXP20X_LDO3,
	AXP20X_LDO4,
	AXP20X_LDO5,
	AXP20X_DCDC2,
	AXP20X_DCDC3,
	AXP20X_REG_ID_MAX,
};

enum {
	AXP22X_DCDC1 = 0,
	AXP22X_DCDC2,
	AXP22X_DCDC3,
	AXP22X_DCDC4,
	AXP22X_DCDC5,
	AXP22X_DC1SW,
	AXP22X_DC5LDO,
	AXP22X_ALDO1,
	AXP22X_ALDO2,
	AXP22X_ALDO3,
	AXP22X_ELDO1,
	AXP22X_ELDO2,
	AXP22X_ELDO3,
	AXP22X_DLDO1,
	AXP22X_DLDO2,
	AXP22X_DLDO3,
	AXP22X_DLDO4,
	AXP22X_RTC_LDO,
	AXP22X_LDO_IO0,
	AXP22X_LDO_IO1,
	AXP22X_REG_ID_MAX,
};

enum {
	AXP806_DCDCA = 0,
	AXP806_DCDCB,
	AXP806_DCDCC,
	AXP806_DCDCD,
	AXP806_DCDCE,
	AXP806_ALDO1,
	AXP806_ALDO2,
	AXP806_ALDO3,
	AXP806_BLDO1,
	AXP806_BLDO2,
	AXP806_BLDO3,
	AXP806_BLDO4,
	AXP806_CLDO1,
	AXP806_CLDO2,
	AXP806_CLDO3,
	AXP806_SW,
	AXP806_REG_ID_MAX,
};

enum {
	AXP809_DCDC1 = 0,
	AXP809_DCDC2,
	AXP809_DCDC3,
	AXP809_DCDC4,
	AXP809_DCDC5,
	AXP809_DC1SW,
	AXP809_DC5LDO,
	AXP809_ALDO1,
	AXP809_ALDO2,
	AXP809_ALDO3,
	AXP809_ELDO1,
	AXP809_ELDO2,
	AXP809_ELDO3,
	AXP809_DLDO1,
	AXP809_DLDO2,
	AXP809_RTC_LDO,
	AXP809_LDO_IO0,
	AXP809_LDO_IO1,
	AXP809_SW,
	AXP809_REG_ID_MAX,
};

enum {
	AXP803_DCDC1 = 0,
	AXP803_DCDC2,
	AXP803_DCDC3,
	AXP803_DCDC4,
	AXP803_DCDC5,
	AXP803_DCDC6,
	AXP803_DC1SW,
	AXP803_ALDO1,
	AXP803_ALDO2,
	AXP803_ALDO3,
	AXP803_DLDO1,
	AXP803_DLDO2,
	AXP803_DLDO3,
	AXP803_DLDO4,
	AXP803_ELDO1,
	AXP803_ELDO2,
	AXP803_ELDO3,
	AXP803_FLDO1,
	AXP803_FLDO2,
	AXP803_RTC_LDO,
	AXP803_LDO_IO0,
	AXP803_LDO_IO1,
	AXP803_REG_ID_MAX,
};

enum {
	AXP813_DCDC1 = 0,
	AXP813_DCDC2,
	AXP813_DCDC3,
	AXP813_DCDC4,
	AXP813_DCDC5,
	AXP813_DCDC6,
	AXP813_DCDC7,
	AXP813_ALDO1,
	AXP813_ALDO2,
	AXP813_ALDO3,
	AXP813_DLDO1,
	AXP813_DLDO2,
	AXP813_DLDO3,
	AXP813_DLDO4,
	AXP813_ELDO1,
	AXP813_ELDO2,
	AXP813_ELDO3,
	AXP813_FLDO1,
	AXP813_FLDO2,
	AXP813_FLDO3,
	AXP813_RTC_LDO,
	AXP813_LDO_IO0,
	AXP813_LDO_IO1,
	AXP813_SW,
	AXP813_REG_ID_MAX,
};

enum {
	AXP858_DCDC1 = 0,
	AXP858_DCDC2,
	AXP858_DCDC3,
	AXP858_DCDC4,
	AXP858_DCDC5,
	AXP858_DCDC6,
	AXP858_ALDO1,
	AXP858_ALDO2,
	AXP858_ALDO3,
	AXP858_ALDO4,
	AXP858_ALDO5,
	AXP858_BLDO1,
	AXP858_BLDO2,
	AXP858_BLDO3,
	AXP858_BLDO4,
	AXP858_BLDO5,
	AXP858_CLDO1,
	AXP858_CLDO2,
	AXP858_CLDO3,
	AXP858_CLDO4,
	AXP858_CPUSLDO,
	AXP858_DC1SW,
	AXP858_REG_ID_MAX,
};

/* IRQs */
enum {
	AXP152_IRQ_LDO0IN_CONNECT = 1,
	AXP152_IRQ_LDO0IN_REMOVAL,
	AXP152_IRQ_ALDO0IN_CONNECT,
	AXP152_IRQ_ALDO0IN_REMOVAL,
	AXP152_IRQ_DCDC1_V_LOW,
	AXP152_IRQ_DCDC2_V_LOW,
	AXP152_IRQ_DCDC3_V_LOW,
	AXP152_IRQ_DCDC4_V_LOW,
	AXP152_IRQ_PEK_SHORT,
	AXP152_IRQ_PEK_LONG,
	AXP152_IRQ_TIMER,
	AXP152_IRQ_PEK_RIS_EDGE,
	AXP152_IRQ_PEK_FAL_EDGE,
	AXP152_IRQ_GPIO3_INPUT,
	AXP152_IRQ_GPIO2_INPUT,
	AXP152_IRQ_GPIO1_INPUT,
	AXP152_IRQ_GPIO0_INPUT,
};

enum {
	AXP20X_IRQ_ACIN_OVER_V = 1,
	AXP20X_IRQ_ACIN_PLUGIN,
	AXP20X_IRQ_ACIN_REMOVAL,
	AXP20X_IRQ_VBUS_OVER_V,
	AXP20X_IRQ_VBUS_PLUGIN,
	AXP20X_IRQ_VBUS_REMOVAL,
	AXP20X_IRQ_VBUS_V_LOW,
	AXP20X_IRQ_BATT_PLUGIN,
	AXP20X_IRQ_BATT_REMOVAL,
	AXP20X_IRQ_BATT_ENT_ACT_MODE,
	AXP20X_IRQ_BATT_EXIT_ACT_MODE,
	AXP20X_IRQ_CHARG,
	AXP20X_IRQ_CHARG_DONE,
	AXP20X_IRQ_BATT_TEMP_HIGH,
	AXP20X_IRQ_BATT_TEMP_LOW,
	AXP20X_IRQ_DIE_TEMP_HIGH,
	AXP20X_IRQ_CHARG_I_LOW,
	AXP20X_IRQ_DCDC1_V_LONG,
	AXP20X_IRQ_DCDC2_V_LONG,
	AXP20X_IRQ_DCDC3_V_LONG,
	AXP20X_IRQ_PEK_SHORT = 22,
	AXP20X_IRQ_PEK_LONG,
	AXP20X_IRQ_N_OE_PWR_ON,
	AXP20X_IRQ_N_OE_PWR_OFF,
	AXP20X_IRQ_VBUS_VALID,
	AXP20X_IRQ_VBUS_NOT_VALID,
	AXP20X_IRQ_VBUS_SESS_VALID,
	AXP20X_IRQ_VBUS_SESS_END,
	AXP20X_IRQ_LOW_PWR_LVL1,
	AXP20X_IRQ_LOW_PWR_LVL2,
	AXP20X_IRQ_TIMER,
	AXP20X_IRQ_PEK_RIS_EDGE,
	AXP20X_IRQ_PEK_FAL_EDGE,
	AXP20X_IRQ_GPIO3_INPUT,
	AXP20X_IRQ_GPIO2_INPUT,
	AXP20X_IRQ_GPIO1_INPUT,
	AXP20X_IRQ_GPIO0_INPUT,
};

enum axp22x_irqs {
	AXP22X_IRQ_ACIN_OVER_V = 1,
	AXP22X_IRQ_ACIN_PLUGIN,
	AXP22X_IRQ_ACIN_REMOVAL,
	AXP22X_IRQ_VBUS_OVER_V,
	AXP22X_IRQ_VBUS_PLUGIN,
	AXP22X_IRQ_VBUS_REMOVAL,
	AXP22X_IRQ_VBUS_V_LOW,
	AXP22X_IRQ_BATT_PLUGIN,
	AXP22X_IRQ_BATT_REMOVAL,
	AXP22X_IRQ_BATT_ENT_ACT_MODE,
	AXP22X_IRQ_BATT_EXIT_ACT_MODE,
	AXP22X_IRQ_CHARG,
	AXP22X_IRQ_CHARG_DONE,
	AXP22X_IRQ_BATT_TEMP_HIGH,
	AXP22X_IRQ_BATT_TEMP_LOW,
	AXP22X_IRQ_DIE_TEMP_HIGH,
	AXP22X_IRQ_PEK_SHORT,
	AXP22X_IRQ_PEK_LONG,
	AXP22X_IRQ_LOW_PWR_LVL1,
	AXP22X_IRQ_LOW_PWR_LVL2,
	AXP22X_IRQ_TIMER,
	AXP22X_IRQ_PEK_RIS_EDGE,
	AXP22X_IRQ_PEK_FAL_EDGE,
	AXP22X_IRQ_GPIO1_INPUT,
	AXP22X_IRQ_GPIO0_INPUT,
};

enum axp288_irqs {
	AXP288_IRQ_VBUS_FALL     = 2,
	AXP288_IRQ_VBUS_RISE,
	AXP288_IRQ_OV,
	AXP288_IRQ_FALLING_ALT,
	AXP288_IRQ_RISING_ALT,
	AXP288_IRQ_OV_ALT,
	AXP288_IRQ_DONE          = 10,
	AXP288_IRQ_CHARGING,
	AXP288_IRQ_SAFE_QUIT,
	AXP288_IRQ_SAFE_ENTER,
	AXP288_IRQ_ABSENT,
	AXP288_IRQ_APPEND,
	AXP288_IRQ_QWBTU,
	AXP288_IRQ_WBTU,
	AXP288_IRQ_QWBTO,
	AXP288_IRQ_WBTO,
	AXP288_IRQ_QCBTU,
	AXP288_IRQ_CBTU,
	AXP288_IRQ_QCBTO,
	AXP288_IRQ_CBTO,
	AXP288_IRQ_WL2,
	AXP288_IRQ_WL1,
	AXP288_IRQ_GPADC,
	AXP288_IRQ_OT            = 31,
	AXP288_IRQ_GPIO0,
	AXP288_IRQ_GPIO1,
	AXP288_IRQ_POKO,
	AXP288_IRQ_POKL,
	AXP288_IRQ_POKS,
	AXP288_IRQ_POKN,
	AXP288_IRQ_POKP,
	AXP288_IRQ_TIMER,
	AXP288_IRQ_MV_CHNG,
	AXP288_IRQ_BC_USB_CHNG,
};

enum axp803_irqs {
	AXP803_IRQ_ACIN_OVER_V = 1,
	AXP803_IRQ_ACIN_PLUGIN,
	AXP803_IRQ_ACIN_REMOVAL,
	AXP803_IRQ_VBUS_OVER_V,
	AXP803_IRQ_VBUS_PLUGIN,
	AXP803_IRQ_VBUS_REMOVAL,
	AXP803_IRQ_BATT_PLUGIN,
	AXP803_IRQ_BATT_REMOVAL,
	AXP803_IRQ_BATT_ENT_ACT_MODE,
	AXP803_IRQ_BATT_EXIT_ACT_MODE,
	AXP803_IRQ_CHARG,
	AXP803_IRQ_CHARG_DONE,
	AXP803_IRQ_BATT_CHG_TEMP_HIGH,
	AXP803_IRQ_BATT_CHG_TEMP_HIGH_END,
	AXP803_IRQ_BATT_CHG_TEMP_LOW,
	AXP803_IRQ_BATT_CHG_TEMP_LOW_END,
	AXP803_IRQ_BATT_ACT_TEMP_HIGH,
	AXP803_IRQ_BATT_ACT_TEMP_HIGH_END,
	AXP803_IRQ_BATT_ACT_TEMP_LOW,
	AXP803_IRQ_BATT_ACT_TEMP_LOW_END,
	AXP803_IRQ_DIE_TEMP_HIGH,
	AXP803_IRQ_GPADC,
	AXP803_IRQ_LOW_PWR_LVL1,
	AXP803_IRQ_LOW_PWR_LVL2,
	AXP803_IRQ_TIMER,
	AXP803_IRQ_PEK_RIS_EDGE,
	AXP803_IRQ_PEK_FAL_EDGE,
	AXP803_IRQ_PEK_SHORT,
	AXP803_IRQ_PEK_LONG,
	AXP803_IRQ_PEK_OVER_OFF,
	AXP803_IRQ_GPIO1_INPUT,
	AXP803_IRQ_GPIO0_INPUT,
	AXP803_IRQ_BC_USB_CHNG,
	AXP803_IRQ_MV_CHNG,
};

enum axp806_irqs {
	AXP806_IRQ_DIE_TEMP_HIGH_LV1,
	AXP806_IRQ_DIE_TEMP_HIGH_LV2,
	AXP806_IRQ_DCDCA_V_LOW,
	AXP806_IRQ_DCDCB_V_LOW,
	AXP806_IRQ_DCDCC_V_LOW,
	AXP806_IRQ_DCDCD_V_LOW,
	AXP806_IRQ_DCDCE_V_LOW,
	AXP806_IRQ_POK_LONG,
	AXP806_IRQ_POK_SHORT,
	AXP806_IRQ_WAKEUP,
	AXP806_IRQ_POK_FALL,
	AXP806_IRQ_POK_RISE,
};

enum axp809_irqs {
	AXP809_IRQ_ACIN_OVER_V = 1,
	AXP809_IRQ_ACIN_PLUGIN,
	AXP809_IRQ_ACIN_REMOVAL,
	AXP809_IRQ_VBUS_OVER_V,
	AXP809_IRQ_VBUS_PLUGIN,
	AXP809_IRQ_VBUS_REMOVAL,
	AXP809_IRQ_VBUS_V_LOW,
	AXP809_IRQ_BATT_PLUGIN,
	AXP809_IRQ_BATT_REMOVAL,
	AXP809_IRQ_BATT_ENT_ACT_MODE,
	AXP809_IRQ_BATT_EXIT_ACT_MODE,
	AXP809_IRQ_CHARG,
	AXP809_IRQ_CHARG_DONE,
	AXP809_IRQ_BATT_CHG_TEMP_HIGH,
	AXP809_IRQ_BATT_CHG_TEMP_HIGH_END,
	AXP809_IRQ_BATT_CHG_TEMP_LOW,
	AXP809_IRQ_BATT_CHG_TEMP_LOW_END,
	AXP809_IRQ_BATT_ACT_TEMP_HIGH,
	AXP809_IRQ_BATT_ACT_TEMP_HIGH_END,
	AXP809_IRQ_BATT_ACT_TEMP_LOW,
	AXP809_IRQ_BATT_ACT_TEMP_LOW_END,
	AXP809_IRQ_DIE_TEMP_HIGH,
	AXP809_IRQ_LOW_PWR_LVL1,
	AXP809_IRQ_LOW_PWR_LVL2,
	AXP809_IRQ_TIMER,
	AXP809_IRQ_PEK_RIS_EDGE,
	AXP809_IRQ_PEK_FAL_EDGE,
	AXP809_IRQ_PEK_SHORT,
	AXP809_IRQ_PEK_LONG,
	AXP809_IRQ_PEK_OVER_OFF,
	AXP809_IRQ_GPIO1_INPUT,
	AXP809_IRQ_GPIO0_INPUT,
};

enum axp858_irqs {
	/* irq0 */
	AXP858_IRQ_TEMP_OVER1 = 0,
	AXP858_IRQ_TEMP_OVER2,
	AXP858_IRQ_DCDC1_UNDER,
	AXP858_IRQ_DCDC2_UNDER,
	AXP858_IRQ_DCDC3_UNDER,
	AXP858_IRQ_DCDC4_UNDER,
	AXP858_IRQ_DCDC5_UNDER,
	AXP858_IRQ_DCDC6_UNDER,
	/* irq1 */
	AXP858_IRQ_POKLIRQ_EN,
	AXP858_IRQ_POKSIRQ_EN,
	AXP858_IRQ_GPIO1_EN,
	AXP858_IRQ_POKNIRQ_EN,
	AXP858_IRQ_POKPIRQ_EN,
	AXP858_IRQ_GPIO2_EN,
	AXP858_IRQ_DCDC2_CUR_OVER,
	AXP858_IRQ_DCDC3_CUR_OVER,
};

struct axp20x_dev {
	struct device			*dev;
	int				irq;
	unsigned long			irq_flags;
	struct regmap			*regmap;
	struct regmap_irq_chip_data	*regmap_irqc;
	long				variant;
	int                             nr_cells;
	const struct mfd_cell           *cells;
	const struct regmap_config	*regmap_cfg;
	const struct regmap_irq_chip	*regmap_irq_chip;
};

/* generic helper function for reading 9-16 bit wide regs */
static inline int axp20x_read_variable_width(struct regmap *regmap,
	unsigned int reg, unsigned int width)
{
	unsigned int reg_val, result;
	int err;

	err = regmap_read(regmap, reg, &reg_val);
	if (err)
		return err;

	result = reg_val << (width - 8);

	err = regmap_read(regmap, reg + 1, &reg_val);
	if (err)
		return err;

	result |= reg_val;

	return result;
}

/**
 * axp20x_match_device(): Setup axp20x variant related fields
 *
 * @axp20x: axp20x device to setup (.dev field must be set)
 * @dev: device associated with this axp20x device
 *
 * This lets the axp20x core configure the mfd cells and register maps
 * for later use.
 */
int axp20x_match_device(struct axp20x_dev *axp20x);

/**
 * axp20x_device_probe(): Probe a configured axp20x device
 *
 * @axp20x: axp20x device to probe (must be configured)
 *
 * This function lets the axp20x core register the axp20x mfd devices
 * and irqchip. The axp20x device passed in must be fully configured
 * with axp20x_match_device, its irq set, and regmap created.
 */
int axp20x_device_probe(struct axp20x_dev *axp20x);

/**
 * axp20x_device_remove(): Remove a axp20x device
 *
 * @axp20x: axp20x device to remove
 *
 * This tells the axp20x core to remove the associated mfd devices
 */
int axp20x_device_remove(struct axp20x_dev *axp20x);

#endif /* __LINUX_MFD_AXP20X_H */