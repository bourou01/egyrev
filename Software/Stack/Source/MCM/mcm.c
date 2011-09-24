#include "global_types.h"
#include "icm_structs.h"
#include "icm_macros.h"
#include "db.h"
#include "wrapper.h"
#include "mcm.h"

MCM_DB g_MCM_DB;

/* ************************************************************************************************
 * Description:
 *
 * Arguments:
 * 		arg1_type	arg1_name:
 *
 * Return:
 * 		return_type:
 * ***********************************************************************************************/
void mcm_init()
{
    /*Initialize the component DB*/
    COMMON_MEMORY_SET(&g_MCM_DB, 0, sizeof(g_MCM_DB));
}

/* ************************************************************************************************
 * Description:
 *
 * Arguments:
 * 		arg1_type    arg1_name:
 *
 * Return:
 * 		void:
 * ***********************************************************************************************/
void MCM_ICM_REQ_Scan(ICM_Struct_REQ_MCM_Scan* a_ICM_Info_Ptr)
{
    UINT32                                loopIndex;
    /*Check the requested scan type*/
    switch(a_ICM_Info_Ptr->scanType)
    {
    case SCAN_TYPE_PASSIVE:

        /*Store current PAN_ID on which device is associated cause it'll be changed while scan*/
        g_MCM_DB.PAN_ID = DB_GET_PAN_ID();

        /*Set PAN_ID to (0xFFFF) to accept all beacons while scanning*/
        DB_SET_PAN_ID(ACCEPT_ALL_BEACONS_PAN_ID);

        /*Request from MDM to set filter to only beacons*/
        ICM_CMD_MDM_SET_FILTER_TYPE(FILTER_TYPE_BEACONS_ONLY);

        /*Request from PHY to set attributes (current page)*/
        ICM_REQ_PAL_SET(&a_ICM_Info_Ptr->channelPage, PHY_ATTRIBUTE_TYPE_CURRENT_PAGE);

        /*TODO:Set PHY attribute (TRX state) to RX*/

        for(loopIndex = 0; loopIndex < STD_SCAN_CHANNELS_BITMAP_SIZE; loopIndex++)
        {
            if(0 != (a_ICM_Info_Ptr->scanChannels & 1 << loopIndex))
            {
                /*This channel is requested to be scanned*/

                /*Set PHY attribute (phyChannel) to this channel*/
                ICM_REQ_PAL_SET(loopIndex, PHY_ATTRIBUTE_TYPE_CURRENT_CHANNEL);
            }
            else
            {
                /*This channel isn't requested to be scanned, do nothing*/
            }
        }

        /*Start timer with the scan duration value*/
        WRP_StartTimer(a_ICM_Info_Ptr->scanDuration, MCM_ScanTimerExpiryHandler);
        break;

    case SCAN_TYPE_ED:
        /*fall_through*/
    case SCAN_TYPE_ACTIVE:
        /*fall_through*/
    case SCAN_TYPE_ORPHAN:
        /*Do nothing - NEXT_RELEASE*/
        break;

    default:
        COMMON_ERROR("Invalid enum value");
        break;
    }
}

/* ************************************************************************************************
 * Description:
 *
 * Arguments:
 *      arg1_type    arg1_name:
 *
 * Return:
 *      void:
 * ***********************************************************************************************/
void MCM_ScanTimerExpiryHandler()
{
}
