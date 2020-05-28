EESchema Schematic File Version 2
LIBS:rlcsv2_modular-rescue
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:custom
LIBS:rlcsv2_modular-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 11
Title "RLCSv2"
Date "2017-07-09"
Rev "C"
Comp "Waterloo Rocketry Team"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MEZD71201A-G T1
U 1 1 596A4D15
P 5750 1850
F 0 "T1" H 6100 1700 60  0000 C CNN
F 1 "MEZD71201A-G" H 5750 1950 60  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 5750 1950 60  0001 C CNN
F 3 "" H 5750 1950 60  0001 C CNN
	1    5750 1850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR023
U 1 1 596A4E41
P 5750 2250
F 0 "#PWR023" H 5750 2000 50  0001 C CNN
F 1 "GND" H 5750 2100 50  0000 C CNN
F 2 "" H 5750 2250 50  0001 C CNN
F 3 "" H 5750 2250 50  0001 C CNN
	1    5750 2250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR024
U 1 1 596A4E5C
P 5750 3100
F 0 "#PWR024" H 5750 2850 50  0001 C CNN
F 1 "GND" H 5750 2950 50  0000 C CNN
F 2 "" H 5750 3100 50  0001 C CNN
F 3 "" H 5750 3100 50  0001 C CNN
	1    5750 3100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR025
U 1 1 596A4E70
P 5600 4300
F 0 "#PWR025" H 5600 4050 50  0001 C CNN
F 1 "GND" H 5600 4150 50  0000 C CNN
F 2 "" H 5600 4300 50  0001 C CNN
F 3 "" H 5600 4300 50  0001 C CNN
	1    5600 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 3100 6300 3100
Wire Wire Line
	6300 3100 6300 2250
Wire Wire Line
	5900 2250 7200 2250
$Comp
L +5V #PWR026
U 1 1 596A4E9C
P 6700 2100
F 0 "#PWR026" H 6700 1950 50  0001 C CNN
F 1 "+5V" H 6700 2240 50  0000 C CNN
F 2 "" H 6700 2100 50  0001 C CNN
F 3 "" H 6700 2100 50  0001 C CNN
	1    6700 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	6700 2250 6700 2100
Connection ~ 6300 2250
$Comp
L +15V #PWR027
U 1 1 596A4EC2
P 6700 3550
F 0 "#PWR027" H 6700 3400 50  0001 C CNN
F 1 "+15V" H 6700 3690 50  0000 C CNN
F 2 "" H 6700 3550 50  0001 C CNN
F 3 "" H 6700 3550 50  0001 C CNN
	1    6700 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 4150 7100 4150
Wire Wire Line
	6700 4150 6700 3550
Wire Wire Line
	5100 4150 5700 4150
Wire Wire Line
	5100 2250 5100 4150
Wire Wire Line
	4550 2250 5600 2250
Wire Wire Line
	4500 3100 5600 3100
Connection ~ 5100 3100
$Comp
L GND #PWR028
U 1 1 596A4F64
P 3850 3200
F 0 "#PWR028" H 3850 2950 50  0001 C CNN
F 1 "GND" H 3850 3050 50  0000 C CNN
F 2 "" H 3850 3200 50  0001 C CNN
F 3 "" H 3850 3200 50  0001 C CNN
	1    3850 3200
	1    0    0    -1  
$EndComp
$Comp
L +12V #PWR029
U 1 1 596A4F9C
P 4550 2100
F 0 "#PWR029" H 4550 1950 50  0001 C CNN
F 1 "+12V" H 4550 2240 50  0000 C CNN
F 2 "" H 4550 2100 50  0001 C CNN
F 3 "" H 4550 2100 50  0001 C CNN
	1    4550 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 2250 4550 2100
Connection ~ 5100 2250
$Comp
L GND #PWR030
U 1 1 596A5068
P 2650 2900
F 0 "#PWR030" H 2650 2650 50  0001 C CNN
F 1 "GND" H 2650 2750 50  0000 C CNN
F 2 "" H 2650 2900 50  0001 C CNN
F 3 "" H 2650 2900 50  0001 C CNN
	1    2650 2900
	1    0    0    -1  
