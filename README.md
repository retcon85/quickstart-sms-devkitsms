# A github template and quickstart project for devkitSMS (C programming language) SMS games

## Features

- Everything needed to build a "Hello, World!" project with devkitsms from a standing start
- Use Github Actions to develop and build in the cloud
- Or use the retcon85/toolchain-sms container to develop locally with or without Visual Studio Code integration
- Perfect for beginners or those wanting to avoid installing lots of tools to get into SMS development

## Prerequisites

### Using Github Actions (easiest quickstart)

You can use this project to build your code in the cloud with Github Actions and in that case you won't need to install anything at all on your computer: you just need your own Github account set up.

### Using Visual Studio Code devcontainers on your computer (most recommended)

This is the most powerful way to develop using our standard SMS toolchain image and you will need only minimal installs:

- Docker for Desktop or equivalent  (see here for more information)
- Visual Studio Code
- (optional) utilities for managing image assets for SMS development

### Using retcon85/toolchain-sms Docker image standalone

You can use the toolchain-sms Docker image directly, without using it as a Visual Studio Code devcontainer.
In this case the only prerequisite is Docker for Desktop or equivalent.

See [here](https://github.com/retcon85/toolchain-sms/blob/main/README.md#usage) for instructions on pulling and using the image.

### Manual tooling setup

You can install all the prerequisites manually if you don't want to use a Docker based solution.

- [devkitSMS](https://github.com/sverx/devkitSMS) - note you will also need to install SDCC as documented
- [GNU Make](https://www.gnu.org/software/make/)
- (optional) [retcon-audio]() utility

## Usage

### Using Github Actions (easiest quickstart)

1. At the top of this repository page, click the button which says "Use this template" and select "Create a new repository".
1. Give your new repository a name, e.g. 'sms-hello-world'. You can change the name later.
1. Create the repository
1. Click the Actions tab. You should see that a build has already started running. When it changes to a green tick, you can click into the build to see the "Artifacts" section. Within the "Artifacts" section should be an artifact called "roms" and clicking that will download a zipfile with the built SMS ROM inside it.
1. Run the ROM in your emulator or flashcart of choice!

To develop in the code, you can use the Github web experience to edit code. Every time you modify code it will rebuild the project and – assuming there are no build errors – will produce a new "roms" artifact in the Actions tab.

You can also produce official releases of your project in Github automatically whenever you create a new tag.


### Using Visual Studio Code devcontainers on your computer (most recommended)

### Using retcon85/toolchain-sms Docker image standalone

### Manual tooling setup

1. Download and install prerequisites
1. Run `make` or `make build` to build a .sms file into the `build` folder
1. Read the docs at https://github.com/sverx/devkitSMS/wiki
1. Have fun

## Cleaning

Run `make clean` to clean the build

## Hello World

Minimal code and assets are provided to produce an animated Hello World demo illustrating some basic functionality.
