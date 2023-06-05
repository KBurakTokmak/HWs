;Kadir Burak Tokmak e2036200
 ; TODO INSERT CONFIG CODE HERE USING CONFIG BITS GENERATOR

; PIC18F8722 Configuration Bit Settings

; Assembly source line config statements

#include "p18f8722.inc"

; CONFIG1H
  CONFIG  OSC = RCIO6           ; Oscillator Selection bits (External RC oscillator, port function on RA6)
  CONFIG  FCMEN = OFF           ; Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
  CONFIG  IESO = OFF            ; Internal/External Oscillator Switchover bit (Two-Speed Start-up disabled)

; CONFIG2L
  CONFIG  PWRT = OFF            ; Power-up Timer Enable bit (PWRT disabled)
  CONFIG  BOREN = SBORDIS       ; Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
  CONFIG  BORV = 3              ; Brown-out Voltage bits (Minimum setting)

; CONFIG2H
  CONFIG  WDT = ON              ; Watchdog Timer (WDT enabled)
  CONFIG  WDTPS = 32768         ; Watchdog Timer Postscale Select bits (1:32768)

; CONFIG3L
  CONFIG  MODE = MC             ; Processor Data Memory Mode Select bits (Microcontroller mode)
  CONFIG  ADDRBW = ADDR20BIT    ; Address Bus Width Select bits (20-bit Address Bus)
  CONFIG  DATABW = DATA16BIT    ; Data Bus Width Select bit (16-bit External Bus mode)
  CONFIG  WAIT = OFF            ; External Bus Data Wait Enable bit (Wait selections are unavailable for table reads and table writes)

; CONFIG3H
  CONFIG  CCP2MX = PORTC        ; CCP2 MUX bit (ECCP2 input/output is multiplexed with RC1)
  CONFIG  ECCPMX = PORTE        ; ECCP MUX bit (ECCP1/3 (P1B/P1C/P3B/P3C) are multiplexed onto RE6, RE5, RE4 and RE3 respectively)
  CONFIG  LPT1OSC = OFF         ; Low-Power Timer1 Oscillator Enable bit (Timer1 configured for higher power operation)
  CONFIG  MCLRE = ON            ; MCLR Pin Enable bit (MCLR pin enabled; RG5 input pin disabled)

; CONFIG4L
  CONFIG  STVREN = ON           ; Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
  CONFIG  LVP = ON              ; Single-Supply ICSP Enable bit (Single-Supply ICSP enabled)
  CONFIG  BBSIZ = BB2K          ; Boot Block Size Select bits (1K word (2 Kbytes) Boot Block size)
  CONFIG  XINST = OFF           ; Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

; CONFIG5L
  CONFIG  CP0 = OFF             ; Code Protection bit Block 0 (Block 0 (000800, 001000 or 002000-003FFFh) not code-protected)
  CONFIG  CP1 = OFF             ; Code Protection bit Block 1 (Block 1 (004000-007FFFh) not code-protected)
  CONFIG  CP2 = OFF             ; Code Protection bit Block 2 (Block 2 (008000-00BFFFh) not code-protected)
  CONFIG  CP3 = OFF             ; Code Protection bit Block 3 (Block 3 (00C000-00FFFFh) not code-protected)
  CONFIG  CP4 = OFF             ; Code Protection bit Block 4 (Block 4 (010000-013FFFh) not code-protected)
  CONFIG  CP5 = OFF             ; Code Protection bit Block 5 (Block 5 (014000-017FFFh) not code-protected)
  CONFIG  CP6 = OFF             ; Code Protection bit Block 6 (Block 6 (01BFFF-018000h) not code-protected)
  CONFIG  CP7 = OFF             ; Code Protection bit Block 7 (Block 7 (01C000-01FFFFh) not code-protected)

; CONFIG5H
  CONFIG  CPB = OFF             ; Boot Block Code Protection bit (Boot Block (000000-0007FFh) not code-protected)
  CONFIG  CPD = OFF             ; Data EEPROM Code Protection bit (Data EEPROM not code-protected)

