﻿#include "stdafx.h"
#pragma hdrstop

#include "xrHemisphere.h"

#define HEMI1_VERTS 26
#define HEMI1_FACES 40
#define HEMI2_VERTS 91
#define HEMI2_FACES 160
#define HEMI3_VERTS 196

#pragma warning (disable:4305)
const Fvector hemi_1[HEMI1_VERTS] =
{
    {0.525730, 0.850655, -0.000000},
    {0.162460, 0.850655, 0.500000},
    {0.000000, 1.000000, -0.000000},
    {-0.425324, 0.850655, 0.309015},
    {-0.425324, 0.850655, -0.309017},
    {0.162460, 0.850655, -0.500000},
    {0.688194, 0.525730, 0.500000},
    {-0.262865, 0.525730, 0.809013},
    {-0.850647, 0.525730, -0.000001},
    {-0.262865, 0.525730, -0.809021},
    {0.688194, 0.525730, -0.500000},
    {0.894424, 0.447212, -0.000000},
    {0.276394, 0.447212, 0.850647},
    {-0.723610, 0.447212, 0.525730},
    {-0.723610, 0.447212, -0.525734},
    {0.276394, 0.447212, -0.850655},
    {0.951057, 0.000000, 0.309017},
    {0.587788, 0.000000, 0.809013},
    {0.000000, 0.000000, 1.000000},
    {-0.587784, 0.000000, 0.809013},
    {-0.951057, 0.000000, 0.309015},
    {-0.951057, 0.000000, -0.309017},
    {-0.587784, 0.000000, -0.809021},
    {0.000000, 0.000000, -1.000000},
    {0.587788, 0.000000, -0.809013},
    {0.951057, 0.000000, -0.309017},
};
const u16 hemi_1v[HEMI1_FACES * 3] =
{
    0, 1, 2,
    1, 3, 2,
    3, 4, 2,
    4, 5, 2,
    5, 0, 2,
    1, 0, 6,
    3, 1, 7,
    4, 3, 8,
    5, 4, 9,
    0, 5, 10,
    10, 11, 0,
    11, 6, 0,
    6, 12, 1,
    12, 7, 1,
    7, 13, 3,
    13, 8, 3,
    8, 14, 4,
    14, 9, 4,
    9, 15, 5,
    15, 10, 5,
    6, 11, 16,
    12, 6, 17,
    7, 12, 18,
    13, 7, 19,
    8, 13, 20,
    14, 8, 21,
    9, 14, 22,
    15, 9, 23,
    10, 15, 24,
    11, 10, 25,
    25, 16, 11,
    16, 17, 6,
    17, 18, 12,
    18, 19, 7,
    19, 20, 13,
    20, 21, 8,
    21, 22, 14,
    22, 23, 9,
    23, 24, 15,
    24, 25, 10,
};

