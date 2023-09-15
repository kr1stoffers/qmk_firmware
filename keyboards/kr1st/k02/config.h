#define QUICK_TAP_TERM 0

#define BOOTMAGIC_LITE_ROW          0
#define BOOTMAGIC_LITE_COLUMN       0
#define BOOTMAGIC_LITE_ROW_RIGHT    5
#define BOOTMAGIC_LITE_COLUMN_RIGHT 5

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U // Timeout window in ms in which the double tap can occur.
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED_MASK 0U // Specify a optional status led which blinks when entering the bootloader

/* Serial settings */
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1
#define USB_VBUS_PIN        GP28
#define SPLIT_HAND_PIN      GP24

#ifdef OLED_ENABLE
#define OLED_DISPLAY_128X32
#define I2C1_SCL_PIN        GP3
#define I2C1_SDA_PIN        GP2
#define OLED_BRIGHTNESS 128
#define I2C_DRIVER I2CD1
#define SPLIT_OLED_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_WPM_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_LED_STATE_ENABLE
#endif

#define USB_SUSPEND_WAKEUP_DELAY 200