$EndComp
Text Notes 1100 2250 0    60   ~ 0
Batteries driving actuators\n
Text Notes 2450 3200 0    60   ~ 0
Battery driving logic\n
$Comp
L FUSE F1
U 1 1 596A51F3
P 2650 2650
F 0 "F1" H 2650 2800 50  0000 C CNN
F 1 "20A" H 2500 2800 50  0000 C CNN
F 2 "custom:littlefuse_01000020Z" V 2580 2650 50  0001 C CNN
F 3 "" H 2650 2650 50  0001 C CNN
	1    2650 2650
	0    -1   -1   0   
$EndComp
$Comp
L FUSE F2
U 1 1 596A52CE
P 4250 3100
F 0 "F2" H 4250 3250 50  0000 C CNN
F 1 "10A" H 4250 2950 50  0000 C CNN
F 2 "custom:littlefuse_01000020Z" V 4180 3100 50  0001 C CNN
F 3 "" H 4250 3100 50  0001 C CNN
	1    4250 3100
	-1   0    0    1   
$EndComp
Wire Wire Line
	3850 3100 4000 3100
$Comp
L CONN_01X02 J12
U 1 1 596DD762
P 3650 3150
F 0 "J12" H 3650 3300 50  0000 C CNN
F 1 "BATT_1" V 3750 3150 50  0000 C CNN
F 2 "Terminal_Blocks:TerminalBlock_Pheonix_MKDS1.5-2pol" H 3650 3150 50  0001 C CNN
F 3 "" H 3650 3150 50  0001 C CNN
	1    3650 3150
	-1   0    0    1   
$EndComp
$Comp
L MEZD71201A-G T2
U 1 1 596DD88D
P 5750 2700
F 0 "T2" H 6100 2550 60  0000 C CNN
F 1 "MEZD71201A-G" H 5750 2800 60  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 5750 2800 60  0001 C CNN
F 3 "" H 5750 2800 60  0001 C CNN
	1    5750 2700
	1    0    0    -1  
$EndComp
Connection ~ 6700 2250
$Comp
L GND #PWR031
U 1 1 596DDA81
P 7100 2500
F 0 "#PWR031" H 7100 2250 50  0001 C CNN
F 1 "GND" H 7100 2350 50  0000 C CNN
F 2 "" H 7100 2500 50  0001 C CNN
F 3 "" H 7100 2500 50  0001 C CNN
	1    7100 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 2400 7100 2400
Wire Wire Line
	7100 2400 7100 2500
Text GLabel 7200 2250 2    60   Input ~ 0
ARD_PWR
Text GLabel 7200 2400 2    60   Input ~ 0
ARD_GND
$Comp
L 12-15v T3
U 1 1 596D28DE
P 5750 3550
F 0 "T3" H 6100 3450 60  0000 C CNN
F 1 "12-15v" H 5750 3650 60  0000 C CNN
F 2 "Converters_DCDC_ACDC:DCDC-Conv_TRACO_TMR_1-xxxx_Single" H 5750 3650 60  0001 C CNN
F 3 "" H 5750 3650 60  0001 C CNN
	1    5750 3550
	1    0    0    -1  
$EndComp
NoConn ~ 5150 3400
$Comp
L TEST_1P TP8
U 1 1 5973AD84
P 7100 3650
F 0 "TP8" H 7100 3920 50  0000 C CNN
F 1 "TEST_15" H 7100 3850 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 7300 3650 50  0001 C CNN
F 3 "" H 7300 3650 50  0000 C CNN
	1    7100 3650
	1    0    0    -1  
$EndComp
$Comp
L TEST_1P TP4
U 1 1 5973AED7
P 3650 2250
F 0 "TP4" H 3650 2520 50  0000 C CNN
F 1 "TEST_IGN_P" H 3650 2450 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 3850 2250 50  0001 C CNN
F 3 "" H 3850 2250 50  0000 C CNN
	1    3650 2250
	-1   0    0    1   
