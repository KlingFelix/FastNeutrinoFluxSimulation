#include "Rivet/Analysis.hh"
#include "Rivet/Projections/FinalState.hh"
#include "Rivet/Projections/HeavyHadrons.hh"
#include <math.h>
#include <random>

namespace Rivet {
    
    class Run3_Neutrinos_Charm : public Analysis {
        public:
        
        DEFAULT_RIVET_ANALYSIS_CTOR(Run3_Neutrinos_Charm);
        
        
        void init() {
            
            srand (time(NULL));
            declare(HeavyHadrons(), "HH");
            
            // Energy distribution of neutrinos in the hadron decay rest frame. the first vector
            // constains the energy [GeV], and the second vector the CDF.
            _energy_cdf[411][12].push_back({
                2.0000e-02, 6.0000e-02, 1.0000e-01, 1.4000e-01, 1.8000e-01,
                2.2000e-01, 2.6000e-01, 3.0000e-01, 3.4000e-01, 3.8000e-01,
                4.2000e-01, 4.6000e-01, 5.0000e-01, 5.4000e-01, 5.8000e-01,
                6.2000e-01, 6.6000e-01, 7.0000e-01, 7.4000e-01, 7.8000e-01,
                8.2000e-01, 8.6000e-01, 9.0000e-01, 9.4000e-01, 9.8000e-01 });
            _energy_cdf[411][12].push_back({
                8.0000e-04, 5.2700e-03, 1.5230e-02, 3.2300e-02, 5.7920e-02,
                9.1390e-02, 1.3327e-01, 1.8323e-01, 2.4095e-01, 3.0416e-01,
                3.7399e-01, 4.4904e-01, 5.2759e-01, 6.0577e-01, 6.8237e-01,
                7.5379e-01, 8.1748e-01, 8.7260e-01, 9.2168e-01, 9.6331e-01,
                9.9097e-01, 9.9765e-01, 9.9970e-01, 1.0000e+00, 1.0000e+00 });
            
            _energy_cdf[411][14].push_back({
                0.02   , 0.06   , 0.1    , 0.14   , 0.18   ,
                0.22   , 0.26   , 0.3    , 0.34   , 0.38   ,
                0.42   , 0.46   , 0.5    , 0.54   , 0.58   ,
                0.62   , 0.66   , 0.7    , 0.74   , 0.78   ,
                0.82   , 0.86   , 0.9    , 0.94   , 0.98   });
            _energy_cdf[411][14].push_back({
                0.00143, 0.0066 , 0.01779, 0.0359 , 0.06308,
                0.09736, 0.14047, 0.19267, 0.25056, 0.31516,
                0.38533, 0.4603 , 0.53944, 0.61904, 0.69671,
                0.76859, 0.82864, 0.88298, 0.93119, 0.9717 ,
                0.99315, 0.9955 , 0.99756, 1.     , 1.     });
            
            _energy_cdf[411][16].push_back({
                0.09002, 0.09006, 0.0901 , 0.09014, 0.09018,
                0.09022, 0.09026, 0.0903 , 0.09034, 0.09038,
                0.09042, 0.09046, 0.0905 , 0.09054, 0.09058,
                0.09062, 0.09066, 0.0907 , 0.09074, 0.09078,
                0.09082, 0.09086, 0.0909 , 0.09094, 0.09098 });
            _energy_cdf[411][16].push_back({
                0.     , 0.     , 0.     , 0.     , 0.     ,
                0.     , 0.     , 0.     , 0.     , 0.     ,
                0.     , 0.     , 1.     , 1.     , 1.     ,
                1.     , 1.     , 1.     , 1.     , 1.     ,
                1.     , 1.     , 1.     , 1.     , 1.      });
            
            _energy_cdf[4122][12].push_back({
                2.0000e-02, 6.0000e-02, 1.0000e-01, 1.4000e-01, 1.8000e-01,
                2.2000e-01, 2.6000e-01, 3.0000e-01, 3.4000e-01, 3.8000e-01,
                4.2000e-01, 4.6000e-01, 5.0000e-01, 5.4000e-01, 5.8000e-01,
                6.2000e-01, 6.6000e-01, 7.0000e-01, 7.4000e-01, 7.8000e-01,
                8.2000e-01, 8.6000e-01, 9.0000e-01, 9.4000e-01, 9.8000e-01});
            _energy_cdf[4122][12].push_back({
                4.7000e-04, 3.5100e-03, 1.1730e-02, 2.7100e-02, 5.2330e-02,
                8.6570e-02, 1.3012e-01, 1.8371e-01, 2.4600e-01, 3.1687e-01,
                3.9504e-01, 4.7553e-01, 5.6096e-01, 6.4640e-01, 7.2686e-01,
                8.0066e-01, 8.6366e-01, 9.1608e-01, 9.5668e-01, 9.8267e-01,
                9.9486e-01, 9.9852e-01, 9.9980e-01, 1.0000e+00, 1.0000e+00});
            
            _energy_cdf[4122][14].push_back({
                2.0000e-02, 6.0000e-02, 1.0000e-01, 1.4000e-01, 1.8000e-01,
                2.2000e-01, 2.6000e-01, 3.0000e-01, 3.4000e-01, 3.8000e-01,
                4.2000e-01, 4.6000e-01, 5.0000e-01, 5.4000e-01, 5.8000e-01,
                6.2000e-01, 6.6000e-01, 7.0000e-01, 7.4000e-01, 7.8000e-01,
                8.2000e-01, 8.6000e-01, 9.0000e-01, 9.4000e-01, 9.8000e-01});
            _energy_cdf[4122][14].push_back({
                5.3000e-04, 4.2600e-03, 1.3230e-02, 2.9650e-02, 5.5470e-02,
                9.0560e-02, 1.3608e-01, 1.9190e-01, 2.5644e-01, 3.3082e-01,
                4.1116e-01, 4.9705e-01, 5.8394e-01, 6.6998e-01, 7.5044e-01,
                8.2409e-01, 8.8539e-01, 9.3578e-01, 9.7089e-01, 9.9116e-01,
                9.9686e-01, 9.9939e-01, 1.0000e+00, 1.0000e+00, 1.0000e+00});
                
            _energy_cdf[421][12].push_back({
                2.0000e-02, 6.0000e-02, 1.0000e-01, 1.4000e-01, 1.8000e-01,
                2.2000e-01, 2.6000e-01, 3.0000e-01, 3.4000e-01, 3.8000e-01,
                4.2000e-01, 4.6000e-01, 5.0000e-01, 5.4000e-01, 5.8000e-01,
                6.2000e-01, 6.6000e-01, 7.0000e-01, 7.4000e-01, 7.8000e-01,
                8.2000e-01, 8.6000e-01, 9.0000e-01, 9.4000e-01, 9.8000e-01});
            _energy_cdf[421][12].push_back({
                7.2000e-04, 4.8200e-03, 1.4330e-02, 3.0760e-02, 5.5140e-02,
                8.9280e-02, 1.3066e-01, 1.8116e-01, 2.3762e-01, 3.0164e-01,
                3.7017e-01, 4.4564e-01, 5.2277e-01, 6.0160e-01, 6.7859e-01,
                7.4933e-01, 8.1201e-01, 8.6752e-01, 9.1658e-01, 9.5984e-01,
                9.8774e-01, 9.9556e-01, 9.9974e-01, 1.0000e+00, 1.0000e+00});
              
            _energy_cdf[421][14].push_back({
                0.02   , 0.06   , 0.1    , 0.14   , 0.18   ,
                0.22   , 0.26   , 0.3    , 0.34   , 0.38   ,
                0.42   , 0.46   , 0.5    , 0.54   , 0.58   ,
                0.62   , 0.66   , 0.7    , 0.74   , 0.78   ,
                0.82   , 0.86   , 0.9    , 0.94   , 0.98   });
            _energy_cdf[421][14].push_back({
                0.00113, 0.00621, 0.01742, 0.03612, 0.0625 ,
                0.09749, 0.14195,  0.192 , 0.25073, 0.31636,
                0.38674, 0.46105, 0.53936, 0.61836, 0.69505,
                0.76506, 0.82535, 0.87729, 0.92687, 0.96856,
                0.99192, 0.99651, 1.     , 1.     , 1.    });
           
            _energy_cdf[431][12].push_back({
                2.0000e-02, 6.0000e-02, 1.0000e-01, 1.4000e-01, 1.8000e-01,
                2.2000e-01, 2.6000e-01, 3.0000e-01, 3.4000e-01, 3.8000e-01,
                4.2000e-01, 4.6000e-01, 5.0000e-01, 5.4000e-01, 5.8000e-01,
                6.2000e-01, 6.6000e-01, 7.0000e-01, 7.4000e-01, 7.8000e-01,
                8.2000e-01, 8.6000e-01, 9.0000e-01, 9.4000e-01, 9.8000e-01});
            _energy_cdf[431][12].push_back({
                4.6000e-04, 3.1900e-03, 1.0240e-02, 2.2980e-02, 4.3440e-02,
                7.2440e-02, 1.1018e-01, 1.5764e-01, 2.1334e-01, 2.7765e-01,
                3.5003e-01, 4.2807e-01, 5.0993e-01, 5.9429e-01, 6.7402e-01,
                7.4794e-01, 8.0973e-01, 8.6083e-01, 9.0426e-01, 9.4334e-01,
                9.7551e-01, 9.9512e-01, 9.9971e-01, 9.9999e-01, 1.0000e+00});
          
            _energy_cdf[431][14].push_back({
                2.2000e-02, 6.6000e-02, 1.1000e-01, 1.5400e-01, 1.9800e-01,
                2.4200e-01, 2.8600e-01, 3.3000e-01, 3.7400e-01, 4.1800e-01,
                4.6200e-01, 5.0600e-01, 5.5000e-01, 5.9400e-01, 6.3800e-01,
                6.8200e-01, 7.2600e-01, 7.7000e-01, 8.1400e-01, 8.5800e-01,
                9.0200e-01, 9.4600e-01, 9.9000e-01, 1.0340e+00, 1.0780e+00});
            _energy_cdf[431][14].push_back({
                5.6000e-04, 4.1300e-03, 1.2960e-02, 2.8820e-02, 5.5100e-02,
                9.1320e-02, 1.3923e-01, 1.9547e-01, 2.6281e-01, 3.3909e-01,
                4.2140e-01, 5.0623e-01, 5.9237e-01, 6.7092e-01, 7.3848e-01,
                7.8896e-01, 8.3460e-01, 8.7674e-01, 9.0920e-01, 9.2550e-01,
                9.2676e-01, 9.2693e-01, 1.0000e+00, 1.0000e+00, 1.0000e+00});
                
            _energy_cdf[431][16].push_back({
                0.1802, 0.1806, 0.181 , 0.1814, 0.1818,
                0.1822, 0.1826, 0.183 , 0.1834, 0.1838,
                0.1842, 0.1846, 0.185 , 0.1854, 0.1858,
                0.1862, 0.1866, 0.187 , 0.1874, 0.1878,
                0.1882, 0.1886, 0.189 , 0.1894, 0.1898});
            _energy_cdf[431][16].push_back({
                0.    , 0.    , 0.    , 0.    , 0.    ,
                1.    , 1.    , 1.    , 1.    , 1.    ,
                1.    , 1.    , 1.    , 1.    , 1.    ,
                1.    , 1.    , 1.    , 1.    , 1.    ,
                1.    , 1.    , 1.    , 1.    , 1.    });
            
            _energy_cdf[431][-16].push_back({
                2.0000e-02, 6.0000e-02, 1.0000e-01, 1.4000e-01, 1.8000e-01,
                2.2000e-01, 2.6000e-01, 3.0000e-01, 3.4000e-01, 3.8000e-01,
                4.2000e-01, 4.6000e-01, 5.0000e-01, 5.4000e-01, 5.8000e-01,
                6.2000e-01, 6.6000e-01, 7.0000e-01, 7.4000e-01, 7.8000e-01,
                8.2000e-01, 8.6000e-01, 9.0000e-01, 9.4000e-01, 9.8000e-01});
            _energy_cdf[431][-16].push_back({
                2.2000e-04, 1.4800e-03, 4.3300e-03, 1.0100e-02, 1.9300e-02,
                3.2400e-02, 4.9590e-02, 7.2690e-02, 1.0185e-01, 1.3781e-01,
                1.7934e-01, 2.2865e-01, 2.8289e-01, 3.3915e-01, 3.9708e-01,
                4.5813e-01, 5.3759e-01, 6.2729e-01, 7.1516e-01, 7.9205e-01,
                8.6338e-01, 9.1464e-01, 9.5473e-01, 9.8698e-01, 1.0000e+00});
            
            _decay_branchings[411]  = {0.17058, -1     , 0.16611, -1     , 0.000971, -1      };
            _decay_branchings[-411] = {-1     , 0.17058, -1     , 0.16611, -1      , 0.000971};
            _decay_branchings[421]  = {0.06785, -1     , 0.06566, -1     , -1      , -1      };
            _decay_branchings[-421] = {-1     , 0.06785, -1     , 0.06566, -1      , -1      };
            _decay_branchings[431]  = {0.08103, -1     , 0.08688, -1     , 0.063011, 0.063011};
            _decay_branchings[-431] = {-1     , 0.08103, -1     , 0.08688, 0.063011, 0.063011};
            _decay_branchings[4122] = {0.04491, -1     , 0.04485, -1     , -1      , -1      };
            _decay_branchings[-4122]= {-1     , 0.04491, -1     , 0.04485, -1      , -1      };
        }
        
