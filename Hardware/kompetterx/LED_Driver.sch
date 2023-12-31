EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Driver_LED:IS31FL3731-QF U?
U 1 1 605E5925
P 3600 2500
AR Path="/605E5925" Ref="U?"  Part="1" 
AR Path="/605E4900/605E5925" Ref="U?"  Part="1" 
F 0 "U?" H 3950 3550 50  0000 C CNN
F 1 "IS31FL3731-QF" H 3900 1450 50  0000 C CNN
F 2 "Package_DFN_QFN:QFN-28-1EP_4x4mm_P0.4mm_EP2.3x2.3mm" H 3600 2500 50  0001 C CNN
F 3 "http://www.issi.com/WW/pdf/31FL3731.pdf" H 3600 2500 50  0001 C CNN
	1    3600 2500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 605E5AD8
P 3600 3700
F 0 "#PWR?" H 3600 3450 50  0001 C CNN
F 1 "GND" H 3605 3527 50  0000 C CNN
F 2 "" H 3600 3700 50  0001 C CNN
F 3 "" H 3600 3700 50  0001 C CNN
	1    3600 3700
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 605EC99A
P 1900 800
AR Path="/605EC99A" Ref="#PWR?"  Part="1" 
AR Path="/605E4900/605EC99A" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 1900 650 50  0001 C CNN
F 1 "+3.3V" H 1915 973 50  0000 C CNN
F 2 "" H 1900 800 50  0001 C CNN
F 3 "" H 1900 800 50  0001 C CNN
	1    1900 800 
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 605EDCB7
P 2400 1050
F 0 "C?" H 2492 1096 50  0000 L CNN
F 1 "10uF" H 2492 1005 50  0000 L CNN
F 2 "" H 2400 1050 50  0001 C CNN
F 3 "~" H 2400 1050 50  0001 C CNN
	1    2400 1050
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 605EEF8D
P 2900 1050
F 0 "C?" H 2992 1096 50  0000 L CNN
F 1 "10uF" H 2992 1005 50  0000 L CNN
F 2 "" H 2900 1050 50  0001 C CNN
F 3 "~" H 2900 1050 50  0001 C CNN
	1    2900 1050
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 605EF6B1
P 1900 1050
F 0 "C?" H 1992 1096 50  0000 L CNN
F 1 "10uF" H 1992 1005 50  0000 L CNN
F 2 "" H 1900 1050 50  0001 C CNN
F 3 "~" H 1900 1050 50  0001 C CNN
	1    1900 1050
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 800  1900 850 
Wire Wire Line
	1900 850  2400 850 
Wire Wire Line
	2400 850  2400 950 
Connection ~ 1900 850 
Wire Wire Line
	1900 850  1900 950 
Wire Wire Line
	2400 850  2900 850 
Wire Wire Line
	2900 850  2900 950 
Connection ~ 2400 850 
Wire Wire Line
	2900 850  3600 850 
Wire Wire Line
	3600 850  3600 1400
Connection ~ 2900 850 
Wire Wire Line
	2900 1150 2900 1300
Wire Wire Line
	2900 1300 2400 1300
Wire Wire Line
	1900 1300 1900 1150
Wire Wire Line
	2400 1150 2400 1300
Connection ~ 2400 1300
Wire Wire Line
	2400 1300 1900 1300
$Comp
L power:GND #PWR?
U 1 1 60600F72
P 1900 1350
F 0 "#PWR?" H 1900 1100 50  0001 C CNN
F 1 "GND" H 1905 1177 50  0000 C CNN
F 2 "" H 1900 1350 50  0001 C CNN
F 3 "" H 1900 1350 50  0001 C CNN
	1    1900 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 1350 1900 1300
Connection ~ 1900 1300
Wire Wire Line
	1450 850  1450 1050
