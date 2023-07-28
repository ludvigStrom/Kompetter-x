// usb_hid.c

#include "usbHidReport.h"

//debug
#include "ImprovedKeylayouts.h"

static KeyboardHID keyboardhid;
static uint8_t hid_report[NUM_KEYS];
static uint8_t hid_report_prev[NUM_KEYS];
static uint8_t hid_report_mod = 0; // Current modifier keys
static uint8_t hid_report_mod_prev = 0; // Previous modifier keys
static MouseHID mousehid;
static USBD_HandleTypeDef *usbDeviceHandle;

void usbHidInit(USBD_HandleTypeDef *handle) {
    usbDeviceHandle = handle;
    memset(hid_report, 0, NUM_KEYS);
    memset(hid_report_prev, 0, NUM_KEYS);

    memset(&keyboardhid, 0, sizeof(KeyboardHID));
    keyboardhid.REPORT_ID = 0x01;

    memset(&mousehid, 0, sizeof(MouseHID));
    mousehid.REPORT_ID = 0x02;
}

void usbHidAddKey(uint8_t keycode, uint8_t mod) {
    for (int i = 0; i < NUM_KEYS; i++) {
        if (hid_report[i] == 0) {
            hid_report[i] = keycode;
            hid_report_mod |= mod; // Add the modifier key to the HID report
            break;
        }
    }
}

void usbHidRemoveKey(uint8_t keycode, uint8_t mod) {
    for (int i = 0; i < NUM_KEYS; i++) {
        if (hid_report[i] == keycode) {
            hid_report[i] = 0;
            hid_report_mod &= ~mod; // Remove the modifier key from the HID report
            break;
        }
    }
}

void usbHidHandleMacro(uint8_t* macro, uint8_t macro_length) {
    // Only send key report, don't clear it
    for (int i = 0; i < macro_length; i++) {
        usbHidAddKey(macro[i], 0); // 0 default value for the modifier
    }

    // Send key report
    usbHidSendKeyboardReport();
}

void usbHidSendKeyboardReport() {
    // Copy keycodes from hid_report to keyboardhid
    keyboardhid.KEYCODE1 = hid_report[0];
    keyboardhid.KEYCODE2 = hid_report[1];
    keyboardhid.KEYCODE3 = hid_report[2];
    keyboardhid.KEYCODE4 = hid_report[3];
    keyboardhid.KEYCODE5 = hid_report[4];
    keyboardhid.KEYCODE6 = hid_report[5];

    // Copy the modifier keys from hid_report_mod to keyboardhid
    keyboardhid.MODIFIER = hid_report_mod;

    //send current key report
    USBD_HID_SendReport(usbDeviceHandle, (uint8_t*)&keyboardhid, sizeof(keyboardhid));
    //save it to previous report
    memcpy(hid_report_prev, hid_report, NUM_KEYS);
    hid_report_mod_prev = hid_report_mod;
}

uint8_t usbHidkeyReportChanged(){
	uint8_t report_changed = 0;

	for (int i = 0; i < NUM_KEYS; i++) {
		if (hid_report[i] != hid_report_prev[i]) {
			report_changed = 1;
			break;
		}
	}
	return report_changed;
}

void usbHidUpdateMouseReport(int8_t x, int8_t y, int8_t wheel, uint8_t buttons) {
    mousehid.X = x;
    mousehid.Y = y;
    mousehid.WHEEL = wheel;
    mousehid.BUTTONS = buttons;
}

void usbHidSendMouseReport(void) {
    USBD_HID_SendReport(usbDeviceHandle, (uint8_t*)&mousehid, sizeof(mousehid));
}
