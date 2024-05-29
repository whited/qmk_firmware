MCU = RP2040
BOOTLOADER = rp2040

# LTO must be disabled for RP2040 builds
LTO_ENABLE = no

SERIAL_DRIVER = vendor
WS2812_DRIVER = vendor  # to allow PIO

# Audio driver does not work for rp2040
AUDIO_ENABLE = no

OLED_ENABLE = yes

ENCODER_ENABLE = yes       # Enables the use of one or more encoders
# ENCODER_MAP_ENABLE = yes
RGBLIGHT_ENABLE = yes      # Enable keyboard RGB underglow
MOUSEKEY_ENABLE = yes

CAPS_WORD_ENABLE = yes

# convert to kb2040 pinout
CONVERT_TO = kb2040

#VIA_ENABLE = yes
NKRO_ENABLE = yes

# Enable console for debug output
CONSOLE_ENABLE = no
