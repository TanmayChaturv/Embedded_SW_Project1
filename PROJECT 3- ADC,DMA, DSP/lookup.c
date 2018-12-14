/*

 * lookup.c
 *
 *  Created on: Dec 14, 2018
 *      Author: Smitha Bhaskar
 */


#include<../INC/lookup.h>



 struct map_adc adc_map[NUM_raw_signal];

 void map_raw_signal_values(void)
{
    int i;
    for (i = 0; i < NUM_raw_signal - 1; i++)
    {
        adc_map[i].signal_level = raw_signal_data[i].signal_level;

        adc_map[i].peak_value = (raw_signal_data[i].peak_mid + raw_signal_data[i+1].peak_mid) / 2;
    }

    adc_map[i].signal_level = adc_map[i-1].signal_level + 1;
    adc_map[i].peak_value = 0;
}

 int signal_level_from_adc(int peak_value)
{
    int i;
    for (i = 0; i < NUM_raw_signal; i++)
    {
        /* Use of > determined by inspection of data - colder signal_levels have higher ADC value */
        if (peak_value > adc_map[i].peak_value)
            return adc_map[i].signal_level;
    }
    assert(0);
    return 300;
}

 void dump_adc_map(void)
{
    for (int i = 0; i < NUM_raw_signal; i++)
    {
        assert(raw_signal_data[i].signal_level == adc_map[i].signal_level);
        printf("Signal value in dbfs = %.3d  = (%6.2f:%6.2f:%6.2f) Limit = %d\n",
                raw_signal_data[i].signal_level, raw_signal_data[i].peak_low,
                raw_signal_data[i].peak_mid, raw_signal_data[i].peak_high,
                adc_map[i].peak_value);
    }
}





