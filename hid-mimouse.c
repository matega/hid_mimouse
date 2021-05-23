// SPDX-License-Identifier: GPL-3.0-or-later
/*
 *  HID driver for Xiaomi Silent Mouse
 *
 *  Copyright (c) 2021 Dr. Galambos Máté
 */

/*
 */

#include <linux/device.h>
#include <linux/hid.h>
#include <linux/module.h>

#define XIAOMI_FAULT_OFFSET	17

static const __u8 xiaomi_faulty_rdesc[] = {
0x05, 0x01,                    // Usage Page (Generic Desktop)        0
0x09, 0x02,                    // Usage (Mouse)                       2
0xa1, 0x01,                    // Collection (Application)            4
0x85, 0x03,                    //  Report ID (3)                      6
0x09, 0x01,                    //  Usage (Pointer)                    8
0xa1, 0x00,                    //  Collection (Physical)              10
0x05, 0x09,                    //   Usage Page (Button)               12
0x19, 0x01,                    //   Usage Minimum (1)                 14
0x29, 0x03,                    //   Usage Maximum (3) FAULTY          16
0x15, 0x00,                    //   Logical Minimum (0)               18
0x25, 0x01,                    //   Logical Maximum (1)               20
0x75, 0x01,                    //   Report Size (1)                   22
0x95, 0x05,                    //   Report Count (5)                  24
0x81, 0x02,                    //   Input (Data,Var,Abs)              26
0x75, 0x03,                    //   Report Size (3)                   28
0x95, 0x01,                    //   Report Count (1)                  30
0x81, 0x01,                    //   Input (Cnst,Arr,Abs)              32
0x05, 0x01,                    //   Usage Page (Generic Desktop)      34
0x09, 0x30,                    //   Usage (X)                         36
0x09, 0x31,                    //   Usage (Y)                         38
0x15, 0x81,                    //   Logical Minimum (-127)            40
0x25, 0x7f,                    //   Logical Maximum (127)             42
0x75, 0x08,                    //   Report Size (8)                   44
0x95, 0x02,                    //   Report Count (2)                  46
0x81, 0x06,                    //   Input (Data,Var,Rel)              48
0x09, 0x38,                    //   Usage (Wheel)                     50
0x15, 0x81,                    //   Logical Minimum (-127)            52
0x25, 0x7f,                    //   Logical Maximum (127)             54
0x75, 0x08,                    //   Report Size (8)                   56
0x95, 0x01,                    //   Report Count (1)                  58
0x81, 0x06,                    //   Input (Data,Var,Rel)              60
0xc0,                          //  End Collection                     62
0xc0,                          // End Collection                      63
0x06, 0x01, 0xff,              // Usage Page (Vendor Usage Page 0xff01) 64
0x09, 0x01,                    // Usage (Vendor Usage 0x01)           67
0xa1, 0x01,                    // Collection (Application)            69
0x85, 0x05,                    //  Report ID (5)                      71
0x09, 0x05,                    //  Usage (Vendor Usage 0x05)          73
0x15, 0x00,                    //  Logical Minimum (0)                75
0x26, 0xff, 0x00,              //  Logical Maximum (255)              77
0x75, 0x08,                    //  Report Size (8)                    80
0x95, 0x04,                    //  Report Count (4)                   82
0xb1, 0x02,                    //  Feature (Data,Var,Abs)             84
0xc0,                          // End Collection                      86
};

/*
 * we fix the report descriptor by setting byte 17 to 5
 */

static __u8 *mimouse_report_fixup(struct hid_device *hdev, __u8 *rdesc,
		unsigned int *rsize)
{
//  Check if the start of the report maches our expectations
    if(memcmp(rdesc, xiaomi_faulty_rdesc, XIAOMI_FAULT_OFFSET) != 0) return rdesc;
    rdesc[XIAOMI_FAULT_OFFSET] = 0x05;
	return rdesc;
}

static const struct hid_device_id xiaomi_silent_mouse_devices[] = {
	{ HID_BLUETOOTH_DEVICE(0x2717,
			 0x5014) },
	{ }
};
MODULE_DEVICE_TABLE(hid, xiaomi_silent_mouse_devices);

static struct hid_driver mimouse_driver = {
	.name = "mi-silent-mouse",
	.id_table = xiaomi_silent_mouse_devices,
	.report_fixup = mimouse_report_fixup,
};
module_hid_driver(mimouse_driver);

MODULE_AUTHOR("Dr. Galambos Máté <thermate18@gmail.com>");
MODULE_DESCRIPTION("HID Xiaomi Silent Mouse driver");
MODULE_LICENSE("GPL");
