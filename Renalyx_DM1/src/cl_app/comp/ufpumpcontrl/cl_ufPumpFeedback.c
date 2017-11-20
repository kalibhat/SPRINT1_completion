/*
 * cl_ufPumpFeedback.c
 *
 * Created: 11/6/2014 9:04:07 AM
 *  Author: user
 */ 

#include "cl_ufPumpFeedback_include.h"
#include "cl_ufPumpFeedback_proto.h"
#include "cl_types.h"

// extern Cl_ReturnCodeType Cl_SysStat_GetSensor_Status_Query(Cl_SensorDeviceIdType, uint16_t*);
// extern Cl_ReturnCodeType  Cl_SendDatatoconsole(Cl_ConsoleTxCommandtype , Cl_Uint8Type* ,Cl_Uint8Type );





static Cl_Uint16Type uf_expected_period = 0;
static cl_ufpump_states  cl_ufpump_state = CL_UFP_STATE_IDLE;
static Cl_Uint16Type uf_rotataion_marker = 1,prev_uf_rotataion_marker = 1;
static Cl_Uint16Type twentymscounter=0,uf_period = 0,uf_avg_period = 0, uf_freq_in_min = 0;
static Cl_Uint16Type uf_rotation_counter = 0,uf_selftest_rotation_counter = 0,temptwenty_counter = 0 ,newuf_period = 0;
Cl_Uint16Type extuf_period = 0;
static Cl_BoolType count_state = false;
Cl_Uint16Type ucont=0;
Cl_Uint16Type temp_array[35];
int uffb_alm_cnt = 0;
extern Cl_Uint32Type uf_fb_lower , uf_fb_upper;
int uffeedstart = 0;

Cl_ReturnCodeType cl_selftestFeedback_start(void)
{
	cl_ufpump_state = CL_UFP_SELFTEST_STARTED;
	uf_periodvalue = 0;
	return 0;
}

Cl_ReturnCodeType cl_selftestFeedback_stop(void)
{
	cl_ufpump_state = CL_UFP_STATE_IDLE;
	return 0;
}
Cl_ReturnCodeType cl_ufpumpFeedback_start(void) 
{
	cl_ufpump_state = CL_UFP_STATE_STARTED;
	uffeedstart = 1;
	return 0;
}
Cl_ReturnCodeType cl_ufpumpFeedback_stop(void)
{
	cl_ufpump_state = CL_UFP_STATE_IDLE;
	uffeedstart = 0;
	
	return 0;
}
Cl_ReturnCodeType cl_ufpumpFeedback_get_state(cl_ufpump_states* pstate)
{
	*pstate = cl_ufpump_state;
	return 0;
}
Cl_ReturnCodeType cl_ufpumpFeedback_get_delta(int16_t* pdelta)
{
	*pdelta = uf_period - uf_expected_period;
	return 0;
}
Cl_ReturnCodeType cl_ufpumpFeedback_set_expected_period(int16_t period)
{
	uf_expected_period = period;
	return 0;
}

