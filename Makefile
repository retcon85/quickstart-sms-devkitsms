# Friends don't let friends fool around with Makefiles :)

# by default output will take the name of the folder we're in
export PROJECTNAME ?= $(notdir $(CURDIR))
# set USEPSGLIB to 0 to compile without audio support
export USEPSGLIB ?= 1
export TARGET_EXTENSION ?= sms

# allow for unmanaged banks at beginning of ROM. 2 is usually the starting value here.
export FIRSTBANK := 2
export TARGETDIR := ../build/
export SOURCEDIR := ./
# the default entrypoint (where main function is defined), which must come first in the linker
export ENTRYPOINT := main
export SMSLIB_DIR := /opt/devkitsms/lib
export SMSINC_DIR := /opt/devkitsms/include

export MKDIR := mkdir -p

.PHONY: all
all: assets
	@$(MAKE) --no-print-directory --directory=./src

.PHONY: assets
assets:
	@$(MAKE) --no-print-directory --directory=./assets

.PHONY: clean
clean:
	@$(MAKE) --no-print-directory --directory=./assets clean
	@$(MAKE) --no-print-directory --directory=./src clean
