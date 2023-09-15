SRC += features/achordion.c

PICO_INTRINSICS_ENABLED = no

# Build options
SLEEP_LED_ENABLE = no
OLED_ENABLE = yes
OLED_DRIVER = ssd1306
WS2812_DRIVER = vendor
SPLIT_KEYBOARD = yes
SERIAL_DRIVER = vendor