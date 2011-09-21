#include "global_types.h"
#include "icm_structs.h"
#include "icm_macros.h"

MCM_DB g_MCM_DB;

/* ****************************************************************************************************************************************
 * Description:
 *
 * Arguments:
 * 		arg1_type	arg1_name:
 *
 * Return:
 * 		return_type:
 * ***************************************************************************************************************************************/
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

    /*Check the requested scan type*/
    switch(a_ICM_Info_Ptr->scanType)
    {
    case SCAN_TYPE_PASSIVE:
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

    a_ICM_Info_Ptr->channelPage;
    a_ICM_Info_Ptr->scanChannels;
    a_ICM_Info_Ptr->scanDuration;

    a_ICM_Info_Ptr->securityContext;
}
