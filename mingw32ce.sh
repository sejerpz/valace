#!/bin/sh
export MINGW32CE_PATH=$HOME/opt/mingw32ce
export WINCE_PATH=`pwd`/wince

export PATH=$MINGW32CE_PATH/bin:$PATH
export LDFLAGS="-L$WINCE_PATH/lib"
export LD_LIBRARY_PATH="$WINCE_PATH/bin"
export PKG_CONFIG_PATH="$WINCE_PATH/lib/pkgconfig"
export WINDRES="arm-mingw32ce-windres"