Cl_ReturnCodeType cl_ufpumpFeedback_timer(void) // 20 ms clock
{
	if(cl_ufpump_state != CL_UFP_STATE_IDLE)
	{
	//cl_Datastreamtype cl_data;	
	//cl_testgetsensordata(UF_ROTATION_MARKER,&uf_rotataion_marker);
	Cl_SysStat_GetSensor_Status_Query(SENSOR_UFP_FB, &uf_rotataion_marker);

	twentymscounter++;
	temptwenty_counter++;
// 	if((cl_ufpump_state ==  CL_UFP_STATE_STARTED)) /*&& (uf_rotation_counter > ))*/
// 	{
// 		cl_ufpump_state = CL_UFP_STATE_RUNNING;
// 	}
	
	
	if(count_state == false)
	{
		if(uf_rotataion_marker == 0 )
		{
			if(prev_uf_rotataion_marker != uf_rotataion_marker)
			{
				count_state = true;
				//uf_rotation_counter++;
				twentymscounter = 0;
			}
		}
	}
	else
	{
		if(uf_rotataion_marker == 0 )
		{
			if(prev_uf_rotataion_marker != uf_rotataion_marker)
			{
				count_state = true;
				uf_rotation_counter++;
				uf_period = twentymscounter*50;
				uf_selftest_rotation_counter++;
				
				newuf_period = temptwenty_counter*50 ;
				extuf_period = temptwenty_counter*50 ;
				
					if((cl_ufpump_state == CL_UFP_STATE_STARTED))
					{
						
						if(newuf_period < 20){
							
							uffb_alm_cnt++;
							if(uffb_alm_cnt > 4){
								Cl_Alarm_TriggerAlarm(UFP_OVERRUN,1);
								uffb_alm_cnt = 0;
							}
							
						}
						else if((newuf_period > uf_fb_upper + 50))
						{
							
							uffb_alm_cnt++;
							if(uffb_alm_cnt > 8){
								Cl_Alarm_TriggerAlarm(UFP_OVERRUN,1);
								uffb_alm_cnt = 0;
							}
						}
						else if((newuf_period < uf_fb_lower- 50 ))
						{
							
							uffb_alm_cnt++;
							if(uffb_alm_cnt > 8){
								Cl_Alarm_TriggerAlarm(UFP_UNDERRUN,1);
								uffb_alm_cnt = 0;
							}
						}
						else
						{
							uffb_alm_cnt = 0;
							
						}
					}

// 				if (uf_selftest_rotation_counter >= 4)
// 				{
// 					
// 			      uf_periodvalue = uf_period;   //  uf_periodvalue = &uf_period;
// 			       uf_selftest_rotation_counter = 0;
// 				   uf_rotation_counter = 0;
// 				   twentymscounter = 0;
// 				}
				
// 								if(ucont < 30){
// 							temp_array[ucont] = temptwenty_counter*50 ;
// 						}
// 						if(ucont == 20){
// 						int16_t klm = 0;						
// 							for(int k =0 ; k < 30 ; k++){
// 								
// 								temp_array[k] = 0;
// 							}
// 							ucont = 0;
// 						}
// 						ucont++;
// 				
				
	
			
			
				
// 				if((cl_ufpump_state != CL_UFP_STATE_STARTED) && (cl_ufpump_state !=  CL_UFP_SELFTEST_STARTED))
// 				{
// 					if(uf_period > (1.01 *uf_expected_period))
// 					{
// 						cl_ufpump_state = CL_UFP_STATE_RUNNING_SLOW;
// 					}
// 					else if(uf_period < (0.99 *uf_expected_period))
// 					{
// 						cl_ufpump_state = CL_UFP_STATE_RUNNING_FAST;
// 					}
// 					else
// 					{
// 						cl_ufpump_state = CL_UFP_STATE_RUNNING_NORMAL;
// 					}
// 				}
// 
// 				
// 				uf_freq_in_min  = ( 60000) / uf_period;
				twentymscounter = 0;
				
				 temptwenty_counter = 0;
				 
				// newuf_period = 0;
			//	extuf_period = 0;
			//	 Cl_SendDatatoconsole(CON_TX_COMMAND_PRINTTEXT,"HP_PERIOD",9);
			//	 Cl_SendDatatoconsole(CON_TX_COMMAND_PRINTDATA,&uf_period,2);
			//	 Cl_SendDatatoconsole(CON_TX_COMMAND_PRINTDATA,&uf_expected_period,2);
				 
				
			//	Cl_SendDatatoconsole(CON_TX_COMMAND_PRINTTEXT,"UF_RPM",6);
			//	Cl_SendDatatoconsole(CON_TX_COMMAND_PRINTDATA,&uf_freq_in_min,2);
			//	Cl_SendDatatoconsole(CON_TX_COMMAND_PRINTDATA,&uf_rotation_counter,2);
				
				//	cl_data.Twobyte = uf_freq_in_min;
				//	dataarray[0] = CON_TX_PARAM_DATA_UF_RPM;
				//	dataarray[1] = cl_data.bytearray[0];
				//	dataarray[2] = cl_data.bytearray[1];
				//	Cl_SendDatatoconsole(CON_TX_COMMAND_SYSDATA,&dataarray,3);
				
			}
		}
		
	}
	prev_uf_rotataion_marker = uf_rotataion_marker;
	}
	return 0;
}
