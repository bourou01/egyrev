UINT8       g_fieldMaskArray[7];

/* ************************************************************************************************
 * Description:
 *
 * Arguments:
 * 		arg1_type	arg1_name:
 *
 * Return:
 * 		return_type:
 * ***********************************************************************************************/
void CODEC_Init()
{
    g_fieldMaskArray[0] = 0b00000000;
    g_fieldMaskArray[1] = 0b00000001;
    g_fieldMaskArray[2] = 0b00000011;
    g_fieldMaskArray[3] = 0b00000111;
    g_fieldMaskArray[4] = 0b00001111;
    g_fieldMaskArray[5] = 0b00011111;
    g_fieldMaskArray[6] = 0b00111111;
    g_fieldMaskArray[7] = 0b01111111;
}
