# Fast Neutrino Flux Simulation

**By Felix Kling**

[![arXiv](http://img.shields.io/badge/arXiv-2105.08270-B31B1B.svg)](https://arxiv.org/abs/2105.08270)

## Introduction

With the upcoming Run~3 of the LHC, the FASERv and SND@LHC detectors will start a new era of neutrino physics using the far-forward high-energy neutrino beam produced in collisions at ATLAS. This emerging LHC neutrino physics program requires reliable estimates of the LHC’s forward neutrino fluxes and their uncertainties. Here, we provide a new fast-neutrino flux simulation, implemented as a RIVET module, to address this issue. 

### Paper

Our main publication [Forward Neutrino Fluxes and Simulation at the LHC](https://arxiv.org/abs/2105.08270)
provides an overview over this simulation and presents its results. We recommend reading it first before jumping into the code.

### Fluxes

We provide the obtained neutrino energy spectra, both for neutrinos passing through the detector and charged current (CC) neutrino interctions with the detector volume, in the `Fluxes` directory. The files essentially contain a a digitized energie histogra, with energy in the first column and the number of events in the second column.  Here we consider the `FASERv` and `SND@LHC` experiments during LHC Run 3 with an integrated luminosity of 150/fb placed 480m downstream from the ATLAS IP in the tunnels TI12 and TI18, respecitively. In addition, we also considered proposed detectors at the Forward Physics Facility (or FPF) during the HL-LHC era with an integrated luminosity of 3000/fb placed 620m downstream from the ATLAS IP: `FASERv2`, `FLArE10` and `FLArE100` (as introduced in [2101.10338](https://arxiv.org/abs/2101.10338)).

### Support

If you have any questions, please write us at [felixk@slac.stanford.edu](felixk@slac.stanford.edu).

### Citations

If you use this code, or its results, please cite our main publication: [2105.08270](https://arxiv.org/abs/2105.08270)

### Usefull References 

- FASERv Letter of Intent and Physics: [1908.02310](https://arxiv.org/abs/1908.02310)
- FASER Technical Proposal: [2001.03073](https://arxiv.org/abs/2001.03073)
- SND@LHC Paper: [2002.08722](https://arxiv.org/abs/2002.08722)
- Forward Physics Facility Paper: [2109.10905](https://arxiv.org/abs/2109.10905)