const Fvector hemi_2[HEMI2_VERTS] =
{
    {0.273268, 0.961937, -0.000000},
    {0.084444, 0.961937, 0.259892},
    {0.000000, 1.000000, -0.000000},
    {0.525730, 0.850655, -0.000000},
    {0.361805, 0.894424, 0.262865},
    {0.162460, 0.850655, 0.500000},
    {-0.221077, 0.961937, 0.160622},
    {-0.138196, 0.894424, 0.425324},
    {-0.425324, 0.850655, 0.309015},
    {-0.221077, 0.961937, -0.160623},
    {-0.447212, 0.894424, -0.000001},
    {-0.425324, 0.850655, -0.309017},
    {0.084445, 0.961937, -0.259892},
    {-0.138196, 0.894424, -0.425327},
    {0.162460, 0.850655, -0.500000},
    {0.361805, 0.894424, -0.262865},
    {0.447212, 0.723610, 0.525730},
    {0.638195, 0.723610, 0.262865},
    {0.688194, 0.525730, 0.500000},
    {-0.361801, 0.723610, 0.587784},
    {-0.052786, 0.723610, 0.688187},
    {-0.262865, 0.525730, 0.809013},
    {-0.670822, 0.723610, -0.162460},
    {-0.670822, 0.723610, 0.162458},
    {-0.850647, 0.525730, -0.000001},
    {-0.052786, 0.723610, -0.688194},
    {-0.361801, 0.723610, -0.587788},
    {-0.262865, 0.525730, -0.809021},
    {0.638195, 0.723610, -0.262865},
    {0.447212, 0.723610, -0.525734},
    {0.688194, 0.525730, -0.500000},
    {0.738174, 0.674606, -0.000000},
    {0.822617, 0.505722, -0.259892},
    {0.894424, 0.447212, -0.000000},
    {0.822617, 0.505722, 0.259892},
    {0.228109, 0.674606, 0.702049},
    {0.501377, 0.505722, 0.702049},
    {0.276394, 0.447212, 0.850647},
    {0.007032, 0.505722, 0.862671},
    {-0.597195, 0.674606, 0.433887},
    {-0.512752, 0.505722, 0.693779},
    {-0.723602, 0.447212, 0.525730},
    {-0.818275, 0.505722, 0.273266},
    {-0.597195, 0.674606, -0.433887},
    {-0.818275, 0.505722, -0.273268},
    {-0.723602, 0.447212, -0.525734},
    {-0.512753, 0.505722, -0.693779},
    {0.228109, 0.674606, -0.702049},
    {0.007032, 0.505722, -0.862671},
    {0.276394, 0.447212, -0.850655},
    {0.501377, 0.505722, -0.702049},
    {0.861801, 0.276394, 0.425323},
    {0.959251, 0.232454, 0.160622},
    {0.951057, 0.000000, 0.309017},
    {0.449184, 0.232454, 0.862671},
    {0.670822, 0.276394, 0.688187},
    {0.587788, 0.000000, 0.809013},
    {-0.138196, 0.276394, 0.951057},
    {0.143665, 0.232454, 0.961937},
    {0.000000, 0.000000, 1.000000},
    {-0.681641, 0.232454, 0.693779},
    {-0.447212, 0.276394, 0.850647},
    {-0.587784, 0.000000, 0.809013},
    {-0.947212, 0.276394, 0.162458},
    {-0.870460, 0.232454, 0.433887},
    {-0.951057, 0.000000, 0.309015},
    {-0.870460, 0.232454, -0.433887},
    {-0.947212, 0.276394, -0.162460},
    {-0.951057, 0.000000, -0.309017},
    {-0.447212, 0.276394, -0.850655},
    {-0.681641, 0.232454, -0.693779},
    {-0.587784, 0.000000, -0.809021},
    {0.143665, 0.232454, -0.961937},
    {-0.138196, 0.276394, -0.951057},
    {0.000000, 0.000000, -1.000000},
    {0.670822, 0.276394, -0.688194},
    {0.449188, 0.232454, -0.862671},
    {0.587788, 0.000000, -0.809013},
    {0.959251, 0.232454, -0.160623},
    {0.861801, 0.276394, -0.425327},
    {0.951057, 0.000000, -0.309017},
    {1.000000, 0.000000, -0.000000},
    {0.809021, 0.000000, 0.587784},
    {0.309017, 0.000000, 0.951057},
    {-0.309015, 0.000000, 0.951057},
    {-0.809013, 0.000000, 0.587784},
    {-1.000000, 0.000000, -0.000001},
    {-0.809013, 0.000000, -0.587788},
    {-0.309015, 0.000000, -0.951057},
    {0.309017, 0.000000, -0.951057},
    {0.809021, 0.000000, -0.587788},
};
const u16 hemi_2v[HEMI2_FACES * 3] =
{
    0, 1, 2,
    3, 4, 0,
    4, 1, 0,
    4, 5, 1,
    1, 6, 2,
    5, 7, 1,
    7, 6, 1,
    7, 8, 6,
    6, 9, 2,
    8, 10, 6,
    10, 9, 6,
    10, 11, 9,
    9, 12, 2,
    11, 13, 9,
    13, 12, 9,
    13, 14, 12,
    12, 0, 2,
    14, 15, 12,
    15, 0, 12,
    15, 3, 0,
    16, 17, 18,
    5, 4, 16,
    4, 17, 16,
    4, 3, 17,
    19, 20, 21,
    8, 7, 19,
    7, 20, 19,
    7, 5, 20,
    22, 23, 24,
    11, 10, 22,
    10, 23, 22,
    10, 8, 23,
    25, 26, 27,
    14, 13, 25,
    13, 26, 25,
    13, 11, 26,
    28, 29, 30,
    3, 15, 28,
    15, 29, 28,
    15, 14, 29,
    28, 31, 3,
    30, 32, 28,
    32, 31, 28,
    32, 33, 31,
    31, 17, 3,
    33, 34, 31,
    34, 17, 31,
    34, 18, 17,
    16, 35, 5,
    18, 36, 16,
    36, 35, 16,
    36, 37, 35,
    35, 20, 5,
    37, 38, 35,
    38, 20, 35,
    38, 21, 20,
    19, 39, 8,
    21, 40, 19,
    40, 39, 19,
    40, 41, 39,
    39, 23, 8,
    41, 42, 39,
    42, 23, 39,
    42, 24, 23,
    22, 43, 11,
    24, 44, 22,
    44, 43, 22,
    44, 45, 43,
    43, 26, 11,
    45, 46, 43,
    46, 26, 43,
    46, 27, 26,
    25, 47, 14,
    27, 48, 25,
    48, 47, 25,
    48, 49, 47,
    47, 29, 14,
    49, 50, 47,
    50, 29, 47,
    50, 30, 29,
    51, 52, 53,
    18, 34, 51,
    34, 52, 51,
    34, 33, 52,
    54, 55, 56,
    37, 36, 54,
    36, 55, 54,
    36, 18, 55,
    57, 58, 59,
    21, 38, 57,
    38, 58, 57,
    38, 37, 58,
    60, 61, 62,
    41, 40, 60,
    40, 61, 60,
    40, 21, 61,
    63, 64, 65,
    24, 42, 63,
    42, 64, 63,
    42, 41, 64,
    66, 67, 68,
    45, 44, 66,
    44, 67, 66,
    44, 24, 67,
    69, 70, 71,
    27, 46, 69,
    46, 70, 69,
    46, 45, 70,
    72, 73, 74,
    49, 48, 72,
    48, 73, 72,
    48, 27, 73,
    75, 76, 77,
    30, 50, 75,
    50, 76, 75,
    50, 49, 76,
    78, 79, 80,
    33, 32, 78,
    32, 79, 78,
    32, 30, 79,
    78, 52, 33,
    80, 81, 78,
    81, 52, 78,
    81, 53, 52,
    51, 55, 18,
    53, 82, 51,
    82, 55, 51,
    82, 56, 55,
    54, 58, 37,
    56, 83, 54,
    83, 58, 54,
    83, 59, 58,
    57, 61, 21,
    59, 84, 57,
    84, 61, 57,
    84, 62, 61,
    60, 64, 41,
    62, 85, 60,
    85, 64, 60,
    85, 65, 64,
    63, 67, 24,
    65, 86, 63,
    86, 67, 63,
    86, 68, 67,
    66, 70, 45,
    68, 87, 66,
    87, 70, 66,
    87, 71, 70,
    69, 73, 27,
    71, 88, 69,
    88, 73, 69,
    88, 74, 73,
    72, 76, 49,
    74, 89, 72,
    89, 76, 72,
    89, 77, 76,
    75, 79, 30,
    77, 90, 75,
    90, 79, 75,
    90, 80, 79,
};