$Comp
L Device:R_Small R?
U 1 1 60603A32
P 1000 1150
F 0 "R?" H 1059 1196 50  0000 L CNN
F 1 "10K" H 1059 1105 50  0000 L CNN
F 2 "" H 1000 1150 50  0001 C CNN
F 3 "~" H 1000 1150 50  0001 C CNN
	1    1000 1150
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 60604771
P 1450 1150
F 0 "R?" H 1509 1196 50  0000 L CNN
F 1 "10K" H 1509 1105 50  0000 L CNN
F 2 "" H 1450 1150 50  0001 C CNN
F 3 "~" H 1450 1150 50  0001 C CNN
	1    1450 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 1250 1450 1600
Wire Wire Line
	1000 1050 1000 850 
Wire Wire Line
	1000 850  1450 850 
Connection ~ 1450 850 
$Comp
L Device:R_Small R?
U 1 1 60609738
P 2100 2000
F 0 "R?" H 2041 1954 50  0000 R CNN
F 1 "10K" H 2041 2045 50  0000 R CNN
F 2 "" H 2100 2000 50  0001 C CNN
F 3 "~" H 2100 2000 50  0001 C CNN
	1    2100 2000
	-1   0    0    1   
$EndComp
Wire Wire Line
	1000 1250 1000 1700
Wire Wire Line
	3100 1800 2100 1800
$Comp
L power:GND #PWR?
U 1 1 6060D17F
P 2100 2200
F 0 "#PWR?" H 2100 1950 50  0001 C CNN
F 1 "GND" H 2105 2027 50  0000 C CNN
F 2 "" H 2100 2200 50  0001 C CNN
F 3 "" H 2100 2200 50  0001 C CNN
	1    2100 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 2200 2100 2100
Wire Wire Line
	2100 1800 2100 1900
$Comp
L power:+3.3V #PWR?
U 1 1 6060E842
P 2900 2000
AR Path="/6060E842" Ref="#PWR?"  Part="1" 
AR Path="/605E4900/6060E842" Ref="#PWR?"  Part="1" 
F 0 "#PWR?" H 2900 1850 50  0001 C CNN
F 1 "+3.3V" V 3000 2100 50  0000 C CNN
F 2 "" H 2900 2000 50  0001 C CNN
F 3 "" H 2900 2000 50  0001 C CNN
	1    2900 2000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3100 2000 2900 2000
NoConn ~ 3100 2300
Wire Wire Line
	1450 1600 3100 1600
Wire Wire Line
	1000 1700 3100 1700
Wire Wire Line
	1450 850  1900 850 
$Comp
L Device:R_Small R?
U 1 1 60612449
P 2950 2950
F 0 "R?" H 2891 2904 50  0000 R CNN
F 1 "10K" H 2891 2995 50  0000 R CNN
F 2 "" H 2950 2950 50  0001 C CNN
F 3 "~" H 2950 2950 50  0001 C CNN
	1    2950 2950
	-1   0    0    1   
$EndComp
Wire Wire Line
	3100 2600 2950 2600
Wire Wire Line
	2950 2600 2950 2850
Wire Wire Line
	3600 3600 3600 3650
Wire Wire Line
	2950 3650 3600 3650
Wire Wire Line
	2950 3050 2950 3650
Connection ~ 3600 3650
Wire Wire Line
	3600 3650 3600 3700
Text Label 4100 1600 0    50   ~ 0
CA1
Text Label 4100 1700 0    50   ~ 0
CA2
Text Label 4100 1800 0    50   ~ 0
CA3
Text Label 4100 1900 0    50   ~ 0
CA4
Text Label 4100 2000 0    50   ~ 0
CA5
Text Label 4100 2100 0    50   ~ 0
CA6
Text Label 4100 2200 0    50   ~ 0
CA7
Text Label 4100 2300 0    50   ~ 0
CA8
Text Label 4100 2400 0    50   ~ 0
CA9
Text Label 4100 2600 0    50   ~ 0
CB1
Text Label 4100 2700 0    50   ~ 0
CB2
Text Label 4100 2800 0    50   ~ 0
CB3
Text Label 4100 2900 0    50   ~ 0
CB4
Text Label 4100 3000 0    50   ~ 0
CB5
Text Label 4100 3100 0    50   ~ 0
CB6
Text Label 4100 3200 0    50   ~ 0
CB7
Text Label 4100 3300 0    50   ~ 0
CB8
Text Label 4100 3400 0    50   ~ 0
CB9
NoConn ~ 3100 2400
Text HLabel 1400 1600 0    50   Input ~ 0
SDA
Text HLabel 950  1700 0    50   Input ~ 0
SCL
Text HLabel 3050 2100 0    50   Input ~ 0
INTB
Text HLabel 2050 1800 0    50   Input ~ 0
ADDR
Wire Wire Line
	950  1700 1000 1700
