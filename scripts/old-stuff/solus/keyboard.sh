#! /bin/bash
# A script for playing a keyboard on Solus using FluidSynth, with installer
# keyboard.sh: version 1.0

# Confirmation block for setup
confirm() {
    read -r -p "${1:-Are you sure? [y/N]} " response
    case "$response" in
        [yY][eE][sS]|[yY])
            true
            ;;
        *)
            false
            ;;
    esac
}

confirm "Do you wish to run setup for Solus?" && {

echo "Installing FluidSynth"
  sudo eopkg it fluidsynth parallel -y

echo "Setting up the SoundFont for FluidSynth"
  mkdir -p $HOME/sf2
  wget http://http.debian.net/debian/pool/main/f/fluid-soundfont/fluid-soundfont_3.1.orig.tar.gz -O $HOME/sf2/fluid-soundfont.tar.gz
  cd $HOME/sf2/ && tar xvf fluid-soundfont.tar.gz fluid-soundfont-3.1/FluidR3_GM.sf2 --strip=1
  rm fluid-soundfont.tar.gz

}

echo "Starting FluidSynth with specified SoundFont and connecting it to the MIDI input"
# Set alsa as audio backend and set the gain to 1.5 for slightly higher volume
# We also run the connection in parallel right after the start of FluidSynth, we should also learn parallel how to shut up
  fluidsynth -a alsa -s -g 1.5 $HOME/sf2/FluidR3_GM.sf2 | parallel aconnect 24:0 128:0