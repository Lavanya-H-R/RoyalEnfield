
/*********************************************************************************
 *    FILENAME    : diag_adapt.h                                                 *          
 *    DESCRIPTION : Application adapter interface file for DIAG Stacks.          *
 *********************************************************************************
 * Revision history                                                              *               
 *                                                                               *
 * Ver Author       Date               Description                               *
 * 1   Sloki     1/10/2019		   Initial version                           *
 *********************************************************************************
*/  

#ifndef _DIAG_ADAPT_H_
#define _DIAG_ADAPT_H_

#include "diag_typedefs.h"

typedef	struct{				/* NVM operation result information 	*/
	U2	u2_data;		/* receiving data 			*/
	U1	u1_ret;			/* result information(normal or abnormal) */
}NVM_RET;

/*--------------------------------------------------------------------------*/
/*  macro definition                                                        */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/*  maximum number of NVM request                                           */
/*--------------------------------------------------------------------------*/
#define u1_MAX_NVMREQ       ((U1)22)
#define u1_MAX_NVMREQ_DTC   ((U1)11)


/*---------------------------------------------------------------------------*/
/*  NVM operation request                                                    */
/*                                                                           */
/*  order of priority   low  MSB    <- - - ->   LSB  high                    */
/*---------------------------------------------------------------------------*/
#define u2_REQ_NVMPLS	 			(BIT00)				/* pulse number request	 		*/
#define u2_REQ_NVMODO	 			(BIT01)				/* odo data request				*/
#define u2_REQ_NVMTRPA	 			(BIT02)				/* trip A request				*/
#define u2_REQ_NVMTRPB	 			(BIT03)				/* trip B request				*/
#define u2_REQ_NVMDSP	 			(BIT04)				/* display mode request			*/
#define u2_REQ_NVMRSTODO 			(BIT05)			    /* Mainodo reset sequence   	*/
#define u2_REQ_NVMODOWRT   			(BIT06)				/* ODO rewrite with ECU data   	*/
#define u2_REQ_NVMODOLRN   			(BIT07)				/* ODO rewrite prev lrn status 	*/
#define u2_REQ_NVM_DEFAULT			(BIT08)				/* Default Configuration write request 	*/
#define u2_REQ_DIAGCONFIG_PARAM		(BIT09)
#define u2_REQ_DTCCONFIG_PARAM		(BIT10)
#define u2_REQ_NVM_ILLU				(BIT11)				/* Illumination Level rewrite request 	*/
#define u2_REQ_NVM_GRT				(BIT12)				/* Global Real Time rewrite request 	*/
#define u2_REQ_NVMCONFIG_PARAM		(BIT13)				/* for read/write request 		*/
#define u2_REQ_NVM_AUTOCONFIG		(BIT14)				/* AutoConfig rewrite request 	*/
#define u2_REQ_3D_PARAM				(BIT15)				/* for read/write request 		*/
#define u2_REQ_NVM_DTCBITMASK		(BIT16)				/* DTC BitMask Rewrite request	*/
#define u2_REQ_NVM_OAT_COOL			(BIT17)					/* OAT Raw Sensor  Cool value  */
#define u2_REQ_NVM_OAT_HOT			(BIT18)					/* OAT Raw Sensor  Hot value  */
#define u2_REQ_NVM_FUEL_LOW			(BIT19)					/* FUEL LOW Calibration   */
#define u2_REQ_NVM_FUEL_FULL		(BIT20)					/* FUEL FULL Calibration   */
#define u2_REQ_NVM_CHECKSUM			(BIT21)					/* EOL CHECK SUM   */



/*--------------------------------------------------------------------------*/
/*  maximum NVM address                                                     */
/*--------------------------------------------------------------------------*/
#define u1_MAX_ADR		((U2)4096)  /* maximum word address			*/

/*---------------------------------------------------------------------------*/
/*  definition of NVM address                                                */
/*---------------------------------------------------------------------------*/
#define u1_ADR_MAIN				    ((U1)0)				/* main memory 												*/
#define u1_ADR_SUBA				    ((U1)4)				/* sub memory A 											*/
#define u1_ADR_SUBB				    ((U1)6)				/* sub memory B 											*/
#define u1_ADR_SUBC				    ((U1)8)				/* sub memory C 											*/
#define u1_ADR_FLAG				    ((U1)10)			/* main memory erase flag 									*/
#define u1_ADR_FLG_SA			    ((U1)11)			/* sub memory A writing flag 								*/
#define u1_ADR_FLG_SB			    ((U1)12)			/* sub memory B writing flag 								*/
#define u1_ADR_FLG_SC			    ((U1)13)			/* sub memory C writing flag 								*/
#define u1_ADR_ODOPLS			    ((U1)14)			/* odo fraction 											*/
#define u1_ADR_TRIPA			    ((U1)17)			/* trip A 													*/
#define u1_ADR_TRIPB			    ((U1)26)			/* trip B 													*/
#define u1_ADR_ODOPREVIP		    ((U1)85)			/* Check Purpose in Odometer								*/
#define u1_ADR_ODORST			    ((U1)86)			/* Odo reset flag 											*/
#define u1_ADR_ODORSTCNT		    ((U1)87)			/* Odometer Reset Count 									*/
/*#define u1_ADR_ODORSTDIST		    ((U1)88)*/			/* Odometer Cumulative Distance Count for odometer Reset 	*/
								    
#define u2_ADR_GRT   			    ((U2)512)			/* 8 Bytes of GRT, RTC sleep time and clock mode			*/
								    
#define u2_ADR_DIAG_PARA   		    ((U2)824)			/* Diagnostics Address 										*/
								    
#define u2_ADR_CONFIG_PARA   	    ((U2)1536)			/* Supplier Configuration 									*/
								    
#define u2_ADR_AUTOCONFIG		    ((U2)1605)			/* Autoconfig Data											*/
								    
#define u2_ADR_ODOLRNFLAG		    ((U2)1616)			/* Flag to notify sussess of previous odometer learning 	*/
#define u2_ADR_DSP				    ((U2)1617)			/* display mode 											*/
#define u2_ADR_ILLULEV	   		    ((U2)1618)			/* Previous Illumination Level								*/
								    
#define u2_ADR_DEF_CHK			    ((U2)2047)			/* Check if default is written at first BON					*/
								    
#define u2_ADR_DTCBITMASK		    ((U2)2048)			/* DTC BitMask Data			 								*/
#define u2_ADR_DTC_PARA   		    ((U2)2052)			/* DTC and Snapshot Address 								*/
								    
#define ADR_OAT_COOL                ((U2)1564)			/*OAT COOL Calibration */
#define ADR_OAT_HOT                 ((U2)1565)			/*OAT HOT Calibration*/
#define ADR_FUEL_CALIB_LOW          ((U2)1566)			/*FUEL LOW Calibration*/
#define ADR_FUEL_CALIB_FULL         ((U2)1567)			/*FUEL FULL Calibration*/
#define ADR_CHECK_SUM	            ((U2)1568)			/*CHECK SUM */


#endif