Connection ~ 1000 1700
Wire Wire Line
	1400 1600 1450 1600
Connection ~ 1450 1600
Wire Wire Line
	2050 1800 2100 1800
Connection ~ 2100 1800
Wire Wire Line
	3050 2100 3100 2100
Wire Wire Line
	5150 1900 5400 1900
$Comp
L Device:LED_Small D?
U 1 1 6062EF41
P 5400 2000
F 0 "D?" V 5354 2098 50  0000 L CNN
F 1 "Yel" V 5445 2098 50  0000 L CNN
F 2 "" V 5400 2000 50  0001 C CNN
F 3 "~" V 5400 2000 50  0001 C CNN
	1    5400 2000
	0    1    1    0   
$EndComp
$Comp
L Device:LED_Small D?
U 1 1 606303D0
P 5400 2400
F 0 "D?" V 5354 2498 50  0000 L CNN
F 1 "Yel" V 5445 2498 50  0000 L CNN
F 2 "" V 5400 2400 50  0001 C CNN
F 3 "~" V 5400 2400 50  0001 C CNN
	1    5400 2400
	0    1    1    0   
$EndComp
$Comp
L Device:LED_Small D?
U 1 1 6063099E
P 5400 2800
F 0 "D?" V 5354 2898 50  0000 L CNN
F 1 "Yel" V 5445 2898 50  0000 L CNN
F 2 "" V 5400 2800 50  0001 C CNN
F 3 "~" V 5400 2800 50  0001 C CNN
	1    5400 2800
	0    1    1    0   
$EndComp
Wire Wire Line
	5400 2500 5400 2550
Wire Wire Line
	5400 2550 5500 2550
Wire Wire Line
	5500 2550 5500 2150
Wire Wire Line
	5400 2700 5400 2650
Wire Wire Line
	5400 2300 5750 2300
Wire Wire Line
	5400 2650 5500 2650
Wire Wire Line
	5050 2300 5250 2300
Wire Wire Line
	5250 2300 5250 2950
Connection ~ 5250 2300
Wire Wire Line
	5400 2950 5400 2900
Connection ~ 5250 2950
Wire Wire Line
	5250 2950 5250 3400
$Comp
L Device:LED_Small D?
U 1 1 60636E86
P 5400 3250
F 0 "D?" V 5354 3348 50  0000 L CNN
F 1 "Yel" V 5445 3348 50  0000 L CNN
F 2 "" V 5400 3250 50  0001 C CNN
F 3 "~" V 5400 3250 50  0001 C CNN
	1    5400 3250
	0    1    1    0   
$EndComp
Text Label 5150 1900 2    50   ~ 0
CA1
Text Label 5050 2300 2    50   ~ 0
CA2
Text Label 5050 2650 2    50   ~ 0
CA3
Text Label 5050 3050 2    50   ~ 0
CA4
Wire Wire Line
	5400 3150 5400 3050
Wire Wire Line
	5400 3050 5750 3050
Wire Wire Line
	5400 3350 5400 3400
Wire Wire Line
	5250 2300 5400 2300
Connection ~ 5400 2300
Wire Wire Line
	5050 2650 5400 2650
Connection ~ 5400 2650
Wire Wire Line
	5250 2950 5400 2950
Wire Wire Line
	5050 3050 5400 3050
