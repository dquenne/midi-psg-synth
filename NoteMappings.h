#ifndef NoteMappings_h
#define NoteMappings_h

// notes used for SN76489 clocked at 4MHz, i.e.
// F = 4,000,000 / (32 * N)
//   =  125,000  /    N
// note: N is a 10-bit integer for SN76489, so max allowed value is 1023
const static unsigned NOTES_125KHZ[] = {
    15281, 14434, 13617, 12860, 12136, 11457, 10813, 10204, 9630, 9091, 8579,
    8101,  7645,  7217,  6812,  6427,  6068,  5726,  5407,  5102, 4815, 4545,
    4290,  4049,  3823,  3608,  3405,  3214,  3034,  2864,  2703, 2551, 2408,
    2273,  2145,  2025,  1911,  1804,  1703,  1607,  1517,  1432, 1351, 1276,
    1204,  1136,  1073,  1012,  956,   902,   851,   804,   758,  716,  676,
    638,   602,   568,   536,   506,   478,   451,   426,   402,  379,  358,
    338,   319,   301,   284,   268,   253,   239,   225,   213,  201,  190,
    179,   169,   159,   150,   142,   134,   127,   119,   113,  106,  100,
    95,    89,    84,    80,    75,    71,    67,    63,    60,   56,   53,
    50,    47,    45,    42,    40,    38,    36,    34,    32,   30,   28,
    27,    25,    24,    22,    21,    20,    19,    18,    17,   16,   15,
    14,    13,    13,    12,    11,    11,    10,
};

// notes used for YM2203 clocked at 4MHz, i.e.
// F = 4,000,000 / (16 * N)
//   =  250,000  /    N
// note: N is a 12-bit integer for YM2203, so max allowed value is 4095
const static unsigned NOTES_250KHZ[] = {
    30562, 28868, 27233, 25720, 24272, 22915, 21626, 20408, 19260, 18182, 17159,
    16202, 15291, 14434, 13624, 12853, 12136, 11452, 10813, 10204, 9630,  9091,
    8579,  8098,  7645,  7215,  6810,  6428,  6068,  5727,  5405,  5102,  4816,
    4545,  4290,  4049,  3822,  3608,  3405,  3214,  3034,  2863,  2703,  2551,
    2408,  2273,  2145,  2025,  1911,  1804,  1703,  1607,  1517,  1432,  1351,
    1276,  1204,  1136,  1073,  1012,  956,   902,   851,   804,   758,   716,
    676,   638,   602,   568,   536,   506,   478,   451,   426,   402,   379,
    358,   338,   319,   301,   284,   268,   253,   239,   225,   213,   201,
    190,   179,   169,   159,   150,   142,   134,   127,   119,   113,   106,
    100,   95,    89,    84,    80,    75,    71,    67,    63,    60,    56,
    53,    50,    47,    45,    42,    40,    38,    36,    34,    32,    30,
    28,    27,    25,    24,    22,    21,    20,
};

// TODO: unsure if it makes sense that there are sublte variatoins across
// octaves. Might be able to collapse this to a 12-item array.
const static unsigned F_NUMBERS_4MHZ[] = {
    618,  654,  693,  734,  778,  824,  873,  925,  980,  1038, 1100, 1165, 617,
    654,  693,  734,  778,  824,  873,  925,  980,  1038, 1100, 1165, 617,  654,
    693,  734,  778,  824,  873,  925,  980,  1038, 1100, 1165, 617,  654,  693,
    734,  778,  824,  873,  925,  980,  1038, 1100, 1165, 617,  654,  693,  734,
    778,  824,  873,  925,  980,  1038, 1100, 1165, 617,  654,  693,  734,  778,
    824,  873,  925,  980,  1038, 1100, 1165, 617,  654,  693,  734,  778,  824,
    873,  925,  980,  1038, 1100, 1165, 617,  654,  693,  734,  778,  824,  873,
    925,  980,  1038, 1100, 1165, 617,  654,  693,  734,  778,  824,  873,  925,
    980,  1038, 1100, 1165, 617,  654,  693,  734,  778,  824,  873,  925,  980,
    1038, 1100, 1165, 617,  654,  693,  734,  778,  824,  873,  925,
};

// PSG frequency utils

/** @returns The number to subtract from the note's N to get note + cents */
unsigned getFrequencyNForCents(unsigned note, unsigned cents,
                               const unsigned note_mappings[128]);

unsigned getFrequencyN(unsigned frequency_cents,
                       const unsigned note_mappings[128]);

// FM frequency utils

unsigned getBlock(unsigned frequency_cents);

/** @returns The number to add to the note's F-Number to get note + cents */
unsigned getFNumberForCents(unsigned note, unsigned cents,
                            const unsigned note_mappings[128]);

unsigned getFNumber(unsigned frequency_cents,
                    const unsigned note_mappings[128]);

#endif
