#include "fscores.ih"

// double Fscores::s_weights[N_QUESTIONS][N_FACTORS] = 
// {
//    { 0.0046,  -0.0417,   0.0201,   0.0221,   0.0182,   0.0163},
//    {-0.0169,   0.0163,   0.0397,  -0.0727,   0.0373,   0.0256},
//    {-0.0265,   0.0024,  -0.0035,   0.0276,   0.0476,   0.0336},
//    {-0.0236,   0.0113,   0.0055,  -0.0911,   0.0195,  -0.0233},
//    {-0.0177,   0.0201,  -0.0439,   0.0592,  -0.0428,  -0.0241},
//    { 0.0247,  -0.0181,  -0.0185,   0.0093,  -0.0232,  -0.0445},
//    {-0.0012,   0.0267,  -0.0176,   0.0149,  -0.0492,  -0.0389},
//    {-0.0294,  -0.0222,   0.0410,   0.0125,  -0.0087,  -0.0282},
//    {-0.0120,   0.0244,  -0.0186,   0.0502,   0.0010,   0.0136},
//    { 0.0156,   0.0295,  -0.0013,  -0.0526,  -0.0250,  -0.0171},
//    {-0.0890,   0.0273,  -0.0271,  -0.0233,   0.0482,  -0.0045},
//    {-0.0016,  -0.0090,   0.0070,  -0.0563,   0.0095,  -0.0277},
//    {-0.0056,   0.0007,  -0.0112,  -0.0222,   0.0144,  -0.0113},
//    { 0.0273,   0.0505,  -0.0095,  -0.0317,   0.0098,   0.0383},
//    { 0.0368,   0.0005,   0.0194,  -0.0530,  -0.0106,   0.0182},
//    {-0.0095,  -0.0262,  -0.0117,   0.0386,  -0.0224,  -0.0359},
//    { 0.0705,  -0.0036,  -0.0022,   0.0021,  -0.0201,   0.0191},
//    {-0.0349,   0.0042,  -0.0252,  -0.0178,   0.0176,  -0.0175},
//    { 0.0271,  -0.0100,   0.0743,   0.0102,  -0.0369,   0.0160},
//    { 0.0248,  -0.0232,   0.0883,   0.0259,  -0.0522,   0.0074},
//    { 0.0480,   0.0332,  -0.0008,  -0.0282,  -0.0035,   0.0305},
//    { 0.0171,  -0.0211,   0.0549,  -0.0007,   0.0192,   0.0315},
//    {-0.0123,   0.0298,  -0.0244,  -0.0846,   0.0070,  -0.0330},
//    { 0.0319,   0.0117,  -0.0054,  -0.0112,   0.0275,   0.0250},
//    { 0.0130,  -0.0375,   0.0014,  -0.0137,   0.0121,  -0.0315},
//    {-0.0086,   0.0127,  -0.0556,  -0.0004,   0.0271,  -0.0034},
//    { 0.0471,  -0.0282,   0.0113,  -0.0099,  -0.0012,  -0.0001},
//    {-0.0009,   0.0472,  -0.0018,  -0.0004,  -0.0021,   0.0264},
//    {-0.0102,   0.0670,  -0.0414,  -0.0079,   0.0016,   0.0180},
//    { 0.0652,  -0.0351,   0.0268,  -0.0039,   0.0062,   0.0138},
//    { 0.0139,   0.0054,   0.0448,   0.0021,  -0.0480,  -0.0141},
//    { 0.0093,  -0.0095,   0.0266,   0.0109,  -0.0566,  -0.0308},
//    {-0.0064,  -0.0044,  -0.0289,  -0.0120,   0.0435,  -0.0035},
//    { 0.0257,  -0.0699,   0.0358,   0.0034,   0.0048,  -0.0250},
//    { 0.0225,   0.0116,  -0.0633,   0.0056,  -0.0213,  -0.0340},
//    { 0.0062,   0.0531,  -0.0342,  -0.0119,   0.0281,   0.0399},
//    {-0.0335,   0.0289,  -0.0219,   0.0093,  -0.0415,  -0.0318},
//    {-0.0276,   0.0181,   0.0110,  -0.0069,   0.0553,   0.0436},
//    {-0.0072,   0.0272,  -0.0010,  -0.0230,   0.0458,   0.0447},
//    { 0.0324,  -0.0333,   0.0034,  -0.0283,  -0.0089,  -0.0274},
//    {-0.0167,  -0.0246,   0.0033,   0.0241,   0.0079,  -0.0124},
//    {-0.0449,   0.0226,   0.0164,  -0.0081,   0.0167,   0.0184},
// };

