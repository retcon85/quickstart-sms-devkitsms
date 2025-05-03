# Friends don't let friends fool around with Makefiles :)

TARGETDIR ?= ../build/
PROJECTNAME ?= $(notdir $(CURDIR))
TARGET_EXTENSION ?= sms
SMSLIB_DIR ?= /opt/devkitsms/lib
SMSINC_DIR ?= /opt/devkitsms/include
ENTRYPOINT ?= main
USEPSGLIB ?= 1
SOURCE_DIRS ?= ../assets/build/

all_source_dirs := ./ $(wildcard ./**/) $(SOURCE_DIRS)
include_options := $(patsubst %,-I %,$(SMSINC_DIR) $(all_source_dirs))
ifeq ("$(USEPSGLIB)", "1")
psglib := $(SMSLIB_DIR)/PSGlib.lib
psgmacro := -DUSEPSGLIB
endif

target := $(TARGETDIR)$(PROJECTNAME).$(TARGET_EXTENSION)
sources := $(foreach dir,$(all_source_dirs),$(wildcard $(dir)*.c))
headers := $(foreach dir,$(all_source_dirs),$(wildcard $(dir)*.h))
banked_sources := $(foreach dir,$(all_source_dirs),$(wildcard $(dir)*.bank*.c))

objects := $(patsubst %.c,$(TARGETDIR)%.rel,$(sources))
banked_objects := $(patsubst %.c,$(TARGETDIR)%.rel,$(banked_sources))
bank_names := $(sort $(subst .,,$(suffix $(basename $(banked_sources)))))
# default behaviour is to automatically generate bank options, modify if you know what you are doing
banks = $(foreach bank,$(bank_names),-Wl-b_$(bank)=0x8000)
# okay this is kind of diabolical...
sorted_banked_objects := $(subst :slash:,/,$(notdir $(sort $(join $(suffix $(basename $(banked_objects))),$(addprefix /,$(subst /,:slash:,$(banked_objects)))))))

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
	sdcc -L$(SMSLIB_DIR) -o$@ -mz80 --no-std-crt0 --data-loc 0xC000 $(banks) $(SMSLIB_DIR)/crt0_sms.rel $(mains) SMSlib.lib $(psglib) $(filter-out $(mains) $(banked_objects),$(objects)) $(sorted_banked_objects)

# compile unbanked sources
$(filter-out $(banked_objects), $(objects)): $(TARGETDIR)%.rel: %.c $(headers) Makefile | $(TARGETDIR)
	$(MKDIR) $(TARGETDIR)$(dir $*)
	sdcc $(include_options) --opt-code-speed -c -mz80 -o$(TARGETDIR)$(dir $*) --peep-file $(SMSLIB_DIR)/peep-rules.txt $(psgmacro) $<

# compile banked sources
$(banked_objects): $(TARGETDIR)%.rel: %.c $(headers) Makefile | $(TARGETDIR)
	$(MKDIR) $(TARGETDIR)$(dir $*)
	sdcc $(include_options) --constseg $(subst .,,$(suffix $(basename $<))) -DTHIS_BANK=$(subst .bank,,$(suffix $(basename $<))) --opt-code-speed -c -mz80 -o$(TARGETDIR)$(dir $*) --peep-file $(SMSLIB_DIR)/peep-rules.txt $(psgmacro) $<

# make clean to remove the build folder and all generated files
.PHONY: clean
clean:
	rm -rf $(TARGETDIR)
	-@rm -r *.generated*.*

