j = Job(application=DaVinci(version='v37r2p4'))
j.backend = Dirac()
j.name = 'noGEC'
j.inputdata = j.application.readInputData('Reco15a_Run164668_modified.py')
j.inputdata.depth=2
j.application.optsfile = 'TestMyStrippingLineAndCreateNtuple.py'

j.outputfiles = [LocalFile("DVTuplesTestMy.root")]
j.splitter = SplitByFiles(filesPerJob = 10,maxFiles = -1)
j.do_auto_resubmit = True


j.submit()
#queues.add(j.submit)
