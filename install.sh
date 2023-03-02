#!/bin/sh

sudo apt install -y vim git zsh


git clone --depth=1 https://github.com/amix/vimrc.git ~/.vim_runtime
sh ~/.vim_runtime/install_basic_vimrc.sh



sh -c "$(wget https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh -O -)"


sed  -i 's/robbyrussell/agnoster/g'    ~/.zshrc  


source ~/.zshrc
