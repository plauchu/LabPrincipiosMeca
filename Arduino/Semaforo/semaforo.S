;--------------
; Assembly Code
;--------------
#define __SFR_OFFSET 0x00
#include "avr/io.h"
;--------------------------
.global START
;--------------------------
START:
;LEDS como salidas (6)
;semaforo principal
    SBI DDRB, 4 ;verde
    SBI DDRB, 3 ;amarillo
    SBI DDRB, 2 ;rojo
;semaforo no principal
    SBI DDRC, 4 ;verde 
    SBI DDRC, 3 ;amarillo
    SBI DDRC, 2 ;rojo
;DIPS como entradas (5)
    CBI DDRD, 2 ; 5 coche
    CBI DDRD, 3 ; 4 coche
    CBI DDRD, 4 ; 3 coche
    CBI DDRD, 5 ; 2 coche
    CBI DDRD, 6 ; 1 coche
    RET 
;-----------------------
;se queda en verde si no hay coches
principal:
    SBI PORTB, 4 ;Prende el verde de la prin
    CBI PORTB, 3 ;apaga todos menos el verde de la prin
    CBI PORTB, 2
    CBI PORTC, 4
    CBI PORTC, 3
    SBI PORTC, 2 ;prende rojo no prin
    SBIC PIND, 2 ;SKIP si el bit esta en low
    rjmp pasan_cinco ;sino deja pasar
    rjmp mi_delay
    SBIC PIND, 3 ;SKIP si el bit esta en low
    rjmp pasan_cuatro ;sino deja pasar
    rjmp mi_delay
    SBIC PIND, 4 ;SKIP si el bit esta en low
    rjmp pasan_tres ;sino deja pasar
    rjmp mi_delay
    SBIC PIND, 5 ;SKIP si el bit esta en low
    rjmp pasan_dos ;sino deja pasar
    rjmp mi_delay
    SBIC PIND, 6 ;SKIP si el bit esta en low
    rjmp pasa_uno ;sino deja pasar
    rjmp mi_delay
    rjmp principal ;loops forever
    
mi_delay: ;para que se vaya a verde la principal
    SBI PORTB, 4 ;Prende el verde de la prin
    CBI PORTB, 3 ;apaga todos menos el verde de la prin
    CBI PORTB, 2
    CBI PORTC, 4
    CBI PORTC, 3
    SBI PORTC, 2 ;prende rojo no prin
    rjmp principal ;loops forever

pasan_cinco: ;3 segs
    CBI PORTB, 4 ;apaga la verde prin
    CBI PORTB, 3 
    SBI PORTB, 2 ;prende rojo prin
    SBI PORTC, 4 ;prende el verde no prin
    CBI PORTC, 3
    CBI PORTC, 2
    rjmp principal ;loops forever
    
pasan_cuatro: ;2.4 segs
    CBI PORTB, 4 ;apaga la verde prin
    CBI PORTB, 3 
    SBI PORTB, 2 ;prende rojo prin
    SBI PORTC, 4 ;prende el verde no prin
    CBI PORTC, 3
    CBI PORTC, 2
    rjmp principal ;loops forever
    
pasan_tres: ;1.8 segs
    CBI PORTB, 3 ;apaga todos menos el verde de la prin
    CBI PORTB, 2
    CBI PORTC, 4
    CBI PORTC, 3
    CBI PORTC, 2
    rjmp principal ;loops forever
    
pasan_dos: ;1.2 segs
    CBI PORTB, 4 ;apaga la verde prin
    CBI PORTB, 3 
    SBI PORTB, 2 ;prende rojo prin
    SBI PORTC, 4 ;prende el verde no prin
    CBI PORTC, 3
    CBI PORTC, 2
    rjmp principal ;loops forever
    
pasa_uno: ;0.6 segs
    CBI PORTB, 4 ;apaga la verde prin
    CBI PORTB, 3 
    SBI PORTB, 2 ;prende rojo prin
    SBI PORTC, 4 ;prende el verde no prin
    CBI PORTC, 3
    CBI PORTC, 2
    rjmp principal ;loops forever

    

        
        
          
    
    
