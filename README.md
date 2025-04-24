# Fast Neutrino Flux Simulation

**By Felix Kling and Max Fieg**

[![arXiv](http://img.shields.io/badge/arXiv-2105.08270-B31B1B.svg)](https://arxiv.org/abs/2105.08270)
[![license](https://img.shields.io/badge/License-MIT-blue.svg)](https://github.com/KlingFelix/FastNeutrinoFluxSimulation/blob/main/LICENSE.md)

## Introduction

With the beginning of Run 3 of the LHC, the FASERv and SND@LHC detectors have started a new era of neutrino physics using the far-forward high-energy neutrino beam produced in collisions at ATLAS. This LHC neutrino physics program requires reliable estimates of the LHC’s forward neutrino fluxes and their uncertainties. Here, we provide a new fast-neutrino flux simulation, implemented as a RIVET module, to address this issue. 

The beam of forward, high-energy neutrinos observable at FASER mainly originates from the weak decays of hadrons that are produced at the ATLAS interaction point. This includes light hadrons (pions, kaons, and hyperons), which are long-lived and decay inside the LHC vacuum beam pipe, and also charm hadrons, which decay essentially promptly.

To obtain the neutrino flux, one needs to model the trajectory of the long-lived hadrons through the LHC beam pipe and magnetic fields and also model the decay of these hadrons into neutrinos. This is done using the fast neutrino flux simulation. This fast neutrino flux simulation (i) reads the forward hadron fluxes from HepMC files produced by the Monte-Carlo (MC) event generator; (ii) propagates the long-lived hadrons through the LHC beam pipe and magnetic fields; (iii) obtains the neutrinos from decays of hadrons at multiple locations along their trajectory; and (iv) stores the resulting neutrinos going through a sample plane at the FASER location as a MC event sample. All parts of the outlined simulation are implemented as a RIVET module, which can be found in the `RIVET_Module` directory. 

### Publications

The simulation was first developed as part of the publication [Forward Neutrino Fluxes and Simulation at the LHC](https://arxiv.org/abs/2105.08270), which provides an overview over this simulation and presents its results. We recommend reading it first before jumping into the code. The simulation was further modified and improved in the publication [Neutrino Rate Predictions for FASER](https://arxiv.org/abs/2402.13318), where the beam and infrastructure modeling were adjusted according to configuration in LHC Run 3 and Run 4, and an event output was introduced.

### Citations

If you use this code, or its results, we ask you to cite [2105.08270](https://arxiv.org/abs/2105.08270) as well as [2402.13318](https://arxiv.org/abs/2402.13318). Please also don't forget to cite the generator used to model the primary interactions. For example, if you use EPOS-LHC in CRMC, we suggest to add a statement like this:  *We employ EPOS-LHC [1306.0121](https://arxiv.org/abs/1306.0121) as implemnted in CRMC [Zenodo](https://zenodo.org/records/5270381) to simulate the production of forward light hadrons and use the fast neutrino flux simulation developed in Ref. [2105.08270](https://arxiv.org/abs/2105.08270) and [2402.13318](https://arxiv.org/abs/2402.13318) to model the propagation long-lived hadrons the LHC infrastructure as well as their decay into neutrinos.*

### Support

If you have any questions, please write us at [flxkling.gmail.com](flxkling.gmail.com) or [mfieg@uci.edu](mfieg@uci.edu).

## Fluxes

We provide the obtained neutrino energy spectra, both for neutrinos passing through the detector and charged current (CC) neutrino interctions with the detector volume, in the `Fluxes` directory. The files essentially contain a a digitized energie histogra, with energy in the first column and the number of events in the second column.  Here we consider the `FASERv` and `SND@LHC` experiments during LHC Run 3 with an integrated luminosity of 150/fb placed 480m downstream from the ATLAS IP in the tunnels TI12 and TI18, respecitively (as obtained in [2105.08270](https://arxiv.org/abs/2105.08270)). In addition, we also considered proposed detectors at the Forward Physics Facility (or FPF) during the HL-LHC era with an integrated luminosity of 3000/fb placed 620m downstream from the ATLAS IP: `FASERv2` and `FLArE` (as introduced in [2101.10338](https://arxiv.org/abs/2101.10338)). 

We note that these files have been produced some time ago. They therefore do not accoount for recent changes, for example regarding the location (FPF is not at z=620m), crossing angle (is not constant), or luminosity (LHC Run 3 is longer than initially planned). For more precise numbers, please contact the authors. 

## RIVET Modules Simulation

The directory `RIVET_Modules` contains a variety of RIVET modules to simulate the neutrino Flux.
- The folder `Rivet_Run2_Histogram` contains the original simulation used in [2105.08270](https://arxiv.org/abs/2105.08270). It simulates the neutrino flux passing through the FASER and SND@LHC cross sectional area and fills it into histograms of neutrino energy. There are three different modules for the neutrino flux from displaced light hadron decays (pion, kaon, hyperons), the  neutrino flux from charmed hadron decays and the neutrino flux from downstream secondary interactions. The setup corresponds to the end of LHC Run 2 with 13 TeV collision energy. 
- The folder `Rivet_Run2_MCFiles` contains a modified simulation that exports the individual neutrino events. No histogram output is provided. We note that this is not the usual way RIVET modules are supposed to be used. There are two different modules: one for unweighted neutrino events from displaced light hadron decays and one for unweighted neutrino events from charmed hadron decays. The setup corresponds to the end of LHC Run 2 with 13 TeV collision energy. 
- The folder `Rivet_Run3_MCFiles` contains a modified simulation that exports the neutrino events files for the beginning of LHC Run 3 with 13.6 TeV collision energy and a crossing angle of 160urad downwards. There are three different modules: one for unweighted neutrino events from displaced light hadron decays, one for unweighted neutrino events from charmed hadron decays, and one for weighted neutrino events from charmed hadron decays. The latter is primarily designed for events generated with POWHEG, where some events have negative weights and a simple unweighting cannot be performed. 
- The folder `Rivet_Run4_MCFiles` contains a modified simulation that exports the neutrino events files for LHC Run 4 with 14 TeV collision energy. As for Run3, there are three different modules. 

### Running the Simulation 

Before running the simulation, we first need produce a HEPMC file of minimum bias events at the LHC. This can, for example, be done using CRMC or CHROMO. The HEPMC file contains the event record, so a list 4-vectors for the various hadrons contained in the Event. 

The event generation and RIVET module can be run together. If one uses CRMC, the command to simulate 100k pp collision events with EPOS-LHC at a CM energy of 13.6TeV would be: 
- `mkfifo fifo_file.hepmc`
- `crmc -o hepmc -n10000 -m0 -S13600 -ffifo_file.hepmc &`
- `rivet fifo_file.hepmc -o Rivet-output.yoda -a Run3_Neutrinos_Light -a Run3_Neutrinos_Charm --pwd`

Here we have used a fifo file, which allows to directly feed the generator output into RIVET without saving the HEPMC file on disc. 

### Event Record

The resulting event record consists of a list of neutrinos passing a cross sectional area at the FASER location at z=480m. For each neutrino, we save i) the neutrino PID, ii) the parent hadron PID, iii) the x-position at z=480m in m, iv) the y-position  at z=480m in m, v) the production z-position in m vi) the x-angle in rad, vii) the y-angle in rad, viii) the energy, and ix) the event weight in pb. The neutrino event record has been unweighted and, by construction, contains 1M events.


