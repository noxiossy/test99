﻿#ifndef DEDICATED_SERVER_ONLY_H_INCLUDED
#define DEDICATED_SERVER_ONLY_H_INCLUDED

//#define DEDICATED_SERVER_ONLY

#ifdef DEDICATED_SERVER_ONLY
# define PROTECT_API
#else// #ifdef DEDICATED_SERVER_ONLY
# define PROTECT_API __declspec(dllexport)
#endif // #ifdef DEDICATED_SERVER_ONLY

#ifdef BENCHMARK_BUILD
# undef PROTECT_API
# define PROTECT_API
#endif // #ifdef BENCHMARK_BUILD

#endif // #ifndef DEDICATED_SERVER_ONLY_H_INCLUDED
