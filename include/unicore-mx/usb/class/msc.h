/** @defgroup usb_msc_defines USB MSC Type Definitions

@brief <b>Defined Constants and Types for the USB MSC Type Definitions</b>

@ingroup USB_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2013
Weston Schmidt <weston_schmidt@alumni.purdue.edu>
Pavol Rusnak <stick@gk2.sk>

@date 27 June 2013

LGPL License Terms @ref lgpl_license
*/

/*
 * Copyright (C) 2013 Weston Schmidt <weston_schmidt@alumni.purdue.edu>
 * Copyright (C) 2013 Pavol Rusnak <stick@gk2.sk>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

/**@{*/

#ifndef UNICORE_USB_CLASS_MSC_H
#define UNICORE_USB_CLASS_MSC_H

/* Definitions of Mass Storage Class from:
 *
 * (A) "Universal Serial Bus Mass Storage Class Bulk-Only Transport
 *      Revision 1.0"
 *
 * (B) "Universal Serial Bus Mass Storage Class Specification Overview
 *      Revision 1.0"
 */

/* (A) Table 4.5: Mass Storage Device Class Code */
#define USB_CLASS_MSC			0x08

/* (B) Table 2.1: Class Subclass Code */
#define USB_MSC_SUBCLASS_RBC		0x01
#define USB_MSC_SUBCLASS_ATAPI		0x02
#define USB_MSC_SUBCLASS_UFI		0x04
#define USB_MSC_SUBCLASS_SCSI		0x06
#define USB_MSC_SUBCLASS_LOCKABLE	0x07
#define USB_MSC_SUBCLASS_IEEE1667	0x08

/* (B) Table 3.1 Mass Storage Interface Class Control Protocol Codes */
#define USB_MSC_PROTOCOL_CBI		0x00
#define USB_MSC_PROTOCOL_CBI_ALT	0x01
#define USB_MSC_PROTOCOL_BBB		0x50

/* (B) Table 4.1 Mass Storage Request Codes */
#define USB_MSC_REQ_CODES_ADSC		0x00
#define USB_MSC_REQ_CODES_GET		0xFC
#define USB_MSC_REQ_CODES_PUT		0xFD
#define USB_MSC_REQ_CODES_GML		0xFE
#define USB_MSC_REQ_CODES_BOMSR		0xFF

/* (A) Table 3.1/3.2 Class-Specific Request Codes */
#define USB_MSC_REQ_BULK_ONLY_RESET	0xFF
#define USB_MSC_REQ_GET_MAX_LUN		0xFE

/* Command Block Wrapper */
#define USB_MSC_CBW_SIGNATURE				0x43425355
#define USB_MSC_CBW_STATUS_SUCCESS			0
#define USB_MSC_CBW_STATUS_FAILED			1
#define USB_MSC_CBW_STATUS_PHASE_ERROR		2

/* Command Status Wrapper */
#define USB_MSC_CSW_SIGNATURE				0x53425355
#define USB_MSC_CSW_STATUS_SUCCESS			0
#define USB_MSC_CSW_STATUS_FAILED			1
#define USB_MSC_CSW_STATUS_PHASE_ERROR		2

/* Implemented SCSI Commands */
#define USB_MSC_SCSI_TEST_UNIT_READY		0x00
#define USB_MSC_SCSI_REQUEST_SENSE			0x03
#define USB_MSC_SCSI_FORMAT_UNIT			0x04
#define USB_MSC_SCSI_READ_6					0x08
#define USB_MSC_SCSI_WRITE_6				0x0A
#define USB_MSC_SCSI_INQUIRY				0x12
#define USB_MSC_SCSI_MODE_SENSE_6			0x1A
#define USB_MSC_SCSI_SEND_DIAGNOSTIC		0x1D
#define USB_MSC_SCSI_READ_CAPACITY			0x25
#define USB_MSC_SCSI_READ_10				0x28


/* Required SCSI Commands */

/* Optional SCSI Commands */
#define USB_MSC_SCSI_REPORT_LUNS					0xA0
#define USB_MSC_SCSI_PREVENT_ALLOW_MEDIUM_REMOVAL	0x1E
#define USB_MSC_SCSI_MODE_SELECT_6					0x15
#define USB_MSC_SCSI_MODE_SELECT_10					0x55
#define USB_MSC_SCSI_MODE_SENSE_10					0x5A
#define USB_MSC_SCSI_READ_12						0xA8
#define USB_MSC_SCSI_READ_FORMAT_CAPACITIES		0x23
#define USB_MSC_SCSI_READ_TOC_PMA_ATIP				0x43
#define USB_MSC_SCSI_START_STOP_UNIT				0x1B
#define USB_MSC_SCSI_SYNCHRONIZE_CACHE				0x35
#define USB_MSC_SCSI_VERIFY							0x2F
#define USB_MSC_SCSI_WRITE_10						0x2A
#define USB_MSC_SCSI_WRITE_12						0xAA

struct usb_msc_cbw {
	uint32_t dCBWSignature;
	uint32_t dCBWTag;
	uint32_t dCBWDataTransferLength;
	uint8_t  bmCBWFlags;
	uint8_t  bCBWLUN;
	uint8_t  bCBWCBLength;
	uint8_t  CBWCB[16];
} __attribute__((packed));

struct usb_msc_csw {
	uint32_t dCSWSignature;
	uint32_t dCSWTag;
	uint32_t dCSWDataResidue;
	uint8_t  bCSWStatus;
} __attribute__((packed));

#endif

/**@}*/
