ifndef THIS_MODULE_PATH
$(error Define THIS_MODULE_PATH before including this module)
endif

# ALL_SUBMODULES_INTERNAL:=$(sort $(dir $(wildcard $(THIS_MODULE_PATH)/*/)))
# ALL_SUBMODULES:=$(filter-out $(THIS_MODULE_PATH)/tests/,$(ALL_SUBMODULES_INTERNAL))
# ALL_SUBMODULES:=$(filter-out $(THIS_MODULE_PATH)/,$(ALL_SUBMODULES))
ALL_SUBMODULES:=$(patsubst %.c,%.o,$(wildcard $(THIS_MODULE_PATH)/*.c))
VPATH+=$(ALL_SUBMODULES)
THIS_MODULE_SOURCES:=$(foreach dir,$(ALL_SUBMODULES),$(wildcard $(dir)*.c))
THIS_MODULE_OBJECTS:=$(patsubst %.c,%.o,$(THIS_MODULE_SOURCES))