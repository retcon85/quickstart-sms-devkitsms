# Friends don't let friends fool around with Makefiles :)

TARGETDIR ?= ../build/
PROJECTNAME ?= $(notdir $(CURDIR))
TARGET_EXTENSION ?= sms
SMSLIB_DIR ?= /opt/devkitsms/lib
SMSINC_DIR ?= /opt/devkitsms/include
ENTRYPOINT ?= main
SOURCE_DIRS ?= ../assets/build/

all_source_dirs := ./ $(wildcard ./**/) $(SOURCE_DIRS)
include_options := $(patsubst %,-I %,$(SMSINC_DIR) $(all_source_dirs))

target := $(TARGETDIR)$(PROJECTNAME).$(TARGET_EXTENSION)
sources := $(foreach dir,$(all_source_dirs),$(wildcard $(dir)*.c))
headers := $(foreach dir,$(all_source_dirs),$(wildcard $(dir)*.h))

objects := $(patsubst %.c,$(TARGETDIR)%.rel,$(sources))

# customize this list to explicitly specify the order of linking
mains := $(TARGETDIR)./$(ENTRYPOINT).rel

# main build target
build: $(target)

# create the build folder if it doesn't exist
$(TARGETDIR):
	$(MKDIR) $(TARGETDIR)

# packing stage - generally runs once to create a single output
# pads to minimum 64kb with -pm to ensure SRAM is used
$(target): $(TARGETDIR)$(ENTRYPOINT).ihx
	ihx2sms -pm $< $(target)

# link stage - generally runs once to create a single output
%.ihx: $(objects)
	sdcc -L$(SMSLIB_DIR) -o$@ -mz80 --no-std-crt0 --data-loc 0xC000 $(SMSLIB_DIR)/crt0_sms.rel $(mains) SMSlib.lib

# compile unbanked sources
$(TARGETDIR)%.rel: %.c $(headers) Makefile | $(TARGETDIR)
	$(MKDIR) $(TARGETDIR)$(dir $*)
	sdcc $(include_options) --opt-code-speed -c -mz80 -o$(TARGETDIR)$(dir $*) --peep-file $(SMSLIB_DIR)/peep-rules.txt $<

# make clean to remove the build folder and all generated files
.PHONY: clean
clean:
	rm -rf $(TARGETDIR)
	-@rm -r *.generated*.*

