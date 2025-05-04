# A github template and quickstart project for devkitSMS (C programming language) SMS games

## Features

- Everything needed to build a "Hello, World!" project with devkitsms from a standing start!
- Use Github Actions to develop and build in the cloud!
- Or use the `retcon85/toolchain-sms` container to develop locally with or without Visual Studio Code integration!
- Perfect for beginners or those wanting to avoid installing lots of tools to get into SMS development!

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

- [devkitsms](https://github.com/sverx/devkitSMS) - note you will also need to install SDCC as documented
- [GNU Make](https://www.gnu.org/software/make/)
- (optional) [retcon-audio]() utility

## Usage

### Using Github Actions (easiest quickstart)

1. At the top of this repository page, click the button which says "Use this template" and select "Create a new repository".
1. Give your new repository a name, e.g. 'sms-hello-world'. You can change the name later.
1. Create the repository.
1. (optional) enable discussions on your repo if you want discussion posts to be automatically created for new tag releases.
1. Click the Actions tab. You should see that a build has already started running. When it changes to a green tick, you can click into the build to see the "Artifacts" section. Within the "Artifacts" section should be an artifact called "roms" and clicking that will download a zipfile with the built SMS ROM inside it.
1. Run the ROM in your emulator or flashcart of choice!

To develop in the code, you can use the Github web experience to edit code. Every time you modify code it will rebuild the project and – assuming there are no build errors – will produce a new "roms" artifact in the Actions tab.

You can also produce more "official" releases of your project in Github automatically in two ways:
- when pushing a new tag from a git client, a new release will be created for that tag, and a discussion post created if discussions are enabled for your repo
- creating a new release from the Github web UI will trigger a new release build, and if successful the output of the build will be attached to the release you created

If you want to disable these Github Actions you can either disable them at the repo level in your repository settings in Github, or you can simply delete the files inside the `.github/workflows` folder in the repo. You could also edit the `.yml` files to modify the build process to your needs.

Also if you want to make a change to your source but skip the automatic build steps, add the text `[skip ci]` to your commit message.

### Using Visual Studio Code devcontainers on your computer (most recommended)

Note, steps 1–5 below are the same as for Github Actions above.

1. Install prerequisites (Visual Studio Code and Docker for Desktop) on your computer
1. At the top of this repository page, click the button which says "Use this template" and select "Create a new repository".
1. Give your new repository a name, e.g. 'sms-hello-world'. You can change the name later.
1. Create the repository.
1. (optional) enable discussions on your repo if you want discussion posts to be automatically created for new tag releases.
1. Copy the URL of your new repository by clicking the "Code" button on the main page and clicking the copy button next to the URL.
1. Launch Visual Studio Code.
1. Open the "Source Control" toolbar by clicking the icon in the left hand menu.
1. Click the "Clone Repository" button and paste the URL of your repository into the text box.
1. Select a folder on your disk to clone the repository to. We recommend putting all your projects into a single root folder called "projects" or "workspaces" so you don't lose track of them.
1. Open the Visual Studio Code command palette from the View -> Command Palette menu item, or with a keyboard shortcut
1. Start typing in the text box to locate the function called "Dev Containers: Rebuild and Reopen in Container". This may already be the top suggested command. Selecting this command will begin the process of downloading and building the `recton85/toolchain-sms` image in the background and so might take a few minutes the first time you run it.
1. Once the project is open in container mode, open a new Terminal inside Visual Studio Code from the Terminal -> New Terminal menu item, or with a keyboard shortcut
1. Type `make` and press enter in the terminal to build your project for the first time. The output of the project can be found inside the `build` folder underneath where you clones the repo to. The `.sms` file generated here can be opened directly in your emulator for testing, or uploaded to your flashcart.

From this point you are free to edit the source code in Visual Studio Code. Every time you want to rebuild the project you will need to run `make` again from the terminal.

Every command you type into the Terminal while Visual Studio Code is in container mode will actually execute inside the `retcon85/toolchain-sms` container, rather than on your local computer. This container is running Linux, so commands may be different from those you are used to, especially if your host computer is running Windows.

If you want to update your repo on Github with your changes you can use Visual Studio Code to do so, or you can use the `git` client inside the container. You will probably need to set up an SSH certificate to connect to Github, and you can find instructions for how to do so [on the web](https://docs.github.com/en/authentication/connecting-to-github-with-ssh). It's not too hard, but it can feel technical and daunting for some beginners. You may also want to read some [basic tutorials on how git works](https://www.undeveloper.com/blog/git-quickstart), even if you intend to use the Visual Studio Code visual source control UI.

Visual Studio Code devcontainers are quite easy to configure. The files inside the `.devcontainer` folder in this project are what tell Visual Studio Code how to download and configure the `retcon85/toolchain-sms` container to run command in. You can upgrade the version of the image used as new ones are released by modifying the version number on the very first line of the `Dockerfile` file in this folder. Our example also installs the zsh shell with the ohmyzsh additions on top, because that is our favourite shell setup. If you want to use a different shell you can change these lines. Removing them will revert to a simple bash shell. You can also run any other commands you like on the image here, which will change the way the container is configured for all commands. For example, if you add a line like `RUN use-sdcc 4.3`, this will configure the container to use version 4.3 of SDCC by default.
If you do edit these `.devcontainer` files, you will need to run "Dev Containers: Rebuild Container" from the command palette to see the changes.

### Using retcon85/toolchain-sms Docker image standalone

It's also quite possible to use the `retcon85/toolchain-sms` Docker image directly, without using the devcontainers feature of Visual Studio Code. In this case, refer to the [instructions in the retcon85/toolchain-sms repo](https://github.com/retcon85/toolchain-sms/blob/main/README.md#usage).

### Manual tooling setup

If you are installing your own prerequisites and developing locally, you can follow the steps from the Using Visual Studio Code devcontainers section but skip the steps relating to opening the project in a devcontainer. You should just be able to run `make` on a local terminal if you have installed all your prerequisites properly.

## The project structure

### Overview

This is an opinionated project template with a very basic structure:

- All C source code files (except for generated assets) are inside the `src` folder.
- All raw asset files are in the `assets` folder.
- Project outputs are built to the `build` folder.

The Makefiles supplied with this project allow you to nest your source code one level deep inside the `src` folder, but it's easiest to keep the folder flat and without any sub-folders if you can.

### Makefiles

We've supplied a Makefile setup that should be useful for most projects and reflects our typical setup.

From your project root folder:
- `make` (or `make all`) will run the default top level build which builds assets and source code to produce a final ROM.
- `make assests` will _only_ compile the assets and not the source code.
- `make clean` will wipe all output and generated files from the filesystem and is useful if your build gets in a strange state.

There are many options you can change in the Makefiles to tweak your build, but we recommend that you don't unless you know exactly what you're doing!
A few settings have been designed to be overridden from the command line or with environment variables. In particular the `PROJECTNAME` setting can be overridden. If it's not supplied then it will simply take the name of the folder your project is in. You can override the `PROJECTNAME` setting by adding `-e PROJECTNAME=your-new-project-name` to your `make` commands, or if you are using the devcontainer feature you can add an environment variable to the `Dockerfile` with an `ENV PROJECTNAME=your-new-project-name` command.

### Asset pipeline & banking (advanced)

We've added a flexible asset build pipeline in the `assets/Makefile` file. By default this will bundle any file with a `.bin` or `.psg` extension as a banked asset source code file. It will also automatically convert `.vgm` files to `.psg` files so you don't have to worry about doing that manually. In future we'll update the pipeline to handle image assets too, but for now you will need to manage those yourselves.

Note that if you _delete_ an asset (or rename one), you will likely need to run a `make clean` on your project to ensure the old resources are properly destroyed. If you don't do this, you might find they are still being bundled into your source which could increase your ROM size needlessly.

Another cool feature of the source building Makefile is that it automatically manages the SDCC link commands to add banking information so that ideally you will never have to worry about changing the banking directives as you add new assets. This works by locating any file in the source code which is named `*.bankN.c`, where `N` is a bank number and automatically registering that as a banked asset in the build pipeline. This applies both to files automatically generated (by assets2banks) and also to any files you explicitly create with the same naming convention. For example, if you create a regular source file called `my_file.bank4.c` then it will be compiled and linked into bank 4 automatically. You can override the `FIRSTBANK` setting in the Makefile pipeline if you need to add explicitly banked code and don't want automatic banking to use the same space. This setting also allows you to reserve part of a bank. Run `assets2banks` from devkitsms without parameters to find out more information.

## The `retcon85/toolchain-sms` image

The `retcon85/toolchain-sms` image is designed to provide an environment with tooling to build SMS projects. In particular it provides:

- Python
- devkitsms / SDCC for C projects; and
- WLA-DX for assembly language projects

More tools will be added in future.

Because embedded projects can be quite sensitive to tool versions, we've taken the approach of supplying multiple versions on a single image.

You can switch between versions 4.3, 4.4 or 4.5 of SDCC by running the `use-sdcc <version>` command, either temporarily from the container shell or permanantely by building a derived image (e.g. in the devcontainer `Dockerfile`). The default SDCC version is currently 4.4. Version 4.5 is currently incompatible with the version of devkitsms included on the image.

Similarly you can switch between versions 10.5 and 10.6 of WLA-DX by running `use-wla-dx <version>`. The default WLA-DX version is currently 10.6.

There is also a "slim" variant of the image, which is slightly smaller in terms of image size and should work for most if not all projects. We recommend using the slim variant unless you find that it doesn't support your needs. This project uses the slim variant in its devcontainer setup.

To find out more about the image, please refer to the [documentation in the repo](https://github.com/retcon85/toolchain-sms/blob/main/README.md)

## Hello World

Minimal code and assets are provided to produce an animated Hello World demo illustrating some basic functionality.
Delete code inside `// EXAMPLE` and `// END:EXAMPLE` blocks and delete the example assets to remove this example functionality.

## More about devkitsms

Devkitsms make writing awesome SMS homebrew games incredibly easy using the C programming language. There are three parts to it:

- [SDCC](https://sdcc.sourceforge.net/), which is a C compiler specifically targeting CPUs like the Z80 inside the SMS.
- SMSLib, which is a software development kit (SDK) library that exposes basic SMS functionality as C functions.
- PSGLib, which is a basic music and sound driver for the SMS's Programmable Sound Generator (PSG) chip.

Head over to the [devkitsms documentation](https://github.com/sverx/devkitSMS/wiki) to find out more about this amazing project.
