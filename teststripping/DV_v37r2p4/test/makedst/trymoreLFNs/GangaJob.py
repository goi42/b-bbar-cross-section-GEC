j = Job(application=DaVinci(version='v37r2p4'))
j.backend = Dirac()
j.name = 'noGEC_moreLFNs'
j.inputdata = j.application.readInputData('164668_Real Data_Reco15a_90000000_RDST.py')
#j.inputdata.depth=2
j.application.optsfile = 'TestMyStrippingLineAndCreateNtuple.py'

j.outputfiles = [DiracFile("DVTuplesTestMy.root")]
j.splitter = SplitByFiles(filesPerJob = 10,maxFiles = -1)
#j.do_auto_resubmit = True


j.submit()
#queues.add(j.submit)
