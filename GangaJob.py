import os #use this file for everything

#DaVinciVersion = 'v32r2p1'
myApplication = DaVinci()
#myApplication.version = DaVinciVersion
myApplication.user_release_area = '~/cmtuser'
#myApplication.platform = 'x86_64-slc5-gcc46-opt'

myEnv = myApplication.getenv()
myApplication.optsfile = [File('DV_noPID_StrippingArchive.py')]
j = Job(name='noGEC', application=myApplication, backend=Dirac())
j.backend.settings['CPUTime'] = 50000
mySplitter = SplitByFiles(filesPerJob=1)
#myData = [ 'LFN:/lhcb/LHCb/Collision11/SEMILEPTONIC.DST/00022761/0000/00022761_00001773_1.semileptonic.dst' ]
#myInputData = LHCbDataset(files = myData)
j.outputfiles = [DiracFile('DVTuples1noGEC.root')] #has to match what's in optsfile
j.inputfiles = [LocalFile('/afs/cern.ch/user/m/mwilkins/luminosity/LUT-M1M2-L0PT.txt')] #inputting lookup table for the L0pt correction
j.splitter = mySplitter
j.splitter.bulksubmit = False 
#j.inputdata = myInputData 
#j.inputdata = j.application.readInputData('../data_list/BK_LHCb_Collision11_Beam3500GeV-VeloClosed-MagUp_Real Data_Reco14_Stripping20r1_90000000_SEMILEPTONIC.DST.py') #you can uncomment these lines and comment the next one to test it
#j.inputdata = j.application.readInputData('/afs/cern.ch/user/m/mwilkins/LbJpsipPi/test/sampleDST/MC_2012_Beam4000GeV2012MagDownNu2.5Pythia6_Sim08a_Digi13_Trig0x409f0045_Reco14a_Stripping20NoPrescalingFlagged_15144103_ALLSTREAMS.DST.py')
j.inputdata = j.application.readInputData('000000.Semileptonic.DST.py')
j.submit()
