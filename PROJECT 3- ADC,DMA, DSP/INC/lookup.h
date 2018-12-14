/*
 * lookup.h
 *
 *  Created on: Dec 14, 2018
 *      Author: 17202
 */

#ifndef INC_LOOKUP_H_
#define INC_LOOKUP_H_

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 void map_raw_signal_values(void);
 int signal_level_from_adc(int peak_value);
 void dump_adc_map(void);

struct raw_signal
{
    int signal_level;
    double peak_low;
    double peak_mid;
    double peak_high;
};

//Lookup table

/* Logarthmic formula used to calculate values for lookup table is:
 *{ 20log10 * (2^n(sqrt(3/2)) }
 *This reports the values in dbfs
 *
 */

static struct raw_signal raw_signal_data[] =
{
	{ 3.3, 10500, 11000, 37000},
    { 2.8875, 9000, 9500, 10000 },
    { 2.475, 7500, 8000, 8500 },
    { 2.0625, 6000, 6500, 7000 },
    { 1.65, 4500, 5000, 5500 },
    { 1.2375, 3000, 3500, 4000 },
    { 0.825, 1500, 2000, 2500 },
    { 0.4125, 0, 500, 1000 },
};
enum { NUM_raw_signal = sizeof(raw_signal_data) / sizeof(raw_signal_data[0]) };

struct map_adc
{
    int signal_level;
    int peak_value;
};




#endif /* INC_LOOKUP_H_ */
