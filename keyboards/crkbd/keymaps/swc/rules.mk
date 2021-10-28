MOUSEKEY_ENABLE     = no     # Mouse keysi
RGBLIGHT_ENABLE     = no    # Enable WS2812 RGB underlight.
VIA_ENABLE          = yes         # Enable VIA
OLED_ENABLE = yes
OLED_DRIVER = SSD1306
LTO_ENABLE = yes
BOOTMAGIC_ENABLE = yes

OCEAN_DREAM_ENABLE = no
LUNA_ENABLE = no # disabled so travis build succeeds

# if firmware size over limit, try this option
# CFLAGS += -flto