$EndComp
$Comp
L TEST_1P TP7
U 1 1 5973AF7F
P 7000 2150
F 0 "TP7" H 7000 2420 50  0000 C CNN
F 1 "TEST_5" H 7000 2350 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 7200 2150 50  0001 C CNN
F 3 "" H 7200 2150 50  0000 C CNN
	1    7000 2150
	1    0    0    -1  
$EndComp
$Comp
L TEST_1P TP5
U 1 1 5973B4CA
P 4900 2150
F 0 "TP5" H 4900 2420 50  0000 C CNN
F 1 "TEST_12V" H 4900 2350 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 5100 2150 50  0001 C CNN
F 3 "" H 5100 2150 50  0000 C CNN
	1    4900 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 2150 4900 2250
Connection ~ 4900 2250
Wire Wire Line
	7000 2150 7000 2250
Connection ~ 7000 2250
Wire Wire Line
	7100 4150 7100 3650
Connection ~ 6700 4150
$Comp
L TEST_1P TP6
U 1 1 5973C558
P 5950 4300
F 0 "TP6" H 5950 4570 50  0000 C CNN
F 1 "TEST_GND" H 5950 4500 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 6150 4300 50  0001 C CNN
F 3 "" H 6150 4300 50  0000 C CNN
	1    5950 4300
	-1   0    0    1   
$EndComp
Text HLabel 3800 2000 2    60   Input ~ 0
IGN_P
Text HLabel 3800 2100 2    60   Input ~ 0
DIS_P
Text HLabel 3800 2300 2    60   Input ~ 0
VALVE2_P
$Comp
L TEST_1P TP2
U 1 1 5975D0C0
P 3150 2250
F 0 "TP2" H 3150 2520 50  0000 C CNN
F 1 "TEST_V1_P" H 3150 2450 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 3350 2250 50  0001 C CNN
F 3 "" H 3350 2250 50  0000 C CNN
	1    3150 2250
	-1   0    0    1   
$EndComp
$Comp
L TEST_1P TP3
U 1 1 5975D0FB
P 3400 2450
F 0 "TP3" H 3400 2720 50  0000 C CNN
F 1 "TEST_V2_P" H 3400 2650 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 3600 2450 50  0001 C CNN
F 3 "" H 3600 2450 50  0000 C CNN
	1    3400 2450
	-1   0    0    1   
$EndComp
Wire Wire Line
	2650 2300 3800 2300
Wire Wire Line
	2650 2200 3800 2200
Wire Wire Line
	2650 2100 3800 2100
Wire Wire Line
	2900 2450 2900 2300
Connection ~ 2900 2300
Wire Wire Line
	3150 2250 3150 2200
Connection ~ 3150 2200
Wire Wire Line
	3400 2450 3400 2100
Connection ~ 3400 2100
Wire Wire Line
	2650 1900 2650 1900
$Comp
L CONN_01X05 J11
U 1 1 5977E3BD
P 2450 2200
F 0 "J11" H 2450 2500 50  0000 C CNN
F 1 "ACTUATOR_PWR" V 2550 2200 50  0000 C CNN
F 2 "Terminal_Blocks:TerminalBlock_Pheonix_MKDS1.5-5pol" H 2450 2200 50  0001 C CNN
F 3 "" H 2450 2200 50  0000 C CNN
	1    2450 2200
	-1   0    0    1   
$EndComp
$Comp
L TEST_1P TP1
U 1 1 5977E76D
P 2900 2450
F 0 "TP1" H 2900 2720 50  0000 C CNN
F 1 "TEST_RD_P" H 2900 2650 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01_Pitch2.54mm" H 3100 2450 50  0001 C CNN
F 3 "" H 3100 2450 50  0000 C CNN
	1    2900 2450
	-1   0    0    1   
$EndComp
Wire Wire Line
	3650 2250 3650 2000
Wire Wire Line
	2650 2000 3800 2000
Connection ~ 3650 2000
Text HLabel 3800 2200 2    60   Input ~ 0
VALVE1_P
Wire Wire Line
	5700 4150 5700 4000
Wire Wire Line
	5850 4150 5850 4000
Wire Wire Line
	5600 4000 5600 4300
Wire Wire Line
	5600 4300 5950 4300
Wire Wire Line
	5950 4300 5950 4000
$EndSCHEMATC