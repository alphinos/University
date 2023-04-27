
@ First, I tried to iterate over an array to create this, but I failed...
@ So, I'll just use an array with constant indexes

.sum:
    mov r5, 0 @sum
    ld r6, [r3]
    add r5, r5, r6
    .print r6
    ld r6, 4[r3]
    add r5, r5, r6
    .print r6
    ld r6, 8[r3]
    add r5, r5, r6
    .print r6
    ld r6, 12[r3]
    add r5, r5, r6
    .print r6
    
    ret

.main:
    mov r4, 0 @helper
    mov r1, 0 @ value
    mov r3, 0 @ the start of the array

    st r1, [r3]
    add r1, r1, 1
    st r1, 4[r3]
    add r1, r1, 1
    st r1, 8[r3]
    add r1, r1, 1
    st r1, 12[r3]
    add r1, r1, 1

    mov r4, sp
    ld r4, [r3]
    .print r4
    ld r4, 4[r3]
    .print r4
    ld r4, 8[r3]
    .print r4
    ld r4, 12[r3]
    .print r4

    mov r1, 4 @ size of array

    call .sum
    nop
    .print r5