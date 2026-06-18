#include <pic18.h>

void timer();

void main(void) {
    TRISD = 0x00;    // PORTD as output
    TMR1L = 0x96;    // Load low byte
    TMR1H = 0xE7;    // Load high byte
    T1CON = 0x79;    // Enable Timer1, prescaler 8

    while (1) {
        LATD = 0xFF; // PORTD high
        timer();
        LATD = 0x00; // PORTD low
        timer();
    }
}

void timer() {
    while (TMR1IF == 0); // Wait for overflow
    TMR1IF = 0;          // Clear overflow flag
    TMR1L = 0x96;        // Reload low byte
    TMR1H = 0xE7;        // Reload high byte
}
