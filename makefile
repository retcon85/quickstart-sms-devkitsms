# Forgive me for I know not what I do.
PROJECTNAME := $(notdir $(CURDIR))
TARGETDIR := ./build/
TARGETEXT := sms
SOURCEEXT := s
TARGET := $(TARGETDIR)$(PROJECTNAME).$(TARGETEXT)
ENTRYPOINT := main
SMSLIB_DIR := /usr/local/share/sdcc/lib/sms
SMSINC_DIR := /usr/local/share/sdcc/include/sms

SOURCES := $(wildcard src/*.c)
OBJECTS := $(patsubst src/%.c,$(TARGETDIR)%.rel,$(SOURCES))
MAINS := $(TARGETDIR)$(ENTRYPOINT).rel

build: $(TARGETDIR) $(TARGET)

$(TARGETDIR):
	mkdir -p $(TARGETDIR)

$(TARGETDIR)%.ihx: $(OBJECTS)
	sdcc -L$(SMSLIB_DIR) -o$@ -mz80 --no-std-crt0 --data-loc 0xC000 $(SMSLIB_DIR)/crt0_sms.rel $(MAINS) $(filter-out $(MAINS),$(OBJECTS)) SMSlib.lib $(SMSLIB_DIR)/PSGlib.rel

$(TARGETDIR)%.rel: src/%.c
	sdcc -I$(SMSINC_DIR) -c -mz80 -o$(TARGETDIR) --peep-file $(SMSLIB_DIR)/peep-rules.txt $<

$(TARGET): $(TARGETDIR)$(ENTRYPOINT).ihx
	makesms $< $(TARGET)

.PHONY: clean
clean:
	rm -rf $(TARGETDIR)
