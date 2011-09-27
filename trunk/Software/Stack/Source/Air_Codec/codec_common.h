extern UINT8       g_fieldMaskArray[7];


/* ************************************************************************************************
 * Description:
 *
 * Arguments:
 * 		arg1_type	arg1_name:
 *
 * Return:
 * 		return_type:
 * ***********************************************************************************************/
#define CODEC_GET_FIELD(a_srcByte, a_fieldOffset, a_fieldSize, a_dstByte)                         \
{                                                                                                 \
    a_dstByte = ((a_srcByte >> a_fieldOffset) & g_fieldMaskArray[a_fieldSize]);                   \
}

/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef union CODEC_Address
{
    /**/
    UINT16                      shortAddress;
    /**/
    UINT64                      extendedAddress;
};


/* ************************************************************************************************
 * Description
 *
 * ***********************************************************************************************/
typedef enum CODEC_STATUS
{
    /**/
    CODEC_STATUS_SUCCESS,
    /**/
    CODEC_STATUS_FAILURE,
};