        // function that interpolates arrays with constant function (used for cross section)
        double linear_interpolation(vector< vector<float> > data, float x){
            int icount = 0;
            while (data[0][icount]<=x) icount++;
            return data[1][icount-1] + (x-data[0][icount-1])/(data[0][icount]-data[0][icount-1]) * (data[1][icount]-data[1][icount-1]);
        }
        
        void analyze(const Event& event) {
            
            //Extract Event Weight
            double evtweight = event.weights()[0];
 
            // Read particles
            const HeavyHadrons &hh = apply<HeavyHadrons> (event, "HH");
            Particles charms = hh.particles(Cuts::abspid==411 or Cuts::abspid==421 or Cuts::abspid==431 or Cuts::abspid==4122 );
            
            // loop through all charm hadrons
            for (const Particle& part : charms) {
                
                //read particle
                int pid  = part.pid();
                int apid = part.abspid();
                int sign = pid/apid;
                
                // rotate with beam crossing angle
                FourMomentum phad = part.momentum();
                if (_xing_urad_v != 0){
                    float angle = _xing_urad_v/1000./1000. ;
                    phad.setXYZM(
                        phad.x(),
                        phad.y()*cos(angle)+phad.z()*sin(angle),
                        phad.z()*cos(angle)-phad.y()*sin(angle),
                        phad.mass()
                    );
                }
                if (_xing_urad_h != 0){
                    float angle = _xing_urad_h/1000./1000. ;
                    phad.setXYZM(
                        phad.x()*cos(angle)+phad.z()*sin(angle),
                        phad.y(),
                        phad.z()*cos(angle)-phad.x()*sin(angle),
                        phad.mass()
                   );
                }
                
                // redecay rate
                int nrepeat = _nrepeat0;
                if (apid==431) nrepeat = _nrepeat0*_nenhance;
                
                // loop through all possible decays
                for (int iv=0; iv<6; iv++){
                    // repeat decays nrepeat times for enhanced statistics
                    for (int irepeat=0;irepeat<nrepeat;irepeat++){
                    
                        // get neutrino id
                        int vpid = _vpids[iv];
                        float br = _decay_branchings[pid][iv];
                        if (br <= 0) continue;
                        float weight = br/float(nrepeat);
                        
                        //construct neutrino in hadron rest frame
                        float cdfval = float(rand())/float((RAND_MAX));
                        int icdf = 0;
                        while (_energy_cdf[apid][sign*vpid][1][icdf] < cdfval) icdf++;
                        float enu = _energy_cdf[apid][sign*vpid][0][icdf];
                        float phi = float(rand())/float((RAND_MAX)) * 2. * 3.1415926;
                        float costh = 0.9999999 * ( float(rand())/float((RAND_MAX)) * 2. - 1. );
                        
                        // boost neutrino in lab frame
                        FourMomentum vrest;
                        vrest.setThetaPhiME(acos(costh), phi, 0, enu);
                        LorentzTransform ltf;
                        ltf.setBetaVec( phad.betaVec() );
                        FourMomentum p = ltf.transform(vrest);

                        // get position at FASER interface plane
                        if (p.pz()<=0 or p.E()<=10) continue;
                        double posx= p.px()/p.pz() * 480. + _xorigin_h;
                        double posy= p.py()/p.pz() * 480. + _xorigin_v;
                        bool   pass = (posx>_dim[0] and posx<_dim[1] and posy>_dim[2] and posy<_dim[3]);
                        
                        if (pass){
                            if (abs(vpid)!=16){
                                xposition.push_back(posx);
                                yposition.push_back(posy);
                                xangle.push_back(p.vector3().x()/p.vector3().z());
                                yangle.push_back(p.vector3().y()/p.vector3().z());
                                energy.push_back(p.E()/GeV);
                                eventweight.push_back(evtweight*weight*pow(p.E()/GeV,_epow));
                                hadronpid.push_back(pid);
                                neutrinopid.push_back(vpid);
                                nused.push_back(0);
                            }
                            else{
                                t_xposition.push_back(posx);
                                t_yposition.push_back(posy);
                                t_xangle.push_back(p.vector3().x()/p.vector3().z());
                                t_yangle.push_back(p.vector3().y()/p.vector3().z());
                                t_energy.push_back(p.E()/GeV);
                                t_eventweight.push_back(evtweight*weight*pow(p.E()/GeV,_epow));
                                t_hadronpid.push_back(pid);
                                t_neutrinopid.push_back(vpid);
                                t_nused.push_back(0);
                            }
                        }
                    } // end loop nrepeat
                } //end neutrino loop
            } //end hadron loop
        } // end analyse
        