; CONFIG6L
  CONFIG  WRT0 = OFF            ; Write Protection bit Block 0 (Block 0 (000800, 001000 or 002000-003FFFh) not write-protected)
  CONFIG  WRT1 = OFF            ; Write Protection bit Block 1 (Block 1 (004000-007FFFh) not write-protected)
  CONFIG  WRT2 = OFF            ; Write Protection bit Block 2 (Block 2 (008000-00BFFFh) not write-protected)
  CONFIG  WRT3 = OFF            ; Write Protection bit Block 3 (Block 3 (00C000-00FFFFh) not write-protected)
  CONFIG  WRT4 = OFF            ; Write Protection bit Block 4 (Block 4 (010000-013FFFh) not write-protected)
  CONFIG  WRT5 = OFF            ; Write Protection bit Block 5 (Block 5 (014000-017FFFh) not write-protected)
  CONFIG  WRT6 = OFF            ; Write Protection bit Block 6 (Block 6 (01BFFF-018000h) not write-protected)
  CONFIG  WRT7 = OFF            ; Write Protection bit Block 7 (Block 7 (01C000-01FFFFh) not write-protected)

; CONFIG6H
  CONFIG  WRTC = OFF            ; Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write-protected)
  CONFIG  WRTB = OFF            ; Boot Block Write Protection bit (Boot Block (000000-007FFF, 000FFF or 001FFFh) not write-protected)
  CONFIG  WRTD = OFF            ; Data EEPROM Write Protection bit (Data EEPROM not write-protected)

; CONFIG7L
  CONFIG  EBTR0 = OFF           ; Table Read Protection bit Block 0 (Block 0 (000800, 001000 or 002000-003FFFh) not protected from table reads executed in other blocks)
  CONFIG  EBTR1 = OFF           ; Table Read Protection bit Block 1 (Block 1 (004000-007FFFh) not protected from table reads executed in other blocks)
  CONFIG  EBTR2 = OFF           ; Table Read Protection bit Block 2 (Block 2 (008000-00BFFFh) not protected from table reads executed in other blocks)
  CONFIG  EBTR3 = OFF           ; Table Read Protection bit Block 3 (Block 3 (00C000-00FFFFh) not protected from table reads executed in other blocks)
  CONFIG  EBTR4 = OFF           ; Table Read Protection bit Block 4 (Block 4 (010000-013FFFh) not protected from table reads executed in other blocks)
  CONFIG  EBTR5 = OFF           ; Table Read Protection bit Block 5 (Block 5 (014000-017FFFh) not protected from table reads executed in other blocks)
  CONFIG  EBTR6 = OFF           ; Table Read Protection bit Block 6 (Block 6 (018000-01BFFFh) not protected from table reads executed in other blocks)
  CONFIG  EBTR7 = OFF           ; Table Read Protection bit Block 7 (Block 7 (01C000-01FFFFh) not protected from table reads executed in other blocks)

; CONFIG7H
  CONFIG  EBTRB = OFF           ; Boot Block Table Read Protection bit (Boot Block (000000-007FFF, 000FFF or 001FFFh) not protected from table reads executed in other blocks)




count1 udata 0x21
count1
count2 udata 0x22
count2
count3 udata 0x23
count3  
op udata 0x23
op 
ra4h udata 0x24
ra4h
 
    
RES_VECT  CODE    0x0000            ; processor reset vector
    GOTO    INIT                   ; go to beginning of program

; TODO ADD INTERRUPTS HERE IF USED

MAIN_PROG CODE                      ; let linker place main program

 
 
 
 
INIT
    MOVLW b'00010000'
    MOVWF TRISA
    MOVLW b'00001111'
    MOVWF TRISB
    MOVWF TRISC
    MOVLW b'00000000'
    MOVWF TRISD
    MOVLW b'00011000'
    MOVWF TRISE
    BSF ADCON1,4
    CLRF op
 
 START
    MOVLW b'00001111'
    MOVWF LATB
    MOVWF LATC
    MOVLW 0xFF
    MOVWF LATD
    call delay1sec
    CLRF LATB
    CLRF LATC
    CLRF LATD
    
    
    
operation:
    call ra4p
    BTFSC ra4h,0
    call ra4rel
    ;call re3p
    ;BTFSC re3h,0
    ;call re3rel
    ;BTFSS re3h,1
    goto operation
    ;goto bport
    
    
 

    GOTO $                          ; loop forever

ra4p:
    BTFSC PORTA,4
    BSF ra4h,0
    return
  
ra4rel:
    BTFSC PORTA,4
    GOTO ra4rel
    BSF ra4h,1
    return
    
    
    
    
delay1sec:
 MOVLW D'250'
 MOVWF count1
 MOVLW D'199'
 MOVWF count2
 MOVLW D'51'
 MOVWF count3

 loop:
 decfsz count1,1
 goto loop
 decfsz count2,1
 goto loop
 decfsz count3,1
 goto loop
 return

    
    
    
    END
