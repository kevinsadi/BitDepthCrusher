# BitDepthCrusher

This project is a BitCrusher external patch created for audio programming language Pure Data. External patches are written in c and compiled to their source destination dependent on platform. The source destination differs depending on Windows, Linux, and MacOS. Respectively, the extensions are .dll, .pd_darwin, and .pd_linux. The destinations for these compiled files can be found [here](https://puredata.info/docs/faq/how-do-i-install-externals-and-help-files).

## Theory

This patch leverages bit depth to modify audio streams. To create digital audio, we usually sample from analog at a sampling rate of around 44.2kHz. The bit depth for each sample specifies how much information we can store about the audio for every sample. For example, a bit depth of 1 bit can store 2 values, while a bit depth of 4 can store 16 values. 

Our external patch takes in any audio source within pure data and a requested bit depth. If the bit depth is less than the one of the audio source, it is crushed for audio effect. This can create new harmonics in the sound, but also create issues within aliasing. Aliasing can create unwanted lower frequencies in the sound.

## The Patch

This repository comes with a sample patch demonstrating the external patch. The external patch comes with a help file. 

## Compilation

The current state of the program has been compiled using Code::Blocks. To compile, "m_pd.h" from the PD source must be in your source repo. We also must link from "program files\Pd\bin\pd.lib" in your installation of Pd.  


TODO: Create MakeFile.