
.main:

    @ Primeiro número

    movu r0, 00011
    .print r0
    st r0, [r4]
    movu r0, 5792
    .print r0
    st r0, 4[r4]

    movu r0, 08921
    .print r0
    st r0, 8[r4]
    movu r0, 0356
    .print r0
    st r0, 12[r4]

    movu r0, 24876
    .print r0
    st r0, 16[r4]
    movu r0, 2697
    .print r0
    st r0, 20[r4]

    movu r0, 44694
    .print r0
    st r0, 24[r4]
    movu r0, 9407
    .print r0
    st r0, 28[r4]

    movu r0, 57353
    .print r0
    st r0, 32[r4]
    movu r0, 0086
    .print r0
    st r0, 36[r4]

    movu r0, 14341
    .print r0
    st r0, 40[r4]
    movu r0, 5290
    .print r0
    st r0, 44[r4]

    movu r0, 31419
    .print r0
    st r0, 48[r4]
    movu r0, 5533
    .print r0
    st r0, 52[r4]

    movu r0, 63130
    .print r0
    st r0, 56[r4]
    movu r0, 8867
    .print r0
    st r0, 60[r4]

    movu r0, 09785
    .print r0
    st r0, 64[r4]
    movu r0, 3951
    .print r0
    st r0, 68[r4]

    .print r8

    @ Segundo número

    movu r0, 00014
    .print r0
    st r0, 72[r4]
    movu r0, 0929
    .print r0
    st r0, 76[r4]

    movu r0, 05687
    .print r0
    st r0, 80[r4]
    movu r0, 5212
    .print r0
    st r0, 84[r4]

    movu r0, 19007
    .print r0
    st r0, 88[r4]
    movu r0, 0682
    .print r0
    st r0, 92[r4]

    movu r0, 55056
    .print r0
    st r0, 96[r4]
    movu r0, 0009
    .print r0
    st r0, 100[r4]

    movu r0, 65535
    movu r0,27484
    .print r0
    st r0, 104[r4]
    movu r0, 8227
    .print r0
    st r0, 108[r4]

    
    movu r0, 65535
    movu r0,15322
    .print r0
    st r0, 112[r4]
    movu r0, 0709
    .print r0
    st r0, 116[r4]

    movu r0, 65535
    movu r0,13508
    .print r0
    st r0, 120[r4]
    movu r0, 0510
    .print r0
    st r0, 124[r4]

    movu r0, 65535
    movu r0,16448
    .print r0
    st r0, 128[r4]
    movu r0, 0666
    .print r0
    st r0, 132[r4]

    movu r0, 00771
    .print r0
    st r0, 136[r4]
    movu r0, 7983
    .print r0
    st r0, 140[r4]

    .print r8

    ld r12, 68[r4]
    ld r13, 140[r4]
    add r10, r12, r13
    sub r10, r10, 10000
    .print r10

    ld r12, 64[r4]
    ld r13, 136[r4]
    add r10, r12, r13
    addu r10, r10, 1

    ld r12, 60[r4]
    ld r13, 132[r4]
    add r10, r12, r13
    .print r10

    ld r12, 56[r4]
    ld r13, 128[r4]
    add r10, r12, r13
    .print r10

    ld r12, 52[r4]
    ld r13, 124[r4]
    add r10, r12, r13
    .print r10

    ld r12, 48[r4]
    ld r13, 120[r4]
    add r10, r12, r13
    .print r10

    ld r12, 44[r4]
    ld r13, 116[r4]
    add r10, r12, r13
    .print r10

    ld r12, 40[r4]
    ld r13, 112[r4]
    add r10, r12, r13
    .print r10

    ld r12, 36[r4]
    ld r13, 108[r4]
    add r10, r12, r13
    .print r10

    ld r12, 32[r4]
    ld r13, 104[r4]
    add r10, r12, r13
    .print r10

    ld r12, 28[r4]
    ld r13, 100[r4]
    add r10, r12, r13
    .print r10

    ld r12, 24[r4]
    ld r13, 96[r4]
    add r10, r12, r13
    .print r10

    ld r12, 20[r4]
    ld r13, 92[r4]
    add r10, r12, r13
    .print r10

    ld r12, 16[r4]
    ld r13, 88[r4]
    add r10, r12, r13
    .print r10

    ld r12, 12[r4]
    ld r13, 84[r4]
    add r10, r12, r13
    .print r10

    ld r12, 8[r4]
    ld r13, 80[r4]
    add r10, r12, r13
    .print r10

    ld r12, 4[r4]
    ld r13, 76[r4]
    add r10, r12, r13
    .print r10

    ld r12, [r4]
    ld r13, 72[r4]
    add r10, r12, r13
    .print r10

    nop