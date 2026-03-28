FROM ghcr.io/retcon85/toolchain-sms:2.0-slim

# EXAMPLE
RUN DEBIAN_FRONTEND=noninteractive apt-get update && apt-get -y install \
  xxd \
  nano

# install ohmyzsh
RUN DEBIAN_FRONTEND=noninteractive apt-get update && apt-get -y install zsh
RUN zsh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
# END:EXAMPLE
