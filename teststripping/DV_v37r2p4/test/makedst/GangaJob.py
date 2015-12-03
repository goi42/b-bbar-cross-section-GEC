import os #use this file for everything

myApplication = DaVinci(version='v37r2p4')
myApplication.user_release_area = '~/cmtuser'

j = Job(name='noGEC_dst', application=myApplication, backend=Dirac())
j.comment = 'all LFN, commented out input in optsfile, listed Reco as optsfile'
j.splitter = SplitByFiles(filesPerJob=5)
myOptsfiles = ['./TestMyStrippingLine_noGEC_modified.py','./Reco15a_Run164668_modified.py']
j.application.optsfile = myOptsfiles
j.inputdata = j.application.readInputData(myOptsfiles)
j.submit()
