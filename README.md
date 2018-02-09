# AudioTools
This is a real time audio framework thinked for writing audio programs and synthetizer

## Philosophy (KISS)
The framework wants to be as simple as possibile, you must be able to do everythings in the easiest way.

## Guidelines

### StereoSmp
The class `StereoSmp` allows operation and convertions between mono and stereo, in the framework all things work with template, so you can make each Object mono or stereo using same algorithms.

### Wavetables
The framework core are `WaveTables`, wavetables allows you to think in anlogic domain throw linear interpolation. They can be `periodic` or `oneshot`, when you work with this framework you should think that **all is a wavetable**, in this way the CPU load will be reduced a lot.

### Filters
The framwork can implements `IIR` and `FIR` filters throw `second trasposed form`. The filter can be used in indipendet way or otherwise you can insert a filter in a wavetable.

### Enveloope
The framework provides `enveloope windows` that are calculated and then stored in wavetables, they can be `linears` or `exponentials`

### OutputMaker
This is an `interface` that stores `time axis` and `sampling rate` of each thing that produces audio.
Each audio producer object should inherit `OutputMaker`





