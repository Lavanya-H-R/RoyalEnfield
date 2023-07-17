/*
 ****************************************************************************************
 *    FILENAME    : uds_serv11.h
 *
 *    DESCRIPTION : File contains uds_serv11.c related definitions and declarations.
 *
 *    $Id         : $
 *
 ****************************************************************************************
 * Revision history
 *
 * Ver  Author              Date              Description
 * 1    Sloki             16/1/2019         Initial version
 ****************************************************************************************/

#ifndef UDS_SERV11_H_    /* Guard against multiple inclusion */
#define UDS_SERV11_H_

/*
 ****************************************************************************************
 *    Includes
 ****************************************************************************************
*/

#include "uds_conf.h"
#include "diag_typedefs.h"
#include "diag_adapt.h"


/*
 ****************************************************************************************
 *    Defines
 ****************************************************************************************
*/
#define SERV_11_MAX_LEN                     2
#define SID_ECURESET                        0x11
#define SUB_ID_HARDRESET                    0x01
#define SUB_ID_KEYOFFONRESET                0x02
#define SUB_ID_SOFTRESET                    0x03
#define SUB_ID_EN_RAPID_SHUTDOWN            0x04
#define SUB_ID_DIS_RAPID_SHUTDOWN           0x05
#define EXAMPLE_CONSTANT                     0
#define SOFT_RESET_ADDRESS                  0x3FFFC0
/*
 ****************************************************************************************
 *    ENUM Definition
 ****************************************************************************************
*/

/*
 ****************************************************************************************
 *    Structure Definition
 ****************************************************************************************
*/

/*
 ****************************************************************************************
 *    al Variables
 ****************************************************************************************
*/
extern bool reset_b;
/*
 ****************************************************************************************
 *    Function Prototypes
 ****************************************************************************************
*/
//extern bool SoftReset_b;
extern UDS_Serv_resptype_En_t iso14229_serv11 (UDS_Serv_St_t* );
extern void softreset(void);
extern void hardreset(void);
#endif /* _EXAMPLE_FILE_NAME_H */

