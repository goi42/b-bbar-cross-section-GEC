import os #use this file for everything

#myApplication = DaVinci(version='v37r2p4')
#myApplication.user_release_area = '~/cmtuser'
myApplication = DaVinci()

j = Job(name='GEC_dst', application=myApplication, backend=Dirac())
j.comment = 'job 294, but with latest DV'
j.splitter = SplitByFiles(filesPerJob=5)
j.application.optsfile = [File('./TestMyStrippingLine_noGEC_modified.py')]
j.inputdata = j.application.readInputData('./Reco15a_Run164668_modified.py')
j.submit()