Connection ~ 5400 3050
Wire Wire Line
	5250 3400 5400 3400
Wire Wire Line
	5400 2100 5400 2150
Wire Wire Line
	5400 2150 5500 2150
Wire Wire Line
	5050 3500 5400 3500
$Comp
L Device:LED_Small D?
U 1 1 60641F6D
P 5400 3750
F 0 "D?" V 5354 3848 50  0000 L CNN
F 1 "Yel" V 5445 3848 50  0000 L CNN
F 2 "" V 5400 3750 50  0001 C CNN
F 3 "~" V 5400 3750 50  0001 C CNN
	1    5400 3750
	0    1    1    0   
$EndComp
$Comp
L Device:LED_Small D?
U 1 1 606429E1
P 5400 4250
F 0 "D?" V 5354 4348 50  0000 L CNN
F 1 "Yel" V 5445 4348 50  0000 L CNN
F 2 "" V 5400 4250 50  0001 C CNN
F 3 "~" V 5400 4250 50  0001 C CNN
	1    5400 4250
	0    1    1    0   
$EndComp
$Comp
L Device:LED_Small D?
U 1 1 60642F60
P 5400 4750
F 0 "D?" V 5354 4848 50  0000 L CNN
F 1 "Yel" V 5445 4848 50  0000 L CNN
F 2 "" V 5400 4750 50  0001 C CNN
F 3 "~" V 5400 4750 50  0001 C CNN
	1    5400 4750
	0    1    1    0   
$EndComp
$Comp
L Device:LED_Small D?
U 1 1 606436BB
P 5400 5250
F 0 "D?" V 5354 5348 50  0000 L CNN
F 1 "Yel" V 5445 5348 50  0000 L CNN
F 2 "" V 5400 5250 50  0001 C CNN
F 3 "~" V 5400 5250 50  0001 C CNN
	1    5400 5250
	0    1    1    0   
$EndComp
Wire Wire Line
	5050 4000 5400 4000
Wire Wire Line
	5050 4500 5400 4500
Wire Wire Line
	5050 5000 5400 5000
Wire Wire Line
	5250 3400 5250 3950
Connection ~ 5250 3400
Wire Wire Line
	5250 3950 5400 3950
Wire Wire Line
	5400 3950 5400 3850
Connection ~ 5250 3950
Wire Wire Line
	5400 4850 5400 4950
Wire Wire Line
	5400 4950 5250 4950
Wire Wire Line
	5400 5350 5400 5450
Wire Wire Line
	5400 5450 5250 5450
Wire Wire Line
	5400 4350 5400 4450
Wire Wire Line
	5400 4450 5250 4450
Wire Wire Line
	5250 3950 5250 4450
Wire Wire Line
	5250 4450 5250 4950
Connection ~ 5250 4450
Wire Wire Line
	5250 5450 5250 4950
Connection ~ 5250 4950
Wire Wire Line
	5400 5150 5400 5000
Connection ~ 5400 5000
Wire Wire Line
	5400 5000 5750 5000
Wire Wire Line
	5400 4650 5400 4500
Connection ~ 5400 4500
Wire Wire Line
	5400 4500 5750 4500
Wire Wire Line
	5400 4150 5400 4000
Connection ~ 5400 4000
Wire Wire Line
	5400 4000 5750 4000
Wire Wire Line
	5400 3650 5400 3500
Connection ~ 5400 3500
Wire Wire Line
	5400 3500 5750 3500
Connection ~ 5400 1900
Wire Wire Line
	5400 1900 5750 1900
Text Label 5050 3500 2    50   ~ 0
CA5
Text Label 5050 4000 2    50   ~ 0
CA6
Text Label 5050 4500 2    50   ~ 0
CA7
Text Label 5050 5000 2    50   ~ 0
CA8
Wire Wire Line
	5500 2550 5500 2650
Connection ~ 5500 2550
Connection ~ 5500 2650
Wire Wire Line
	5500 2650 5750 2650
$EndSCHEMATC