const Fvector hemi_3[HEMI3_VERTS] =
{
    {+0.0000, +0.5000, +0.0000},
    {+0.2629, +0.4253, +0.0000},
    {+0.0812, +0.4253, +0.2500},
    {-0.2127, +0.4253, +0.1545},
    {-0.2127, +0.4253, -0.1545},
    {+0.0812, +0.4253, -0.2500},
    {+0.4472, +0.2236, +0.0000},
    {+0.1382, +0.2236, +0.4253},
    {-0.3618, +0.2236, +0.2629},
    {-0.3618, +0.2236, -0.2629},
    {+0.1382, +0.2236, -0.4253},
    {+0.3441, +0.2629, +0.2500},
    {-0.1314, +0.2629, +0.4045},
    {-0.4253, +0.2629, -0.0000},
    {-0.1314, +0.2629, -0.4045},
    {+0.3441, +0.2629, -0.2500},
    {+0.4755, +0.0000, +0.1545},
    {+0.2939, +0.0000, +0.4045},
    {-0.0000, +0.0000, +0.5000},
    {-0.2939, +0.0000, +0.4045},
    {-0.4755, +0.0000, +0.1545},
    {-0.4755, +0.0000, -0.1545},
    {-0.2939, +0.0000, -0.4045},
    {+0.0000, +0.0000, -0.5000},
    {+0.2939, +0.0000, -0.4045},
    {+0.4755, +0.0000, -0.1545},
    {+0.0917, +0.4915, +0.0000},
    {+0.1804, +0.4663, +0.0000},
    {+0.0283, +0.4915, +0.0872},
    {+0.0557, +0.4663, +0.1715},
    {-0.0742, +0.4915, +0.0539},
    {-0.1459, +0.4663, +0.1060},
    {-0.0742, +0.4915, -0.0539},
    {-0.1459, +0.4663, -0.1060},
    {+0.0283, +0.4915, -0.0872},
    {+0.0557, +0.4663, -0.1715},
    {+0.2106, +0.4448, +0.0884},
    {+0.1492, +0.4448, +0.1730},
    {-0.0190, +0.4448, +0.2276},
    {-0.1184, +0.4448, +0.1953},
    {-0.2224, +0.4448, +0.0523},
    {-0.2224, +0.4448, -0.0523},
    {-0.1184, +0.4448, -0.1953},
    {-0.0190, +0.4448, -0.2276},
    {+0.1492, +0.4448, -0.1730},
    {+0.2106, +0.4448, -0.0884},
    {+0.3364, +0.3699, +0.0000},
    {+0.3986, +0.3019, +0.0000},
    {+0.1040, +0.3699, +0.3200},
    {+0.1232, +0.3019, +0.3791},
    {-0.2722, +0.3699, +0.1978},
    {-0.3225, +0.3019, +0.2343},
    {-0.2722, +0.3699, -0.1978},
    {-0.3225, +0.3019, -0.2343},
    {+0.1040, +0.3699, -0.3200},
    {+0.1232, +0.3019, -0.3791},
    {+0.3036, +0.3873, +0.0884},
    {+0.3311, +0.3323, +0.1730},
    {+0.0097, +0.3873, +0.3161},
    {-0.0622, +0.3323, +0.3683},
    {-0.2976, +0.3873, +0.1069},
    {-0.3695, +0.3323, +0.0547},
    {-0.1936, +0.3873, -0.2500},
    {-0.1662, +0.3323, -0.3346},
    {+0.1779, +0.3873, -0.2614},
    {+0.2668, +0.3323, -0.2614},
    {+0.3036, +0.3873, -0.0884},
    {+0.3311, +0.3323, -0.1730},
    {+0.1779, +0.3873, +0.2614},
    {+0.2668, +0.3323, +0.2614},
    {-0.1936, +0.3873, +0.2500},
    {-0.1662, +0.3323, +0.3346},
    {-0.2976, +0.3873, -0.1069},
    {-0.3695, +0.3323, -0.0547},
    {+0.0097, +0.3873, -0.3161},
    {-0.0622, +0.3323, -0.3683},
    {+0.4269, +0.2452, +0.0872},
    {+0.3922, +0.2584, +0.1715},
    {+0.0490, +0.2452, +0.4330},
    {-0.0420, +0.2584, +0.4260},
    {-0.3967, +0.2452, +0.1804},
    {-0.4181, +0.2584, +0.0917},
    {-0.2941, +0.2452, -0.3215},
    {-0.2165, +0.2584, -0.3693},
    {+0.2149, +0.2452, -0.3791},
    {+0.2843, +0.2584, -0.3200},
    {+0.3922, +0.2584, -0.1715},
    {+0.4269, +0.2452, -0.0872},
    {+0.2843, +0.2584, +0.3200},
    {+0.2149, +0.2452, +0.3791},
    {-0.2165, +0.2584, +0.3693},
    {-0.2941, +0.2452, +0.3215},
    {-0.4181, +0.2584, -0.0917},
    {-0.3967, +0.2452, -0.1804},
    {-0.0420, +0.2584, -0.4260},
    {+0.0490, +0.2452, -0.4330},
    {+0.4728, +0.1534, +0.0539},
    {+0.4824, +0.0780, +0.1060},
    {+0.4063, +0.1819, +0.2276},
    {+0.4508, +0.0930, +0.1953},
    {+0.3421, +0.1819, +0.3161},
    {+0.3251, +0.0930, +0.3683},
    {+0.1974, +0.1534, +0.4330},
    {+0.2499, +0.0780, +0.4260},
    {+0.0948, +0.1534, +0.4663},
    {+0.0482, +0.0780, +0.4915},
    {-0.0909, +0.1819, +0.4568},
    {-0.0465, +0.0930, +0.4891},
    {-0.1949, +0.1819, +0.4230},
    {-0.2499, +0.0930, +0.4230},
    {-0.3508, +0.1534, +0.3215},
    {-0.3279, +0.0780, +0.3693},
    {-0.4142, +0.1534, +0.2343},
    {-0.4526, +0.0780, +0.1978},
    {-0.4625, +0.1819, +0.0547},
    {-0.4795, +0.0930, +0.1069},
    {-0.4625, +0.1819, -0.0547},
    {-0.4795, +0.0930, -0.1069},
    {-0.4142, +0.1534, -0.2343},
    {-0.4526, +0.0780, -0.1978},
    {-0.3508, +0.1534, -0.3215},
    {-0.3279, +0.0780, -0.3693},
    {-0.1949, +0.1819, -0.4230},
    {-0.2499, +0.0930, -0.4230},
    {-0.0909, +0.1819, -0.4568},
    {-0.0465, +0.0930, -0.4891},
    {+0.0948, +0.1534, -0.4663},
    {+0.0482, +0.0780, -0.4915},
    {+0.1974, +0.1534, -0.4330},
    {+0.2499, +0.0780, -0.4260},
    {+0.3421, +0.1819, -0.3161},
    {+0.3251, +0.0930, -0.3683},
    {+0.4063, +0.1819, -0.2276},
    {+0.4508, +0.0930, -0.1953},
    {+0.4728, +0.1534, -0.0539},
    {+0.4824, +0.0780, -0.1060},
    {+0.4330, +0.0000, +0.2500},
    {+0.3716, +0.0000, +0.3346},
    {+0.2034, +0.0000, +0.4568},
    {+0.1040, +0.0000, +0.4891},
    {-0.1040, +0.0000, +0.4891},
    {-0.2034, +0.0000, +0.4568},
    {-0.3716, +0.0000, +0.3346},
    {-0.4330, +0.0000, +0.2500},
    {-0.4973, +0.0000, +0.0523},
    {-0.4973, +0.0000, -0.0523},
    {-0.4330, +0.0000, -0.2500},
    {-0.3716, +0.0000, -0.3346},
    {-0.2034, +0.0000, -0.4568},
    {-0.1040, +0.0000, -0.4891},
    {+0.1040, +0.0000, -0.4891},
    {+0.2034, +0.0000, -0.4568},
    {+0.3716, +0.0000, -0.3346},
    {+0.4330, +0.0000, -0.2500},
    {+0.4973, +0.0000, -0.0523},
    {+0.4973, +0.0000, +0.0523},
    {+0.1208, +0.4772, +0.0878},
    {-0.0461, +0.4772, +0.1420},
    {-0.1493, +0.4772, -0.0000},
    {-0.0461, +0.4772, -0.1420},
    {+0.1208, +0.4772, -0.0878},
    {+0.2465, +0.3965, +0.1791},
    {-0.0941, +0.3965, +0.2897},
    {-0.3047, +0.3965, -0.0000},
    {-0.0941, +0.3965, -0.2897},
    {+0.2465, +0.3965, -0.1791},
    {+0.3715, +0.3229, -0.0881},
    {+0.3715, +0.3229, +0.0881},
    {+0.1986, +0.3229, +0.3261},
    {+0.0310, +0.3229, +0.3805},
    {-0.2488, +0.3229, +0.2896},
    {-0.3523, +0.3229, +0.1471},
    {-0.3523, +0.3229, -0.1471},
    {-0.2488, +0.3229, -0.2896},
    {+0.0310, +0.3229, -0.3805},
    {+0.1986, +0.3229, -0.3261},
    {+0.4476, +0.1707, +0.1433},
    {+0.2746, +0.1707, +0.3814},
    {+0.0020, +0.1707, +0.4700},
    {-0.2778, +0.1707, +0.3790},
    {-0.4463, +0.1707, +0.1471},
    {-0.4463, +0.1707, -0.1471},
    {-0.2778, +0.1707, -0.3790},
    {+0.0020, +0.1707, -0.4700},
    {+0.2746, +0.1707, -0.3814},
    {+0.4476, +0.1707, -0.1433},
    {+0.4936, +0.0799, +0.0000},
    {+0.3971, +0.0952, +0.2885},
    {+0.1525, +0.0799, +0.4694},
    {-0.1517, +0.0952, +0.4668},
    {-0.3993, +0.0799, +0.2901},
    {-0.4909, +0.0952, -0.0000},
    {-0.3993, +0.0799, -0.2901},
    {-0.1517, +0.0952, -0.4668},
    {+0.1525, +0.0799, -0.4694},
    {+0.3971, +0.0952, -0.2885},
};
#pragma warning(default:4305)