double Fscores::s_weights[N_FACTORS][N_QUESTIONS] = 
{
    { 
        .0046, -.0169, -.0265, -.0236, -.0177,  .0247, -.0012, -.0294,
       -.0120,  .0156, -.0890, -.0016, -.0056,  .0273,  .0368, -.0095,
       -.0705, -.0349,  .0271,  .0248,  .0480,  .0171, -.0123,  .0319,
        .0130, -.0086,  .0471, -.0009, -.0102,  .0652,  .0139,  .0093,
       -.0064,  .0257,  .0225,  .0062, -.0335, -.0276, -.0072,  .0324,
       -.0167, -.0449, 
    },
    {
       -.0417,  .0163,  .0024,  .0113,  .0201, -.0181,  .0267, -.0222,  
        .0244,  .0295,  .0273, -.0090,  .0007,  .0505,  .0005, -.0262, 
       -.0036,  .0042, -.0100, -.0232,  .0332, -.0211,  .0298,  .0117, 
       -.0375,  .0127, -.0282,  .0472,  .0670, -.0351,  .0054, -.0095, 
       -.0044, -.0699,  .0116,  .0531,  .0289,  .0181,  .0272, -.0333, 
       -.0246,  .0226,
    },
    {
        .0201,  .0397, -.0035,  .0055, -.0439, -.0185, -.0176,  .0410,
       -.0186, -.0013, -.0271,  .0070, -.0112, -.0095,  .0194, -.0117,
       -.0022, -.0252,  .0743,  .0883, -.0008,  .0549, -.0244, -.0054,
        .0014, -.0556,  .0113, -.0018, -.0414,  .0268,  .0448,  .0266,
       -.0289,  .0358, -.0633, -.0342, -.0219,  .0110, -.0010,  .0034,
        .0033,  .0164,
    },
    {
        .0221, -.0727,  .0276, -.0911,  .0592,  .0093,  .0149,  .0125,
        .0502, -.0526, -.0233, -.0563, -.0222, -.0317, -.0530,  .0386,
        .0021, -.0178,  .0102,  .0259, -.0282, -.0007, -.0846, -.0112,
       -.0137, -.0004, -.0099, -.0004, -.0079, -.0039,  .0021,  .0109,
       -.0120,  .0034,  .0056, -.0119,  .0093, -.0069, -.0230, -.0283,
        .0241, -.0081,
    },
    {
        .0182,  .0373,  .0476,  .0195, -.0428, -.0232, -.0492, -.0087,
        .0010, -.0250,  .0482,  .0095,  .0144,  .0098, -.0106, -.0224,
       -.0201,  .0176, -.0369, -.0522, -.0035,  .0192,  .0070,  .0275,
        .0121,  .0271, -.0012, -.0021,  .0016,  .0062, -.0480, -.0566,
        .0435,  .0048, -.0213,  .0281, -.0415,  .0553,  .0458, -.0089,
        .0079,  .0167,
    },
    {
        .0163,  .0256,  .0336, -.0233, -.0241, -.0445, -.0389, -.0282,
        .0136, -.0171, -.0045, -.0277, -.0113,  .0383,  .0182, -.0359,
        .0191, -.0175,  .0160,  .0074,  .0305,  .0315, -.0330,  .0250,
       -.0315, -.0034, -.0001,  .0264,  .0180,  .0138, -.0141, -.0308,
       -.0035, -.0250, -.0340,  .0399, -.0318,  .0436,  .0447, -.0274,
       -.0124,  .0184,
    },
};