        void finalize() {
            
            cout << crossSection()/picobarn << " " << sumOfWeights() <<  endl;
            int nevent = 450000;
            double weightsum = std::accumulate(eventweight.begin(), eventweight.end(), 0.0);
            double weight = crossSection()/picobarn / sumOfWeights() * weightsum / double(nevent);
            std::default_random_engine generator;
            std::discrete_distribution<int> distribution {eventweight.begin(), eventweight.end()};
            
            int t_nevent = 50000;
            double t_weightsum = std::accumulate(t_eventweight.begin(), t_eventweight.end(), 0.0);
            double t_weight = crossSection()/picobarn / sumOfWeights() * t_weightsum / double(t_nevent);
            std::default_random_engine t_generator;
            std::discrete_distribution<int> t_distribution {t_eventweight.begin(), t_eventweight.end()};
            
            int nmax = 0 ;
            std::ofstream eventfile;
            eventfile.open ("events_charm.txt");
            eventfile << std::setprecision(4) << endl;
            for (int ievent=0; ievent<nevent; ++ievent) {
                int i = distribution(generator);
                eventfile << std::setw(3) << neutrinopid[i]  << " ";
                eventfile << std::setw(5) << hadronpid[i]    << " ";
                eventfile << std::setw(9) << std::fixed      << int(xposition[i]*100000)/100000. << " ";
                eventfile << std::setw(9) << std::fixed      << int(yposition[i]*100000)/100000. << " ";
                eventfile << std::setw(7) << std::fixed      << 0.                           << " ";
                eventfile << std::setw(9) << std::scientific << xangle[i]                    << " ";
                eventfile << std::setw(9) << std::scientific << yangle[i]                    << " ";
                eventfile << std::setw(8) << std::scientific << energy[i]                    << " ";
                eventfile << std::setw(8) << std::scientific << weight/pow(energy[i],_epow)  << endl;
                nused[i] = nused[i]+1;
                if (nused[i]>nmax)  nmax = nused[i];
            }
            
            int t_nmax = 0 ;
            for (int ievent=0; ievent<t_nevent; ++ievent) {
                int i = t_distribution(t_generator);
                eventfile << std::setw(3) << t_neutrinopid[i]  << " ";
                eventfile << std::setw(5) << t_hadronpid[i]    << " ";
                eventfile << std::setw(9) << std::fixed      << int(t_xposition[i]*100000)/100000. << " ";
                eventfile << std::setw(9) << std::fixed      << int(t_yposition[i]*100000)/100000. << " ";
                eventfile << std::setw(7) << std::fixed      << 0.                             << " ";
                eventfile << std::setw(9) << std::scientific << t_xangle[i]                    << " ";
                eventfile << std::setw(9) << std::scientific << t_yangle[i]                    << " ";
                eventfile << std::setw(8) << std::scientific << t_energy[i]                    << " ";
                eventfile << std::setw(8) << std::scientific << t_weight/pow(t_energy[i],_epow)<< endl;
                t_nused[i] = t_nused[i]+1;
                if (t_nused[i]>t_nmax)  t_nmax = t_nused[i];
            }
            eventfile.close();
            
            cout << "charm ve/vmu"<<endl;
            cout << "-- found " << eventweight.size() << " weighted events" << endl;
            cout << "-- sample " << nevent << " unwighted events" << endl;
            double wmax = 0;
            int ievmax = 0;
            for (int iev=0; iev<eventweight.size() ; ++iev) {
                if (eventweight[iev]>wmax) {
                    wmax=eventweight[iev];
                    ievmax = iev;
                }
            }
            cout << "-- total event weight " << weightsum << endl;
            cout << "-- maximal event weight " << wmax << endl;
            cout << "-- effective number of events " << weightsum/wmax << endl;
            cout << "-- max weight events VPID: " << neutrinopid[ievmax] << endl;
            cout << "-- max weight events HPID: " << hadronpid[ievmax] << endl;
            cout << "-- max weight events E: " << energy[ievmax] << endl;
            cout << "-- maximum number of repeated events : " << nmax << endl;
            cout << "-- realized effective number events : " << nevent/nmax << endl;
            
            
            cout << "charm vtau"<<endl;
            cout << "-- found " << t_eventweight.size() << " weighted events" << endl;
            cout << "-- sample " << t_nevent << " unwighted events" << endl;
            double t_wmax = 0;
            int t_ievmax = 0;
            for (int iev=0; iev<t_eventweight.size() ; ++iev) {
                if (t_eventweight[iev]>t_wmax) {
                    t_wmax=t_eventweight[iev];
                    t_ievmax = iev;
                }
            }
            cout << "-- total event weight " << t_weightsum << endl;
            cout << "-- maximal event weight " << t_wmax << endl;
            cout << "-- effective number of events " << t_weightsum/t_wmax << endl;
            cout << "-- max weight events VPID: " << t_neutrinopid[t_ievmax] << endl;
            cout << "-- max weight events HPID: " << t_hadronpid[t_ievmax] << endl;
            cout << "-- max weight events E: " << t_energy[t_ievmax] << endl;
            cout << "-- maximum number of repeated events : " << t_nmax << endl;
            cout << "-- realized effective number events : " << t_nevent/t_nmax << endl;
        
        }
        
        
        /*void finalize() {
             
            double factor = crossSection()/picobarn / sumOfWeights();
            cout << crossSection()/picobarn << " " << sumOfWeights() << endl;
            /// double fac2 = 20050426503.041 / 9839066113.868;
             
            std::ofstream eventfile;
            eventfile.open ("events_charm.txt");
            eventfile << std::setprecision(4) << endl;
            for (int i=0; i<neutrinopid.size(); i++){
                eventfile << std::setw(3) << neutrinopid[i]  << " ";
                eventfile << std::setw(5) << hadronpid[i]    << " ";
                eventfile << std::setw(5) << std::fixed      << int(xposition[i]*1000)/1000. << " ";
                eventfile << std::setw(5) << std::fixed      << int(yposition[i]*1000)/1000. << " ";
                eventfile << std::setw(5) << std::fixed      << 0.                           << " ";
                eventfile << std::setw(9) << std::scientific << xangle[i]                    << " ";
                eventfile << std::setw(9) << std::scientific << yangle[i]                    << " ";
                eventfile << std::setw(8) << std::scientific << energy[i]                    << " ";
                eventfile << std::setw(8) << std::scientific << eventweight[i] * factor      << endl;
            }
            eventfile.close();

         }*/
         
        
        private:
        
        //How often redecay?
        int _nrepeat0 = 1000;
        int _nenhance = 10;
        double _epow = 1;
        
        // output
        vector<double > xposition, yposition, xangle, yangle, energy, eventweight;
        vector<int> hadronpid, neutrinopid, nused;
        vector<double > t_xposition, t_yposition, t_xangle, t_yangle, t_energy, t_eventweight;
        vector<int> t_hadronpid, t_neutrinopid, t_nused;
        
        // beam crossing angle
        static constexpr float _xing_urad_h = 0;
        static constexpr float _xing_urad_v = -160;
        static constexpr float _xorigin_h = 0;
        static constexpr float _xorigin_v = 0;
        
        // spatial cuts: xmin, xmax, ymin, ymax
        vector<float> _dim = {-0.5, 0.5, -0.5, 0.5};
        
        // other input
        vector<int> _vpids = {12,-12,14,-14,16,-16};
        vector<int> _hpids = {411,421,431,4122};
        map<int, map<int, vector< vector<float> > > > _energy_cdf;
        map<int, vector<float> > _decay_branchings;
        
    };
    
    DECLARE_RIVET_PLUGIN(Run3_Neutrinos_Charm);
    
}

