import os #use this file for everything

myApplication = DaVinci(version='v37r2p4')
myApplication.user_release_area = '~/cmtuser'

j = Job(name='noGEC_dst', application=myApplication, backend=Dirac())
j.comment = 'all LFN, commented out input in optsfile, no splitter'
j.splitter = SplitByFiles(filesPerJob=5)
j.application.optsfile = './TestMyStrippingLine_noGEC_modified.py'
j.inputdata = j.application.readInputData('./Reco15a_Run164668_modified.py')
j.submit()