void ECORE_API xrHemisphereBuild(int quality, float energy, xrHemisphereIterator* iterator, LPVOID param)
{
    const Fvector* hemi = 0;
    int h_count = xrHemisphereVertices(quality, hemi);
    VERIFY(h_count > 0);
    // Calculate energy
    float total = (float)h_count;
    float E = 1.f / total;

    // Iterate
    for (int i = 0; i < h_count; i++)
    {
        float x = -float(hemi[i][0]);
        float y = -float(hemi[i][1]);
        float z = -float(hemi[i][2]);
        float mag = _sqrt(x*x + y*y + z*z);
        x /= mag;
        y /= mag;
        z /= mag;
        iterator(x, y, z, E*energy, param);
    }
}

int ECORE_API xrHemisphereVertices(int quality, const Fvector*& verts)
{
    // SELECT table
    int h_count = 0;
    switch (quality)
    {
    case 1: // LOW quality
        h_count = HEMI1_VERTS;
        verts = hemi_1;
        break;
    case 2: // HIGH quality
        h_count = HEMI2_VERTS;
        verts = hemi_2;
        break;
    case 3: // SUPER HIGH quality
        h_count = HEMI3_VERTS;
        verts = hemi_3;
        break;
    default:// NO
        NODEFAULT;
    }
    return h_count;
}

int ECORE_API xrHemisphereIndices(int quality, const u16*& indices)
{
    // SELECT table
    int h_count = 0;
    switch (quality)
    {
    case 1: // LOW quality
        h_count = HEMI1_FACES * 3;
        indices = hemi_1v;
        break;
    case 2: // HIGH quality
        h_count = HEMI2_FACES * 3;
        indices = hemi_2v;
        break;
    // case 3: // SUPER HIGH quality
    // h_count = HEMI3_FACES*3;
    // indices = hemi_3v;
    // break;
    default:// NO
        NODEFAULT;
    }
    return h_count;
}